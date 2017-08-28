#include "BloqueRegistro.h"

BloqueRegistro::BloqueRegistro(int t, int r) : Bloque(t){
    registros = new Lista<Registro*>();
    cantReg = 0;
    tamReg = r;
}

char * BloqueRegistro::toChar(){
    int pos = 0;
    char * data = new char[sizeB];
    memcpy(&data[pos], &sizeB, 4);
    pos = pos + 4;
    memcpy(&data[pos], &num, 4);
    pos = pos + 4;
    memcpy(&data[pos], &sig, 4);
    pos = pos + 4;
    memcpy(&data[pos], &cantReg, 4);
    pos = pos + 4;
    memcpy(&data[pos], &tamReg, 4);
    pos = pos + 4;
    for(int i = 0; i < cantReg; i++){
        memcpy(&data[pos], campos->index(i)->toChar(), tamReg);
        pos = pos + tamReg;
    }

    return data;
}
