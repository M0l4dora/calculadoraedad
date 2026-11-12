# Calculadora de Edad — Actividad 1 (Python & C++)

Trabajo de revisión integral de la materia **Laboratorio de Programación (LPR)** — EEST N.º 1 “Eduardo Ader”, 5.º año, 3.ª división, grupos A-B (2026).

## Descripción

El programa calcula la **edad exacta** de una persona restando su año de nacimiento al año actual y ajustando el resultado si todavía no cumplió años en el año en curso.

Antes de calcular, se valida que la fecha ingresada exista realmente en el calendario:

- Rango admitido: años **1900 a 2026**.
- Meses de **1 a 12** y días de **1 a 31**.
- Meses de 30 días (abril, junio, septiembre, noviembre): no admiten día 31.
- **Febrero**: 28 días, o 29 si el año es bisiesto.
- La fecha de nacimiento **no puede ser posterior** a la fecha actual del ejercicio (08/07/2026).

La misma lógica está resuelta en los dos entornos para poder compararlos:

| Entorno | Archivo | Ejecución |
|---|---|---|
| Python | `proyecto_python/main.py` | `python main.py` |
| C++ | `proyecto_cpp/main.cpp` | compilar y ejecutar `main.cpp` |

## Estructura del proyecto

```
calculadoraedad/
├── .gitignore                          # evita subir archivos pesados y temporales
├── README.md                           # este archivo
├── LICENSE                             # licencia del proyecto
├── docs/
│   └── InformeProyectoCalculadoraEdad.pdf   # informe del proyecto (APA v7)
├── proyecto_cpp/
│   └── main.cpp                        # código en C++
└── proyecto_python/
    └── main.py                         # código en Python
```

## Cómo ejecutar

### Python

```bash
cd proyecto_python
python main.py
```

El programa acepta los tres valores en una misma línea (`20 10 2008`) o uno por línea, igual que la versión en C++.

### C++ (local, con MSYS2 / MinGW)

```bash
cd proyecto_cpp
g++ main.cpp -o main
./main
```

### C++ (OnlineGDB)

Si el equipo de la escuela no permite compilar, pegar el contenido de `main.cpp` en [OnlineGDB](https://www.onlinegdb.com/) (lenguaje C++), ejecutar y guardar las capturas de pantalla.

## Casos de prueba

Ejemplos para verificar el filtro de consistencia y el cálculo:

| Entrada (día/mes/año) | Resultado esperado |
|---|---|
| 29/02/2000 | Fecha válida (2000 es bisiesto) → edad calculada |
| 29/02/1900 | `[ERROR]` — 1900 no es bisiesto |
| 31/04/2000 | `[ERROR]` — abril tiene 30 días |
| 15/13/2000 | `[ERROR]` — mes inexistente |
| 01/01/1899 | `[ERROR]` — año fuera de rango |
| 01/12/2026 | `[ERROR]` — fecha posterior a la fecha actual |
| 20/10/2008 | 17 años (aún no cumplió en 2026) |
| 05/03/2008 | 18 años (ya cumplió en 2026) |

## Informe

El informe del proyecto se encuentra en `docs/InformeProyectoCalculadoraEdad.pdf`, con formato APA v7, y detalla objetivos, desarrollo, pruebas y comparación entre Python y C++.

## Licencia

Este proyecto se distribuye bajo la licencia MIT. Ver el archivo `LICENSE`.
