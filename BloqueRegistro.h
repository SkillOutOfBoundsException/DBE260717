#ifndef BLOQUEREGISTRO_H
#define BLOQUEREGISTRO_H
#include "Bloque.h"
#include "Lista.h"
#define int_size sizeof(int)
#define str_size 20


class BloqueRegistro : public Bloque{
    public:
        BloqueRegistro();
        //Lista<Registro*> * registros;
        int cantReg;

        bool addReg();

        char * toChar();
        void load(char*);

        void write();
        void read();

        void printBloque();
};

#endif // BLOQUEREGISTRO_H
