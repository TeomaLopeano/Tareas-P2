/* 5369059 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/cadena.h"

// los elementos se mantienen entre 0 y cantidad - 1, incluidos
struct _rep_cadena {
  nat t;
  TInfo inf[L];
};

TCadena crearCadena() {
  TCadena cade = new _rep_cadena;
  cade ->t =0;
  return cade;
}

/* en siguientes tareas
void liberarCadena(TCadena cad) {
}
*/

nat cantidadEnCadena(TCadena cad) {
  nat cant;
  cant = cad->t;
  return cant;
 
}

bool estaEnCadena(nat natural, TCadena cad) {
  bool est = false;
  nat h = 0;
  while ((!est) && (h<cad->t))
  {
    if (natInfo(cad->inf[h])== natural)
    {
      est = true;
    }
    h+=1;
  }
  return est;
}

TCadena insertarAlInicio(nat natural, double real, TCadena cad) {
  cad->t += 1;
  if (cad->t > 0)
  {
    for (nat i = cad->t; i >0 ; i--)
    {
      cad->inf[i]=cad->inf[i-1];
    }
   
  }
   cad->inf[0]= crearInfo(natural, real);
  return cad;
}

TInfo infoCadena(nat natural, TCadena cad) {
  nat h = 0;
    bool est = false;
    while ((!est) && (h<cad->t)){
      if (natInfo(cad->inf[h])== natural){
      est = true;
    }
    h+=1;
  }

return cad->inf[h-1];
}

TCadena removerDeCadena(nat natural, TCadena cad) {
  nat h = 0;

    while (infoCadena(natural,cad)!=cad->inf[h]){
      h +=1;
    }
  
  for (nat i = h; i < cad->t ; i++){
      cad->inf[i]=cad->inf[i+1];
    }
  liberarInfo(cad->inf[cad->t]);
  cad->t-=1;
  return cad;
}

void imprimirCadena(TCadena cad) {
  if ( cantidadEnCadena(cad) == 0 )
  {
    printf("\n");
  }
  else {
    for (nat h = 0; h < cad->t; h++){
     imprimirInfo(cad->inf[h]);
    
  }
    printf("\n");
}
  
}
