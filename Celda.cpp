#include "Celda.h"

Celda::Celda(Campo * c, char * d){
    campo = c;
    if(campo->tipo == 1){
        data = new char[str_size];
        memcpy(&data[0], &d[0], str_size);
    }
    else{
        data = new char[int_size];
        memcpy(&data[0], &d[0], int_size);
    }
}

void Celda::printCelda(){
    if(campo->tipo == 1)
        cout << data;
    else{
        int d;
        memcpy(&d, &data[0], int_size);
        cout << d;
    }
}
