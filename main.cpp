#include <iostream>
#include "Lista.h"
#include "Bloque.h"
#include "Archivo.h"
#include "BManager.h"


using namespace std;



int main(){


//    int x = 1234;
//
//    char y[4];
//
//    memcpy(&y[0], &x, 4);
//
//    cout << y << endl;
//
//    man->arch->write(&y[0], 0, 4);
//
//    char * data;
//    data = man->arch->read(0, 4);
//
//    memcpy(&x, &data[0], 4);
//
//    cout << x << endl;

    Bloque* b = new Bloque(512);

    b->num = 0;


    b->write();

    b->read(0);

    Bloque * c = new Bloque(512);

    c->num = 12;

    c->sizeB = 15;

    c->read(0);

    cout << c->num << " - " << c->sizeB << endl;





    return 0;

}
