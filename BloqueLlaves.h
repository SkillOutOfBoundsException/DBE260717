#ifndef BLOQUELLAVES_H
#define BLOQUELLAVES_H
#include "Bloque.h"
#include "Llave.h"
#include "Lista.h"
#define int_size sizeof(int)
#define str_size 20
#define llave_size 32

class BloqueLlaves : public Bloque{
    public:
        BloqueLlaves(int t);
        Lista<Llave*> * llaves;
        int cantLlaves;

        bool addLlave(Llave*);

        char * toChar();
        void load(char *);

        void write();
        void read();

        void printBloque();
};

#endif // BLOQUELLAVES_H
