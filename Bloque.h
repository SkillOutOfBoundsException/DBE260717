#ifndef BLOQUE_H
#define BLOQUE_H
#include <string.h>
#include <iostream>
#include "Archivo.h"

using namespace std;

class Bloque{
    public:
        Bloque(int t);
        int sig;
        int num;
        int sizeB;

        Archivo * arch;

        char * toChar();
        void load(char data[512]);

        void write();
        void read(int n);
};

#endif // BLOQUE_H
