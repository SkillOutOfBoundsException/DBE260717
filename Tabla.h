#ifndef TABLA_H
#define TABLA_H
#include <string.h>


class Tabla
{
    public:
        Tabla();

        char nombre[20];
        int id;
        int primerBloqueCampo;
        int actualBloqueCampo;
        int primerBloqueReg;
        int actualBloqueReg;

        char * toChar();
        void loadTabla(char*);
};

#endif // TABLA_H
