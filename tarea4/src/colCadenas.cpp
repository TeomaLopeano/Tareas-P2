/* 5369059 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/colCadenas.h"

struct _rep_colCadenas {
TCadena *cad;
nat cant;
};

TColCadenas crearColCadenas(nat tamanio) { 
  TColCadenas aux =new _rep_colCadenas;
  aux->cad= new TCadena[tamanio];
  aux->cant=tamanio;
  for (nat i = 0; i < tamanio; i++){
    aux->cad[i]=crearCadena();
  }
  return aux;
}

void liberarColCadenas(TColCadenas col) {
  nat x= col->cant;
  for (nat i = 0; i < x; i++)
  {
    liberarCadena(col->cad[i]);
  }
  delete[] col->cad;
  delete col;  
}

nat tamanioColCadenas(TColCadenas col) { 
  return col->cant;
}

TCadena cadenaDeColCadenas(nat pos, TColCadenas col) { 
  return col->cad[pos];
}

nat cantidadColCadenas(nat pos, TColCadenas col) { 
  return cantidadEnCadena(col->cad[pos]);
}

bool estaEnColCadenas(nat natural, nat pos, TColCadenas col) { 
  return estaEnCadena(natural,col->cad[pos]);
}

TColCadenas insertarEnColCadenas(nat natural, double real, nat pos, TColCadenas col) {
  col->cad[pos]=insertarAlInicio(natural,real,col->cad[pos]);
  return col;
}

TInfo infoEnColCadenas(nat natural, nat pos, TColCadenas col) { 
  return infoCadena(natural,col->cad[pos]);
}

TColCadenas removerDeColCadenas(nat natural, nat pos, TColCadenas col) {
  col->cad[pos]=removerDeCadena(natural,col->cad[pos]);
  return col;
}
