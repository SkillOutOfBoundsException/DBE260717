#include "BloqueTabla.h"

BloqueTabla::BloqueTabla(int t) : Bloque(t){
    tablas = new Lista<Tabla*>();
    cantTablas = 0;
}

char * BloqueTabla::toChar(){
    int pos = 0;
    char * data = new char[sizeB];
    memcpy(&data[pos], &sizeB, 4);
    pos = pos + 4;
    memcpy(&data[pos], &num, 4);
    pos = pos + 4;
    memcpy(&data[pos], &sig, 4);
    pos = pos + 4;
    memcpy(&data[pos], &cantTablas, 4);
    pos = pos + 4;
    for(int i = 0; i < cantTablas; i++){
        memcpy(&data[pos], tablas->index(i)->toChar(), tablaSize);
        pos = pos + tablaSize;
    }
    return data;
}

void BloqueTabla::load(char * data){
    int pos = 0;
    memcpy(&sizeB, &data[pos], 4);
    pos = pos + 4;
    memcpy(&num, &data[pos], 4);
    pos = pos + 4;
    memcpy(&sig, &data[pos], 4);
    pos = pos + 4;
    memcpy(&cantTablas, &data[pos], 4);
    pos = pos + 4;
    for(int i = 0; i < cantTablas; i++){
        Tabla * t = new Tabla();
        t->loadTabla(&data[pos]);
        tablas->pushBack(t);
        pos = pos + tablaSize;
    }
}
