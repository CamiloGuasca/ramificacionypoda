#include <iostream>
#include <vector>
using namespace std;

struct Nodo {
    string dato;
    vector<Nodo*> hijos;

    Nodo(string valor) {
        dato = valor;
    }
};

int main() {
    int totalNodos;
    cout << "¿Cuántos nodos quieres crear? ";
    cin >> totalNodos;

    vector<Nodo*> nodos;
    string valor;

    // Crear nodos con datos
    for (int i = 0; i < totalNodos; i++) {
        cout << "Ingresa el valor del nodo " << i << ": ";
        cin >> valor;
        nodos.push_back(new Nodo(valor));
    }

    // Conexiones padre-hijo
    for (int i = 0; i < totalNodos; i++) {
        int numHijos;
        cout << "¿Cuántos hijos tiene el nodo " << i << " (" << nodos[i]->dato << ")? ";
        cin >> numHijos;

        for (int j = 0; j < numHijos; j++) {
            int indiceHijo;
            cout << "  Ingresa el índice del hijo #" << j + 1 << ": ";
            cin >> indiceHijo;

            if (indiceHijo >= 0 && indiceHijo < totalNodos) {
                nodos[i]->hijos.push_back(nodos[indiceHijo]);
            } else {
                cout << "  Índice inválido. Se omite este hijo." << endl;
            }
        }
    }

    // Mostrar árbol básico
    for (int i = 0; i < totalNodos; i++) {
        cout << "Nodo " << i << " (" << nodos[i]->dato << ") tiene " << nodos[i]->hijos.size() << " hijos: ";
        for (Nodo* h : nodos[i]->hijos) {
            cout << h->dato << " ";
        }
        cout << endl;
    }

    // Liberar memoria
    for (Nodo* nodo : nodos) {
        delete nodo;
    }

    return 0;
}
