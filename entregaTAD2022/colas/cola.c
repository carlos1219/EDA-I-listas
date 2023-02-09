#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "cola.h"




int colaCreaVacia(Cola *c)
{
   if(c==NULL){
   	return -1;
   } else{
   	c->fondo=NULL;
   	c->frente=NULL;
   	return 0;
   }
}

int colaVacia(Cola *c)
{
    if(c==NULL){
    	return -1;
	}else{
		return (c->fondo==NULL);
	}
}

int colaInsertaC(Cola *c,tipoElemento elemento)
{
    tipoCelda *n;
    if(c==NULL){
    }else{
    	n=(tipoCelda *)malloc(sizeof(tipoCelda));
    	if(n==NULL){
    		return -2;
		}else{
			n->sig=NULL;
			n->elemento=elemento;
			if(c->fondo==NULL){
				c->frente=n;
				c->fondo=n;
			}else{
			c->fondo->sig=n;
			c->fondo=n;
			}
			return 0;
		}
	}
}

tipoElemento colaSuprime(Cola *c)
{
    tipoCelda *aBorrar;
    tipoElemento elemento;
    if(colaVacia(c)){
    	return -1;
	}else{
		aBorrar=c->frente;
		elemento=c->frente->elemento;
		if(c->frente->sig!=NULL){
			c->frente=c->frente->sig;
		}else{
			c->frente=NULL;
			c->fondo=NULL;
		}
		free(aBorrar);
		return elemento;
	}
}
