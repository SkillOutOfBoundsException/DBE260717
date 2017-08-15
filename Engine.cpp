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
    }
    Tabla * t;
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

void Engine::loadTablas(){
    tablas->clearList();
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
