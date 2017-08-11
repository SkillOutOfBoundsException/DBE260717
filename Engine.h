#ifndef ENGINE_H
#define ENGINE_H
#include "BloqueMaster.h"
#include "BloqueTabla.h"
#include "Lista.h"
#include "Tabla.h"
#define int_size sizeof(int)
#define str_size 20


class Engine{

    public:
        Engine();
        BloqueMaster * bm;
        Lista<Tabla*> * tablas;

        void format();
        void load();
        void addTabla(char*);

        Tabla * searchTabla(int id);
        BloqueTabla * searchBloqueTabla(int id);
        void addCampoToTabla(int idTabla, char * nombre, int tipo);

        void loadTablas();
        void printTablas();

};

#endif // ENGINE_H
