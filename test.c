#include "exercises.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char msg[300];
int test_id = -1;


int test_suite(int (*test)(), char *msg, int max_score, int id, int req_id) {
  if (test_id == -1 || test_id == id) {
    printf("\n%s\n", msg);
    int score = test();

    if (id == req_id && score == max_score){
        printf("SUCCESS\n");
        exit(0);
    }

    printf("   partial_score: %d/%d\n", score, max_score);

    return score;
  }
  return 0;
}


void print_array(int arr[], int size) {
  printf("[");
  for (int i = 0; i < size; i++) {
    printf("%d, ", arr[i]);
  }
  printf("]\n");
}

void print_linked_list(Nodo* lista) {
  printf("   linked list: ");
  while (lista) {
    printf("%d -> ", lista->numero);
    lista = lista->siguiente;
  }
  printf("NULL\n");
}


void readIntArray(int arr[], int *size) {
  for (int i = 0; i < *size; i++) {
    int k = 0;
    if (scanf("%d", &k) != -1) {
      if (k == -1) {
        *size = i;
        return;
      }
      arr[i] = k;
    }
  }
}

void create_random_array(int arr[], int *size, int max_size) {
  *size = rand() % max_size + 1;
  for (int i = 0; i < *size; i++) {
    arr[i] = rand() % 100; // Puedes ajustar el rango según lo necesites
  }
}



void create_random_sorted_array(int arr[], int *size, int max_size, int descending) {
  *size = rand() % (max_size-4) + 5;
  arr[0] = rand() % 10;
  for (int i = 1; i < *size; i++) {
    arr[i] = arr[i - 1] + (descending ? -(rand() % 10) : rand() % 10);
  }
}

void create_random_unsorted_array(int arr[], int *size, int max_size) {
  create_random_sorted_array(arr, size, max_size, 0); // Create an ascending sorted array
  int pos = rand() % (*size - 1);
  int temp = arr[pos];
  arr[pos] = arr[pos + 1] + 1;
  arr[pos + 1] = temp; 
}


int test_findMax() {
  for (int k = 0; k < 10; k++) {
    int arr[10];
    int size;
    create_random_array(arr, &size, 10);
    int result = findMax(arr, size);
    int found = 0;
    for (int i = 0; i < size; i++) {
      if (result < arr[i]) {
        printf("   input array: ");
        print_array(arr, size);
        printf("   result: %d\n", result);
        printf("   [FAILED] El elemento retornado no es maximo\n");
        return 0;
      }
      if (result == arr[i])
        found = 1;
    }
    if (found == 0) {
      printf("   input array: ");
      print_array(arr, size);
      printf("   result: %d\n", result);
      printf(
          "   [FAILED] El elemento retornado no se encuentra en el arreglo.\n");
      return 0;
    }
  }
  printf("   [PASSED] Prueba exitosa\n");
  return 10;
}

int test_reverseArray() {
  for (int k = 0; k < 10; k++) {
    int arr[100];
    int size;
    create_random_array(arr, &size, 10);
    int arr2[100];
    memcpy(arr2, arr, sizeof(arr));

    reverseArray(arr, size);
    for (int i = 0; i < size; i++) {
      if (arr[i] != arr2[size - i - 1]) {
        printf("   input array: ");
        print_array(arr2, size);
        printf("   reversed array: ");
        print_array(arr, size);
        printf(
            "   [FAILED] reverseArray no invierte correctamente el arreglo\n");
        return 0;
      }
    }
  }
  printf("   [PASSED] Prueba exitosa\n");
  return 10;
}



