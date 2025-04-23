#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo** hijos;  
    int n;         
   
    Nodo(int valor, int numHijos) {
        dato = valor;
        n = numHijos;
        hijos = new Nodo*[n];

        for (int i = 0; i < n; i++) {
            hijos[i] = nullptr;
        }
    }
};

int main() {
    Nodo* raiz = new Nodo(10, 3);

    raiz->hijos[0] = new Nodo(20, 0);
    raiz->hijos[1] = new Nodo(30, 0);
    raiz->hijos[2] = new Nodo(40, 0);

    cout << "Nodo raíz: " << raiz->dato << endl;
    for (int i = 0; i < raiz->n; i++) {
        if (raiz->hijos[i])
            cout << "  Hijo " << i << ": " << raiz->hijos[i]->dato << endl;
    }

    delete raiz;

    return 0;
}
