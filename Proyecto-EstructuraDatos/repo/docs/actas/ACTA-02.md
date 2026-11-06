# Acta de Reunión 02 — Revisión de avance: módulo de menú y lista enlazada

**Proyecto:** Sistema Operativo Simulado — Grupo 9
**Fecha:** miércoles 22 de octubre de 2026
**Hora:** 18:00 – 19:00
**Modalidad:** Virtual

## Asistentes

Jeremy P. V. (`JeremyPV-YOUSEFF`), Rey J. D. (`Rey23JD`),
_Integrante 3_, _Integrante 4_.

## Agenda

1. Demostración de `menu.h` y `libreria.h`.
2. Revisión del módulo de lista enlazada.
3. Casos borde detectados.
4. Estado de las ramas.

## Desarrollo

**1. Librería y menú (Jeremy).** Se muestra el menú principal y los tres
submenús funcionando. `leerEntero()` reintenta la lectura cuando el usuario
escribe letras, limpiando el buffer con `cin.clear()` y
`cin.ignore(numeric_limits<streamsize>::max(), '\n')`. El equipo aprueba el
enfoque porque evita el bucle infinito típico de `cin >> entero` cuando
falla la conversión.

**2. Lista enlazada (Rey).** Se revisa la clase `GestorProcesos`: inserción
al final, eliminación por ID contemplando el caso de la cabeza, búsqueda,
modificación de prioridad y listado con prioridad promedio.

**3. Observaciones de la revisión de pares.**
- *Observación 1 (Integrante 3):* si se inserta dos veces el mismo ID, el
  listado queda ambiguo al buscar. **Acción:** agregar el método privado
  `idExiste()` y rechazar la inserción duplicada. *(Rey — 23/10)*
- *Observación 2 (Integrante 4):* si el usuario ingresa una prioridad fuera
  del rango 1–10 se guardan valores sin sentido. **Acción:** validar el rango
  en `insertarProceso()` y en `modificarPrioridad()`. *(Rey — 23/10)*
- *Observación 3 (Jeremy):* el nombre del proceso no debe quedar vacío.
  **Acción:** validar `nombre.empty()`. *(Rey — 23/10)*

**4. Estado de las ramas.** `rama-menu` y `rama-gestor-de-procesos` están al
día. Se acuerda fusionar `rama-gestor-de-procesos` a `main` el 23/10 una vez
aplicadas las tres correcciones.

## Acuerdos

| # | Acuerdo | Responsable | Fecha |
|---|---|---|---|
| B1 | Implementar `idExiste()` y validaciones de rango y nombre | Rey | 23/10/2026 |
| B2 | Fusionar `rama-gestor-de-procesos` en `main` | Jeremy | 23/10/2026 |
| B3 | Iniciar `rama-planificador-cpu` desde `main` actualizado | Integrante 3 | 26/10/2026 |

## Riesgos identificados

* Retraso en el módulo de pila dinámica si no se libera correctamente la
  memoria (fugas por `delete` faltante). Se acuerda revisar el destructor y
  las funciones `liberarProceso()` / `liberarTodo()` en la revisión del 01/11.

## Próxima reunión

Miércoles 28 de octubre de 2026, 18:00.

---
*Acta redactada por Jeremy P. V., revisada por Rey J. D.*
