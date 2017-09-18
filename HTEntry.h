#ifndef HTENTRY_H
#define HTENTRY_H
#include <iostream>
#include <string.h>
#include <stdio.h>
#define int_size sizeof(int)
#define str_size 20
#define hash_size 16

using namespace std;

class HTEntry{
    public:
        HTEntry();

        int primerBloqueLlave;
        int actualBloqueLlave;
        int cantBloqueLlaves;
        int cantLlaves;

        char * toChar();
        void loadHTEntry(char *);
};

#endif // HTENTRY_H
