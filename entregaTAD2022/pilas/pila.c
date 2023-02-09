#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "pila.h"



int pilaCreaVacia(Pila *p)
{
    if(p==NULL){
    	return -1;
	}
	*p=NULL;
	return 0;
}

int pilaVacia(Pila *p)
{
    if(p==NULL){
    	return -1;
	}
	return (*p==NULL);
    
}

int pilaInserta(Pila *p,tipoElemento elemento)
{
    tipoCelda *n;
    
    if(p==NULL){
        return -1;	
	}
	n=(tipoCelda *)malloc(sizeof(tipoCelda));
	if(n==NULL) {
		return -2;
	}
	else{
		n->elemento=elemento;
		if(pilaVacia(p)){
		*p=n;
		n->sig=NULL;
		return 0;
		}
		else{
			n->sig=*p;
			*p=n;
			return 0;
		}
	} 
}

tipoElemento pilaSuprime(Pila *p)
{
    tipoCelda *aBorrar;
    tipoElemento elemento;
    
    if(p==NULL || pilaVacia(p)){
    	return -1;
	}
	else{
		aBorrar=*p;
		elemento=(*p)->elemento;
		*p=(*p)->sig;
		free(aBorrar);
		return elemento;
	}	
}
