# Acta de Reunión 03 — Revisión de avance: CPU y memoria

**Proyecto:** Sistema Operativo Simulado — Grupo 9
**Fecha:** domingo 1 de noviembre de 2026
**Hora:** 17:00 – 18:10
**Modalidad:** Virtual

## Asistentes

Jeremy P. V. (`JeremyPV-YOUSEFF`), Rey J. D. (`Rey23JD`),
_Integrante 3_, _Integrante 4_.

## Agenda

1. Revisión del módulo planificador de CPU.
2. Revisión del módulo gestor de memoria.
3. Corrección de errores detectados en las pruebas cruzadas.
4. Plan de integración final.

## Desarrollo

**1. Cola de prioridad (Integrante 3).** La cola se implementa con dos
punteros, `Frente` y `Final`, y un contador `Tamano`. `encolarProceso()`
inserta de forma ordenada recorriendo la cola mientras la prioridad del
siguiente nodo sea menor o igual a la del nuevo, de modo que el frente
siempre contiene la prioridad más baja numéricamente (= máxima prioridad).
Se prueba con la secuencia de prioridades `3, 1, 5, 2` y se obtiene
`1 → 2 → 3 → 5`. **Aprobado.**

**2. Pila dinámica (Integrante 4).** Se revisa `asignarMemoria()`, que
registra un proceso con N operaciones (1–100) y acumula el espacio total en
bytes; `mostrarEstadoMemoria()` marca la cima de la pila; `liberarProceso()`
aplica LIFO y `liberarTodo()` vacía la pila por completo.

**3. Errores encontrados y corregidos.**
- *Error 1 (crítico):* al crear el nodo con `new Proceso(pr)` el constructor
  copiaba `sge` del objeto original, generando un puntero colgante cuando el
  proceso no era el último. **Ajuste:** el constructor de copia inicializa
  `sge = NULL` explícitamente.
- *Error 2:* `p.Tamano` no se incrementaba cuando la pila estaba vacía al
  asignar el primer proceso. **Ajuste:** se unificó el incremento del
  contador en todas las ramas.
- *Error 3:* `liberarProceso()` no reiniciaba `Inicio` y `Final` al eliminar
  el último elemento, dejando punteros inválidos. **Ajuste:** se asignan en
  `NULL` al vaciar la pila.
- *Error 4:* `buscarProcesoMemoria()` necesitaba una `Pila` temporal para
  reutilizar `mostrarEstadoMemoria()` sin mostrar los procesos siguientes.
  Se valida que la `Pila` temporal se inicialice siempre antes de usarse.

**4. Plan de integración.** Cada rama se fusionará a `main` en el orden
menú → procesos → CPU → memoria. Jeremy integrará las llamadas en
`main.cpp` y compilará con `-Wall` para detectar advertencias.

## Acuerdos

| # | Acuerdo | Responsable | Fecha |
|---|---|---|---|
| C1 | Aplicar las cuatro correcciones del módulo de memoria | Integrante 4 | 02/11/2026 |
| C2 | Fusionar `rama-planificador-cpu` en `main` | Jeremy | 02/11/2026 |
| C3 | Fusionar `rama-gestor-memoria-procesos` en `main` | Jeremy | 02/11/2026 |
| C4 | Integrar los tres módulos en `main.cpp` | Jeremy | 03/11/2026 |

## Pruebas acordadas para la integración

| # | Caso de prueba | Resultado esperado |
|---|---|---|
| P1 | Insertar proceso con prioridad 11 | Mensaje de error, no se inserta |
| P2 | Insertar ID repetido | Mensaje de error, no se inserta |
| P3 | Encolar prioridades 3, 1, 5, 2 | Orden resultante 1, 2, 3, 5 |
| P4 | Ejecutar ráfaga completa | La cola queda vacía |
| P5 | Asignar dos procesos y liberar uno | Se libera el último (LIFO) |
| P6 | Liberar toda la memoria | Pila vacía, sin fugas |

---
*Acta redactada por Jeremy P. V., revisada por los cuatro integrantes.*
