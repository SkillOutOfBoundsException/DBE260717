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
#include <iostream>
#include <string>
#include <math.h>

using namespace std;


int main(){


    Engine * e = new Engine();

    /*
    for(int i = 0; i < 100; i++){
        e->addTabla("WOW");
        for(int k = 0; k < 10; k++){
            e->addCampoToTabla(i, "Campo", k%2);
        }
    }
    */

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

    Registros:
        Tamaño Variable;
        Tamaño depende de la cantidad  tipo de campos;

    Hash Tables:
        Propiedades:
            -Insertar O(1)
            -Buscar O(1)
            -Eliminar O(1)

        Hash Function:
            Buscamos mayor dispercion posible;

            Ejemplo para examen:
                int fnHash(char * k){
                    return keytoInt(k)%m;
                }

            fnHash pronostica C colisiones para tablas de tamano M con N elementos;

            Formas de manejar colisiones:
                Sumarle 1 a fnHash(k);

*/
