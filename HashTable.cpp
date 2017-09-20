#include "HashTable.h"

HashTable::HashTable(){
    primerBloqueHash = -1;
    actualBloqueHash = -1;
    cantBloqueHash = 0;
    cantHash = 0;
    m = hashXbloque;
}

Llave * HashTable::buscar(char * id){
    int pos = fnHash(id);
    int bloqueHashRelativo = pos/hashXbloque;
    int entradaRelativa = pos%hashXbloque;
    int bloqueActual = primerBloqueHash;
    for(int i = 0; i < bloqueHashRelativo; i++){
        BloqueHash * bh = new BloqueHash(bloqueActual);
        bh->read();
        bloqueActual = bh->sig;
        delete bh;
    }
    BloqueHash * bh = new BloqueHash(bloqueActual);
    bh->read();
    HTEntry * hte = bh->getHTEntry(entradaRelativa);
    int bloqueLlave = hte->primerBloqueLlave;
    while(bloqueLlave != -1){
        BloqueLlaves * bl = new BloqueLlaves(bloqueLlave);
        bl->read();
        for(int i = 0; i < bl->cantLlaves; i++){
            Llave * l = bl->llaves->index(i);
            if(strcmp(l->id, id) == 0)
                return l;
            delete l;
        }
        bloqueLlave = bl->sig;
        delete bl;
    }
    return 0;
}

void HashTable::createFirstTable(BloqueMaster * bm){
    BloqueHash * bh = new BloqueHash(bm->cantBloques);
    bm->cantBloques++;
    cantBloqueHash++;
    primerBloqueHash = bh->num;
    actualBloqueHash = bh->num;
    bh->write();
    bm->write();
}

void HashTable::newEntry(char * id, int numBloque, int numRelRegistro, BloqueMaster * bm){
    if(primerBloqueHash == -1)
        createFirstTable(bm);
    int llave = fnHash(id);
    Llave * l = new Llave();
    l->setAttributes(id, llave, numBloque, numRelRegistro);
    cantHash++;
    int bloqueHashRel = llave/hashXbloque;
    int hTERelativa = llave%hashXbloque;
    int bloqueActual = primerBloqueHash;
    for(int i = 0; i < bloqueHashRel; i++){
        BloqueHash * bh = new BloqueHash(bloqueActual);
        bh->read();
        bloqueActual = bh->sig;
        delete bh;
    }
    BloqueHash * bh = new BloqueHash(bloqueActual);
    bh->read();
    HTEntry * hte = bh->getHTEntry(hTERelativa);
    addLlaveToHTEntry(l, hte, bm);
    bh->write();
    if(cantHash == m-1)
        reHash(bm); //SUBJECT TO CHANGE
}

void HashTable::addLlaveToHTEntry(Llave * l, HTEntry * hte, BloqueMaster * bm){
    hte->cantLlaves++;
    if(hte->primerBloqueLlave == -1){
        BloqueLlaves * bl = new BloqueLlaves(bm->cantBloques);
        hte->cantBloqueLlaves++;
        bm->cantBloques++;
        hte->primerBloqueLlave = bl->num;
        hte->actualBloqueLlave = bl->num;
        bl->addLlave(l);
        bl->write();
    }
    else{
        BloqueLlaves * bl = new BloqueLlaves(hte->actualBloqueLlave);
        bl->read();
        if(!bl->addLlave(l)){
            BloqueLlaves * bl2 = new BloqueLlaves(bm->cantBloques);
            hte->cantBloqueLlaves++;
            bm->cantBloques++;
            bl->sig = bl2->num;
            hte->actualBloqueLlave = bl2->num;
            bl2->addLlave(l);
            bl2->write();
        }
        bl->write();
    }
    bm->write();
}

void HashTable::reHash(BloqueMaster * bm){
    cantHash = 0;
    llaves->clearList();
    int i = primerBloqueHash;
    while(i != -1){
        BloqueHash * bh = new BloqueHash(i);
        bh->read();
        for(int k = 0; k < bh->cantHashEntries; k++){
            HTEntry * hte = bh->hashEntries->index(k);
            int j = hte->primerBloqueLlave;
            while(j != -1){
                BloqueLlaves * bl = new BloqueLlaves(j);
                bl->read();
                for(int z = 0; z < bl->cantLlaves; z++){
                    llaves->pushBack(bl->llaves->index(z));
                }
                bl->llaves->clearList();
                bl->write();
                delete bl;
            }
        }
        bh->reFillList();
        bh->write();
        delete bh;
    }
    int goal = cantBloqueHash * 2;
    int prev = -1;
    for(int i = cantBloqueHash; i < goal; i++){
        BloqueHash * bh = new BloqueHash(bm->cantBloques);
        bm->cantBloques++;
        bh->write();
        bm->write();
        BloqueHash * bh2 = new BloqueHash(actualBloqueHash);
        bh2->read();
        bh2->sig = bh->num;
        actualBloqueHash = bh->num;
        bh2->write();
        delete bh;
        delete bh2;
    }
    cantBloqueHash = goal;
    m = m*2;
    for(int i = 0; i < llaves->length(); i++){
        Llave * l = llaves->index(i);
        newEntry(l->id, l->numeroBloque, l->numeroDeRegistroRelativo, bm);
    }
}

int HashTable::fnHash(char * id){
    unsigned int l = 0;
    for(int i = 0; i < strlen(id); i++)
        l = l + int(id[i]);
    l = l * 100;
    return l%m;
}

char * HashTable::toChar(){
    int pos = 0;
    char * data = new char[hTable_size];
    memcpy(&data[pos], &primerBloqueHash, 4);
    pos = pos + 4;
    memcpy(&data[pos], &actualBloqueHash, 4);
    pos = pos + 4;
    memcpy(&data[pos], &cantBloqueHash, 4);
    pos = pos + 4;
    memcpy(&data[pos], &cantHash, 4);
    pos = pos + 4;
    memcpy(&data[pos], &m, 4);
    pos = pos + 4;
    return data;
}

void HashTable::loadHashTable(char * data){
    int pos = 0;
    memcpy(&primerBloqueHash, &data[pos], 4);
    pos = pos + 4;
    memcpy(&actualBloqueHash, &data[pos], 4);
    pos = pos + 4;
    memcpy(&cantBloqueHash, &data[pos], 4);
    pos = pos + 4;
    memcpy(&cantHash, &data[pos], 4);
    pos = pos + 4;
    memcpy(&m, &data[pos], 4);
    pos = pos + 4;
}
