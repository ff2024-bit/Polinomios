#ifndef PARCIAL2_H
#define PARCIAL2_H

#include "Polinomio.h"

Termino* multiplicar(Termino* P1, Termino* P2)
{
    return multiplicarPolinomios(P1, P2);
}


Termino* dividir(Termino* P1, Termino* P2)
{
    Termino* resultado = nullptr;
    Termino* resto = nullptr;

    if (P1 == nullptr || P2 == nullptr)
        return nullptr;

    if (P2->coeficiente == 0)
        return nullptr;

    
    Termino* actual = P1;

    while (actual != nullptr)
    {
        resto = insertarTermino(
            resto,
            actual->coeficiente,
            actual->exponente
        );

        actual = actual->siguiente;
    }

    
    while (resto != nullptr &&
           gradoPolinomio(resto) >= gradoPolinomio(P2))
    {
        float coeficiente =
            resto->coeficiente / P2->coeficiente;

        int exponente =
            resto->exponente - P2->exponente;

        
        resultado = insertarTermino(
            resultado,
            coeficiente,
            exponente
        );

        
        actual = P2;

        while (actual != nullptr)
        {
            float nuevoCoef =
                actual->coeficiente * coeficiente;

            int nuevoExp =
                actual->exponente + exponente;

            resto = insertarTermino(
                resto,
                -nuevoCoef,
                nuevoExp
            );

            actual = actual->siguiente;
        }
    }

    destruirPolinomio(resto);

    return resultado;
}

bool sonIguales(Termino* P1, Termino* P2)
{
    while (P1 != nullptr && P2 != nullptr)
    {
        if (P1->coeficiente != P2->coeficiente)
            return false;

        if (P1->exponente != P2->exponente)
            return false;

        P1 = P1->siguiente;
        P2 = P2->siguiente;
    }

    if (P1 == nullptr && P2 == nullptr)
        return true;

    return false;
}

Termino* insertar(Termino* P, int exp, float coe)
{
    return insertarTermino(P, coe, exp);
}


#endif