#ifndef ENGINE_H
#define ENGINE_H
#include "BloqueMaster.h"
#include "BloqueTabla.h"
#include "Lista.h"
#include "Tabla.h"
#include "Archivo.h"
#define int_size sizeof(int)
#define str_size 20


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
        void addRegistroToTabla(int idTabla);

        Tabla * searchTabla(int id);
        BloqueTabla * searchBloqueTabla(int id);

        void loadTablas();
        void printTablas();
        void printBloques();

};

#endif // ENGINE_H
