# Acta de Reunión 04 — Cierre, integración y entrega

**Proyecto:** Sistema Operativo Simulado — Grupo 9
**Fecha:** miércoles 4 de noviembre de 2026
**Hora:** 18:00 – 19:30
**Modalidad:** Híbrida (presencial y virtual)

## Asistentes

Jeremy P. V. (`JeremyPV-YOUSEFF`), Rey J. D. (`Rey23JD`),
_Integrante 3_, _Integrante 4_.

## Agenda

1. Demostración de la versión integrada.
2. Ejecución de la batería de pruebas P1–P6.
3. Revisión del historial de Git.
4. Organización de la entrega del Capítulo 4.

## Desarrollo

**1. Demostración.** Se ejecuta el sistema completo: menú principal → tres
submenús → retorno al menú principal. Los tres módulos conviven sin
interferencias porque cada uno mantiene su propia estructura
(`GestorProcesos`, `Cola cpuSO`, `Pila memoriaSO`).

**2. Resultado de las pruebas.**

| # | Caso | Resultado |
|---|---|---|
| P1 | Prioridad 11 en el módulo 1 | ✅ Rechazado correctamente |
| P2 | ID repetido | ✅ Rechazado correctamente |
| P3 | Orden de la cola 3, 1, 5, 2 | ✅ 1, 2, 3, 5 |
| P4 | Ráfaga completa | ✅ Cola vacía al finalizar |
| P5 | Liberar LIFO | ✅ Se elimina el último proceso asignado |
| P6 | Liberar toda la memoria | ✅ Pila vacía |
| P7 | Entrada no numérica en el menú | ✅ Vuelve a pedir el dato sin ciclo infinito |

**3. Revisión del historial de Git.** Se verifica que existan commits de los
cuatro integrantes y una rama por módulo, y que `main` contenga todas las
fusiones. Se acuerda que las capturas de pantalla del Capítulo 4 se tomen de
ese historial.

**4. Entrega.** Se reparte la redacción del Capítulo 4: capturas del
repositorio (Jeremy), plan de trabajo y roles (Rey), cronograma (Integrante 3)
y compilación de las actas (Integrante 4).

## Acuerdos finales

| # | Acuerdo | Responsable | Fecha |
|---|---|---|---|
| D1 | Congelar el código de `main` (sólo correcciones críticas) | Todos | 04/11/2026 |
| D2 | Tomar las capturas del repositorio y del historial de ramas | Jeremy | 05/11/2026 |
| D3 | Redactar el Capítulo 4 y unificar el documento | Todos | 05/11/2026 |
| D4 | Publicar el enlace del repositorio en la entrega | Jeremy | 06/11/2026 |

## Lecciones aprendidas

* Dividir el código en cabeceras por módulo eliminó prácticamente los
  conflictos de fusión.
* La validación de entradas en una sola librería evitó duplicar código en
  los tres módulos.
* Las revisiones de pares detectaron cuatro errores de punteros que no
  aparecían en la ejecución normal, sólo en los casos borde.

## Cierre

Se da por concluido el proyecto, con el repositorio integrado, probado y
documentado. Entrega final: 06 de noviembre de 2026.

---
*Acta redactada por Jeremy P. V., aprobada por los cuatro integrantes.*
