#include "HTEntry.h"

HTEntry::HTEntry(){
    primerBloqueLlave = -1;
    actualBloqueLlave = -1;
    cantBloqueLlaves = 0;
    cantLlaves = 0;
}

char * HTEntry::toChar(){
    char * data = new char[hash_size];
    int pos = 0;
    memcpy(&data[pos], &primerBloqueLlave, 4);
    pos = pos + 4;
    memcpy(&data[pos], &actualBloqueLlave, 4);
    pos = pos + 4;
    memcpy(&data[pos], &cantBloqueLlaves, 4);
    pos = pos + 4;
    memcpy(&data[pos], &cantLlaves, 4);
    pos = pos + 4;
    return data;
}

void HTEntry::loadHTEntry(char * data){
    int pos = 0;
    memcpy(&primerBloqueLlave, &data[pos], 4);
    pos = pos + 4;
    memcpy(&actualBloqueLlave, &data[pos], 4);
    pos = pos + 4;
    memcpy(&cantBloqueLlaves, &data[pos], 4);
    pos = pos + 4;
    memcpy(&cantLlaves, &data[pos], 4);
    pos = pos + 4;
}
