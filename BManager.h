#ifndef BMANAGER_H
#define BMANAGER_H
#include "Archivo.h"
#include "Bloque.h"


class BManager{
    public:
        BManager();
        int cant;
        int sizeB;
        Archivo * arch;

        void newBloque();
        void writeBloque(Bloque*);
        Bloque* readBloque(int b);
};

#endif // BMANAGER_H
