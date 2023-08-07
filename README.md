

Ejercicios sobre punteros arreglos y la declaración Struct
=====


---
**Antes de comenzar**

* Importe el repositorio desde su cuenta en repl.it (si no tiene siga [este tutorial](https://chartreuse-goal-d5c.notion.site/C-mo-comenzar-con-los-labs-b4dd8c7abc5a425d8f25e2eaa060e5b5?pvs=4))
* Sólo puede modificar el archivo `exercises.c` 
* Para testear sus códigos debe abrir un terminal *git bash* y ejecutar el comando `./test.sh`
* Verifique que sus cambios se hayan subido a este repositorio
* **No está permitido usar comandos de git** (a menos que el profesor lo indique)
---

1. **Encuentra el Elemento Mayor**. Escribe una función que tome un arreglo de enteros
y su tamaño, y devuelva el valor más grande del arreglo.

2. **Invertir un Arreglo**. Escribe una función que tome un arreglo y su tamaño, y luego
invierta el orden de sus elementos.

3. **Filtrar Números Pares**. Escribe una función que tome un arreglo de enteros
y su tamaño, y luego devuelva un nuevo arreglo que contenga solo
los números pares del arreglo original.

4. **Fusión de dos Arreglos Ordenados**. Escribe una función que tome dos arreglos
ordenados y sus tamaños, y luego fusione estos dos
arreglos en un tercer arreglo también ordenado.

5. **Comprobación de Ordenación.** Escribe una función que tome un arreglo y su tamaño,
y luego devuelva 1 si el arreglo está ordenado en orden ascendente,
  0 si no está ordenado, y -1 si está ordenado en orden descendente.

6. **Información de una Biblioteca**. Vamos a representar la información de una biblioteca. En la
biblioteca, hay libros, y cada libro tiene un autor. Queremos organizar esta
información utilizando estructuras anidadas en C. Escribe la función para
inicializar la información de un libro.

````c
typedef struct {
  char nombre[50];
  int anioNacimiento;
} Autor;

typedef struct {
  char titulo[100];
  Autor autor;
  int anioPublicacion;
} Libro;
````

7. **Lista enlazada de números**. Escribe una función que tome un arreglo de enteros y su tamaño, y
luego cree una lista enlazada usando la estructura Nodo. Cada nodo de la lista
debe contener un número del arreglo, y los nodos deben estar enlazados en el
mismo orden que los números aparecen en el arreglo. El último nodo de la lista
debe apuntar a NULL. La función debe devolver un puntero al primer nodo de la
lista enlazada.
Recuerda reservar memoria dinámica para cada nodo usando malloc.

````c
typedef struct nodo {
  int numero;
  struct nodo *siguiente; // puntero al siguiente nodo
} Nodo;
````
