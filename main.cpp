#include <iostream>
#include "Lista.h"
#include "Bloque.h"
#include "BloqueTabla.h"
#include "BloqueMaster.h"
#include "BloqueLlaves.h"
#include "BloqueCampo.h"
#include "Campo.h"
#include "Engine.h"
#include "Archivo.h"
#include "Llave.h"
#include "json11.hpp"
#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>

using namespace std;
using namespace json11;

int main(){

    Engine * e = new Engine();
    /*
    e->addTabla("niggers");
    e->addCampoToTabla(0, "age", 0);
    e->addRegistroToTabla(0);
    //*/
    e->searchTabla(0)->printReg("Diego");


    //e->printTablas();
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

    Upcoming changes:

        void Registro::insertar(){
            ...
            int nBloque = ...
            int numDeRegRel = ...
            ...
            IdxEntry * entry = new IdxEntry(tabla, nBloque, numDeRegRel, llave, id);
            tabla->indice->agregarEntrada(entry); //indice es tipo HashTable
         }

         Registro * Tabla::buscarRegistro(char * id){
            IdxEntry * entry = indice->buscar(id);
            if(entry == null)
                return null;
            Registro * reg = cargarRegistro(entry->nB, entry->nRR);
            return reg;
         }

    Nuevas classes para manejar indices:

        IdxEntry{
            int numBloque;
            int numRegistroRelativo;
        }

        HashTableEntry{
            int primerBloqueLlave;
            int actualBloqueLlave;
        }

        IdxEntry * Indice::Buscar(char * id){
            int pos = fnHash(id);
            int bloqueHashRelativo = pos/CANT_HASH_TABLE_ENTRIES_POR_BLOQUE;
            int entradaRelativa = pos%CANT_HASH_TABLE_ENTRIES_POR_BLOQUE;
            int bloqueActual = tabla->primerBloqueIndice;
            for(int i = 0; i < bloqueHashRelativo; i++){
                BloqueHashTable * bht = new BloqueHashTable(bloqueActual);
                bht->load();
                bloqueActual = bht->sig;
                delete bht;
            }
            BloqueHashTable * bht = new BloqueHashTAble(bloqueAcutal);
            bht->load();
            HashTableEntry * hte = bht->entradas->get(entradaRelativa);
            int bloqueLlave = hte->primerBloqueLlaves;
            while(bloqueLlave != hte->actualBloqueLlave){
                BloqueIdxEntries * bie = new BloqueIdxEntries(bloqueLlave);
                bie->load();
                for(int i = 0; i < bie->cantEntradas; i++){
                    IdxEntry * entry = bie->entradas->get(i);
                    if(entry->id ?==? id)
                        return entry;
                    delete entry;
                }
                bloqueLlaves = b->sig;
                delete b;
            }
            return null;
        }

        mit ocw introduction to algorithm
            buscar hash tables;





    Arboles B:
        Nodo es un bloque
        0 <= elementos <= m
        0 <= hijos <= m+1

        TamanoBloque = EncabezadoB + (m+1)*TamanoHijo + m * TamanoEntry

        Implementar Busqueda:

            int ArbolB::buscar(int x){
                return buscar(x, root);
            }

            int ArbolB::buscar(int x, Bloque * sraiz){
                if(sraiz == 0)
                    return 0;
                int hijo = 0;
                for(int i = 0; i < M; i++){
                    if(llaves[i]->key > key)
                        break;
                    if(llaves[i]->key > key)
                        retur llaves[i];
                    hijo++; hey b.
                }
                if(sraiz->esHoja())
                    return 0;
                Bloque * b = new Bloque(sraiz->Hijos[hijo]);
                b->load();
                return buscar(x, b);
            }

            Bloque * ArbolB::buscarBloqueObjetivo(){
                if(sraiz == 0)
                    return 0;
                int hijo = 0;
                for(int i = 0; i < M; i++){
                    if(llaves[i]->key > key)
                        break;
                    if(llaves[i]->key > key)
                        retur llaves[i];
                    hijo++;
                }
                if(sraiz->esHoja())
                    return sraiz;
                Bloque * b = new Bloque(sraiz->Hijos[hijo]);
                b->load();
                return buscar(x, b);
            }

            void ArbolB::insert(int x){
                //hey boo. -jackie-senpai
                Bloque * bloque;
                if(raiz == null){
                    bloque = new Bloque();
                    raiz = bloque;

                }
                else{
                    bloque = buscarBloqueObjetivo();
                    if(bloque == null)
                        return -1;//colision
                }
                int pos = 0;
                for(int i = 0; i < m; i++){
                    if(llaves[i]->key > key)
                        break;
                    pos++;
                }
                for(int i = llaves->size(); i < pos; i++){
                    llaves[i] = llaves[i - 1];
                }
                llaves[pos] = entry;
                //pendiente promover

            }


            struct promocion(int llave, Bloque * hIzq, Bloque * hDer);

            promocion * ArbolB::split(Bloque * actual){
                Bloque * hermano = new Bloque();
                int mitad = m + 1;
                for(int i = 0; i < mitad + i + 1 <= m + 1; i++){
                    if(mitad + i + 1 < m + 1){
                        hermano->llaves = actual->llaves[mitad + 1 + i];
                        actual->llaves[mitad + i + 1] = null; //eliminar
                    }
                    hermano->hijos[i] = actual->hijos[mitad + i + 1];
                    actual->hijos->eliminarAt(mitad + i + 1);
                }
                return new promocion(actual->llaves->pop_back(), actual, hermano);
            }

            void ArbolB::crecer(Bloque * actual){
                if(actual->llaves>size <= m){
                    return
                }
                struct promocion * strp = split(actual);
                if(actual->padre == null){
                    raiz = new Bloque();
                    actual->padre = raiz;
                }
                promover(actual->padre, strp);
                crecer(actual->padre);
            }

            void ArbolB::promover(Bloque * padre, struct promocion * strp){
                int pos = 0;
                for(int i = 0; i < m + 1; i++){
                    if(padre->llaves[i]->key > strp->key)
                        break;
                    pos++;
                }
                for(int i = padre->llaves->size(); i < pos; i--){
                    hashbrows k e k
                    padre->llaves[i] = padre->llaves[i-1];
                }
                for(int i = padre->llaves->size(); i > pos + 1; i--){
                    padre->hijos[i] = padre->hijos[i-1];
                }
                padre->llaves[pos] = strp->key;
                padre->hijos[pos] = strp->BloqueIzquierdo;
                padre->hijos[pos + 1] = strp->BloqueDerecho;
            }
*/

