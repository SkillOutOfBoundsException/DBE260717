#include "BManager.h"

BManager::BManager(){
    cant = 0;
    sizeB = 512;
    arch = new Archivo();
}

void BManager::newBloque(){
    Bloque* bl = new Bloque(sizeB);
    bl->num = cant++;
    writeBloque(bl);
}

void BManager::writeBloque(Bloque* b){
    arch->open("r+");
    arch->write(b->toChar(), (cant-1)*sizeB, sizeB);
    arch->close();
}

Bloque* BManager::readBloque(int b){
    arch->open("r");
    char * data = arch->read(b*sizeB, sizeB);
    Bloque* bl = new Bloque(sizeB);
    bl->load(data);
    return bl;
}
