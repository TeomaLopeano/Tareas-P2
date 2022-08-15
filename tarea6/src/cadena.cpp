/* 5369059 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/cadena.h"

struct _rep_cadena {
  _rep_cadena *ant;
  _rep_cadena *post;
  TInfo elm;
};

TCadena crearCadena() {
  TCadena cade;
  cade=NULL;
  return cade;
}

void liberarCadena(TCadena cad) {
  if (cad != NULL){
    TCadena aux,aux2;
    aux= cad->post;
    while (aux != cad){
      aux2=aux;
      aux=aux->post;
      liberarInfo(aux2->elm);
      delete aux2;
  }
  liberarInfo(aux->elm);
  delete aux;
  }
}

nat cantidadEnCadena(TCadena cad) {
  nat h;
  if (cad == NULL){
    h = 0;
  }else {
    TCadena aux;
    h=1;
    aux =cad;
    while (aux->post != cad){
      aux = aux->post;
      h +=1;
    }
  }
  return h;

}

bool estaEnCadena(nat natural, TCadena cad) {
  bool est;
  est = false;
  if (cad!=NULL){
    if (natInfo(cad->elm)== natural)
    {
      est = true;
    }
    TCadena aux;
    aux = cad->post;
    while ((!est) && (aux !=cad)){
      if (natInfo(aux->elm)== natural){
        est = true;
      }
      aux= aux->post;
    }
  }
  
  return est;
}

TCadena insertarAlInicio(nat natural, double real, TCadena cad) {
    TCadena ins;
    ins = new _rep_cadena;
    ins->elm= crearInfo(natural, real);
  if (cad == NULL){
    ins->ant = ins;
    ins->post = ins;
    cad= ins;
  }else{
    ins->ant = cad->ant;
    ins->post = cad;
    ins->ant->post=ins;
    cad->ant = ins;
  }
  return ins;
}

TInfo infoCadena(nat natural, TCadena cad) {
  while (natInfo(cad->elm)!=natural) {
    cad= cad->post;
  }
  return cad->elm;
}

TInfo primeroEnCadena(TCadena cad) {
  return cad->elm;
}

TCadena cadenaSiguiente(TCadena cad) {
  if (cad != NULL)
  {
    cad = cad->post;
    return cad;
  }else{
    return cad;
  }
  
}

TCadena removerDeCadena(nat natural, TCadena cad) {
  
  if ((cantidadEnCadena(cad)==1)&&(natInfo(cad->elm)==natural)){
      liberarInfo(cad->elm);
      delete cad;
      cad = NULL;
      return cad;
  }else {
    TCadena aux=cad;
    while (natInfo(cad->elm)!= natural){
      cad=cad->post;
  }
  TCadena aux2=cad;
  cad->ant->post=cad->post; //Acomodo punteros
  cad->post->ant=cad->ant;

  if (cad != aux ) {
    cad = aux;
    liberarInfo(aux2->elm);
    delete aux2;
  }else{
    cad=cad->post;
    liberarInfo(aux2->elm);
    delete aux2;
  }
  return cad;
  }
  
}

void imprimirCadena(TCadena cad) {
  if (cad != NULL){
    TCadena aux=cad;
    while (aux->post != cad)
    {
      imprimirInfo(aux->elm);
      aux = aux->post;
    }
    imprimirInfo(aux->elm);
  }
  printf ("\n");
}

TCadena insertarAlFinal(nat natural, double real, TCadena cad) {
 TCadena aux = cadenaSiguiente(insertarAlInicio(natural, real, cad));
 cad = aux;
 return cad;
}

TCadena removerPrimero(TCadena cad) {
   if (cad->post != cad)
  {
    TCadena aux = cad;
    cad=cad->post;
    aux->ant->post = cad;
    cad->ant = aux->ant;
    liberarInfo(aux->elm);
    delete aux;
    
  }else{
    liberarInfo(cad->elm);
    delete cad;
    cad = NULL;
  }
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
