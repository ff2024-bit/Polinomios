#include <iostream>
#include <cmath>

using namespace std;

struct Termino
{
    float coeficiente;
    int exponente;
    Termino *siguiente;
};


Termino *crearNodo(float coeficiente, int exponente)
{
    Termino *nuevo = new Termino;

    nuevo->coeficiente = coeficiente;
    nuevo->exponente = exponente;
    nuevo->siguiente = nullptr;

    return nuevo;
}


Termino *insertarTermino(Termino *cabeza, float coeficiente, int exponente)
{
    if (cabeza == nullptr)
    {
        return crearNodo(coeficiente, exponente);
    }

    Termino *nuevo = crearNodo(coeficiente, exponente);

    if (exponente > cabeza->exponente)
    {
        nuevo->siguiente = cabeza;
        return nuevo;
    }

    Termino *actual = cabeza;

    while (actual->siguiente != nullptr &&
           actual->siguiente->exponente > exponente)
    {
        actual = actual->siguiente;
    }

    if (actual->siguiente != nullptr &&
        actual->siguiente->exponente == exponente)
    {
        actual->siguiente->coeficiente =
            actual->siguiente->coeficiente + coeficiente;

        delete nuevo;
    }
    else
    {
        nuevo->siguiente = actual->siguiente;
        actual->siguiente = nuevo;
    }

    return cabeza;
}


void imprimirPolinomio(Termino *cabeza)
{
    Termino *actual = cabeza;

    while (actual != nullptr)
    {
        if (actual->coeficiente > 0 && actual != cabeza)
        {
            cout << " + ";
        }

        if (actual->coeficiente < 0)
        {
            cout << " - ";
        }

        float coeficiente = fabs(actual->coeficiente);

        if (coeficiente != 1 || actual->exponente == 0)
        {
            cout << coeficiente;
        }

        if (actual->exponente > 0)
        {
            cout << "x";
        }

        if (actual->exponente > 1)
        {
            cout << "^" << actual->exponente;
        }

        actual = actual->siguiente;
    }

    cout << endl;
}


Termino *sumarPolinomios(Termino *polinomio1, Termino *polinomio2)
{
    Termino *resultado = nullptr;

    Termino *actual = polinomio1;

    while (actual != nullptr)
    {
        resultado = insertarTermino(
            resultado,
            actual->coeficiente,
            actual->exponente
        );

        actual = actual->siguiente;
    }

    actual = polinomio2;

    while (actual != nullptr)
    {
        resultado = insertarTermino(
            resultado,
            actual->coeficiente,
            actual->exponente
        );

        actual = actual->siguiente;
    }

    return resultado;
}

// Destruir polinomio
void destruirPolinomio(Termino *&cabeza)
{
    Termino *actual;

    while (cabeza != nullptr)
    {
        actual = cabeza;
        cabeza = cabeza->siguiente;
        delete actual;
    }
}

int main()
{
    Termino *polinomio1 = nullptr;
    Termino *polinomio2 = nullptr;
    Termino *resultado = nullptr;

    float coeficiente;
    int exponente;

    
    cout << "POLINOMIO 1" << endl;

    for (int i = 0; i < 4; i++)
    {
        cout << "Ingrese el coeficiente: ";
        cin >> coeficiente;

        cout << "Ingrese el exponente: ";
        cin >> exponente;

        polinomio1 = insertarTermino(
            polinomio1,
            coeficiente,
            exponente
        );
    }

    
    cout << endl;
    cout << "POLINOMIO 2" << endl;

    for (int i = 0; i < 4; i++)
    {
        cout << "Ingrese el coeficiente: ";
        cin >> coeficiente;

        cout << "Ingrese el exponente: ";
        cin >> exponente;

        polinomio2 = insertarTermino(
            polinomio2,
            coeficiente,
            exponente
        );
    }

    
    cout << endl;
    cout << "Primer polinomio: ";
    imprimirPolinomio(polinomio1);

    
    cout << "Segundo polinomio: ";
    imprimirPolinomio(polinomio2);

    
    resultado = sumarPolinomios(polinomio1, polinomio2);

   
    cout << "Resultado: ";
    imprimirPolinomio(resultado);

    // Destruir polinomios
    destruirPolinomio(polinomio1);
    destruirPolinomio(polinomio2);
    destruirPolinomio(resultado);

    cout << endl;
    cout << "Memoria liberada." << endl;

    return 0;
}