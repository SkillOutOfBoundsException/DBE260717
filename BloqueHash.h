#ifndef BLOQUEHASH_H
#define BLOQUEHASH_H
#include "Bloque.h"
#include "HTEntry.h"
#include "Lista.h"
#define int_size sizeof(int)
#define str_size 20
#define hash_size 16
#define hashXbloque 2

class BloqueHash : public Bloque{
    public:
        BloqueHash(int t);
        Lista<HTEntry*> * hashEntries;
        int cantHashEntries;    //to be removed

        void reFillList();
        HTEntry * getHTEntry(int x);

        char * toChar();
        void load(char *);

        void write();
        void read();

        void printBloque();
};

#endif // BLOQUEHASH_H
