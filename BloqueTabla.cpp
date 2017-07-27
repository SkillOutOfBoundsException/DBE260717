#include "BloqueTabla.h"

BloqueTabla::BloqueTabla(int t) : Bloque(t){
    tablas = new Lista<Tabla*>();
    int cantTablas = 0;

}

char * Bloque::toChar(){
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
        memcpy(&data[pos], tablas->)
    }
    return data;
}

char* Bloque::tablaToChar(Tabla* t){
    char * data = new char[44];
    int pos = 0;
    memcpy(&data[pos], &t->nombre[0], 20);
    pos = pos + 20;
    memcpy(&data[pos], &t->id, 4);
    pos = pos + 4;
    memcpy(&data[pos], &t->primerBloqueCampo, 4);
    pos = pos + 4;
    memcpy(&data[pos], &t->actualBloqueCampo, 4);
    pos = pos + 4;
    memcpy(&data[pos], &t->primerBloqueReg, 4);
    pos = pos + 4;
    memcpy(&data[pos], &t->actualBloqueReg, 4);
    pos = pos + 4;
    return data;
}

Tabla* Bloque::charToTabla(char* data){
    int pos = 0;
    struct Tabla* t;
    memcpy(&t->nombre[0], &data[pos], 20);
    pos = pos + 20;
    memcpy(&t->id, &data[pos],  4);
    pos = pos + 4;
    memcpy(&data[pos], &t->primerBloqueCampo, 4);
    pos = pos + 4;
    memcpy(&data[pos], &t->actualBloqueCampo, 4);
    pos = pos + 4;
    memcpy(&data[pos], &t->primerBloqueReg, 4);
    pos = pos + 4;
    memcpy(&data[pos], &t->actualBloqueReg, 4);
    pos = pos + 4;
    return t;
}
