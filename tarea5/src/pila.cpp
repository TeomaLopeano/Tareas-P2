/* 5369059 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/pila.h"
#include "../include/cadena.h"

struct _rep_pila {
    TCadena cad;
    nat cant;
};

TPila crearPila() { 
    TPila nuevo= new _rep_pila;
    nuevo->cad=crearCadena();
    nuevo->cant=0;
    return nuevo;
}

void liberarPila(TPila p) {
    liberarCadena(p->cad); 
    delete p;
}

nat cantidadEnPila(TPila p) { 
    return p->cant; 
}

TPila apilar(TInfo info, TPila p) {
    p->cad=insertarAlInicio(natInfo(info),realInfo(info),p->cad);
    p->cant++;
    return p;
 }

TInfo cima(TPila p) { 
    return primeroEnCadena(p->cad);
 }

TPila desapilar(TPila p) {
    p->cad=removerPrimero(p->cad);
    p->cant--;
    return p;
}
