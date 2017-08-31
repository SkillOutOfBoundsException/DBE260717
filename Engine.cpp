#include "Engine.h"

Engine::Engine(){
    arch = new Archivo();
    bm = new BloqueMaster();
    tablas = new Lista<Tabla*>();
    load();
}

void Engine::load(){
    if(arch->exists()){
        bm->read();
        return;
    }
    arch->open("w");
    arch->close();
    bm->write();
}

void Engine::format(){
    bm = new BloqueMaster();
    bm->write();
}

void Engine::addTabla(char* nombre){
    Tabla * t = new Tabla(bm->cantTablas);
    t->setNombre(nombre);
    bm->cantTablas++;
    if(bm->primerBloqueTabla == -1){
        BloqueTabla * bt = new BloqueTabla(bm->cantBloques);
        bm->cantBloqueTabla++;
        bm->cantBloques++;
        bm->actualBloqueTabla = bt->num;
        bm->primerBloqueTabla = bt->num;
        bt->addTabla(t);
        bt->write();
    }
    else{
        BloqueTabla * bt = new BloqueTabla(bm->actualBloqueTabla);
        bt->read();
        if(!bt->addTabla(t)){
            BloqueTabla * bt2 = new BloqueTabla(bm->cantBloques);
            bm->cantBloqueTabla++;
            bm->cantBloques++;
            bt->sig = bt2->num;
            bm->actualBloqueTabla = bt2->num;
            bt2->addTabla(t);
            bt2->write();
        }
        bt->write();
    }
    bm->write();
}

void Engine::addCampoToTabla(int idTabla, char * nombre, int tipo){
    BloqueTabla * bt = searchBloqueTabla(idTabla);
    if(bt == 0){
        cout << "tabla not found" << endl;
        return;
    }
    Tabla * t = 0;
    for(int i = 0; i < bt->cantTablas; i++){
        Tabla * temp = bt->tablas->index(i);
        if(idTabla == temp->id){
            t = temp;
            break;
        }
    }
    t->addCampo(nombre, tipo, bm);
    bt->write();
}

void Engine::addRegistroToTabla(int idTabla, char * data){
    BloqueTabla * bt = searchBloqueTabla(idTabla);
    if(bt == 0){
        cout << "tabla not found" << endl;
        return;
    }
    Tabla * t = 0;
    for(int i = 0; i < bt->cantTablas; i++){
        Tabla * temp = bt->tablas->index(i);
        if(idTabla == temp->id){
            t = temp;
            break;
        }
    }
    data = data == 0 ? t->generateReg() : data;
    t->addRegistro(data, bm);
    bt->write();
}

BloqueTabla * Engine::searchBloqueTabla(int id){
    int i = bm->primerBloqueTabla;
    while(i != -1){
        BloqueTabla * bt = new BloqueTabla(i);
        bt->read();
        for(int k = 0; k < bt->cantTablas; k++){
            if(bt->tablas->index(k)->id == id)
                return bt;
        }
        i = bt->sig;
    }
    return 0;
}

Tabla * Engine::searchTabla(int id){
    loadTablas();
    for(int i = 0; i < bm->cantTablas; i++){
        Tabla * t = tablas->index(i);
        if(t->id == id)
            return t;
    }
    return 0;
}

void Engine::writeJson(){
    loadTablas();
    vector<Json> jTablas;
    for(int i = 0; i < bm->cantTablas; i++){
        Json js = tablas->index(i)->tablaToJson();
        jTablas.push_back(js);
    }
    Json jDB = Json::object{
        {"cantTablas", bm->cantTablas},
        {"Tablas", jTablas}
    };
    ofstream rip("db.json");
    rip << jDB.dump();
    rip.close();
}

void Engine::readJson(){
    format();
    ifstream rip("db.json");
    string e;
    string j;
    getline(rip, j);
    rip.close();
    Json jDB = Json::parse(j, e);
    int ct = jDB["cantTablas"].int_value();
    for(int i = 0; i < ct; i++){
        Json jtabla = jDB["Tablas"][i];
        char * nom = new char[20];
        strcpy(nom, jtabla["Nombre"].string_value().c_str());
        addTabla(nom);
        Json jcampos = jtabla["Campos"];
        int cc = jcampos["cantCampos"].int_value();
        for(int k = 0; k < cc; k++){
            Json campo = jcampos["Campos"][k];
            char * cNom = new char[20];
            strcpy(cNom, campo["nombre"].string_value().c_str());
            int tipo = campo["tipo"].int_value();
            addCampoToTabla(i, cNom, tipo);
        }
        Json jregistros = jtabla["Registros"];
        int cr = jregistros["cantReg"].int_value();
        for(int k = 0; k < cr; k++){
            char * data = new char[searchTabla(i)->tamReg()];
            int pos = 4;
            for(int j = 0; j < cc; j++){
                Json celda = jregistros["Registros"][k][j];
                int tipo = celda["tipo"].int_value();
                if(tipo == 1){
                    char * cData = new char[20];
                    strcpy(cData, celda["data"].string_value().c_str());
                    memcpy(&data[pos], &cData[0], str_size);
                    pos = pos + str_size;
                }
                else{
                    int cData = celda["data"].int_value();
                    memcpy(&data[pos], &cData, int_size);
                    pos = pos + int_size;
                }
            }
            addRegistroToTabla(i, data);
        }
    }
}

void Engine::loadTablas(){
    tablas->clearList();
    if(bm->primerBloqueTabla == -1){
        cout << "No hay tablas" << endl;
        return;
    }
    int i = bm->primerBloqueTabla;
    while(i != -1){
        BloqueTabla * bt = new BloqueTabla(i);
        bt->read();
        for(int k = 0; k < bt->cantTablas; k++)
            tablas->pushBack(bt->tablas->index(k));
        i = bt->sig;
    }
}

void Engine::printTablas(){
    loadTablas();
    for(int i = 0; i < bm->cantTablas; i++){
        tablas->index(i)->printTabla();
    }
}

void Engine::printBloques(){
    bm->printSelf();
    cout << "------------------------" << endl;
    int i = bm->primerBloqueTabla;
    while(i != -1){
        BloqueTabla * bt = new BloqueTabla(i);
        bt->read();
        bt->printBloque();
        i = bt->sig;
    }
}
