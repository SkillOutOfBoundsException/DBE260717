#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <string.h>
#include <stdio.h>
#include "BloqueMaster.h"
#include "BloqueHash.h"
#include "BloqueLlaves.h"
#include "Lista.h"
#define int_size sizeof(int)
#define str_size 20
#define hash_size 16
#define hTable_size 20
#define hashXbloque 31

using namespace std;

class HashTable{
    public:
        HashTable();

        Lista<Llave*>*llaves;

        int primerBloqueHash;
        int actualBloqueHash;
        int cantBloqueHash;
        int cantHash;

        int m;

        Llave * buscar(char * id);

        void newEntry(char * id, int numBloque, int numRelReistro, BloqueMaster * bm);
        void addLlaveToHTEntry(Llave * l, HTEntry * hte, BloqueMaster * bm);

        int fnHash(char * id);
        void createFirstTable(BloqueMaster * bm);
        void reHash(BloqueMaster * bm);

        char * toChar();
        void loadHashTable(char *);
};

#endif // HASHTABLE_H
