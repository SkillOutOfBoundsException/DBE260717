#ifndef ARCHIVO_H
#define ARCHIVO_H
#include <stdio.h>
#include <string.h>

class Archivo
{
    public:
        Archivo(char * p);
        FILE * myFile;

        void open();
        void close();
        void write(char * data, int pos = 0, int length = 0);
        char * read();


};

#endif // ARCHIVO_H
