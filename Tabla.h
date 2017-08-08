#ifndef TABLA_H
#define TABLA_H
#include <string.h>
#include <iostream>

using namespace std;

class Tabla
{
    public:
        Tabla(int n);

        char nombre[20];
        int id;
        int primerBloqueCampo;
        int actualBloqueCampo;
        int primerBloqueReg;
        int actualBloqueReg;

        char * toChar();
        void loadTabla(char*);

        void printTabla();

};

#endif // TABLA_H
