#include <iostream>
#include "Lista.h"
#include "Bloque.h"
#include "BloqueTabla.h"
#include "BloqueMaster.h"
#include "BloqueLlaves.h"
#include "BloqueCampo.h"
#include "Campo.h"
#include "Tabla.h"
#include "Engine.h"
#include "Archivo.h"
#include "Llave.h"
#include "json11.hpp"
#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <sstream>
#define str_size 20
#define int_size 4

using namespace std;
using namespace json11;

void generateHugeTable(Engine * e, Tabla * t, int regs){
    srand((int)time(0));
    int tabla = t->id;
    int tam = t->tamReg();
    int cantReg = t->cantReg;
    e->addCampoToTabla(tabla, "Name", 1);
    e->addCampoToTabla(tabla, "Last Name", 1);
    e->addCampoToTabla(tabla, "Age", 0);
    e->addCampoToTabla(tabla, "Address", 1);
    e->addCampoToTabla(tabla, "# of Children", 0);
    e->addCampoToTabla(tabla, "# of Dogs", 0);
    e->addCampoToTabla(tabla, "# of Cats", 0);
    e->addCampoToTabla(tabla, "House #", 0);
    e->addCampoToTabla(tabla, "Annual Earning ($)", 0);

    char * fnames[50] = {
    "Nichol",
    "Viki",
    "Maddie",
    "Alpha",
    "Salena",
    "Anya",
    "Tierra",
    "Bethanie",
    "Edris",
    "Chloe",
    "Coreen",
    "Yvette",
    "Daphne",
    "Senaida",
    "Darron",
    "Gilma",
    "Dorotha",
    "Ranee",
    "Laure",
    "Bridget",
    "Carli",
    "Arnold",
    "Chance",
    "Sumiko",
    "Cythia",
    "Nakisha",
    "Eura",
    "Neal",
    "Annalee",
    "Fe",
    "Moira",
    "Madelene",
    "Juli",
    "Janina",
    "Latanya",
    "Kyoko",
    "Janey",
    "Phuong",
    "Mercy",
    "Mertie",
    "Shakia",
    "Faith",
    "Tilda",
    "Dorcas",
    "Latina",
    "Dulce",
    "Genna",
    "Priscilla",
    "Willena",
    "Willena",
    };

    char * lnames[50] = {
    "Moses",
    "Whitney",
    "Frye",
    "Sims",
    "Steele",
    "Coffey",
    "Jimenez",
    "Knox",
    "Mitchell",
    "Rosario",
    "Nguyen",
    "Allison",
    "Ford",
    "Bennett",
    "Phillips",
    "Neal",
    "Wong",
    "Delacruz",
    "Romero",
    "Velazquez",
    "Hogan",
    "Fernandez",
    "Hughes",
    "Rodriguez",
    "Clarke",
    "Singh",
    "Proctor",
    "Holloway",
    "Fischer",
    "Spears",
    "Fitzpatrick",
    "Stevenson",
    "Barnes",
    "Kennedy",
    "Gibbs",
    "Swanson",
    "Davenport",
    "Dalton",
    "Maddox",
    "Freeman",
    "Russo",
    "Weaver",
    "Chase",
    "Whitaker",
    "Miranda",
    "Alexander",
    "Lester",
    "Mcmahon",
    "Dillon",
    "Barnett",
    };

    char * address[11] = {
    "9 Wilson Drive",
    "467 East Creek",
    "352 6th St. Rahway",
    "7495 Wood Ave.Manch",
    "7073 Plumb Branch",
    "427 Saxon Dr. Bis",
    "36 San Juan Street",
    "253 West Division",
    "99 Sunbeam Street",
    "9879 High Ridge St",
    "WOW INCREDIBLE",
    };

    for(int i = 0; i < regs; i++){
        char * id = new char[20];
        char * name = new char[20];
        char * lastName = new char[20];
        char * add = new char[20];
        int age = (rand() % 37) + 18;
        int children = (rand() % 5);
        int dogs = (rand() % 4);
        int cats = (rand() % 3);
        int hNum = (rand() % 4001) + 1000;
        int earning = ((rand() % 10) + 1) * 10000;

        ostringstream ss;
        int kek = i + cantReg;
        ss << kek;
        string x = ss.str();
        strcpy(id, x.c_str());

        name = fnames[(rand() % 49) + 1];
        lastName = lnames[(rand() % 49) + 1];
        add = address[(rand() % 9) + 1];

        char * data = new char[tam];
        int pos = 4;
        memcpy(&data[pos], &id[0], str_size);
        pos = pos + str_size;
        memcpy(&data[pos], &name[0], str_size);
        pos = pos + str_size;
        memcpy(&data[pos], &lastName[0], str_size);
        pos = pos + str_size;
        memcpy(&data[pos], &age, int_size);
        pos = pos + int_size;
        memcpy(&data[pos], &add[0], str_size);
        pos = pos + str_size;
        memcpy(&data[pos], &children, int_size);
        pos = pos + int_size;
        memcpy(&data[pos], &dogs, int_size);
        pos = pos + int_size;
        memcpy(&data[pos], &cats, int_size);
        pos = pos + int_size;
        memcpy(&data[pos], &hNum, int_size);
        pos = pos + int_size;
        memcpy(&data[pos], &earning, int_size);
        pos = pos + int_size;
        e->addRegistroToTabla(tabla, data);
        delete data;
        delete id;
        delete name;
        delete lastName;
        delete add;
        delete ss;
    }
}

int main(){
    Engine * e = new Engine();

    //e->format();

    int tabla = 0;

    //tabla = e->addTabla("Huge Table");

    Tabla * t = e->searchTabla(tabla);
    generateHugeTable(e, t, 60);

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

