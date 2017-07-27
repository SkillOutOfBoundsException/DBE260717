#ifndef BLOQUE_H
#define BLOQUE_H
#include <string.h>


class Bloque{
    public:
        Bloque(int t);
        int sig;
        int num;
        int sizeB;

        char * toChar();
        void load();
};

#endif // BLOQUE_H
