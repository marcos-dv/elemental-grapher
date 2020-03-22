#ifndef TDAGRAFICO_H_
#define TDAGRAFICO_H_

#include "TDAFuncion.h"

/**
   \file TDAGrafico.h
   \brief Permite utilizar funciones para crear, insertar, liberar, o representar un gráfico, el cual tiene asociadas unas funciones representadas mediante el archivo 'TDAFuncion.h'.
   \author Marcos Domínguez Velad, para Tecnología de la Programación, UM, 2016.
*/

/**
    \brief Tipo de Dato Abstracto Gráfico.
*/
typedef struct GraficoRep * Grafico;

/**
    \brief Devuelve un nuevo gráfico vacío.
    \return Un gráfico vacío.
*/
Grafico GraficoCrea ();

/**
    \brief Inserta una nueva función en el gráfico.
    \pre g es distinto de NULL.
    \param g Gráfico donde insertar.
    \param f Función a insertar.
*/

void GraficoInserta (Grafico g, Funcion f);

/**
    \brief Suprime la última función asociada a un gráfico.
    \param g Gráfico donde se realiza la supresión.
*/
void GraficoEliminaPrimero (Grafico g);

/**
    \brief Libera la memoria asociada a un gráfico.
    \pre g es distinto de NULL.
    \param g Gráfico a liberar.
*/
void GraficoLibera (Grafico g);

/**
    \brief Representa todas las funciones asociadas a un gráfico.
    \pre Intervalo debe ser 3, 4 o 5.
    \param g Gráfico a representar.
    \param Intervalo Si es 3, representa en el intervalo (-1, 1); si es 4, (-10, 10); si es 5, (-100,100).
*/

void GraficoRepresenta (Grafico g, int Intervalo);

#endif // TDAGRAFICO_H_
