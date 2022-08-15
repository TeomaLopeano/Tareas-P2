/* 5369059 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/colCadenas.h"

struct _rep_colCadenas {
  TCadena colec[CANT_CADS];
};

TColCadenas crearColCadenas() {
  TColCadenas colcad =new _rep_colCadenas;
  for (nat i = 0; i < CANT_CADS; i++)
  {
    colcad->colec[i]=crearCadena();
  }
  
  return colcad;
}

void liberarColCadenas(TColCadenas col) {
   for (nat i = 0; i < CANT_CADS; i++){
    liberarCadena(col->colec[i]);
  }
  delete col;
}

TCadena cadenaDeColCadenas(nat pos, TColCadenas col) {
  return col->colec[pos];
}

nat cantidadColCadenas(nat pos, TColCadenas col) {
  return cantidadEnCadena(col->colec[pos]);
}

bool estaEnColCadenas(nat natural, nat pos, TColCadenas col) {
  return estaEnCadena(natural, col->colec[pos]);
}

TColCadenas insertarEnColCadenas(nat natural, double real, nat pos,TColCadenas col) {
  col->colec[pos]=insertarAlInicio(natural, real, col->colec[pos]);
  return col;
}

TInfo infoEnColCadenas(nat natural, nat pos, TColCadenas col) {
  return infoCadena(natural, col->colec[pos]);
}

TColCadenas removerDeColCadenas(nat natural, nat pos, TColCadenas col) {
  col->colec[pos]=removerDeCadena(natural, col->colec[pos]);
  return col; 
}
