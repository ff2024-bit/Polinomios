#ifndef POLINOMIO_H
#define POLINOMIO_H

#include <string>

using namespace std;

struct Termino {
    float coeficiente;
    int exponente;
    Termino* siguiente;
};

Termino* crearNodo(float coef, int exp);

Termino* insertarTermino(Termino* cabeza, float coef, int exp);

void imprimirPolinomio(Termino* cabeza);

int destruirPolinomio(Termino*& cabeza);

Termino* sumarPolinomios(Termino* p1, Termino* p2);

Termino* multiplicarPolinomios(Termino* p1, Termino* p2);

float evaluarPolinomio(Termino* cabeza, float x);

Termino* derivarPolinomio(Termino* cabeza);

int contarTerminos(Termino* cabeza);

int gradoPolinomio(Termino* cabeza);

void separador(const string& titulo);

#endif