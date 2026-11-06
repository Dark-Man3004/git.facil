#ifndef GESTOR_PROCESOS_H
#define GESTOR_PROCESOS_H

#include "libreria.h"

struct NodoProceso {
    int id;
    string nombre;
    int prioridad;
    NodoProceso* siguiente;

    NodoProceso(int _id, string _nombre, int _prioridad) {
        id = _id;
        nombre = _nombre;
        prioridad = _prioridad;
        siguiente = NULL;
    }
};

//Clase encargada de administrar los procesos registrados en el sistema.
class GestorProcesos {
private:
    NodoProceso* cabeza;

	//Verifica si un ID ya existe dentro de la lista.
    bool idExiste(int id) {
        NodoProceso* actual = cabeza;
        while(actual != NULL) {
            if(actual->id == id) return true;
            actual = actual->siguiente;
        }
        return false;
    }

public:
    GestorProcesos() { cabeza = NULL; }

    void insertarProceso(int id, string nombre, int prioridad) {
        if(prioridad < 1 || prioridad > 10) {
            cout << " La prioridad debe estar entre 1 y 10." << endl;
            return;
        }
        if(idExiste(id)) {
            cout << " Ya existe un proceso con ID " << id << "." << endl;
            return;
        }
        if(nombre.empty()) {
            cout << " El nombre no puede estar vacio." << endl;
            return;
        }

        NodoProceso* nuevo = new NodoProceso(id, nombre, prioridad);

        if(cabeza == NULL) {
            cabeza = nuevo;
        } else {
            NodoProceso* actual = cabeza;
            while(actual->siguiente != NULL) actual = actual->siguiente;
            actual->siguiente = nuevo;
        }

        cout << " Proceso insertado\n";
        cout << "  ID: " << id << " --- Nombre: " << nombre << " --- Prioridad: " << prioridad << "\n";
    }

    void eliminarProceso(int id) {
        if(cabeza == NULL) { cout << " No hay procesos registrados.\n"; return; }

        if(cabeza->id == id) {
            NodoProceso* temp = cabeza;
            cabeza = cabeza->siguiente;
            cout << " Proceso eliminado: " << temp->nombre << " (ID: " << id << ")\n";
            delete temp;
            return;
        }

        NodoProceso* actual = cabeza;
        while(actual->siguiente != NULL && actual->siguiente->id != id)
            actual = actual->siguiente;

        if(actual->siguiente == NULL) {
            cout << " No se encontro un proceso con ID " << id << ".\n";
        } else {
            NodoProceso* temp = actual->siguiente;
            actual->siguiente = temp->siguiente;
            cout << " Proceso eliminado: " << temp->nombre << " (ID: " << id << ")\n";
            delete temp;
        }
    }

	//Busca un proceso utilizando su ID.
    void buscarPorID(int id) {
        if(cabeza == NULL) { cout << " No hay procesos registrados.\n"; return; }

        NodoProceso* actual = cabeza;
        while(actual != NULL) {
            if(actual->id == id) {
                cout << " Proceso encontrado:\n";
                cout << "  ID: " << actual->id << " --- Nombre: " << actual->nombre
                     << " --- Prioridad: " << actual->prioridad << "\n";
                return;
            }
            actual = actual->siguiente;
        }
        cout << " No se encontro un proceso con ID " << id << ".\n";
    }

	//Modifica la prioridad de un proceso existente.
    void modificarPrioridad(int id, int nuevaPrioridad) {
        if(cabeza == NULL) { cout << " No hay procesos registrados.\n"; return; }
        if(nuevaPrioridad < 1 || nuevaPrioridad > 10) {
            cout << " La prioridad debe estar entre 1 y 10.\n"; return;
        }

        NodoProceso* actual = cabeza;
        while(actual != NULL) {
            if(actual->id == id) {
                cout << " Prioridad modificada.\n";
                cout << "  Proceso: " << actual->nombre << "\n";
                cout << "  Prioridad anterior: " << actual->prioridad << "\n";
                actual->prioridad = nuevaPrioridad;
                cout << "  Nueva prioridad: " << nuevaPrioridad << "\n";
                return;
            }
            actual = actual->siguiente;
        }
        cout << " No se encontro un proceso con ID " << id << ".\n";
    }

	//Muestra todos los procesos registrados
    void mostrarTodos() {
        if(cabeza == NULL) { cout << " Lista de procesos VACIA.\n"; return; }

        cout << "\n=== LISTA DE PROCESOS ===\n";
        NodoProceso* actual = cabeza;
        int contador = 1;
        int sumaPrioridades = 0;

        while(actual != NULL) {
            cout << contador++ << ". ID: " << actual->id
                 << "  Nombre: " << actual->nombre
                 << "  Prioridad: " << actual->prioridad;

            if(actual->prioridad >= 7) cout << " [ALTA]";
            else if(actual->prioridad <= 3) cout << " [BAJA]";

            cout << "\n";
            sumaPrioridades += actual->prioridad;
            actual = actual->siguiente;
        }

        int total = contador - 1;
        cout << "Total de procesos: " << total << "\n";
        cout << "Prioridad promedio: " << (float)sumaPrioridades / total << "\n";
    }

    ~GestorProcesos() {
        NodoProceso* actual = cabeza;
        while(actual != NULL) {
            NodoProceso* temp = actual;
            actual = actual->siguiente;
            delete temp;
        }
    }
};

#endif
