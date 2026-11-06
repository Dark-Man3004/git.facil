# Plan de Trabajo y Roles Asignados

**Proyecto:** Sistema Operativo Simulado — Estructura de Datos
**Grupo:** 9
**Repositorio:** https://github.com/JeremyPV-YOUSEFF/Proyecto-EstructuraDatos
**Periodo de ejecución:** 12 de octubre de 2026 – 06 de noviembre de 2026
**Última actualización:** 06 de noviembre de 2026

---

## 1. Objetivo del proyecto

Desarrollar un programa en C++ que simule la administración básica de un
sistema operativo, implementando de forma manual —sin usar la biblioteca
estándar de contenedores— tres estructuras de datos lineales: **lista
simplemente enlazada**, **cola con prioridad** y **pila dinámica**.

## 2. Alcance

| Módulo | Funcionalidades comprometidas |
|---|---|
| Gestor de Procesos | Insertar, eliminar, buscar por ID, modificar prioridad, listar con prioridad promedio |
| Planificador de CPU | Encolar por prioridad, desencolar/ejecutar, mostrar cola, ejecutar ráfaga completa |
| Gestor de Memoria | Asignar memoria con N operaciones, buscar proceso, liberar LIFO, mostrar mapa, liberar todo |
| Menú e interfaz | Menú principal, tres submenús, validación de entradas numéricas y de texto |

**Fuera de alcance:** persistencia en archivos, interfaz gráfica, hilos,
planificación multinivel.

## 3. Integrantes y roles

| # | Integrante | Usuario GitHub | Rol principal | Responsabilidades concretas |
|---|---|---|---|---|
| 1 | Jeremy P. V. | `JeremyPV-YOUSEFF` | **Coordinador / líder técnico** | Definir la arquitectura modular, mantener la rama `main`, crear `libreria.h` y `menu.h`, revisar los *pull request* de cada módulo, integrar todo en `main.cpp`, compilar y liberar la versión final |
| 2 | Rey J. D. | `Rey23JD` | **Desarrollador — lista enlazada** | Diseñar el `struct NodoProceso`, implementar la clase `GestorProcesos` (insertar, eliminar, buscar, modificar prioridad, mostrar), validar el ID duplicado y el rango de prioridad |
| 3 | _Integrante 3_ | _completar_ | **Desarrollador — cola de prioridad** | Implementar `NodoCola`, `Cola`, `encolarProceso`, `desencolarProceso`, `mostrarCola` y `ejecutarTodos` con inserción ordenada por prioridad |
| 4 | _Integrante 4_ | _completar_ | **Desarrollador — pila dinámica** | Implementar `Operacion`, `Proceso`, `Pila`, `asignarMemoria`, `mostrarEstadoMemoria`, `liberarProceso`, `buscarProcesoMemoria` y `liberarTodo` (LIFO) |

> **Nota de entrega:** los campos _Integrante 3_ / _Integrante 4_ deben
> completarse con nombre y usuario real de GitHub para que la evidencia de
> commits por integrante quede trazable.

## 4. Desglose de tareas (WBS)

| ID | Tarea | Responsable | Entregable |
|---|---|---|---|
| T1 | Reunión de inicio y reparto de roles | Todos | Acta 01 |
| T2 | Creación del repositorio y `.gitignore` | Jeremy | Repo + commit `Compromiso inicial` |
| T3 | Ramas de trabajo por módulo | Todos | 4 ramas remotas |
| T4 | Librería de entrada y menús | Jeremy | `libreria.h`, `menu.h` |
| T5 | Módulo lista enlazada | Rey | `gestor_procesos.h` |
| T6 | Módulo cola de prioridad | Integrante 3 | `planificador_cpu.h` |
| T7 | Módulo pila dinámica | Integrante 4 | `gestor_memoria.h` |
| T8 | Integración en `main.cpp` | Jeremy | `main.cpp` compilando |
| T9 | Pruebas funcionales y corrección de errores | Todos | Registro de pruebas |
| T10 | Documentación y presentación final | Todos | LÉAME + Capítulo 4 |

## 5. Criterios de aceptación

1. El proyecto compila sin errores con `g++ -std=c++11 -Wall`.
2. Cada módulo es accesible desde el menú y funciona de forma independiente.
3. No se usan `std::list`, `std::queue` ni `std::stack`: las estructuras se
   implementan manualmente con punteros.
4. Existe al menos un commit por integrante y una rama por módulo.
5. La documentación permite a un tercero descargar, compilar y ejecutar.

## 6. Acuerdos de trabajo

* **Ramas:** cada integrante trabaja en su propia rama y fusiona a `main`
  sólo con la revisión del coordinador.
* **Commits:** mensajes en formato `tipo(modulo): descripción`
  (`feat`, `fix`, `docs`, `refactor`), en presente y en español.
* **Reuniones:** miércoles de cada semana, 60 minutos, con acta registrada
  en `docs/actas/`.
* **Comunicación diaria:** grupo de WhatsApp del equipo; los acuerdos
  técnicos se confirman siempre en el repositorio.
* **Revisión entre pares:** ningún módulo se fusiona sin que otro integrante
  lo haya compilado y probado.
