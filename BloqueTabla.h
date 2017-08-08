#ifndef BLOQUETABLA_H
#define BLOQUETABLA_H
#include "Bloque.h"
#include "Lista.h"
#include "Tabla.h"
#define tablaSize 40 //tabla size


class BloqueTabla : public Bloque{

    public:
        BloqueTabla(int t);
        Lista<Tabla*> *tablas;
        int cantTablas;

        bool addTabla(Tabla*);

        char * toChar();
        void load(char* data);

        void write();
        void read();
};

#endif // BLOQUETABLA_H
