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

    Archivo * a = new Archivo();

    //Engine * e = new Engine();

    BloqueMaster * bm = new BloqueMaster();

    //e->addCampoToTabla(2, "noob", 0);
    for(int i = 0; i < 30; i++){
        bm->cantBloques++;
        bm->write();
        cout << bm->cantBloques << endl;
    }

    //e->bm->read();

    //e->bm->printSelf();

    //e->bm->printSelf();









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
