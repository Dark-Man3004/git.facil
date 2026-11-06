# Cronograma de Entregas Parciales

**Proyecto:** Sistema Operativo Simulado — Grupo 9
**Inicio:** 12 de octubre de 2026
**Fecha de entrega final:** 06 de noviembre de 2026

---

## 1. Hitos principales

| Hito | Descripción | Fecha límite | Estado |
|---|---|---|---|
| H0 | Reunión de inicio, reparto de roles y creación del repositorio | 12/10/2026 | ✅ Cumplido |
| H1 | Módulo base: librería de entrada y menú principal funcionando | 17/10/2026 | ✅ Cumplido |
| H2 | Módulo 1 — Gestor de Procesos (lista enlazada) fusionado a `main` | 23/10/2026 | ✅ Cumplido |
| H3 | Módulo 2 — Planificador de CPU (cola de prioridad) fusionado a `main` | 29/10/2026 | ✅ Cumplido |
| H4 | Módulo 3 — Gestor de Memoria (pila dinámica) fusionado a `main` | 02/11/2026 | ✅ Cumplido |
| H5 | Integración final, pruebas y corrección de errores | 04/11/2026 | ✅ Cumplido |
| H6 | Documentación del Capítulo 4, actas y presentación | 06/11/2026 | ✅ Cumplido |

## 2. Cronograma por semana

### Semana 1 — 12/10 al 18/10 · Planificación y entorno
| Fecha | Actividad | Responsable |
|---|---|---|
| Lun 12/10 | Reunión de inicio: alcance, roles y acuerdos (Acta 01) | Todos |
| Mar 13/10 | Creación del repositorio, `.gitignore` y `LÉAME.md` inicial | Jeremy |
| Mié 14/10 | Diseño de la arquitectura modular y convención de commits | Jeremy |
| Jue 15/10 | Implementación de `libreria.h` (validación de enteros y cadenas) | Jeremy |
| Vie 17/10 | Implementación de `menu.h` y esqueleto de `main.cpp` | Jeremy |

### Semana 2 — 19/10 al 25/10 · Estructuras enlazadas
| Fecha | Actividad | Responsable |
|---|---|---|
| Lun 20/10 | Diseño del `struct NodoProceso` y de la clase `GestorProcesos` | Rey |
| Mié 22/10 | Revisión de avance (Acta 02): validaciones y casos borde | Todos |
| Jue 23/10 | Merge de `rama-gestor-de-procesos` a `main` | Jeremy / Rey |
| Vie 24/10 | Pruebas del módulo 1: ID duplicado, prioridad fuera de rango | Rey |

### Semana 3 — 26/10 al 01/11 · Cola y pila dinámica
| Fecha | Actividad | Responsable |
|---|---|---|
| Lun 26/10 | Implementación de `NodoCola`, `Cola` y `encolarProceso` ordenado | Integrante 3 |
| Mié 28/10 | Implementación de `Pila`, `Proceso` y `asignarMemoria` | Integrante 4 |
| Jue 29/10 | Merge de `rama-planificador-cpu` a `main` | Jeremy |
| Vie 30/10 | Implementación de `liberarProceso`, `buscarProcesoMemoria`, `liberarTodo` | Integrante 4 |
| Dom 01/11 | Revisión de avance (Acta 03) y pruebas cruzadas | Todos |

### Semana 4 — 02/11 al 06/11 · Integración y entrega
| Fecha | Actividad | Responsable |
|---|---|---|
| Lun 02/11 | Merge de `rama-gestor-memoria-procesos` a `main` | Jeremy |
| Mar 03/11 | Integración de los tres módulos en `main.cpp` | Jeremy |
| Mié 04/11 | Pruebas integrales y corrección de errores (Acta 04) | Todos |
| Jue 05/11 | Redacción del Capítulo 4 y capturas de pantalla | Todos |
| Vie 06/11 | Entrega final del repositorio y presentación | Todos |

## 3. Diagrama de avance (Gantt simplificado)

```
                  Sem1    Sem2    Sem3    Sem4
Planificación     ████
Repositorio       ████
Librería + menú   ██████
Lista enlazada            ██████
Cola de prioridad                 ██████
Pila dinámica                     ██████
Integración                               ████
Documentación                     ██████████████
```

## 4. Registro de cumplimiento

Todas las entregas parciales se cumplieron dentro del plazo previsto. Los
ajustes respecto de la planificación inicial fueron:

| Cambio | Motivo | Fecha de decisión |
|---|---|---|
| Se dividió `ProyectoED.cpp` en archivos `.h` por módulo | Evitar conflictos de fusión al trabajar en paralelo | 14/10/2026 (Acta 01) |
| Se agregó validación de ID duplicado en el módulo 1 | Detectado en la revisión de pares del 22/10 | 22/10/2026 (Acta 02) |
| La copia de `Proceso` se movió al constructor de la pila | Corregir doble puntero `sge` al asignar memoria | 01/11/2026 (Acta 03) |
