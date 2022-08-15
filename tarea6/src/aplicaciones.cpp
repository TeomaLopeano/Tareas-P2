/*5369059*/ // sustituiir con los 7 dígitos de la cédula

#include "../include/aplicaciones.h"
#include "math.h"
#include "string.h"
#include "../include/cadena.h"
#include "../include/colCadenas.h"
#include "../include/mapping.h"

static nat max(nat a,nat b){
  if (a<b) return b;
  else return a;
  
}
static nat min(nat a,nat b){
  if (a<b) return a;
  else return b;
  
}

static nat altt(TAbb abb){
  if (abb == NULL)
	    return 0;
	 if (izquierdo(abb) == NULL && derecho(abb) == NULL)
	    return 0;
	 else return max (altt(izquierdo(abb)), altt (derecho(abb))) + 1;
}


bool esAvl(TAbb abb) { 
  if (abb == NULL) 
      return true;
  else if (izquierdo(abb)==NULL && derecho(abb)==NULL) 
      return true;
  else if (izquierdo(abb)!= NULL && derecho(abb)==NULL) 
      return (altt(izquierdo(abb)) == 0);
  else if (izquierdo(abb)== NULL && derecho(abb)!=NULL) 
      return (altt(derecho(abb)) ==0);
  else {
    nat ai =altt(izquierdo(abb));
    nat ad=altt(derecho(abb));
    nat mn= min(ai,ad);
    nat mx=max(ai,ad);
    if ((mx-mn>1))
      return false;
    else {
    return (esAvl(izquierdo(abb)) && esAvl(derecho(abb)));
    }
  }
}

static TAbb cantnod(nat h,nat &cant){
  if (h>1){
    TAbb creo=crearAbb();
    TAbb abbizq=cantnod(h-1,cant);
    TInfo inf=crearInfo(cant,0);
    cant++;
    TAbb abbder=cantnod(h-2,cant);
    creo=consAbb(inf,abbizq,abbder);
    return creo;
  }else if(h==1){
    TInfo inf=crearInfo(cant,0);
    TAbb ins= crearAbb();
    ins=insertarEnAbb(inf,ins);
    cant++;
    return ins;
  }else{
    return NULL;
  }
  
}


TAbb avlMin(nat h) { 
  if (h==0){
    return NULL;
  }else{
    nat j=1;
    return cantnod(h,j);
  }
  
}


TCadena filtradaOrdenada(TCadena cad, TIterador it) {
  nat cant=cantidadEnCadena(cad);
  TCadena cade=crearCadena();
  TMapping map;
  TCadena aux=cad;
  if (it!= NULL && cad!=NULL){
    reiniciarIterador(it);
    map=crearMap(cant);
    map=asociarEnMap(natInfo(primeroEnCadena(cad)),realInfo(primeroEnCadena(cad)),map);
    cad=cadenaSiguiente(cad);
    while (aux!=cad){
      if (!esClaveEnMap(natInfo(primeroEnCadena(cad)),map)){
        map= asociarEnMap(natInfo(primeroEnCadena(cad)),realInfo(primeroEnCadena(cad)),map);
        cad=cadenaSiguiente(cad);
      }else{
        double realmap= valorEnMap(natInfo(primeroEnCadena(cad)),map);
        map=desasociarEnMap(natInfo(primeroEnCadena(cad)),map);
        map=asociarEnMap(natInfo(primeroEnCadena(cad)),realmap+realInfo(primeroEnCadena(cad)),map);
        cad= cadenaSiguiente(cad);
      }
    }
    while (estaDefinidaActual(it)){
      if(esClaveEnMap(actualEnIterador(it),map)) cade= insertarAlFinal(actualEnIterador(it),valorEnMap(actualEnIterador(it),map),cade);
      avanzarIterador(it);
    }
    liberarMap(map);
  }
return cade; 

 }



bool estaOrdenada(TCadena cad) {
bool esta=true;
if (cad!= NULL){
TCadena aux=cad;
 while ((cadenaSiguiente(cad)!=aux)&&esta){
   if ((natInfo(primeroEnCadena(cad)))<(natInfo(primeroEnCadena(cadenaSiguiente(cad)))))
      esta = esta && true;
   else esta = esta && false;
  cad= cadenaSiguiente(cad);
}
}
return esta;  
}

