/* 5369059 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/iterador.h"
struct nodo{
  nat elm;
  nodo *sig;
};
typedef nodo *ptrnodo;

struct _rep_iterador {
nodo *actual;
nodo *prim;
nodo *ult;
};

TIterador crearIterador() {
  TIterador ite= new _rep_iterador;
  ite->actual=NULL;
  ite->prim=NULL;
  ite->ult=NULL;
  return ite;
}

void liberarIterador(TIterador iter) {
     iter->actual = iter->prim;
        while (iter->actual != NULL){
            iter->actual=iter->prim->sig;
            delete iter->prim;
            iter->prim=iter->actual;
        }
        delete iter;
        iter =NULL;
}


bool estaDefinidaActual(TIterador iter) {
  bool est =false;
  if (iter->actual != NULL)
  {
    est =true;
  }
  return est;
}

void agregarAIterador(nat elem, TIterador const iter) {
	ptrnodo nodito = new nodo;		
	nodito->elm=elem;
  nodito->sig=NULL;
	if(iter->prim != NULL){
		iter->ult->sig=nodito;
    iter->ult=nodito;
	}else{	
		iter->prim = nodito;
    iter->ult=nodito;
	}

}

void reiniciarIterador(TIterador const iter) { 
 if (iter->prim != NULL){
    iter->actual= iter->prim;
  }
}

void avanzarIterador(TIterador const iter) {
  if (estaDefinidaActual(iter)){
    iter->actual=iter->actual->sig;
  }else if (iter->actual==iter->ult){
    delete iter->actual;
    iter->actual = NULL;
    
  }
}

nat actualEnIterador(TIterador iter) {
  nat h;
  h = iter->actual->elm;
  return h;
}