#ifndef REGISTRO_H
#define REGISTRO_H
#include <stdio.h>
#include <string.h>
#define int_size sizeof(int)
#define str_size 20


class Registro{
    public:
        Registro(int l);
        char * data;
        int len;

        char * toChar();
        void loadRegistro(char *);
};

#endif // REGISTRO_H
