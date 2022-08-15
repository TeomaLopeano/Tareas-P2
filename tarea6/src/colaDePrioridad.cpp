/* 5369059 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/colaDePrioridad.h"
#include "../include/info.h"

struct cola
{
  nat dato;
  double priori;
};

struct _rep_colaDePrioridad
{
  cola *array;
  nat tope;
  char prio;
  nat capacidad;
  nat *pos;
};

void filtradoAscendente(TColaDePrioridad cp,nat tope)
{
  cola *array= cp->array;
  nat posi= tope/2;
  if (tope>1){
  cola swap = array[tope];
    if (cp->prio=='N'){
      if ((array[posi].priori > swap.priori)){
        array[tope] = array[posi];
        cp->pos[array[posi].dato]=tope;
        array[posi] = swap;
        cp->pos[array[posi].dato]=posi;
        tope = tope / 2;
        filtradoAscendente(cp,tope);
    }
    }else{
    if ((array[tope / 2].priori < swap.priori)){
        array[tope] = array[posi];
        cp->pos[array[posi].dato]=tope;
        array[posi] = swap;
        cp->pos[array[posi].dato]=posi;
        tope = tope / 2;
        filtradoAscendente(cp, tope);
    }
   }
  }
}

void filtradoDescendente(TColaDePrioridad cp, nat a, nat tope)
{
  cola *array= cp->array;
  if (tope >= a*2){
  nat hijo = a * 2;
    if (cp->prio=='N'){
      if ((hijo+1 <= tope) && (array[hijo+1].priori < array[hijo].priori)) hijo = hijo + 1;

    if (array[hijo].priori < array[a].priori){
      cola swap = array[a];
      array[a] = array[hijo];
      cp->pos[array[a].dato]=a;
      array[hijo]=swap;
      cp->pos[array[hijo].dato]=hijo;
      a = hijo;
      filtradoDescendente(cp,a,tope);
    }
    }
    else{
      if ((hijo+1 <= tope) && (array[hijo+1].priori > array[hijo].priori)) hijo = hijo + 1;

    if (array[hijo].priori > array[a].priori){
      cola swap = array[a];
      array[a] = array[hijo];
      cp->pos[array[a].dato]=a;
      array[hijo]=swap;
      cp->pos[array[hijo].dato]=hijo;
      a = hijo;
      filtradoDescendente(cp,a,tope);
    }

    }
  }
}

static void actualizarpriori(TColaDePrioridad cp,double dato, nat elem){
  nat posi = cp->pos[elem];
  double prioant = cp->array[posi].priori;
  cp->array[posi].priori = dato;
  if (dato > prioant) filtradoDescendente(cp,posi,cp->tope);
  else filtradoAscendente(cp,posi);
}

TColaDePrioridad crearCP(nat N)
{
  TColaDePrioridad cp = new _rep_colaDePrioridad;
  cp->array = new cola[N + 1];
  cp->pos = new nat[N + 1];
  for (nat i = 0; i <= N; i++){
    cp->pos[i] = 0;
  }
  cp->prio='N';
  cp->tope = 0;
  cp->capacidad = N;

  return cp;
}

TColaDePrioridad invertirPrioridad(TColaDePrioridad cp) { 
  if (cp->prio=='N'){
    cp->prio = 'I';
  }else{
    cp->prio = 'N';
  }
  nat tope = cp->tope;
  for (nat h = tope; h >= 1; h--){
    filtradoAscendente(cp,h);
  }
  return cp;
}

void liberarCP(TColaDePrioridad cp){
    delete[] cp->array;
    delete[] cp->pos;
    delete cp;
}

TColaDePrioridad insertarEnCP(nat elem, double valor, TColaDePrioridad cp)
{
if (cp!=NULL){
  if ((elem > 0) && (elem <= cp->capacidad)){
    if (estaEnCP(elem,cp)){
      actualizarpriori(cp,valor,elem);
    }else{
      cp->tope++;
      cola aux;
      aux.dato = elem;
      aux.priori = valor;
      cp->array[cp->tope] = aux;
      cp->pos[elem] = cp->tope;
      filtradoAscendente(cp,cp->tope);
    }
  } 
}
  return cp;
}

bool estaVaciaCP(TColaDePrioridad cp){
  return cp->tope==0;
}

nat prioritario(TColaDePrioridad cp){
  return cp->array[1].dato;
}

TColaDePrioridad eliminarPrioritario(TColaDePrioridad cp)
{
  if (estaVaciaCP(cp)) return cp;
  else{
     nat x=cp->array[1].dato;
    cp->array[1] = cp->array[cp->tope];
    cp->pos[x]=1;
    cp->tope--;
    cp->pos[x]=0;
    if (cp->tope > 1){
      filtradoDescendente(cp, 1, cp->tope);
    }
    return cp;
  }
}

bool estaEnCP(nat elem, TColaDePrioridad cp)
{
  if ((elem > 0) && (elem <= cp->capacidad)){
    return cp->pos[elem]!=0;
  }else
    return false;
}

double prioridad(nat elem, TColaDePrioridad cp){
   return cp->array[cp->pos[elem]].priori;
}
