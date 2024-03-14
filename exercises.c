#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Ejercicio 1: Encuentra el Elemento Mayor
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y devuelva el valor más grande del arreglo.
*/
int findMax(int arr[], int size){ 
  
  if(size == 0){
      return -1;
  }

  int numeroMayor = arr[0]; 

  for(int i = 1; i < size; i++){
      if (arr[i] > numeroMayor){
          numeroMayor = arr[i];
      }
  }

  return numeroMayor;
  
  return 0; }

/*
Ejercicio 2: Invertir un Arreglo
Descripción: Escribe una función que tome un arreglo y su tamaño, y luego
invierta el orden de sus elementos.
*/
void reverseArray(int arr[], int size){
  int aux[size];
  for(int i = 0; i < size; i++){
      aux[size - 1 - i] = arr[i];
  }
  for(int j = 0; j < size; j++){
      arr[j] = aux[j];
  }
}

/*
Ejercicio 3: Filtrar Números Pares
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y luego devuelva un nuevo arreglo que contenga solo
los números pares del arreglo original.
*/
int *filterEvenNumbers(int arr[], int size, int *newSize) { 
  int cont = 0;
  for (int i = 0; i < size; i++){
      if (arr[i] % 2 == 0){
          cont++;
      }
  }

  int *arregloNuevo = (int *)malloc(cont * sizeof(int));

  if(arregloNuevo == NULL){
      exit(0);
  }

  int m = 0;

  for(int i = 0; i < size; i++){
      if (arr[i] % 2 == 0) {
          arregloNuevo[m] = arr[i];
          m++;
      }
  }

  *newSize = cont;

  return arregloNuevo;
  
  
  
  return NULL; }

/*
Ejercicio 4: Fusión de dos Arreglos Ordenados
Descripción: Escribe una función que tome dos arreglos
ordenados y sus tamaños, y luego fusione estos dos
arreglos en un tercer arreglo también ordenado.
*/
void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2,
                       int result[]) {
  int i = 0, j = 0, k = 0;

  // Fusionar los dos arreglos ordenados
  while (i < size1 && j < size2) {
      if (arr1[i] <= arr2[j]) {
          result[k++] = arr1[i++];
      } else {
          result[k++] = arr2[j++];
      }
  }

  while (i < size1) {
      result[k++] = arr1[i++];
  }

  while (j < size2) {
      result[k++] = arr2[j++];
  }
                       }

/*
Ejercicio 5: Comprobación de Ordenación
Descripción: Escribe una función que tome un arreglo y su tamaño,
y luego devuelva 1 si el arreglo está ordenado en orden ascendente,
  0 si no está ordenado, y -1 si está ordenado en orden descendente.
*/
int checkSorted(int arr[], int size) { 
  
  int ascendente = 1; 
  int descendente = 1;


  for(int i = 1; i < size; i++){
      if(arr[i - 1] > arr[i]){
          ascendente = 0;
          break;
      }
  }

  for(int i = 1; i < size; i++){
      if(arr[i - 1] < arr[i]){
          descendente = 0;
          break;
      }
  }

  int num;
  
  if(ascendente == 1){
      num = 1;
      return num;
  }else if (descendente == 1){
      num = -1;
      return num;
  }else{
      num = 0;
      return num;
  }
  
  
  
  return -2; }

/*
Ejercicio 6: Información de una Biblioteca
Descripción: Vamos a representar la información de una biblioteca. En la
biblioteca, hay libros, y cada libro tiene un autor. Queremos organizar esta
información utilizando estructuras anidadas en C. Escribe la función para
inicializar la información de un libro.
*/

typedef struct {
  char nombre[50];
  int anioNacimiento;
} Autor;

typedef struct {
  char titulo[100];
  Autor autor;
  int anioPublicacion;
} Libro;

void inicializarLibro(Libro *libro, const char *titulo, const char *nombreAutor,
                      int anioNacimiento, int anioPublicacion) {

  strcpy(libro->titulo, titulo);
  strcpy(libro->autor.nombre, nombreAutor);

  libro->autor.anioNacimiento = anioNacimiento;
  libro->anioPublicacion = anioPublicacion;
                      }

/*
Ejercicio 7: Lista enlazada de números
Descripción: Escribe una función que tome un arreglo de enteros y su tamaño, y
luego cree una lista enlazada usando la estructura Nodo. Cada nodo de la lista
debe contener un número del arreglo, y los nodos deben estar enlazados en el
mismo orden que los números aparecen en el arreglo. El último nodo de la lista
debe apuntar a NULL. La función debe devolver un puntero al primer nodo de la
lista enlazada.
Recuerda reservar memoria dinámica para cada nodo usando malloc.
  */

typedef struct nodo {
  int numero;
  struct nodo *siguiente; // puntero al siguiente nodo
} Nodo;

Nodo *crearNodo(int numero) {
    Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
    if (nuevoNodo == NULL) {
        printf("Error: no se pudo asignar memoria para el nodo.\n");
        exit(1);
    }
    nuevoNodo->numero = numero;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

Nodo *crearListaEnlazada(int arr[], int size) { 

  if (size == 0) {
    return NULL; 
  }

  Nodo *primero = crearNodo(arr[0]); 
  Nodo *actual = primero;

  for (int i = 1; i < size; i++) {
    actual->siguiente = crearNodo(arr[i]); 
    actual = actual->siguiente; 
  }

  return primero; 
  
  
  return NULL; }
