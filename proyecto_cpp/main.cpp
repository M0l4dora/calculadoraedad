/*
Materia: Laboratorio de Programación (LPR)
Archivo: main.cpp
Resolución de la Actividad 1 - Entorno C++
*/

#include <iostream>

using namespace std;

// 1. Evalúa si un año es bisiesto
bool esBisiesto(int anio)
{
    return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
}

// 2. Filtro de consistencia de calendario
bool esFechaValida(int d, int m, int a)
{
    if (a < 1900 || a > 2026)
        return false;
    if (m < 1 || m > 12)
        return false;
    if (d < 1 || d > 31)
        return false;

    // Meses de 30 días
    if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30)
        return false;

    // Caso especial de Febrero
    if (m == 2)
    {
        if (esBisiesto(a))
        {
            if (d > 29)
                return false;
        }
        else
        {
            if (d > 28)
                return false;
        }
    }

    return true;
}

// 3. Filtro: la fecha de nacimiento no puede ser posterior a la fecha actual
bool esFechaFutura(int d, int m, int a, int diaActual, int mesActual, int anioActual)
{
    if (a > anioActual)
        return true;
    if (a == anioActual && m > mesActual)
        return true;
    if (a == anioActual && m == mesActual && d > diaActual)
        return true;
    return false;
}

int main()
{
    int diaN, mesN, anioN;
    int diaA = 12, mesA = 11, anioA = 2026; // Fecha actual para el ejercicio

    cout << "=====================================================" << endl;
    cout << "  CALCULADORA DE EDAD                " << endl;
    cout << "=====================================================" << endl;

    cout << "Ingrese Dia, Mes y Anio de nacimiento (separados por espacios): ";
    cin >> diaN >> mesN >> anioN;

    if (!esFechaValida(diaN, mesN, anioN))
    {
        cout << "[ERROR] La fecha ingresada no existe en el calendario." << endl;
        return 1;
    }

    if (esFechaFutura(diaN, mesN, anioN, diaA, mesA, anioA))
    {
        cout << "[ERROR] La fecha de nacimiento no puede ser posterior a la fecha actual." << endl;
        return 1;
    }

    int edad = anioA - anioN;

    // RESOLUCIÓN: Ajuste si aún no cumplió años en el año actual
    if (mesA < mesN || (mesA == mesN && diaA < diaN))
    {
        edad--;
    }

    cout << "\n[SISTEMA] Fecha de hoy: " << diaA << "/" << mesA << "/" << anioA << endl;
    cout << "[SISTEMA] Edad calculada: " << edad << " anios." << endl;
    cout << "=====================================================" << endl;

    return 0;
}
