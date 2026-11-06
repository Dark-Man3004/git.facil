#ifndef LIBRERIA_H
#define LIBRERIA_H

#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Funcion para leer numeros enteros
inline int leerEntero(const string& mensaje) {
    int valor;

    cout << mensaje;

    while (!(cin >> valor)) {
        cout << "Entrada no valida. Ingrese un numero: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return valor;
}

// Funcion para leer cadenas
inline string leerCadena(const string& mensaje) {
    string valor;

    cout << mensaje;
    getline(cin, valor);

    return valor;
}

#endif
