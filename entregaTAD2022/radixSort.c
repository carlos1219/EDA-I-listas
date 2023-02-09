#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>
#include "listas/lista.h"  
#include <time.h>
#include "radixSort.h"
void
imprimeFichero(Lista *l,FILE *f,int num)
{
    tipoCelda *aImprimir;
    int posicion;
    
    if (l == NULL || l->raiz == NULL) {
     
        return;
    }
    else {
        posicion = 1;
        aImprimir = l->raiz->sig;
        if(num==10){
            fprintf(f,"\nLista concatenada:");
        }else{
             fprintf(f,"\nLista[%d]",num);
        }
       
        while (aImprimir != NULL) {
              
            //printf("Valor: %d en posición: %d\n",aImprimir->elemento, posicion++);
            fprintf(f,"\t %d",aImprimir->elemento);
            aImprimir = aImprimir->sig;
        }
       //printf("%d valores en la lista\n",posicion-1);
    }
}
void radixSort(Lista *l, int numListas, int digito) 
{
    if (l == NULL || l->raiz == NULL) {
        return;
    }
    double tiempoInicial , tiempoFinal, tiempoMinimo=10*CLOCKS_PER_SEC ;
    double tiempo;
    FILE *f;  
    int e;
    long int contadorInterno=0, contadorExterno=0,contadorConcatenar=0;
    int repeticiones=0;
    Lista listas[numListas];
    
    f = fopen("resultadoPruebaRadixSort.txt", "w+");
   
    tiempoInicial = tiempoFinal= (double)clock();
    for (int i = 0; i < numListas; i++) {
        e=creaVacia(&listas[i]);
        if(e==-1) fprintf(f,"No se pudo crear la lista vacia");
         fprintf(f,"creamos la lista vacía %d : %d\n",i,e);
       
    }

    
    
     for (int i = 1; i <= digito; i++) {
        fprintf(f,"\nIteración número %d\n",i);
        fprintf(f,"====================\n");
        tipoPosicion posicion = primero(l);
        while(posicion->sig!=NULL){
            tipoElemento elem = recupera(posicion, l);
            if(elem==-1) fprintf(f,"algo ha fallado en recupera");

            int digitoActual = (elem/ (int) pow(10, i-1) ) % 10;
            
            e=traspasarNodo(posicion, l, fin(&listas[digitoActual]), &listas[digitoActual]);
           if(e==-1) fprintf(f,"Algo ha pasado en traspasar nodo");
            contadorInterno++;
        } 
        e=anula(l);
        if(e==-1) fprintf(f,"lista vacia en anula");
        e=creaVacia(l);
        if(e==-1) fprintf(f,"no se pudo crear vacia la lista");
        
        for (int j = 0; j < numListas; j++)
        {
            imprimeFichero(&listas[j],f,j);
            e=concatenarListas(l, &listas[j]);
            if(e==-2){
                if(e==-1) fprintf(f,"No se pudieron concatenar las listas");
            }
            e=anula(&listas[j]);
            if(e==-1) fprintf(f,"lista vacia en anula");
            e=creaVacia(&listas[j]);
             if(e==-1) fprintf(f,"no se pudo crear vacia la lista");
                 contadorConcatenar++;
        }
     
        tiempoFinal = (double) clock();
		contadorExterno++;
        repeticiones++;
        imprimeFichero(l,f,10);
    }
    fprintf(f,"\ntiempoMedio;Externo;Interno;Concatenar\n");
    tiempo =  (tiempoFinal - tiempoInicial ) / (double)CLOCKS_PER_SEC/repeticiones;
    fprintf(f," %f ;  %ld  ;  %ld  ;  %ld\n",tiempo,contadorExterno,contadorConcatenar,contadorInterno);

    fclose(f);
}

