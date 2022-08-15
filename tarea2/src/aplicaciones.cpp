/* 5369059 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/aplicaciones.h"
#include "../include/cadena.h"
#include "../include/iterador.h"


TCadena insertarAlFinal(nat natural, double real, TCadena cad) {
 TCadena aux = cadenaSiguiente(insertarAlInicio(natural, real, cad));
 cad = aux;
 return cad;
}

TCadena removerPrimero(TCadena cad) {
  cad = removerDeCadena(natInfo(primeroEnCadena(cad)),cad);
  return cad;
}


TCadena copiaCadena(TCadena cad) {
  TCadena copia;
  copia = crearCadena();
while (cantidadEnCadena(cad)!= cantidadEnCadena(copia)){
  copia = insertarAlFinal(natInfo(primeroEnCadena(cad)), realInfo(primeroEnCadena(cad)),copia);
  cad = cadenaSiguiente(cad);
}
return copia;
}

void reverso2(TIterador it, TIterador rever){
  if (!estaDefinidaActual(it)){
  }else{
    nat elm = actualEnIterador(it);
    avanzarIterador(it);
    reverso2(it, rever);
    agregarAIterador(elm,rever);
  }
  
}

TIterador reversoDeIterador(TIterador iter) {
  reiniciarIterador(iter);
  TIterador rever;
  rever = crearIterador();
  reverso2(iter, rever);
  return rever;
}


