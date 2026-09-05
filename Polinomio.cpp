#include <iostream>
#include <cmath>
using namespace std;

class Polinomio {
private:
    int grado;
    int* coeficientes;

public:
    Polinomio(int g) {
        grado = g;
        coeficientes = new int[grado + 1];
    }

    void setCoeficiente(int indice, int valor) {
        if (indice >= 0 && indice <= grado) {
            coeficientes[indice] = valor;
        }
    }

    int getCoeficiente(int indice) {
        if (indice >= 0 && indice <= grado) {
            return coeficientes[indice];
        }

        return 0;
    }

    int evaluar(int x) {
        int resultado = 0;

        for (int i = 0; i <= grado; i++) {
            resultado += coeficientes[i] * pow(x, grado - i);
        }

        return resultado;
    }

    void imprimir() {
        cout << "El polinomio es: ";

        for (int i = 0; i <= grado; i++) {

            if (i == 0) {
                cout << coeficientes[i] << "x^" << grado - i;
            }
            else if (i == grado) {
                cout << " + " << coeficientes[i];
            }
            else {
                cout << " + " << coeficientes[i]
                     << "x^" << grado - i;
            }
        }

        cout << endl;
    }

    ~Polinomio() {
        delete[] coeficientes;
    }
};

int main() {

    cout << "Polinomios" << endl;

    int m = 0;

    cout << "Ingrese el grado del polinomio: ";
    cin >> m;

    Polinomio p(m);

    int exponente = m;

    for (int i = 0; i <= m; i++) {

        int coeficiente;

        cout << "Ingrese el coeficiente del termino de grado "
             << exponente << ": ";

        cin >> coeficiente;

        p.setCoeficiente(i, coeficiente);

        exponente--;
    }

    p.imprimir();

    int x;

    cout << "Ingrese el valor de x: ";
    cin >> x;

    int resultado = p.evaluar(x);

    cout << "El resultado del polinomio evaluado en x = "
         << x << " es: " << resultado << endl;

    return 0;
}
