#include "Tabla.h"


Tabla::Tabla(int n){
    id = n;
    nombre = new char[20];
    primerBloqueCampo = -1;
    primerBloqueReg = -1;
    actualBloqueCampo = -1;
    actualBloqueReg = -1;
    cantCampos = 0;
    cantReg = 0;
    cantBloqueCampos = 0;
    cantBloqueReg = 0;
    campos = new Lista<Campo*>();
}

void Tabla::addCampo(char * nombre, int tipo, BloqueMaster * bm){
    Campo * c = new Campo();
    c->setAttributes(nombre, tipo);
    cantCampos++;
    if(primerBloqueCampo == -1){
        BloqueCampo * bc = new BloqueCampo(bm->cantBloques);
        cantBloqueCampos++;
        bm->cantBloques++;
        primerBloqueCampo = bc->num;
        actualBloqueCampo = bc->num;
        bc->addCampo(c);
        bc->write();
    }
    else{
        BloqueCampo * bc = new BloqueCampo(actualBloqueCampo);
        bc->read();
        if(!bc->addCampo(c)){
            BloqueCampo * bc2 = new BloqueCampo(bm->cantBloques);
            cantBloqueCampos++;
            bm->cantBloques++;
            bc->sig = bc2->num;
            actualBloqueCampo = bc2->num;
            bc2->addCampo(c);
            bc2->write();
        }
        bc->write();
    }
    bm->write();
}

void Tabla::loadTabla(char * data){
    int pos = 0;
    memcpy(&nombre[0], &data[pos], 20);
    pos = pos + 20;
    memcpy(&id, &data[pos], 4);
    pos = pos + 4;
    memcpy(&primerBloqueCampo, &data[pos], 4);
    pos = pos + 4;
    memcpy(&actualBloqueCampo, &data[pos], 4);
    pos = pos + 4;
    memcpy(&primerBloqueReg, &data[pos], 4);
    pos = pos + 4;
    memcpy(&actualBloqueReg, &data[pos], 4);
    pos = pos + 4;
    memcpy(&cantCampos, &data[pos], 4);
    pos = pos + 4;
    memcpy(&cantReg, &data[pos], 4);
    pos = pos + 4;
    memcpy(&cantBloqueCampos, &data[pos], 4);
    pos = pos + 4;
    memcpy(&cantBloqueReg, &data[pos], 4);
    pos = pos + 4;
}

char* Tabla::toChar(){
    char * data = new char[tabla_size];
    int pos = 0;
    memcpy(&data[pos], &nombre[0], 20);
    pos = pos + 20;
    memcpy(&data[pos], &id, 4);
    pos = pos + 4;
    memcpy(&data[pos], &primerBloqueCampo, 4);
    pos = pos + 4;
    memcpy(&data[pos], &actualBloqueCampo, 4);
    pos = pos + 4;
    memcpy(&data[pos], &primerBloqueReg, 4);
    pos = pos + 4;
    memcpy(&data[pos], &actualBloqueReg, 4);
    pos = pos + 4;
    memcpy(&data[pos], &cantCampos, 4);
    pos = pos + 4;
    memcpy(&data[pos], &cantReg, 4);
    pos = pos + 4;
    memcpy(&data[pos], &cantBloqueCampos, 4);
    pos = pos + 4;
    memcpy(&data[pos], &cantBloqueReg, 4);
    pos = pos + 4;
    return data;
}

void Tabla::setNombre(char* n){
    memcpy(&nombre[0], &n[0], 20);
}

void Tabla::loadCampos(){
    campos->clearList();
    int i = primerBloqueCampo;
    while(i != -1){
        BloqueCampo * bc = new BloqueCampo(i);
        bc->read();
        for(int k = 0; k < bc->cantCampos; k++)
            campos->pushBack(bc->campos->index(k));
        i = bc->sig;
    }
}

void Tabla::printTabla(){
    loadCampos();

    cout << "Tabla - " << nombre << endl;
    cout << "ID - " << id << endl;
    cout << cantCampos << " Campo(s): " << endl;
    for(int i = 0; i < cantCampos; i ++){
        campos->index(i)->printCampo();
    }
    cout << "------------------------" << endl;

    //cout << primerBloqueCampo << endl;
    //cout << actualBloqueCampo << endl;
    //cout << primerBloqueReg << endl;
    //cout << actualBloqueReg << endl;
}
