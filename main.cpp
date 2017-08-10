#include <iostream>
#include "Lista.h"
#include "Bloque.h"
#include "BloqueTabla.h"
#include "Archivo.h"
#include <stdio.h>


using namespace std;


int main(){

    Bloque * b = new Bloque(0);
    BloqueTabla * bt = new BloqueTabla(1);

    b->read();
    bt->read();

    bt->tablas->index(0)->printTabla();


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
