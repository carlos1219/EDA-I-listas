# Proyecto para entrega Tipos Abstractos de Datos 2022
#
# ( Añadir las reglas necesarias para la correcta compilación de todas las implementaciones que se piden)


pruebaRadixSort: pruebaRadixSort.c listas/lista.h listas/lista.o radixSort.o colas/cola.o pilas/pila.o
	gcc -g pruebaRadixSort.c radixSort.o listas/lista.o colas/cola.o pilas/pila.o -o pruebaRadixSort -lm

radixSort.o: radixSort.c radixSort.h listas/lista.h
	gcc -g -c radixSort.c

listas/lista.o: listas/lista.c listas/lista.h
	gcc -g -c listas/lista.c -o listas/lista.o

colas/cola.o: colas/cola.c colas/cola.h
	gcc -g -c colas/cola.c  -o colas/cola.o


pilas/pila.o: pilas/pila.c pilas/pila.h
	gcc -g -c pilas/pila.c  -o pilas/pila.o



limpiar:
	rm *.o listas/lista.o pilas/pila.o	colas/cola.o
	
