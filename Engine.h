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

        void load();
        void addTabla(char* nombre, int cantCampos);

        void loadTablas();
        void printTablas();

};

#endif // ENGINE_H
