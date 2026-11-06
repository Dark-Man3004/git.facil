# Acta de Reunión 01 — Reunión de inicio

**Proyecto:** Sistema Operativo Simulado — Estructura de Datos
**Grupo:** 9
**Fecha:** lunes 12 de octubre de 2026
**Hora:** 18:00 – 19:05 (60 min)
**Modalidad:** Virtual (videollamada)

## Asistentes

| Integrante | Usuario GitHub | Asistencia |
|---|---|---|
| Jeremy P. V. | `JeremyPV-YOUSEFF` | Presente |
| Rey J. D. | `Rey23JD` | Presente |
| _Integrante 3_ | _completar_ | Presente |
| _Integrante 4_ | _completar_ | Presente |

## Agenda

1. Lectura de la consigna del proyecto.
2. Definición del alcance y de los módulos.
3. Reparto de roles y responsabilidades.
4. Acuerdos de trabajo con Git.
5. Fijación del cronograma.

## Desarrollo

**1. Alcance.** Se acuerda implementar un simulador de sistema operativo con
tres módulos independientes: gestor de procesos (lista enlazada),
planificador de CPU (cola con prioridad) y gestor de memoria (pila dinámica).
Se descarta la interfaz gráfica y la persistencia en archivos por falta de
tiempo dentro del plazo de entrega.

**2. Arquitectura.** Jeremy propone no concentrar todo el código en un único
`ProyectoED.cpp`, sino dividirlo en una cabecera por módulo (`gestor_procesos.h`,
`planificador_cpu.h`, `gestor_memoria.h`) más `libreria.h` y `menu.h`. El
objetivo es que cada integrante pueda trabajar en paralelo sin conflictos de
fusión. **Se aprueba por unanimidad.**

**3. Reparto de roles.** Se asigna un módulo por integrante (ver
`docs/PLAN_DE_TRABAJO.md`). Jeremy queda como coordinador y responsable de la
integración en `main`; Rey asume la lista enlazada.

**4. Acuerdos de Git.**
- Una rama por módulo, nombrada `rama-<modulo>`.
- Mensajes de commit en formato `tipo(modulo): descripción`.
- Ningún merge a `main` sin revisión de otro integrante.
- Prohibido subir archivos compilados (`.exe`, `.o`, `.gch`): se agrega
  `.gitignore` en el primer commit.

**5. Cronograma.** Se fijan los hitos H0–H6 con entrega final el 06/11/2026
y reuniones de seguimiento los miércoles.

## Acuerdos y compromisos

| # | Acuerdo | Responsable | Fecha límite |
|---|---|---|---|
| A1 | Crear el repositorio y el `.gitignore` | Jeremy | 13/10/2026 |
| A2 | Crear las cuatro ramas de trabajo | Todos | 14/10/2026 |
| A3 | Entregar `libreria.h` y `menu.h` | Jeremy | 17/10/2026 |
| A4 | Entregar el diseño del `NodoProceso` | Rey | 20/10/2026 |

## Próxima reunión

Miércoles 22 de octubre de 2026, 18:00 — revisión de avance del módulo 1.

---
*Acta redactada por Jeremy P. V. y aprobada por los cuatro integrantes.*
