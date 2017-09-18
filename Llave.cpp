#include "Llave.h"

Llave::Llave(){
    id = new char[str_size];
    llave = -1;
    numeroBloque = -1;
    numeroDeRegistroRelativo = -1;
}

void Llave::setAttributes(char * i, int l, int nb, int nrr){
    id = i;
    llave = l;
    numeroBloque = nb;
    numeroDeRegistroRelativo = nrr;
}

char * Llave::toChar(){
    char * data = new char[llave_size];
    int pos = 0;
    memcpy(&data[pos], &id[0], str_size);
    pos = pos + str_size;
    memcpy(&data[pos], &llave, 4);
    pos = pos + 4;
    memcpy(&data[pos], &numeroBloque, 4);
    pos = pos + 4;
    cout << numeroBloque << endl;
    memcpy(&data[pos], &numeroDeRegistroRelativo, 4);
    pos = pos + 4;
    return data;
}

void Llave::loadLlave(char * data){
    int pos = 0;
    id = new char[20];
    memcpy(&id[0], &data[pos], str_size);
    pos = pos + str_size;
    memcpy(&llave, &data[pos], 4);
    pos = pos + 4;
    memcpy(&numeroBloque, &data[pos], 4);
    pos = pos + 4;
    memcpy(&numeroDeRegistroRelativo, &data[pos], 4);
    pos = pos + 4;
}

