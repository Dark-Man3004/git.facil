#ifndef PLANIFICADOR_CPU_H
#define PLANIFICADOR_CPU_H

#include "libreria.h"

int ProcesoIdCPU = 100;

//Nodo utilizado dentro de la cola de prioridad.
struct NodoCola {
    int ProcesoId;
    string Nombre;
    int Prioridad;
    NodoCola* sge;
    NodoCola() { sge = NULL; }
};

//Estructura que representa la cola de prioridad.
struct Cola {
    NodoCola* Frente;
    NodoCola* Final;
    int Tamano;
};

//Inicializa una cola vacía.
inline void inicializarCola(Cola& c) { c.Frente = NULL; c.Final = NULL; c.Tamano = 0; }
/*** Determina si la cola está vacía.*/
inline bool verificarCola(Cola& c)   { return c.Frente == NULL; }

//Inserta un proceso dentro de la cola respetando el orden de prioridad.
inline void encolarProceso(Cola& c) {
    cout << "\n===========================\n== Encolando nuevo proceso ==\n===========================\n";
    NodoCola* nuevo = new NodoCola();
    nuevo->Nombre    = leerCadena("Ingrese el nombre del proceso para CPU: ");
    nuevo->Prioridad = leerEntero("Ingrese la prioridad (1=alta, 5=baja): ");
    nuevo->ProcesoId = ProcesoIdCPU++;
    nuevo->sge = NULL;

    if(verificarCola(c)) {
        c.Frente = nuevo; c.Final = nuevo; c.Tamano++;
        cout << "\nProceso encolado correctamente como unico elemento.\n"; return;
    }
    if(nuevo->Prioridad < c.Frente->Prioridad) {
        nuevo->sge = c.Frente; c.Frente = nuevo; c.Tamano++;
        cout << "\nProceso encolado al frente por tener maxima prioridad.\n"; return;
    }

    NodoCola* temp = c.Frente;
    while(temp->sge != NULL && temp->sge->Prioridad <= nuevo->Prioridad)
        temp = temp->sge;

    nuevo->sge = temp->sge;
    temp->sge  = nuevo;
    if(nuevo->sge == NULL) c.Final = nuevo;
    c.Tamano++;
    cout << "\nProceso encolado respetando su rango de prioridad.\n";
}

/*Simula la ejecución del proceso ubicado en el frente de la cola.
 *Una vez ejecutado se elimina de la cola.*/
inline void desencolarProceso(Cola& c) {
    if(verificarCola(c)) { cout << "\n[Cola vacia]\n"; return; }
    NodoCola* temp = c.Frente;
    cout << "\n================================\n";
    cout << "Ejecutando en CPU: " << temp->Nombre    << "\n";
    cout << "ID del Proceso   : " << temp->ProcesoId << "\n";
    cout << "Prioridad        : " << temp->Prioridad << "\n";
    cout << "================================\n";
    c.Frente = c.Frente->sge;
    if(c.Frente == NULL) c.Final = NULL;
    delete temp;
    c.Tamano--;
    cout << "Proceso ejecutado y liberado de la CPU.\n";
}

//Muestra todos los procesos actualmente almacenados en la cola de prioridad.
inline void mostrarCola(Cola& c) {
    if(verificarCola(c)) { cout << "\n[Cola vacia]\n"; return; }
    NodoCola* temp = c.Frente;
    int pos = 1;
    cout << "\n=== Estado actual del Planificador (Cola) ===\n";
    while(temp != NULL) {
        cout << "\n---------------------------\n";
        cout << "Posicion  : " << pos           << "\n";
        cout << "ID        : " << temp->ProcesoId << "\n";
        cout << "Nombre    : " << temp->Nombre  << "\n";
        cout << "Prioridad : " << temp->Prioridad << " (1=Maximo)\n";
        if(temp == c.Frente) cout << ">>> SIGUIENTE A EJECUTAR (FRENTE) <<<\n";
        temp = temp->sge;
        pos++;
    }
    cout << "\nTotal procesos en cola de CPU: " << c.Tamano << "\n";
}
//Ejecuta todos los procesos pendientes dentro de la cola hasta vaciarla.
inline void ejecutarTodos(Cola& c) {
    if(verificarCola(c)) { cout << "\n[Cola vacia]\n"; return; }
    cout << "\n=== Ejecutando rafaga completa de procesos ===\n";
    while(!verificarCola(c)) desencolarProceso(c);
    cout << "\nTodos los procesos de la CPU fueron completados.\n";
}

#endif
