/* 5369059 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/cola.h"
#include "../include/cadena.h"


struct _rep_cola {
    TCadena cad;
    nat cant;
};


TCola crearCola() { 
   TCola nuevo = new _rep_cola;
   nuevo->cad=crearCadena();
   nuevo->cant=0;
   return nuevo; 
}

void liberarCola(TCola c) {
    liberarCadena(c->cad);
    delete c;
}

nat cantidadEnCola(TCola c) { 
return c->cant;
}

TCola encolar(TInfo info, TCola c) { 
  c->cad= insertarAlFinal(natInfo(info),realInfo(info),c->cad);
  c->cant++;
  return c;
}

TInfo frente(TCola c) { 
return primeroEnCadena(c->cad);
}

TCola desencolar(TCola c) { 
    c->cad=removerPrimero(c->cad);
    c->cant--;
    return c;
}
