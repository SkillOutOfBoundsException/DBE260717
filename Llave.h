#ifndef LLAVE_H
#define LLAVE_H
#include <iostream>
#include <string.h>
#include <stdio.h>
#define int_size sizeof(int)
#define str_size 20
#define llave_size 32

using namespace std;

class Llave{
    public:
        Llave();

        char * id;
        int llave;
        int numeroBloque;
        int numeroDeRegistroRelativo;

        void setAttributes(char * i, int l, int nb, int nrr);

        char * toChar();
        void loadLlave(char *);
};

#endif // LLAVE_H
