#include <iostream>
#include "Lista.h"
#include "Bloque.h"
#include "BloqueTabla.h"
#include "BloqueMaster.h"
#include "BloqueCampo.h"
#include "Campo.h"
#include "Engine.h"
#include "Archivo.h"
#include <stdio.h>


using namespace std;


int main(){


    Engine * e = new Engine();

    //e->addCampoToTabla(2, "noob", 0);
    /*for(int i = 0; i < 500; i++){
        for(int k = 0; k < 100; k++){
            e->addCampoToTabla(i, "kekistan", 1);
        }
    }*/

    e->printTablas();











    return 0;
}


/*
    Master Bloque:
        primerBloqueTabla;
        actualBloqueTabla;
        sizeBloque;

    Manejador de Bloque (DBEngine):
        maneja el blockManager;
        maneja todas las tablas y organiza;
        debe poder formatear la db;

    BloqueTabla:
        numBloque;
        sigBloqueTabla;

    Tablas:
        Poder crearlas:
            crear Tablas en 1 bloque;
            crear N Tablas en N bloques;
*/
