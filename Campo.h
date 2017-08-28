#ifndef CAMPO_H
#define CAMPO_H
#include <string.h>
#include <iostream>
#include <stdio.h>
#define campo_size 28
#define int_size sizeof(int)
#define str_size 20

using namespace std;


class Campo{

    public:
        Campo();
        char * nombre;
        int tipo;
        int regSize;

        char * toChar();
        void loadCampo(char *);

        void setAttributes(char * n, int t);
        void printCampo();
};

#endif // CAMPO_H