int test_filterEvenNumbers() {
  for (int k = 0; k < 10; k++) {
    int arr[100];
    int size;
    create_random_array(arr, &size, 10);

    int newSize;
    int *result = filterEvenNumbers(arr, size, &newSize);

    // result = (int*) malloc(10*sizeof(int));
    // print_array(arr, size);
    // readIntArray(result, &newSize);
    // print_array(result, newSize);

    if (result == NULL) {
      printf("   [FAILED] Retorna NULL\n");
      return 0;
    }

    if (arr == result) {
      printf("   [FAILED] El arreglo retornado es el arreglo original\n");
      return 0;
    }

    int j = 0;
    for (int i = 0; i < size; i++) {
      if (arr[i] % 2 == 0) {
        if (j == newSize || result[j] != arr[i]) {
          printf("   input array: ");
          print_array(arr, size);
          printf("   filtered array: ");
          print_array(result, newSize);
          printf("   [FAILED] El arreglo retornado no es correcto\n");
          return 0;
        }
        j++;
      }
    }
    if (j != newSize) {
      printf("   input array: ");
      print_array(arr, size);
      printf("   filtered array: ");
      print_array(result, newSize);
      printf("   [FAILED] El arreglo retornado no es correcto\n");
      return 0;
    }
  }

  printf("   [PASSED] Prueba exitosa\n");
  return 10;
}

int test_mergeSort() {
  int arr1[5];
  int arr2[5];
  int size1, size2;
  create_random_sorted_array(arr1, &size1, 5, 0);
  create_random_sorted_array(arr2, &size2, 5, 0);

  int result[10];
  mergeSortedArrays(arr1, size1, arr2, size2, result);
  // int size=size1+size2;
  // printf("   input array1: "); print_array(arr1, size1);
  // printf("   input array2: "); print_array(arr2, size2);
  // readIntArray(result, &size);
  

  int newSize = size1 + size2;
  int j = 0, k = 0;
  
  for (int i = 0; i < newSize; i++) {
    if (i > 0 && result[i] < result[i - 1]) {
      printf("   input array1: "); print_array(arr1, size1);
      printf("   input array2: "); print_array(arr2, size2);
      printf("   merged array: "); print_array(result, newSize);
      printf("   [FAILED] El arreglo no está ordenado correctamente\n");
      return 0;
    }
    
    if (j < size1 && (k >= size2 || arr1[j] <= arr2[k])) {
      if (arr1[j] != result[i]) {
        printf("   input array1: "); print_array(arr1, size1);
        printf("   input array2: "); print_array(arr2, size2);
        printf("   merged array: "); print_array(result, newSize);
        printf("   [FAILED] Los elementos no coinciden\n");
        return 0;
      }
      j++;
    } else if (k < size2 && (j >= size1 || arr2[k] <= arr1[j])) {
      if (arr2[k] != result[i]) {
        printf("   input array1: "); print_array(arr1, size1);
        printf("   input array2: "); print_array(arr2, size2);
        printf("   merged array: "); print_array(result, newSize);
        printf("   [FAILED] Los elementos no coinciden\n");
        return 0;
      }
      k++;
    }

  }

  printf("   [PASSED] Prueba exitosa\n");
  return 10;
}


int test_checkSorted() {

  for (int i = 0; i < 10; i++) {
    int arr[10];
    int size;

    // Test random array
    create_random_unsorted_array(arr, &size, 10);
    int result = checkSorted(arr, size);
    if (result != 0) {
      printf("   input array: "); print_array(arr, size);
      printf("   [FAILED] Resultado esperado: 0, resultado obtenido: %d\n", result);
      return 0;
    }

    // Test ascending sorted array
    create_random_sorted_array(arr, &size, 10, 0);
    result = checkSorted(arr, size);
    if (result != 1) {
      printf("   input array: "); print_array(arr, size);
      printf("   [FAILED] Resultado esperado: 1, resultado obtenido: %d\n", result);
      return 0;
    }

    // Test descending sorted array
    create_random_sorted_array(arr, &size, 10, 1);
    result = checkSorted(arr, size);
    if (result != -1) {
      printf("   input array: "); print_array(arr, size);
      printf("   [FAILED] Resultado esperado: -1, resultado obtenido: %d\n", result);
      return 0;
    }
  }

  printf("   [PASSED] Todas las pruebas aleatorias han pasado\n");
  return 10;

}

