#ifndef ENGINE_H
#define ENGINE_H
#include "BloqueMaster.h"
#include "BloqueTabla.h"
#include "Lista.h"
#include "Tabla.h"
#include "Archivo.h"
#define int_size sizeof(int)
#define str_size 20
//json stuff
#include <iostream>
#include "json11.hpp"
#include <vector>
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;
using namespace json11;

class Engine{
    public:
        Engine();
        Archivo * arch;
        BloqueMaster * bm;
        Lista<Tabla*> * tablas;

        void format();
        void load();
        void addTabla(char* nombre);
        void addCampoToTabla(int idTabla, char * nombre, int tipo);
        void addRegistroToTabla(int idTabla, char * data = 0);

        Tabla * searchTabla(int id);
        BloqueTabla * searchBloqueTabla(int id);

        void writeJson();
        void readJson();

        void loadTablas();
        void printTablas();
        void printBloques();

};

#endif // ENGINE_H
