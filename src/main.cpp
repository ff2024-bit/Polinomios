#include <iostream>
#include "../include/polinomio.h"

using namespace std;

int main() {

    Termino* polinomio = nullptr;

    polinomio = insertarTermino(polinomio, 3, 2);
    polinomio = insertarTermino(polinomio, 2, 1);
    polinomio = insertarTermino(polinomio, 5, 0);

    cout << "Polinomio: ";
    imprimirPolinomio(polinomio);

    cout << "Grado: " << gradoPolinomio(polinomio) << endl;

    cout << "Cantidad de terminos: "
         << contarTerminos(polinomio) << endl;

    cout << "Evaluado en x = 2: "
         << evaluarPolinomio(polinomio, 2) << endl;

    Termino* derivada = derivarPolinomio(polinomio);

    cout << "Derivada: ";
    imprimirPolinomio(derivada);

    destruirPolinomio(polinomio);
    destruirPolinomio(derivada);

    return 0;
}