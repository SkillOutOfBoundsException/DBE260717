#include "BloqueLlaves.h"

BloqueLlaves::BloqueLlaves(int t) : Bloque(t){
    cantLlaves = 0;
    llaves = new Lista<Llave*>();
}

bool BloqueLlaves::addLlave(Llave * l){
    if(cantLlaves >= 15)
        return false;
    llaves->pushBack(l);
    cantLlaves++;
    return true;
}

char * BloqueLlaves::toChar(){
    int pos = 0;
    char * data = new char[sizeB];
    memcpy(&data[pos], &sizeB, 4);
    pos = pos + 4;
    memcpy(&data[pos], &num, 4);
    pos = pos + 4;
    memcpy(&data[pos], &sig, 4);
    pos = pos + 4;
    memcpy(&data[pos], &cantLlaves, 4);
    pos = pos + 4;
    for(int i = 0; i < cantLlaves; i++){
        memcpy(&data[pos], llaves->index(i)->toChar(), llave_size);
        pos = pos + llave_size;
    }
    return data;
}

void BloqueLlaves::load(char * data){
    int pos = 0;
    memcpy(&sizeB, &data[pos], 4);
    pos = pos + 4;
    memcpy(&num, &data[pos], 4);
    pos = pos + 4;
    memcpy(&sig, &data[pos], 4);
    pos = pos + 4;
    memcpy(&cantLlaves, &data[pos], 4);
    pos = pos + 4;
    for(int i = 0; i < cantLlaves; i++){
        Llave * l = new Llave();
        l->loadLlave(&data[pos]);
        llaves->pushBack(l);
        pos = pos + llave_size;
    }
}

void BloqueLlaves::write(){
    arch->open("rb+");
    char * data = toChar();
    arch->write(data, num*sizeB, sizeB);
    arch->close();
}

void BloqueLlaves::read(){
    arch->open("rb");
    char * data = arch->read(num*sizeB, sizeB);
    load(data);
    arch->close();
}
