# LÉAME — Proyecto Estructura de Datos (Grupo 9)

## Sistema Operativo Simulado

Simulador de un sistema operativo implementado en **C++** que integra tres
estructuras de datos lineales vistas en el curso:

| Módulo | Estructura de datos | Archivo |
|---|---|---|
| Gestor de Procesos | Lista simplemente enlazada | `gestor_procesos.h` |
| Planificador de CPU | Cola con prioridad | `planificador_cpu.h` |
| Gestor de Memoria | Pila dinámica (LIFO) | `gestor_memoria.h` |

El programa se controla mediante un menú principal y tres submenús
(`menu.h`), y todas las entradas del usuario se validan con las funciones
`leerEntero()` y `leerCadena()` de `libreria.h`.

---

## Estructura del repositorio

```
ProyectoED/
├── main.cpp                      # Punto de entrada e integración de módulos
├── libreria.h                    # Funciones de lectura y validación de datos
├── menu.h                        # Menú principal y submenús
├── gestor_procesos.h             # Módulo 1 - Lista enlazada
├── planificador_cpu.h            # Módulo 2 - Cola de prioridad
├── gestor_memoria.h              # Módulo 3 - Pila dinámica
├── versiones/
│   └── ProyectoED_unico.cpp      # Versión monolítica inicial (referencia)
├── docs/
│   ├── PLAN_DE_TRABAJO.md        # Roles y responsabilidades
│   ├── CRONOGRAMA.md             # Fechas límite de entregas parciales
│   ├── EVIDENCIAS.md             # Checklist del Capítulo 4
│   └── actas/
│       ├── ACTA-01.md            # Reunión de inicio / reparto de roles
│       ├── ACTA-02.md            # Revisión de avance módulo de menú
│       ├── ACTA-03.md            # Revisión de avance CPU y memoria
│       └── ACTA-04.md            # Reunión de cierre e integración
└── .gitignore
```

---

## Cómo compilar y ejecutar

Requiere un compilador de C++ (g++ 9 o superior).

```bash
# Clonar
git clone https://github.com/<usuario>/Proyecto-EstructuraDatos.git
cd Proyecto-EstructuraDatos

# Compilar
g++ -std=c++11 -Wall -o sistema main.cpp

# Ejecutar
./sistema        # Linux / macOS
sistema.exe      # Windows
```

Compilación en Windows con MinGW (equivalente en Dev-C++ / Code::Blocks):

```bash
g++ -std=c++11 -o sistema.exe main.cpp
```

---

## Uso del sistema

```
==========================================
    SISTEMA OPERATIVO SIMULADO (GRUPO 9)
==========================================
1. Gestor de Procesos (Lista Enlazada)
2. Planificador de CPU (Cola de Prioridad)
3. Gestor de Memoria (Pila Dinamica)
4. Salir del Sistema
```

**1. Gestor de Procesos** — insertar, eliminar, buscar por ID, modificar
prioridad (1–10) y listar todos los procesos con su prioridad promedio.

**2. Planificador de CPU** — encolar procesos ordenados por prioridad
(1 = máxima), ejecutar el siguiente proceso, ver la cola y ejecutar la
ráfaga completa.

**3. Gestor de Memoria** — asignar memoria a un proceso con N operaciones,
buscar un proceso, liberar el último proceso (LIFO), mostrar el mapa de
memoria y liberar toda la memoria.

---

## Equipo y roles

| Integrante | Usuario GitHub | Rol | Módulo asignado |
|---|---|---|---|
| Jeremy (coordinador) | `JeremyPV-YOUSEFF` | Líder de proyecto / integración | `main.cpp`, `menu.h`, `libreria.h` |
| Rey | `Rey23JD` | Desarrollo de estructura de datos | `gestor_procesos.h` |
| Integrante 3 | _completar_ | Desarrollo de estructura de datos | `planificador_cpu.h` |
| Integrante 4 | _completar_ | Desarrollo de estructura de datos | `gestor_memoria.h` |

> Los nombres y usuarios marcados como _completar_ deben reemplazarse por los
> datos reales antes de la entrega. Ver `docs/PLAN_DE_TRABAJO.md`.

---

## Flujo de trabajo con Git

El proyecto se desarrolló con una rama `main` estable y una rama por módulo,
fusionadas mediante *merge* al terminar cada funcionalidad:

| Rama | Propósito |
|---|---|
| `main` | Versión estable e integrada |
| `rama-menu` | Menú principal, submenús y lectura de datos |
| `rama-gestor-de-procesos` | Módulo de lista enlazada |
| `rama-planificador-cpu` | Módulo de cola de prioridad |
| `rama-gestor-memoria-procesos` | Módulo de pila dinámica |

Convención de mensajes de commit: `tipo(modulo): descripción`
(`feat`, `fix`, `docs`, `refactor`).

---

## Documentación del Capítulo 4

* Plan de trabajo y roles: [`docs/PLAN_DE_TRABAJO.md`](docs/PLAN_DE_TRABAJO.md)
* Cronograma de entregas: [`docs/CRONOGRAMA.md`](docs/CRONOGRAMA.md)
* Actas de reunión: [`docs/actas/`](docs/actas/)
* Checklist de evidencias: [`docs/EVIDENCIAS.md`](docs/EVIDENCIAS.md)
