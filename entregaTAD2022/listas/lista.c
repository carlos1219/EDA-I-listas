#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "lista.h"


int
creaVacia(Lista *l)
{
    if (l == NULL)
        return -2;
    else if (NULL == (l->raiz = l->ultimo = (tipoCelda *)malloc(sizeof(tipoCelda))))
        return -1;
    else {
        l->raiz->sig = NULL;
        return 0;
    }
}


int
vacia(Lista *l)
{
    if (l == NULL || l->raiz == NULL) {
        return -1;
    }
    else if (l->raiz->sig == NULL)
        return 1;
    else
        return 0;
}


int
destruye(Lista *l)
{
    if (l == NULL || l->raiz == NULL) {
        return -1;
    }
    else if (l->raiz->sig != NULL){
        return -2;
    }
    else {
        free(l->raiz);
        l->raiz = l->ultimo = NULL;
        return 0;
    }
}


void
imprime(Lista *l)
{
    tipoCelda *aImprimir;
    int posicion;
    
    if (l == NULL || l->raiz == NULL) {
     
        return;
    }
    else {
        posicion = 1;
        aImprimir = l->raiz->sig;
        while (aImprimir != NULL) {
              
            //printf("Valor: %d en posición: %d\n",aImprimir->elemento, posicion++);
            printf(" %d ",aImprimir->elemento);
            aImprimir = aImprimir->sig;
        }
       //printf("%d valores en la lista\n",posicion-1);
    }
}


tipoPosicion
anterior(tipoPosicion p, Lista *l)
{
    tipoCelda *anterior;
    
    if (l == NULL || l->raiz == NULL || p == NULL) {
        return NULL;
    }
    else if (p == l->raiz){
        return l->raiz;
    }
    else {
        anterior = l->raiz;
        while (anterior->sig != p)
            anterior = anterior->sig;
        return anterior;
    }
}


tipoPosicion
primero(Lista *l)
{
 if (l == NULL) {
        return NULL;
    }
    else if (l->raiz == NULL){
        return fin(l);
    } else
        return l->raiz;
    
}


tipoPosicion
fin(Lista *l)
{
    if (l == NULL) {
        return NULL;
    }
    else if (l->ultimo == NULL){
        return NULL;
    }
    else
        return l->ultimo;
}


int
inserta(tipoElemento x, tipoPosicion p, Lista *l)
{
    tipoCelda *nuevo;
    
    if (l == NULL) {
        return -1;
    }
    else if (l->raiz == NULL) {
        return -2;
    }
    else if (p == NULL){
        return -3;
    }
    else if (NULL == (nuevo = (tipoCelda*)malloc(sizeof(tipoCelda)))) {
        fprintf(stderr,"Fallo reserva memoria!\n");
        return -4;
    }
    else {
        nuevo->elemento = x;
        nuevo->sig = p->sig;
        p->sig = nuevo;
        if (p == l->ultimo)
            l->ultimo = nuevo;
        return 0;
    }
}


int
suprime (tipoPosicion p, Lista *l)
{
    tipoPosicion aBorrar;
    if (vacia(l) != 0 || p == NULL) return -1;
    else {
        aBorrar = p->sig;
        if(aBorrar == NULL) return -2;
        p->sig = aBorrar->sig;
        free(aBorrar);
        l->ultimo = fin(l);
        return 0;
    }
}


tipoPosicion
siguiente(tipoPosicion p,Lista *l)
{
    tipoPosicion posicion;
    if (vacia(l) != 0 || p == NULL) return NULL;
    else {
        if(p == fin(l)) return p;
        return p->sig;
    }
}


tipoPosicion
localiza (tipoElemento x, Lista *l)
{
	tipoPosicion q;
	if (vacia(l) != 0) return NULL;
	q = l->raiz;
    while (q->sig != NULL)
        {
            if (q->sig->elemento == x) return q;
            q = q->sig;
        } return q; 
    }


tipoElemento
recupera(tipoPosicion p, Lista *l)
{
    if (l == NULL || l->raiz == NULL || p == NULL) return -1;
    else {
        if(p == fin(l)) return -2;
        return p->sig->elemento;
    }
}


int
anula(Lista *l)
{
    if(l==NULL){
        return -1;
    }
    tipoPosicion aBorrar,q;
    q=l->raiz->sig;
    l->raiz->sig=NULL;
    while(q!=NULL){     
        aBorrar=q;
        q=q->sig;
        free(aBorrar);
    }
}


int concatenarListas(Lista *lA, Lista *lB)
{
    tipoPosicion posicion;
    if (lA == NULL || vacia(lB) != 0) return -1;
    posicion = lB->raiz->sig;
    
    while(posicion != NULL) {
        inserta(posicion->elemento,fin(lA),lA);
        posicion = posicion->sig;
    }  

    if(anula(lB) == 0) return 0;
    else return -2;
}


int traspasarNodo(tipoPosicion p, Lista *origen,  tipoPosicion posicion,Lista *destino) {
  if (p == NULL || vacia(origen)) {
    return -1;
  }
  
  tipoElemento elemento = recupera(p, origen);
  suprime(p, origen);
  inserta(elemento, posicion, destino);
  return 0;
}
    