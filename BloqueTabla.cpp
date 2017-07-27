#include "BloqueTabla.h"

BloqueTabla::BloqueTabla(int t) : Bloque(t){
    tablas = new Lista<Tabla*>();

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
    return data;
}
