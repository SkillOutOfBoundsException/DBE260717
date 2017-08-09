#ifndef BLOQUECAMPO_H
#define BLOQUECAMPO_H
#include "Bloque.h"
#include "Campo.h"
#include "Lista.h"
#define tabla_size 40 //tabla size
#define int_size sizeof(int)
#define str_size 20

class BloqueCampo : public Bloque{

    public:
        BloqueCampo();
        Lista<Campo*> campos;
        int cantCampos;

        bool addCampo(Campo*);

        char * toChar();
        void load(char *);

        void write();
        void read();
};

#endif // BLOQUECAMPO_H
