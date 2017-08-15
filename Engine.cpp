#include "Engine.h"

Engine::Engine(){
    arch = new Archivo();
    bm = new BloqueMaster();
    tablas = new Lista<Tabla*>();
    load();
}

void Engine::load(){
    if(arch->exists()){
        bm->read();
        return;
    }
    arch->open("w");
    arch->close();
    bm->write();
}

void Engine::format(){
    bm = new BloqueMaster();
    bm->write();
}

void Engine::addTabla(char* nombre){
    Tabla * t = new Tabla(bm->cantTablas);
    t->setNombre(nombre);
    bm->cantTablas++;
    if(bm->primerBloqueTabla == -1){
        BloqueTabla * bt = new BloqueTabla(bm->cantBloqueTabla);
        bm->cantBloqueTabla++;
        bm->actualBloqueTabla = bt->num;
        bm->primerBloqueTabla = bt->num;
        bt->addTabla(t);
        bt->write();
    }
    else{
        BloqueTabla * bt = new BloqueTabla(bm->actualBloqueTabla);
        bt->read();
        if(!bt->addTabla(t)){
            BloqueTabla * bt2 = new BloqueTabla(bm->cantBloqueTabla);
            bm->cantBloqueTabla++;
            bt->sig = bt2->num;
            bm->actualBloqueTabla = bt2->num;
            bt2->addTabla(t);
            bt2->write();
        }
        bt->write();
    }
    bm->write();
}

void Engine::loadTablas(){
    tablas->clearList();
    for(int i = 1; i < bm->cantBloqueTabla; i++){
        BloqueTabla * bt = new BloqueTabla(i);
        bt->read();
        for(int k = 0; k < bt->cantTablas; k++){
            tablas->pushBack(bt->tablas->index(k));
        }
    }
}

void Engine::printTablas(){
    loadTablas();
    for(int i = 0; i < bm->cantTablas; i++){
        tablas->index(i)->printTabla();
    }
}
