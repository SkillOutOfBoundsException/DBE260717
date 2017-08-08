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

    cout << bt->tablas->isEmpty() << endl;

//    b->write();
//
//    Tabla * t = new Tabla(0);
//
//    t->id = 0;
//    char a[20] = "fuck niggas";
//    memcpy(&t->nombre[0], &a[0], 20);
//
//    bt->addTabla(t);
//
//    bt->write();

    return 0;

}
