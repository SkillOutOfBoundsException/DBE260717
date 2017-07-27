#include "Archivo.h"

Archivo::Archivo(char * p){
    myFile = fopen(p, "r+");
}

void Archivo::write(char * data, int pos, int length){
    fprintf(myFile, data);
}