void imprimirLibro(const Libro *libro) {
  printf("    Título: %s\n", libro->titulo);
  printf("    Autor: %s (Nacido en: %d)\n", libro->autor.nombre, libro->autor.anioNacimiento);
  printf("    Año de Publicación: %d\n", libro->anioPublicacion);
}

int test_biblioteca() {
  Libro libro;

  const char *titulos[] = {
      "El Hobbit", "1984", "Cien Años de Soledad", "Don Quijote de la Mancha"};
  const char *autores[] = {
      "J.R.R. Tolkien", "George Orwell", "Gabriel García Márquez", "Miguel de Cervantes"};
  int aniosNacimiento[] = {1892, 1903, 1927, 1547};
  int aniosPublicacion[] = {1937, 1949, 1967, 1605};

  for (int i = 0; i < 4; i++) {
    inicializarLibro(&libro, titulos[i], autores[i], aniosNacimiento[i],
                     aniosPublicacion[i]);
    printf("   Información del libro %d:\n", i + 1);
    imprimirLibro(&libro);
    printf("\n");

    if (strcmp(libro.titulo, titulos[i]) != 0 ||
        strcmp(libro.autor.nombre, autores[i]) != 0 ||
        libro.autor.anioNacimiento != aniosNacimiento[i] ||
        libro.anioPublicacion != aniosPublicacion[i]) {
      printf("   [FAILED] Los datos no coinciden con la entrada.\n");
      return 0;
    }
  }

  printf("   [PASSED] Todas las pruebas exitosas\n");
  return 10;
}


int test_crearListaEnlazada() {
  for (int k = 0; k < 10; k++) {
    int arr[10];
    int size;
    create_random_array(arr, &size, 10);
    Nodo* lista = crearListaEnlazada(arr, size);

    Nodo* current = lista;
    
    for (int i = 0; i < size; i++) {
      if (current == NULL || current->numero != arr[i]) {
        printf("   input array: ");
        print_array(arr, size);
        print_linked_list(lista);
        printf("   [FAILED] La lista enlazada no coincide con el arreglo.\n");
        // Liberar la lista enlazada antes de retornar
        while (lista) {
          Nodo* temp = lista;
          lista = lista->siguiente;
          free(temp);
        }
        return 0;
      }
      current = current->siguiente;
    }

    // Verificar si hay nodos adicionales en la lista
    if (current != NULL) {
      printf("   input array: ");
      print_array(arr, size);
      print_linked_list(lista);
      printf("   [FAILED] La lista enlazada contiene nodos adicionales.\n");
      // Liberar la lista enlazada antes de retornar
      while (lista) {
        Nodo* temp = lista;
        lista = lista->siguiente;
        free(temp);
      }
      return 0;
    }

    // Liberar la lista enlazada
    while (lista) {
      Nodo* temp = lista;
      lista = lista->siguiente;
      free(temp);
    }
  }
  printf("   [PASSED] Prueba exitosa\n");
  return 10;
}

  

/*************  TESTS  ******************/

int main(int argc, char *argv[]) {
  srand(time(NULL));

  if (argc > 1)
    test_id = atoi(argv[1]);
  srand(time(NULL));

  int total_score = 0;
  total_score += test_suite(test_findMax, "Test Find Max...", 10, 0, test_id);
  total_score +=
      test_suite(test_reverseArray, "Test Reverse Array...", 10, 0, test_id);
  total_score += test_suite(test_filterEvenNumbers,
                            "Test Filter Even Numbers...", 10, 0, test_id);
  total_score +=
      test_suite(test_mergeSort, "Test Merged Sort Arrays...", 10, 0, test_id);
  total_score +=
      test_suite(test_checkSorted, "Test Check Sorted...", 10, 0, test_id);
  total_score +=
      test_suite(test_biblioteca, "Test Biblioteca...", 10, 0, test_id);
  total_score +=
      test_suite(test_crearListaEnlazada, "Test Lista Enlazada...", 10, 0, test_id);
  
  

  if (argc == 1)
    printf("\ntotal_score: %d/70\n", total_score);

  return 0;
}
