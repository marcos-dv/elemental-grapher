#ifndef TDAGRAFICO_H_
#define TDAGRAFICO_H_

#include "TDAFuncion.h"

/**
   \file TDAGrafico.h
   \brief Permite utilizar funciones para crear, insertar, liberar, o representar un gr�fico, el cual tiene asociadas unas funciones representadas mediante el archivo 'TDAFuncion.h'.
   \author Marcos Dom�nguez Velad, para Tecnolog�a de la Programaci�n, UM, 2016.
*/

/**
    \brief Tipo de Dato Abstracto Gr�fico.
*/
typedef struct GraficoRep * Grafico;

/**
    \brief Devuelve un nuevo gr�fico vac�o.
    \return Un gr�fico vac�o.
*/
Grafico GraficoCrea ();

/**
    \brief Inserta una nueva funci�n en el gr�fico.
    \pre g es distinto de NULL.
    \param g Gr�fico donde insertar.
    \param f Funci�n a insertar.
*/

void GraficoInserta (Grafico g, Funcion f);

/**
    \brief Suprime la �ltima funci�n asociada a un gr�fico.
    \param g Gr�fico donde se realiza la supresi�n.
*/
void GraficoEliminaPrimero (Grafico g);

/**
    \brief Libera la memoria asociada a un gr�fico.
    \pre g es distinto de NULL.
    \param g Gr�fico a liberar.
*/
void GraficoLibera (Grafico g);

/**
    \brief Representa todas las funciones asociadas a un gr�fico.
    \pre Intervalo debe ser 3, 4 o 5.
    \param g Gr�fico a representar.
    \param Intervalo Si es 3, representa en el intervalo (-1, 1); si es 4, (-10, 10); si es 5, (-100,100).
*/

void GraficoRepresenta (Grafico g, int Intervalo);

#endif // TDAGRAFICO_H_
