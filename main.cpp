#include <iostream>
#include "Lista.h"
#include "Bloque.h"
#include "Archivo.h"
using namespace std;


class BManager{
    public:
        BManager(char * ){
            cant = 0;
            sizeB = 512;
        }
        int cant;
        int sizeB;
        Archivo * arch;

        void newBloque(){
            cant++;
            Bloque* bl = new Bloque(sizeB, );
        }
};

int main(){

    Archivo * ar = new Archivo("db.txt");

    char wow[20] = "fuckkck";

    ar->write(&wow[0], 0, 0);

    return 0;

}
