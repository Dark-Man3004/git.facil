#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Funcion para leer numeros enteros
int leerEntero(const string& mensaje) {
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
string leerCadena(const string& mensaje) {
    string valor;

    cout << mensaje;
    getline(cin, valor);

    return valor;
}

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
void inicializarCola(Cola& c) { c.Frente = NULL; c.Final = NULL; c.Tamano = 0; }
/*** Determina si la cola está vacía.*/
bool verificarCola(Cola& c)   { return c.Frente == NULL; }

//Inserta un proceso dentro de la cola respetando el orden de prioridad.
void encolarProceso(Cola& c) {
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
void desencolarProceso(Cola& c) {
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
void mostrarCola(Cola& c) {
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
void ejecutarTodos(Cola& c) {
    if(verificarCola(c)) { cout << "\n[Cola vacia]\n"; return; }
    cout << "\n=== Ejecutando rafaga completa de procesos ===\n";
    while(!verificarCola(c)) desencolarProceso(c);
    cout << "\nTodos los procesos de la CPU fueron completados.\n";
}

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

bool verificarPila(Pila& p) { return p.Inicio == NULL; }

void inicializarPila(Pila& p) { p.Inicio = NULL; p.Final = NULL; p.Tamano = 0; }

//Registra un nuevo proceso en memoria.
void asignarMemoria(Pila& p) {
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
void mostrarEstadoMemoria(Pila& p) {
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
void liberarProceso(Pila& p) {
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

void buscarProcesoMemoria(Pila& p) {
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
void liberarTodo(Pila& p) {
    if(verificarPila(p)) { cout << "[Pila vacia]\n"; return; }
    while(!verificarPila(p)) liberarProceso(p);
    cout << "Todos los procesos de la memoria fueron eliminados.\n";
}

void mostrarMenu() {
    cout << "\n==========================================\n";
    cout << "    SISTEMA OPERATIVO SIMULADO (GRUPO 9)  ";
    cout << "\n==========================================\n";
    cout << "1. Gestor de Procesos (Lista Enlazada)\n";
    cout << "2. Planificador de CPU (Cola de Prioridad)\n";
    cout << "3. Gestor de Memoria (Pila Dinamica)\n";
    cout << "4. Salir del Sistema\n";
    cout << "------------------------------------------\n";
}

void mostrarSubMenu1() {
    cout << "\n====================================\n";
    cout << "  SUB-MENU 01: GESTOR DE PROCESOS  ";
    cout << "\n====================================\n";
    cout << "1. Insertar proceso\n";
    cout << "2. Eliminar proceso\n";
    cout << "3. Buscar por ID\n";
    cout << "4. Modificar prioridad\n";
    cout << "5. Mostrar todos los procesos\n";
    cout << "6. Volver al Menu Principal\n";
    cout << "------------------------------------------\n";
}

void mostrarSubMenu2() {
    cout << "\n====================================\n";
    cout << "   SUB-MENU 02: PLANIFICADOR CPU   ";
    cout << "\n====================================\n";
    cout << "1. Encolar proceso (Por Prioridad)\n";
    cout << "2. Desencolar proceso (Ejecutar siguiente)\n";
    cout << "3. Mostrar cola actual de ejecucion\n";
    cout << "4. Ejecutar rafaga (Todos los procesos)\n";
    cout << "5. Volver al Menu Principal\n";
    cout << "------------------------------------------\n";
}

void mostrarSubMenu3() {
    cout << "\n====================================\n";
    cout << "   SUB-MENU 03: GESTOR DE MEMORIA  ";
    cout << "\n====================================\n";
    cout << "1. Asignar memoria a proceso\n";
    cout << "2. Buscar proceso en memoria\n";
    cout << "3. Liberar ultimo proceso (LIFO)\n";
    cout << "4. Mostrar mapa de memoria\n";
    cout << "5. Liberar toda la memoria\n";
    cout << "6. Volver al Menu Principal\n";
    cout << "------------------------------------------\n";
}

int main() {
    GestorProcesos gestorProcesos;

    Pila memoriaSO;
    inicializarPila(memoriaSO);

    Cola cpuSO;
    inicializarCola(cpuSO);

    int op;
    do {
        mostrarMenu();
        op = leerEntero("Seleccione un modulo del sistema: ");

        switch(op) {

            case 1: { // MODULO DE LISTA ENLAZADA
                int op1;
                do {
                    mostrarSubMenu1();
                    op1 = leerEntero("Ingrese una opcion : ");
                    int id, prioridad, nuevaPrioridad;
                    string nombre;
                    switch(op1) {
                        case 1:
                            id        = leerEntero("ID del proceso: ");
                            nombre    = leerCadena("Nombre: ");
                            prioridad = leerEntero("Prioridad (1-10): ");
                            gestorProcesos.insertarProceso(id, nombre, prioridad);
                            break;
                        case 2:
                            id = leerEntero("ID del proceso a eliminar: ");
                            gestorProcesos.eliminarProceso(id);
                            break;
                        case 3:
                            id = leerEntero("ID a buscar: ");
                            gestorProcesos.buscarPorID(id);
                            break;
                        case 4:
                            id             = leerEntero("ID del proceso: ");
                            nuevaPrioridad = leerEntero("Nueva prioridad (1-10): ");
                            gestorProcesos.modificarPrioridad(id, nuevaPrioridad);
                            break;
                        case 5:
                            gestorProcesos.mostrarTodos();
                            break;
                        case 6:
                            cout << "\nRegresando al Menu Principal...\n"; break;
                        default:
                            cout << "\nOpcion invalida.\n"; break;
                    }
                } while(op1 != 6);
                break;
            }

            case 2: { // MODULO DE COLAS
                int op2;
                do {
                    mostrarSubMenu2();
                    op2 = leerEntero("Ingrese una opcion : ");
                    switch(op2) {
                        case 1: encolarProceso(cpuSO);    break;
                        case 2: desencolarProceso(cpuSO); break;
                        case 3: mostrarCola(cpuSO);       break;
                        case 4: ejecutarTodos(cpuSO);     break;
                        case 5: cout << "\nRegresando al Menu Principal...\n"; break;
                        default: cout << "\nOpcion invalida.\n"; break;
                    }
                } while(op2 != 5);
                break;
            }

            case 3: { // MODULO DE PILAS
                int op3;
                do {
                    mostrarSubMenu3();
                    op3 = leerEntero("Ingrese una opcion : ");
                    switch(op3) {
                        case 1: asignarMemoria(memoriaSO);       break;
                        case 2: buscarProcesoMemoria(memoriaSO); break;
                        case 3: liberarProceso(memoriaSO);       break;
                        case 4: mostrarEstadoMemoria(memoriaSO); break;
                        case 5: liberarTodo(memoriaSO);          break;
                        case 6: cout << "\nRegresando al Menu Principal...\n"; break;
                        default: cout << "\nOpcion invalida.\n"; break;
                    }
                } while(op3 != 6);
                break;
            }

            case 4:
                cout << "\nApagando sistema operativo simulado. Adios!\n";
                break;
            default:
                cout << "\nOpcion no valida, intente otra vez.\n";
                break;
        }

    } while(op != 4);

    return 0;
}