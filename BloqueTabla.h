#ifndef BLOQUETABLA_H
#define BLOQUETABLA_H
#include "Bloque.h"
#include "Lista.h"


class BloqueTabla : public Bloque{
    public:

        struct Tabla{
            char nombre[20];
            int id;
            int primerBloqueCampo;
            int actualBloqueCampo;
            int primerBloqueReg;
            int actualBloqueReg;
        };

        BloqueTabla(int t);
        Lista<Tabla*> *tablas;
        int cantTablas;


        char * tablaToChar(Tabla*);
        Tabla* charToTabla(char*);
};

#endif // BLOQUETABLA_H
