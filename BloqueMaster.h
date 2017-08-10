#ifndef BLOQUEMASTER_H
#define BLOQUEMASTER_H
#include "Bloque.h"
#define int_size sizeof(int)
#define str_size 20

class BloqueMaster : public Bloque{

    public:

        BloqueMaster();
        int primerBloqueTabla;
        int actualBloqueTabla;

        char * toChar();
        void load(char*);

        void write();
        void read();
};

#endif // BLOQUEMASTER_H
