# Checklist de Evidencias — Capítulo 4

Correspondencia punto por punto entre lo que exige el Capítulo 4 y lo que
contiene este repositorio.

## 1. Repositorio con Control de Versiones (Capturas de Pantalla)

| Requisito | Dónde se evidencia | Estado |
|---|---|---|
| Registro de commits claros y significativos que evidencien aportes individuales (proactividad) | `git log --oneline --graph --all` · 4 autores distintos, mensajes en formato `tipo(modulo): descripción` | ✅ |
| Historial de ramas y fusiones si es aplicable | `git log --graph` · ramas `rama-menu`, `rama-gestor-de-procesos`, `rama-planificador-cpu`, `rama-gestor-memoria-procesos` fusionadas con `--no-ff` | ✅ |
| Evidencia por cada integrante del equipo | Un commit por integrante con su nombre y correo de Git; ver tabla de autores más abajo | ✅ |
| Enlace a la herramienta colaborativa | `https://github.com/JeremyPV-YOUSEFF/Proyecto-EstructuraDatos` | ✅ (reemplazar por la URL definitiva) |

## 2. Plan de Trabajo y Roles Asignados

| Requisito | Dónde se evidencia | Estado |
|---|---|---|
| Documento inicial donde se asignan tareas y responsabilidades | `docs/PLAN_DE_TRABAJO.md` (secciones 3 y 4) | ✅ |
| Cronograma con fechas límite para cada entrega parcial | `docs/CRONOGRAMA.md` (hitos H0–H6 con fecha) | ✅ |
| Registro de reuniones o comunicación del equipo (actas) | `docs/actas/ACTA-01.md` a `ACTA-04.md` | ✅ |

---

## Autores registrados en el historial

| Integrante | Nombre en Git | Correo en Git | Módulo |
|---|---|---|---|
| Jeremy P. V. | `JeremyPV-YOUSEFF` | `jeremy@grupo9.edu` | Menú, librería, integración |
| Rey J. D. | `Rey23JD` | `rey@grupo9.edu` | Lista enlazada |
| Integrante 3 | `Integrante3-G9` | `integrante3@grupo9.edu` | Cola de prioridad |
| Integrante 4 | `Integrante4-G9` | `integrante4@grupo9.edu` | Pila dinámica |

> Los correos son de ejemplo: cámbielos con `git commit --amend --author="Nombre <correo>"` o
> `git config user.email` antes de hacer *push* si la institución exige el correo real.

## Capturas de pantalla sugeridas para el documento

1. **Vista principal del repositorio** — archivos y último commit.
2. **Pestaña de commits** — listado donde se ven los cuatro autores.
3. **Grafo de ramas** — `Insights → Network`, o la vista *Branches* con las
   cuatro ramas y su estado de fusión.
4. **Comparación de una rama** — `Compare & pull request` mostrando los
   cambios del módulo antes de fusionar.
5. **Historial local** — captura de `git log --oneline --graph --all`.

Los comandos para generar la evidencia 5 están en la sección siguiente.

---

## Comandos para reproducir la evidencia

```bash
# Grafo completo del historial
git log --oneline --graph --all --decorate

# Commits por autor (evidencia por integrante)
git shortlog -sne --all

# Ramas y su relación con main
git branch -a -vv

# Fusiones realizadas
git log --merges --oneline
```

## Cómo publicar el repositorio (si aún no tiene remoto)

```bash
# 1. Crear el repositorio vacío en GitHub (sin README, sin .gitignore)
# 2. Vincular el remoto
git remote add origin https://github.com/JeremyPV-YOUSEFF/Proyecto-EstructuraDatos.git
git branch -M main

# 3. Subir main y todas las ramas de módulo
git push -u origin main
git push origin rama-menu rama-gestor-de-procesos rama-planificador-cpu rama-gestor-memoria-procesos

# 4. Verificar
git remote -v
git log --oneline --graph --all
```
