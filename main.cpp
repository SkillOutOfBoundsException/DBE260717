#include <iostream>
#include "Lista.h"
#include "Bloque.h"
#include "BloqueTabla.h"
#include "BloqueMaster.h"
#include "Engine.h"
#include "Archivo.h"
#include <stdio.h>


using namespace std;


int main(){

    Engine * e = new Engine();

    /*
    for(int i = 0; i < 20; i++){
        e->addTabla("TablaTemp");
    }
    */


    e->addCampoToTabla(7, "RegistroTemp", 1);

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
