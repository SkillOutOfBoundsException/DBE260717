#include "Archivo.h"

Archivo::Archivo(){
    //myFile = fopen("db.txt", "r+");
}

void Archivo::write(char * data, int pos, int length){
    fseek(myFile, pos, SEEK_SET);
    fwrite(data, 1, length, myFile);
}

char * Archivo::read(int pos, int length){
    fseek(myFile, pos, SEEK_SET);
    char data[length];
    fread(data, sizeof(char), length, myFile);
    return data;
}

void Archivo::close(){
    fclose(myFile);
}

void Archivo::open(char * mode){
    myFile = fopen("db.txt", mode);
}

