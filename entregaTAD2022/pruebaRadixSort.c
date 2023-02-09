#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listas/lista.h"
#include "pilas/pila.h"
#include "colas/cola.h"
#include "radixSort.h"
#include <ctype.h>

#define DIM 82

int   palindromo (const char *);
void  convertir_mayusculas (char *);
int prueba (void);

int main(int argc, char *argv[])
{   Lista miLista;
    tipoPosicion p;
    int e;
    int numElementos = 20, codigoError,i;

	if (argc > 2) {
            printf("\n Uso: ./pruebaRadixSort <número de elementos de la lista>\n\n");
            return -1;
        }
       if (argc==2)
		numElementos=atoi(argv[1]);
        e=creaVacia(&miLista);
        if(e==-1) printf("no se pudo crear vacia la lista");
    printf("Creando lista vacía: %d\n",e );
    
    printf("Se crea una lista de %d elementos\n", numElementos);
    
    e=anula(&miLista);
     if(e==-1){
    printf("no se pudo anular la lista");
     } 
    
  
    p = primero(&miLista);
    if(p==NULL) printf("Fallo en primero");
    
    for (i = 0; i < numElementos; i++) {
    	codigoError = inserta(rand()%100000,p,&miLista);
        if(codigoError==-1||codigoError==-2||codigoError==-3||codigoError==-4)
        printf("Fallo en inserta");
    	p = siguiente(p,&miLista);
        if(p==NULL) printf("Fallo en primero");

    }
    imprime(&miLista);
    printf("\n");
    radixSort(&miLista,10,5);
    printf("\nLista Ordenada \n");
    imprime(&miLista);
    e=anula(&miLista);
    if(e==-1){
        printf("no se pudo anular la lista");
    } 

    e=destruye(&miLista);
    if(e==-1||e==-2||e==-3)
    printf("fallo en destruye");
    




    printf("\nprobamos las pilas\n");
    prueba();
    return 0;
}
int prueba (void) 
{
	char cadena[DIM];
	int  espalindromo;

	printf("Introduzca una cadena (max. %d caracteres): ", DIM-2);
	fgets(cadena, DIM - 2, stdin);
	
	//Eliminamos el carácter retorno de carro leído por fgets
	int l = strlen(cadena);
	cadena[l - 1] = '\0';

	convertir_mayusculas (cadena);
	espalindromo = palindromo (cadena);
    
	printf("La cadena %s \n", cadena);
	if (espalindromo)
		printf("es un palindromo.\n");
	else   
		printf("NO es un palindromo.\n");
     
	return 0;

} 


void convertir_mayusculas (char *cad) 
{
	int j = 0;

	while (cad[j] != '\0') {
		cad[j] = toupper(cad[j]);
		j++;
	}
}


int palindromo (const char *expresion) 
{
	Pila p;
	Cola c;
	int i;
	int j=0;
	char cadenacomp[DIM];
	int longitud;
	longitud=strlen(expresion);
	for(i=0;i<longitud;i++){
		if(expresion[i]!=' '){
			cadenacomp[j]=expresion[i];
			j++;
		}
	}

	if(colaCreaVacia(&c)==0 && pilaCreaVacia(&p)==0){
		for(i=0;i<j;i++){
			colaInsertaC(&c,cadenacomp[i]);
			pilaInserta(&p,cadenacomp[i]);
	}}
	for(i=0;i<j;i++){
		if(colaSuprime(&c)!=pilaSuprime(&p)){
			return 0;
		}}
		
		
	
	return 1;
}



