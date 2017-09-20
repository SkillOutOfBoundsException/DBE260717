#include "BloqueHash.h"

BloqueHash::BloqueHash(int t) : Bloque(t){
    cantHashEntries = hashXbloque;
    hashEntries = new Lista<HTEntry*>();
    reFillList();
}

HTEntry * BloqueHash::getHTEntry(int x){
    return hashEntries->index(x);
}

void BloqueHash::reFillList(){
    hashEntries->clearList();
    for(int i = 0; i < hashXbloque; i++)
        hashEntries->pushBack(new HTEntry());
}

char * BloqueHash::toChar(){
    int pos = 0;
    char * data = new char[sizeB];
    memcpy(&data[pos], &sizeB, 4);
    pos = pos + 4;
    memcpy(&data[pos], &num, 4);
    pos = pos + 4;
    memcpy(&data[pos], &sig, 4);
    pos = pos + 4;
    memcpy(&data[pos], &cantHashEntries, 4);
    pos = pos + 4;
    for(int i = 0; i < cantHashEntries; i++){
        memcpy(&data[pos], hashEntries->index(i)->toChar(), hash_size);
        pos = pos + hash_size;
    }
    return data;
}

void BloqueHash::load(char * data){
    hashEntries->clearList();
    int pos = 0;
    memcpy(&sizeB, &data[pos], 4);
    pos = pos + 4;
    memcpy(&num, &data[pos], 4);
    pos = pos + 4;
    memcpy(&sig, &data[pos], 4);
    pos = pos + 4;
    memcpy(&cantHashEntries, &data[pos], 4);
    pos = pos + 4;
    for(int i = 0; i < cantHashEntries; i++){
        HTEntry * hte = new HTEntry();
        hte->loadHTEntry(&data[pos]);
        hashEntries->pushBack(hte);
        pos = pos + hash_size;
    }
}

void BloqueHash::write(){
    arch->open("rb+");
    char * data = toChar();
    arch->write(data, num*sizeB, sizeB);
    arch->close();
}

void BloqueHash::read(){
    arch->open("rb");
    char * data = arch->read(num*sizeB, sizeB);
    load(data);
    arch->close();
}
