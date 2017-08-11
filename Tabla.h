#ifndef TABLA_H
#define TABLA_H
#include <string.h>
#include <iostream>
#include <stdio.h>
#define tabla_size 40 //tablaSize
#define int_size sizeof(int)
#define str_size 20

using namespace std;

class Tabla{
    public:
        Tabla(int n);

        char * nombre;
        int id;
        int primerBloqueCampo;
        int actualBloqueCampo;
        int primerBloqueReg;
        int actualBloqueReg;

        char * toChar();
        void loadTabla(char*);

        void setNombre(char*);
        void printTabla();

};

#endif // TABLA_H
