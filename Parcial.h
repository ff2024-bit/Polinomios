#ifndef PARCIAL_H
#define PARCIAL_H

#include "Polinomio.h"

Termino* multiplicar(Termino* P1, Termino* P2)
{
    return multiplicarPolinomios(P1, P2);
}

Termino* dividir(Termino* P1, Termino* P2)
{
    Termino* resultado = nullptr;
    Termino* actual = P1;

    if (P2 == nullptr)
        return nullptr;

    while (actual != nullptr)
    {
        Termino* divisor = P2;

        while (divisor != nullptr)
        {
            if (actual->exponente >= divisor->exponente)
            {
                float coef = actual->coeficiente / divisor->coeficiente;
                int exp = actual->exponente - divisor->exponente;

                resultado = insertarTermino(resultado, coef, exp);
                break;
            }

            divisor = divisor->siguiente;
        }

        actual = actual->siguiente;
    }

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

Termino* insertar(Termino* P, float coef, int exp)
{
    return insertarTermino(P, coef, exp);
}

#endif