TCadena mezclaCadenas(TCadena cad1, TCadena cad2) {
  TCadena nuevo= crearCadena();
  nat c1=0;
  nat c2=0;
  nat cantcad1=cantidadEnCadena(cad1);
  nat cantcad2=cantidadEnCadena(cad2);
  
  while ((cantcad1>c1)&&(cantcad2>c2)){

     if (natInfo(primeroEnCadena(cad2)) > natInfo(primeroEnCadena(cad1))){
          nuevo = insertarAlFinal(natInfo(primeroEnCadena(cad1)), realInfo(primeroEnCadena(cad1)), nuevo);
          cad1 = cadenaSiguiente(cad1);
          c1++;
        }else if (natInfo(primeroEnCadena(cad2)) < natInfo(primeroEnCadena(cad1))){
          nuevo = insertarAlFinal(natInfo(primeroEnCadena(cad2)), realInfo(primeroEnCadena(cad2)), nuevo);
          cad2 = cadenaSiguiente(cad2);
          c2++;
        }else{
          nuevo = insertarAlFinal(natInfo(primeroEnCadena(cad1)), realInfo(primeroEnCadena(cad1)), nuevo);
          cad1=cadenaSiguiente(cad1);
          cad2=cadenaSiguiente(cad2);
          c1++; c2++;
        }

  }
  while (cantcad2>c2){
    nuevo = insertarAlFinal(natInfo(primeroEnCadena(cad2)), realInfo(primeroEnCadena(cad2)), nuevo);
    cad2=cadenaSiguiente(cad2);
    c2++;
  }
  while (cantcad1>c1){
    nuevo = insertarAlFinal(natInfo(primeroEnCadena(cad1)), realInfo(primeroEnCadena(cad1)), nuevo);
    cad1=cadenaSiguiente(cad1);
    c1++;
  }
return nuevo;
}

TAbb recur (int left,int rigth,TInfo *arre){
  TAbb aBalance = NULL;
  if (rigth < left){
    return aBalance;
  }else{
    nat mid = left + (rigth - left)/2;
    TInfo raiz = copiaInfo(arre[mid]);
    TAbb abbleft = recur (left,mid-1,arre);
    TAbb abbrigth = recur (mid+1,rigth,arre);
    aBalance = consAbb (raiz,abbleft,abbrigth);
    return aBalance;
  }
}

TAbb crearBalanceado(TInfo *arreglo, nat n) {
  TAbb nuevobal =NULL; 
  if (n==0){
    return nuevobal;
  }else{
    nuevobal = recur(0,n-1,arreglo);
    return nuevobal;
  }
  
}

TAbb unionAbbs(TAbb abb1, TAbb abb2) { 
  TCadena cadabb1=linealizacion(abb1);
  TCadena cadabb2=linealizacion(abb2);
  TCadena mezcladecad= mezclaCadenas(cadabb1,cadabb2);
  nat h= cantidadEnCadena(mezcladecad);
  TInfo *arreglo= new TInfo[h];
  for (nat i = 0; i < h; i++){
    arreglo[i]=primeroEnCadena(mezcladecad);
    mezcladecad=cadenaSiguiente(mezcladecad);
  }
  TAbb balanabb;
  balanabb=crearBalanceado(arreglo,h);
  delete[] arreglo;
  liberarCadena(mezcladecad);
  liberarCadena(cadabb1);
  liberarCadena(cadabb2);
  return balanabb;
  

}

TCola ordenadaPorModulo(nat p, TCadena cad) { 

  TCola cola = crearCola();
  TPila pila = crearPila();
  TColCadenas colcad = crearColCadenas(p);
  nat c1 = cantidadEnCadena(cad);
  nat i=1;
  while (i <= c1){
    nat resto = natInfo(primeroEnCadena(cad))%p;
    colcad = insertarEnColCadenas(natInfo(primeroEnCadena(cad)),realInfo(primeroEnCadena(cad)),resto,colcad);
    cad = cadenaSiguiente(cad);
    i++;
  }
  for (nat h = p; h > 0; h--){
    TCadena cad = cadenaDeColCadenas(h-1,colcad);
    nat c2 = cantidadEnCadena(cad);
    i=1;
    while (i <= c2){
      pila = apilar(primeroEnCadena(cad),pila);
      cad = cadenaSiguiente(cad);
      i++;
    }
  }
  liberarColCadenas(colcad);
  i=1;
  while (i <= c1){
    if (cantidadEnPila(pila) > 0){
        cola = encolar(cima(pila),cola);
        pila = desapilar(pila);
      }
    i++;
  }
  liberarPila(pila);
  return cola;
}

TPila menoresQueElResto(TCadena cad, nat cantidad) { 
  TPila nuevo=crearPila();
  if (cantidad==0){
    return nuevo;
  }else if (cantidad>=1){
    nuevo=apilar(primeroEnCadena(cad),nuevo);
    cantidad--;
    cad= cadenaSiguiente(cad);
    while (cantidadEnPila(nuevo)>0 && cantidad>0){
      TInfo menor=primeroEnCadena(cad);

      if (natInfo(menor)>natInfo(cima(nuevo))){
        nuevo=apilar(menor,nuevo);
        cad=cadenaSiguiente(cad);
        cantidad--;

      }else if(natInfo(menor)<=natInfo(cima(nuevo))) nuevo=desapilar(nuevo);


        if (cantidadEnPila(nuevo)==0){
          nuevo=apilar(menor,nuevo);
          cantidad--;
          cad=cadenaSiguiente(cad);
        }
        
      }
    }
  return nuevo;
}

