#include <iostream>
using namespace std;
int main() {
    int n=0;
    cout << "Ingrese la dimension del arreglo: ";
    cin >> n;
    
    int* arreglo = new int[n];
   
    for (int i = 0; i < n; ++i) {
        cout << "Ingrese valor para la posicion [" << i << "] ";
        cin >> arreglo[i];
    }
   
    cout << "Los valores del arreglo son: ";
    for (int i = 0; i < n; ++i) {
        cout << arreglo[i] << " ";
    }
    cout << endl;
   
    delete[] arreglo;
    return 0;
}
