// Autor: de la Riva Martinez Hector Josue
#include <stdio.h>
#include <iostream>

struct nodo {
    int valor;
    nodo *sig;
};

typedef nodo *apu_nodo;

// Agregar Nodos 

void agregarIzquierda(apu_nodo &inicial, apu_nodo &actual, int &ban, int val) {
    apu_nodo aux = new nodo;
    aux->valor = val;

    if (ban == 0) {
        inicial = aux;
        inicial->sig = inicial;
        actual = inicial;
        ban = 1;
    } else {
        aux->sig = inicial;
        actual->sig = aux;
        inicial = aux;
    }
    printf("Nodo agregado al inicio.\n");
}

void agregarDerecha(apu_nodo &inicial, apu_nodo &actual, int &ban, int val) {
    apu_nodo aux = new nodo;
    aux->valor = val;

    if (ban == 0) {
        inicial = aux;
        inicial->sig = inicial;
        actual = inicial;
        ban = 1;
    } else {
        aux->sig = inicial;
        actual->sig = aux;
        actual = aux;
    }
    printf("Nodo agregado al final.\n");
}

void agregarEnPosicion(apu_nodo &inicial, apu_nodo &actual, int &ban, int val, int pos) {
    if (ban == 0 || pos == 1) {
        agregarIzquierda(inicial, actual, ban, val);
        return;
    }

    apu_nodo aux = new nodo;
    aux->valor = val;
    apu_nodo temp = inicial;
    int contador = 1;

    while (contador < pos - 1 && temp->sig != inicial) {
        temp = temp->sig;
        contador++;
    }

    aux->sig = temp->sig;
    temp->sig = aux;
    if (temp == actual) actual = aux;

    printf("Nodo agregado en la posición %d.\n", pos);
}

// Borrar nodos

void eliminarNodoPorPosicion(apu_nodo &inicial, apu_nodo &actual, int &ban, int pos) {
    if (ban == 0) {
        printf("La lista está vacía.\n");
        return;
    }

    apu_nodo prev = actual, temp = inicial;
    int contador = 1;

    // Si el nodo a eliminar está en la primera posición
    if (pos == 1) {
        if (temp == inicial && temp == actual) {
            delete temp;
            ban = 0;
        } else {
            temp = inicial;
            inicial = inicial->sig;
            actual->sig = inicial;
            delete temp;
        }
        printf("Nodo en la posición 1 eliminado correctamente.\n");
        return;
    }

    // Buscar el nodo en la posición dada
    while (contador < pos && temp->sig != inicial) {
        prev = temp;
        temp = temp->sig;
        contador++;
    }

    // Si el nodo existe en la posición proporcionada
    if (contador == pos) {
        prev->sig = temp->sig;
        if (temp == actual) actual = prev;
        delete temp;
        printf("Nodo en la posición %d eliminado correctamente.\n", pos);
    } else {
        printf("Posición no válida.\n");
    }
}


// Modificar nodo

void modificarNodoPorPosicion(apu_nodo inicial, int ban, int pos, int nuevoValor) {
    if (ban == 0) {
        printf("La lista está vacía.\n");
        return;
    }

    apu_nodo temp = inicial;
    int contador = 1;

    while (contador < pos && temp->sig != inicial) {
        temp = temp->sig;
        contador++;
    }

    if (contador == pos) {
        temp->valor = nuevoValor;
        printf("Nodo en la posición %d modificado correctamente.\n", pos);
    } else {
        printf("Posición no encontrada.\n");
    }
}

// Mostrar nodos

void mostrarLista(apu_nodo inicial, int ban) {
    if (ban == 0) {
        printf("No has agregado ningun nodo aun.\n");
        return;
    }

    apu_nodo temp = inicial;
    int i = 1;
    
    while (true) {
        printf("El valor del nodo %d es = %d\n", i, temp->valor);
        temp = temp->sig;
        i++;
        if (temp == inicial) break;
    }
}

// Buscar un nodo

void buscarNodoPorPosicion(apu_nodo inicial, int ban, int pos) {
    if (ban == 0) {
        printf("La lista está vacía.\n");
        return;
    }

    apu_nodo temp = inicial;
    int contador = 1;

    while (contador < pos && temp->sig != inicial) {
        temp = temp->sig;
        contador++;
    }

    if (contador == pos) {
        printf("Nodo en la posición %d tiene el valor: %d\n", pos, temp->valor);
    } else {
        printf("Posición no encontrada.\n");
    }
}


int main(void) {
    int it = 1, opc, val, nuevoVal, pos, ban = 0;
    apu_nodo inicial = NULL, actual = NULL;

    while (it == 1) {
        printf("\nListas simplemente ligadas circulares\n");
        printf("1. Agregar nodo al inicio\n");
        printf("2. Agregar nodo al final\n");
        printf("3. Agregar nodo en una posicion\n");
        printf("4. Eliminar nodo por posición\n");
        printf("5. Modificar nodo por posición\n");
        printf("6. Buscar nodo por posición\n");
        printf("7. Mostrar nodos\n");
        printf("8. Salir\n");
        printf("Que opcion quieres realizar: ");
        scanf("%d", &opc);

        switch (opc) {
            case 1:
                printf("Ingresa el valor de tu nodo: ");
                scanf("%d", &val);
                agregarIzquierda(inicial, actual, ban, val);
                break;
            case 2:
                printf("Ingresa el valor de tu nodo: ");
                scanf("%d", &val);
                agregarDerecha(inicial, actual, ban, val);
                break;
            case 3:
                printf("Ingresa el valor de tu nodo: ");
                scanf("%d", &val);
                printf("Ingresa la posicion donde agregar: ");
                scanf("%d", &pos);
                agregarEnPosicion(inicial, actual, ban, val, pos);
                break;
            case 4:
                printf("Ingresa la posición del nodo a eliminar: ");
                scanf("%d", &pos);
                eliminarNodoPorPosicion(inicial, actual, ban, pos);
                break;
            case 5:
                printf("Ingresa la posición del nodo a modificar: ");
                scanf("%d", &pos);
                printf("Ingresa el nuevo valor: ");
                scanf("%d", &nuevoVal);
                modificarNodoPorPosicion(inicial, ban, pos, nuevoVal);
                break;
                case 6:
                printf("Ingresa la posición del nodo a buscar: ");
                scanf("%d", &pos);
                buscarNodoPorPosicion(inicial, ban, pos);
                break;
            case 7:
                printf("\nMostrar Nodos\n");
                mostrarLista(inicial, ban);
                break;
            case 8:
                printf("Saliendo del programa\n");
                it = 0;
                break;
            default:
                printf("Opcion invalida\n");
                break;
        }
    }
    return 0;
}