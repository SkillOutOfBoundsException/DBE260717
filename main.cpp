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

    //e->addCampoToTabla(2, "noob", 0);
    for(int i = 0; i < 100; i++){
        e->addTabla("WOW");
        for(int k = 0; k < 10; k++){
            e->addCampoToTabla(i, "Campo", k%2);
        }
    }


    //e->addCampoToTabla(1, "WOWZERS", 0);

    //e->addTabla("testing campos");

    //e->addCampoToTabla(0, "Nombre", 1);
    //e->addCampoToTabla(1, "Apellido", 1);
    //e->addCampoToTabla(0, "Edad", 0);
    //e->addRegistroToTabla(0);
    //e->searchTabla(3)->printTabla();

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

    Indice:
        ???

    Arboles AVL:
        Balance:
            |Altura_Izq - Altura_Der| < 2;
            Caso contrario balancear (dentro del insert);

            void insertar(Nodo * n){
                insertar(&root, n);
            }

            void insertar(Nodo ** raiz, Nodo * n){
                if(*raiz == null){
                    *raiz = n;
                    return;
                }
                if(*raiz->valor > n->valor){
                    insertar(&(*raiz->izquierda), n);
                }
                else{
                    insertar(&(*raiz->derecha), n);
                }
            }

        Rotacion derecha simple (Hi - Hd == 2):
            1- Crear temp apuntando a hijo izquierdo de Sroot;
            2- Sroot->izq apunta a hijoIzq->der;
            3- hijoIzq->der apunta a Sroot;
            4- *Sroot = hijoIzq;
        Rotacion izquirda simple (Hi - Hd == -2):
            1- Crear temp apuntando a hijo derecho de Sroot;
            2- Sroot->der apuntna a hijoDer->izq;
            3- hijoDer->izq apunta a Sroot;
            4- *Sroot = hijoIzq;




*/
