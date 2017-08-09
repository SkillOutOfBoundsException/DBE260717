#include "Campo.h"

Campo::Campo(){
    nombre = new char[20];
    tipo = 0;
    regSize = 4;
}

void Campo::loadCampo(char* data){
    int pos = 0;
    memcpy(&nombre[0], &data[pos], 20);
    pos = pos + 20;
    memcpy(&tipo, &data[pos], 4);
    pos = pos + 4;
    memcpy(&regSize, &data[pos], 4);
    pos = pos + 4;
    memcpy(&actualBloqueCampo, &data[pos], 4);
    pos = pos + 4;
}

char * Campo::toChar(){
    char * data = new char[campo_size];
    int pos = 0;
    memcpy(&data[pos], &nombre[0], 20);
    pos = pos + 20;
    memcpy(&data[pos], &tipo, 4);
    pos = pos + 4;
    memcpy(&data[pos], &regSize, 4);
    pos = pos + 4;
    return data;
}
