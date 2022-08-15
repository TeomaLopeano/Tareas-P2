/* 5369059 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/abb.h"

struct _rep_abb {
    TInfo datos;
    TAbb left,rigth;
};

void Rotarizq(TAbb &abb){
    TAbb ne= abb->rigth;
    TAbb en= ne->left;
    ne->left=abb;
    abb->rigth= en;
    abb=ne;
}

void Rotarder(TAbb &abb){
    TAbb ne= abb->left;
    TAbb en= ne->rigth;
    ne->rigth=abb;
    abb->left= en;
    abb=ne;
}

TAbb rotar(nat clave, char tipo[2], TAbb abb) {
   if (abb!=NULL){
        nat inf= natInfo(abb->datos);
        if (inf==clave){
            if (tipo[0]=='R'&& tipo[1]=='R'){
                if (abb->rigth!=NULL){
                    Rotarizq(abb);
                }
            }else if (tipo[0]=='R'&& tipo[1]=='L'){
                if (abb->rigth!=NULL && abb->rigth->left!=NULL){
                   Rotarder(abb->rigth);
                   Rotarizq(abb);
                }  
            }else if (tipo[0]=='L'&& tipo[1]=='L'){
                if (abb->left!=NULL){
                    Rotarder(abb);
                }
            }else if (tipo[0]=='L'&& tipo[1]=='R'){
                if (abb->left!=NULL && abb->left->rigth!=NULL){
                   Rotarizq(abb->left);
                   Rotarder(abb);
                }  
            }
        }else{
                if (inf<clave){
                  abb->rigth=rotar(clave,tipo,abb->rigth);
                }else{
                    abb->left=rotar(clave,tipo,abb->left);
                }
            }
    }
    return abb;
    
}

TAbb crearAbb() { 
    TAbb arb;
    arb=NULL;
    return arb;
 }

void liberarAbb(TAbb abb) {
      if (abb != NULL)
    {
       liberarInfo(abb->datos);
       liberarAbb(abb->rigth);
       liberarAbb(abb->left);
       delete abb;
       abb=NULL;
    }
}

bool esVacioAbb(TAbb abb) { 
    return abb==NULL;
 }

TAbb buscarSubarbol(nat clave, TAbb abb) { 
     while ((abb != NULL) && (natInfo(abb->datos) != clave))
    {
        if (natInfo(abb->datos) > clave){
            abb = abb->left;
        }else{
           abb = abb->rigth; 
        } 
    }
    return abb;
 }

TInfo raiz(TAbb abb) { 
    return abb->datos;
}

TAbb izquierdo(TAbb abb) { 
    return abb->left;
}

TAbb derecho(TAbb abb) { 
    return abb->rigth;
 }

TInfo menorEnAbb(TAbb abb) { 
      if (abb->left == NULL){
        return abb->datos;
    }else{
        abb= abb->left;
        while (abb->left != NULL){
            abb = abb->left;
        }
        return abb->datos;
    }
    
 }

TInfo mayorEnAbb(TAbb abb) { 
     if (abb->rigth == NULL){
        return abb->datos;
    }else{
        abb= abb->rigth;
        while (abb->rigth != NULL){
            abb = abb->rigth;
        }
        return abb->datos;
    }
 }

TAbb consAbb(TInfo dato, TAbb izq, TAbb der) { 
    TAbb arbnew = new _rep_abb;
    arbnew->datos=dato;
    arbnew->left=izq;
    arbnew->rigth=der;
    return arbnew;
 }

TAbb insertarEnAbb(TInfo dato, TAbb abb) { 
    if (abb == NULL){
        abb = new _rep_abb ;
        abb->datos = dato;
        abb->left = NULL;
        abb->rigth = NULL;
    }else if (natInfo(dato) < natInfo(abb->datos)){

            abb->left= insertarEnAbb (dato, abb->left);

       }else if (natInfo(dato)> natInfo(abb->datos)){
           abb->rigth= insertarEnAbb (dato, abb->rigth);
       }
    
    return abb;
 }

static void removerMaxABB(TAbb &a){
     if (a->rigth==NULL)
     {
         TAbb del = a;
         a=a->left;
         delete del;
     }else{
         removerMaxABB(a->rigth);
     }
     
 }
 
static void removerABB ( nat x , TAbb & abb ) {
TAbb aux ;
if ( abb != NULL ) {
    if (natInfo(abb -> datos)  == x ) {
        if ((abb ->left == NULL) || (abb ->rigth == NULL )) {
            aux=abb;
            if (abb->left!=NULL){
                abb=abb->left;
            }else{
                abb=abb->rigth;
            }
            liberarInfo(aux->datos);
            delete aux;
            
        }else {
        liberarInfo(abb->datos);
        abb->datos=mayorEnAbb(abb->left);
        removerMaxABB(abb->left);
        }
    }else if ( x < natInfo(abb -> datos) )
        removerABB (x , abb -> left ) ;
    else
        removerABB (x , abb -> rigth) ;
}
}

TAbb removerDeAbb(nat clave, TAbb abb)
{
removerABB(clave,abb);
return abb;
}

TAbb copiaAbb(TAbb abb) { 
     if (abb == NULL){
        return NULL;
    }else {
        TAbb copia=NULL;
        TInfo dt=copiaInfo(abb->datos);
        copia=insertarEnAbb(dt,copia);
        copia->left= copiaAbb(abb->left);
        copia->rigth=copiaAbb(abb->rigth);
        return copia;
    }
 }