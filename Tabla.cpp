#include "Tabla.h"


Tabla::Tabla(int n){
    id = n;
    nombre = new char[20];
    primerBloqueCampo = -1;
    primerBloqueReg = -1;
    actualBloqueCampo = -1;
    actualBloqueReg = -1;
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
    return data;
}

void Tabla::setNombre(char* n){
    memcpy(&nombre[0], &n[0], 20);
}

void Tabla::printTabla(){
    cout << "Tabla - " << nombre << endl;
    cout << id << endl;
    //cout << primerBloqueCampo << endl;
    //cout << actualBloqueCampo << endl;
    //cout << primerBloqueReg << endl;
    //cout << actualBloqueReg << endl;
}
