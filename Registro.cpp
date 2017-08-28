#include "Registro.h"

Registro::Registro(int l){
    len = l;
    data = new char[len];
}

char * Registro::toChar(){
    char * reg = new char[len + int_size];
    int pos = 0;
    memcpy(&reg[pos], &len, int_size);
    pos = pos + int_size;
    memcpy(&reg[pos], &data[0], len);
    pos = pos + len;
    return reg;
}

void Registro::loadRegistro(char * reg){
    int pos = 0;
    memcpy(&len, &reg[pos], int_size);
    pos = pos + int_size;
    data = new char[len];
    memcpy(&data[0], &reg[pos], len);
    pos = pos + len;
}
