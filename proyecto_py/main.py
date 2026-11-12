# Materia: Laboratorio de Programación (LPR)
# Archivo: main.py
# Resolución de la Actividad 1 - Entorno Python


def es_bisiesto(anio):
    return (anio % 4 == 0 and anio % 100 != 0) or (anio % 400 == 0)


def es_fecha_valida(d, m, a):
    if a < 1900 or a > 2026:
        return False
    if m < 1 or m > 12:
        return False
    if d < 1 or d > 31:
        return False

    # Meses de 30 días
    if m in [4, 6, 9, 11] and d > 30:
        return False

    # Caso especial de Febrero
    if m == 2:
        if es_bisiesto(a):
            if d > 29:
                return False
        else:
            if d > 28:
                return False

    return True


def es_fecha_futura(d, m, a, dia_actual, mes_actual, anio_actual):
    if a > anio_actual:
        return True
    if a == anio_actual and m > mes_actual:
        return True
    if a == anio_actual and m == mes_actual and d > dia_actual:
        return True
    return False


def pedir_fecha():
    """Lee día, mes y año. Acepta los tres valores en una línea o uno por línea."""
    datos = []
    while len(datos) < 3:
        partes = input("Ingrese Dia, Mes y Anio de nacimiento (separados por espacios): ").split()
        for parte in partes:
            datos.append(int(parte))  # Lanza ValueError si no es un número entero
    return datos[0], datos[1], datos[2]


# Código principal
print("=====================================================")
print("  CALCULADORA EN PYTHON DE: Din Djarin                ")
print("=====================================================")

try:
    diaN, mesN, anioN = pedir_fecha()

    diaA, mesA, anioA = 8, 7, 2026

    if not es_fecha_valida(diaN, mesN, anioN):
        print("[ERROR] La fecha ingresada no es valida.")
    elif es_fecha_futura(diaN, mesN, anioN, diaA, mesA, anioA):
        print("[ERROR] La fecha de nacimiento no puede ser posterior a la fecha actual.")
    else:
        edad = anioA - anioN

        # RESOLUCIÓN: Ajuste si aún no cumplió años en el año actual
        if mesA < mesN or (mesA == mesN and diaA < diaN):
            edad -= 1

        print(f"\n[SISTEMA] Fecha de hoy: {diaA}/{mesA}/{anioA}")
        print(f"[SISTEMA] Edad calculada: {edad} años.")

except ValueError:
    print("[ERROR] Deben ingresar numeros enteros.")
