#ifndef GESTOR_MEMORIA_H
#define GESTOR_MEMORIA_H

#include "libreria.h"

int ProcesoIdMemoria = 1;
int OperacionId = 1;

//Representa una operación realizada por un proceso dentro de memoria.
struct Operacion {
    int OperacionId;
    int Espacio;
    string Nombre;
};

//Representa un proceso almacenado dentro de la memoria simulada.
struct Proceso {
    int ProcesoId;
    string Nombre;
    Operacion Ope[100];
    int CantOpe;
    int EspacioTotal;
    Proceso* sge;

    Proceso() { sge = NULL; }

    Proceso(Proceso& pr) {
        ProcesoId    = pr.ProcesoId;
        Nombre       = pr.Nombre;
        CantOpe      = pr.CantOpe;
        EspacioTotal = pr.EspacioTotal;
        for(int i = 0; i < CantOpe; i++) Ope[i] = pr.Ope[i];
        sge = NULL;
    }
};

//Estructura que representa la pila utilizada para administrar memoria.
struct Pila {
    Proceso* Inicio;
    Proceso* Final;
    int Tamano;
};

inline bool verificarPila(Pila& p) { return p.Inicio == NULL; }

inline void inicializarPila(Pila& p) { p.Inicio = NULL; p.Final = NULL; p.Tamano = 0; }

//Registra un nuevo proceso en memoria.
inline void asignarMemoria(Pila& p) {
    cout << "\n=========================\n==Creando nuevo proceso==\n=========================\n";
    Proceso pr;
    pr.Nombre = leerCadena("Ingrese el nombre del proceso : ");
    int can;

do {
    can = leerEntero("Ingrese la cantidad de operaciones (1-100): ");

    if (can < 1 || can > 100) {
        cout << "Error: debe ingresar entre 1 y 100 operaciones.\n";
    }

} while (can < 1 || can > 100);
    float total = 0;
    for(int i = 0; i < can; i++) {
        cout << "\n\tOperacion [" << i+1 << "]\n";
        pr.Ope[i].Nombre    = leerCadena("Ingrese el nombre de la operacion : ");
        pr.Ope[i].Espacio   = leerEntero("Ingrese la cantidad de espacio (bytes) : ");
        pr.Ope[i].OperacionId = OperacionId++;
        total += pr.Ope[i].Espacio;
    }
    pr.CantOpe      = can;
    pr.ProcesoId    = ProcesoIdMemoria++;
    pr.EspacioTotal = (int)total;

    Proceso* nuevoNodo = new Proceso(pr);

    if(verificarPila(p)) {
        p.Inicio = nuevoNodo; p.Final = nuevoNodo;
    } else {
        p.Final->sge = nuevoNodo; p.Final = nuevoNodo; p.Tamano++;
    }
    cout << "\nProceso asignado a la memoria (cima de la pila).\n";
}


//Muestra el estado actual de la memoria.
inline void mostrarEstadoMemoria(Pila& p) {
    if(verificarPila(p)) { cout << "[Pila vacia]\n"; return; }
    Proceso* temp = p.Inicio;
    while(temp != NULL) {
        cout << "\n=================\n== Proceso N [" << temp->ProcesoId << "] ==\n=================\n";
        cout << "Nombre : " << temp->Nombre << "\n";
        cout << "\nLista de operaciones\n";
        for(int i = 0; i < temp->CantOpe; i++) {
            cout << "\tOperacion Id : " << temp->Ope[i].OperacionId << "\n";
            cout << "\tNombre       : " << temp->Ope[i].Nombre      << "\n";
            cout << "\tEspacio      : " << temp->Ope[i].Espacio     << " bytes\n\n";
        }
        cout << "Espacio total : " << temp->EspacioTotal << " bytes\n";
        if(temp == p.Final)
            cout << "\n===================\n==Cima de la pila==\n===================\n";
        temp = temp->sge;
    }
}

//Libera el último proceso agregado a la memoria siguiendo el principio LIFO.
inline void liberarProceso(Pila& p) {
    if(verificarPila(p)) { cout << "[Pila vacia]\n"; return; }
    if(p.Inicio == p.Final) {
        cout << "\nProceso " << p.Inicio->Nombre       << " eliminado correctamente\n";
        cout << "Se libero " << p.Inicio->EspacioTotal << " bytes\n";
        delete p.Final;
        p.Inicio = NULL; p.Final = NULL;
    } else {
        Proceso* pro = p.Inicio;
        while(pro->sge != p.Final) pro = pro->sge;
        cout << "\nProceso " << p.Final->Nombre       << " eliminado correctamente\n";
        cout << "Se libero " << p.Final->EspacioTotal << " bytes\n";
        delete p.Final;
        pro->sge = NULL;
        p.Final  = pro;
    }
}

inline void buscarProcesoMemoria(Pila& p) {
    if(verificarPila(p)) { cout << "[Pila vacia]\n"; return; }
    int id = leerEntero("Ingrese el Id del proceso a buscar : ");
    Proceso* pro = p.Inicio;
    while(pro != NULL) {
        if(pro->ProcesoId == id) {
            Pila temp; inicializarPila(temp);
            temp.Inicio = pro; temp.Final = pro;
            mostrarEstadoMemoria(temp);
            return;
        }
        pro = pro->sge;
    }
    cout << "No se encontro ese proceso\n";
}

//Elimina todos los procesos almacenados dentro de la memoria.
inline void liberarTodo(Pila& p) {
    if(verificarPila(p)) { cout << "[Pila vacia]\n"; return; }
    while(!verificarPila(p)) liberarProceso(p);
    cout << "Todos los procesos de la memoria fueron eliminados.\n";
}

#endif
