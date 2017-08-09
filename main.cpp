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
