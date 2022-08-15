/* 5369059 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/mapping.h"
#include "../include/cadena.h"

struct _rep_mapping {
    TCadena *cad;
    nat tam;
    nat cant;
};

nat hash(nat c,nat M){
    return c % M;
}

TMapping crearMap(nat M) {
    TMapping nuevo= new _rep_mapping;
    nuevo->cad= new TCadena[M];
    nuevo->tam=M;
    for (nat i = 0; i < M; i++){
        nuevo->cad[i]=crearCadena();
    }
    nuevo->cant=0;
    return nuevo;
    
}

void liberarMap(TMapping map) {
    for (nat i = 0; i < map->tam; i++){
        liberarCadena(map->cad[i]);
    }
    delete[] map->cad;
    delete map; 
}

TMapping asociarEnMap(nat clave, double valor, TMapping map) { 
    nat mod= hash(clave,map->tam);
    map->cant++;
    map->cad[mod]= insertarAlInicio(clave,valor,map->cad[mod]);
    return map;
}

TMapping desasociarEnMap(nat clave, TMapping map) {
    nat mod = hash(clave,map->tam);
    map->cant--;
    map->cad[mod]= removerDeCadena(clave, map->cad[mod]);
    return map;

}

bool esClaveEnMap(nat clave, TMapping map) { 
    return estaEnCadena(clave,map->cad[hash(clave,map->tam)]);
 }

double valorEnMap(nat clave, TMapping map) { 
    return realInfo(infoCadena(clave,map->cad[hash(clave,map->tam)]));
}

bool estaLlenoMap(TMapping map) { 
    return map->tam==map->cant;
 }


