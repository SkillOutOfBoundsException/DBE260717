#include <iostream>
#include "Lista.h"
#include "Bloque.h"
#include "BloqueTabla.h"
#include "Archivo.h"
#include "BManager.h"


using namespace std;


int main(){

    Bloque * b = new Bloque(0);

    BloqueTabla * bt = new BloqueTabla(1);

    b->read();

    bt->read();

    bt->tablas->index(0)->printTabla();

    //cout << bt->tablas->isEmpty() << endl;

//    b->write();
//
//    Tabla * t = new Tabla();
//
//    t->id = 0;
//    memcpy(&t->nombre[0], "tabla1", 7);
//
//    bt->addTabla(t);
//
//    bt->write();


    return 0;

}
