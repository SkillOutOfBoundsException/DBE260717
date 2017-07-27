#include "Bloque.h"

Bloque::Bloque(int t, int n){
    sizeB = t;
    num = n;
}

char * Bloque::toChar(){
    int pos = 0;
    char * data;
    memcpy(&data[pos], &sizeB, 4);
    pos = pos + 4;
    memcpy(&data[pos], &num, 4);
    pos = pos + 4;
    memcpy(&data[pos], &sig, 4);
    pos = pos + 4;
    return data;
}

void Bloque::load(){

}


