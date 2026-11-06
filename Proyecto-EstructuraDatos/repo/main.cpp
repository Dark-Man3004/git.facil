#include "libreria.h"
#include "gestor_procesos.h"
#include "planificador_cpu.h"
#include "gestor_memoria.h"
#include "menu.h"

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
