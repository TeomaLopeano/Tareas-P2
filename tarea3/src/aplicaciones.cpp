/* 5369059 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/aplicaciones.h"
#include "math.h"
#include "string.h"

static nat altura(TAbb abb){
  nat h=0;
    if(abb==NULL){
        return -1;
    }else{
      while (derecho(abb)!=NULL)
      {
        h++;
        abb=derecho(abb);
      }
      return h;
    }
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

void imprimirPalabrasCortas(nat k,TPalabras palabras) {
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