static TCadena auxlineal (TCadena cade, TAbb abb) {
  if (abb == NULL)
  {
    return cade;
    }else{
    cade = auxlineal(cade,derecho(abb));
    cade = insertarAlInicio(natInfo(raiz(abb)),realInfo(raiz(abb)),cade);
    cade = auxlineal(cade,izquierdo(abb));
    return cade;
  }

}

TCadena linealizacion(TAbb abb) { 
  TCadena lin = crearCadena();
  if (abb != NULL)
  lin = auxlineal(lin,abb);
  return lin;
}

static void Imprimo (nat h,TAbb abb){
    if (abb == NULL){
    }else{
      Imprimo(h+1,derecho(abb));
      for (nat i = 1; i <= h; i++)
        printf("-");
      imprimirInfo(raiz(abb));
      printf("\n");
      Imprimo(h+1,izquierdo(abb));
    }
}

void imprimirAbb(TAbb abb) {
    if (abb !=NULL) {
    nat hador = 0;
    Imprimo(hador,abb);
  }
}

static nat altura(TAbb abb){
  if (abb == NULL)
	    return -1;
	 if (izquierdo(abb) == NULL && derecho(abb) == NULL)
	    return 0;
	else return max (altura (izquierdo(abb)), altura (derecho(abb))) + 1;
}

static nat noditos(TAbb abb){
  if (abb != NULL){
    return noditos(izquierdo(abb))+noditos(derecho(abb))+1;
  }else return 0;
  
}

bool esPerfecto(TAbb abb) { 
  bool es=false;
nat h = pow(2,altura(abb)+1);
nat i=noditos(abb);
if ((h-1)==i){
    es=true;
}
return es;
}

TAbb menores(double limite, TAbb abb) { 
     TAbb res;
  if (abb != NULL){
    TAbb left = menores(limite,izquierdo(abb));
    TAbb rigth = menores(limite,derecho(abb));
    TInfo Mraiz = raiz(abb);
    if (realInfo(Mraiz) < limite)
    {
      res = consAbb(copiaInfo(Mraiz),left,rigth);
    }else if (left == NULL)
    {
      res = rigth;
    }else if (rigth == NULL)
    {
      res = left;
    }else {
      TInfo mayor = copiaInfo((mayorEnAbb(left)));
      left = removerDeAbb(natInfo(mayor),left);
      res = consAbb(mayor,left,rigth);
    }
  }else{
    res = NULL;
    
  }
   return res; 
}

static TIterador caminoitAs(nat &k,nat key, TAbb abb,TIterador camino) { 
  if (abb != NULL){
    if (natInfo(raiz(abb)) < key)
    {
      camino = caminoitAs(k,key,derecho(abb),camino);
      if (k > 0)
      {
        agregarAIterador(natInfo(raiz(abb)),camino);
        k=k-1;
      }

    }else if (natInfo(raiz(abb)) > key){
      camino = caminoitAs(k,key,izquierdo(abb),camino);
      if (k > 0)
      {
        agregarAIterador(natInfo(raiz(abb)),camino);
        k=k-1;
      }

    }else {
      camino = crearIterador();
      if (k > 0)
      {
        agregarAIterador(natInfo(raiz(abb)),camino);
        k=k-1;
      }
    }
  }else{
      camino = NULL;
  }
  return camino;
}

TIterador caminoAscendente(nat clave, nat k, TAbb abb) { 
   TIterador camino = NULL;
  camino = caminoitAs(k,clave,abb, camino);
  return camino;
}

static void printpal(nat k,nat largo, TPalabras palabra, ArregloChars pre){
if (letra(palabra)=='\0'){
  pre[largo]='\0';
  printf("%s\n",pre);
}else if (k>0){
  pre[largo]=letra(palabra);
  printpal(k-1,largo+1,subarboles(palabra),pre);
}
if (siguientes(palabra)!=NULL){
  printpal(k,largo,siguientes(palabra),pre);
}

}

void imprimirPalabrasCortas(nat k, TPalabras palabras) {
  palabras =subarboles(palabras);
  nat largo =0;
  ArregloChars pal= new char[k+1];
  printpal(k,largo,palabras,pal);
  delete[] pal;
}

static TPalabras auxx(ArregloChars pre, TPalabras palabras,TPalabras pa,nat cant){
  nat largo = strlen(pre);
 if (pre[cant]==letra(palabras)) {
    if(cant==(largo-1)){
      pa =palabras;
    }else{
      pa =auxx(pre,subarboles(palabras),pa,cant+1);
    }
 }else {
   if (siguientes(palabras)==NULL){
   pa = NULL;
 }else{
   pa = auxx(pre,siguientes(palabras),pa,cant);
  }
 }
 return pa;

}

TPalabras buscarFinPrefijo(ArregloChars prefijo, TPalabras palabras) {
  palabras = subarboles(palabras);
  TPalabras pal=NULL;
  pal= auxx(prefijo,palabras,pal,0);
  return pal;
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
