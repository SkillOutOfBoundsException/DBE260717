#include "Tabla.h"
#define tablaSize 40 //tablaSize

Tabla::Tabla(){
    primerBloqueCampo = -1;
    primerBloqueReg = -1;
    actualBloqueCampo = -1;
    actualBloqueReg = -1;
}

void Tabla::loadTabla(char* data){
    int pos = 0;
    memcpy(&nombre[0], &data[pos], 20);
    pos = pos + 20;
    memcpy(&id, &data[pos],  4);
    pos = pos + 4;
    memcpy(&primerBloqueCampo, &data[pos], 4);
    pos = pos + 4;
    memcpy(&actualBloqueCampo, &data[pos], 4);
    pos = pos + 4;
    memcpy(&primerBloqueReg, &data[pos], 4);
    pos = pos + 4;
    memcpy(&actualBloqueReg, &data[pos], 4);
    pos = pos + 4;
}

char* Tabla::toChar(){
    char * data = new char[tablaSize];
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
    return data;
}
