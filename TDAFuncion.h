#ifndef TDAFUNCION_H_
#define TDAFUNCION_H_
#include "TDAListaDouble.h"
#include "Pantalla.h"

#define CodigoSeno          20
#define CodigoCoseno        21
#define CodigoTangente      22
#define CodigoArcoSeno      23
#define CodigoArcoCoseno    24
#define CodigoArcoTangente  25
#define CodigoLogaritmo     30
#define CodigoInversa       41
#define CodigoIdentidad     40
#define CodigoBorra         -1

#define LetraAlto 13
#define LetraAncho 8

#define EjeXLargo 500
#define EjeYAlto 500

/**
   \file TDAFuncion.h
   \brief La biblioteca TDAFuncion es un TDA que representa una función de tipo elemental:
    trigonométrica (seno, coseno, tangente, arcoseno, arcocoseno, arcotangente), logarítmica (logaritmo en base e), potencias del monomio x, la identidad, y su inversa (hipérbola).
    Las identifica mediante las constantes definidas como "Codigo...", y las representa según dos ejes cartesianos de tamaño definido por otras constantes. Además se puede manejar el cálculo de recorrido, máximos, mínimos, y raíces de la función.
   \author Marcos Domínguez Velad, para Tecnología de la Programación, UM, 2016.
*/

/**
    \brief Tipo de dato abstracto Función
*/
typedef struct FuncionRep * Funcion;

/**
    \brief  Devuelve una función asociada a un código
    \param  Codigo Entero asociado a una función elemental, que permite identificar la función
    \return Retorna una nueva función determinada con el código correspondiente
*/
Funcion FuncionCrea (int Codigo);

/**
    \brief Libera la memoria asociada a una función.
    \param f Función a liberar.
*/
void FuncionLibera (Funcion f);


/**
    \brief Inicializa el recorrido de una función en un intervalo, y se analiza en un documento.
    \pre f es distinto de NULL.
    \pre Intervalo es 3, 4, o 5.
    \param f Función a inicializar.
    \param Intervalo Si vale 3, representa el [-1,1], si vale 4 el [-10,10], si vale 5 el [-100,100].
    \param doc_nombre Nombre del archivo donde se escribe el análisis.
*/
void FuncionInicializa (Funcion f, int Intervalo, char * doc_nombre);

/**
    \brief Inicializa la expresión que identifica la función.
    \pre f es distinto de NULL.
    \param f Función cuya expresión se va a calcular.
*/
void FuncionCalculaExpresion(Funcion f);

/**
    \brief Inicializa una lista que contiene el recorrido de la función.
    \pre f es distinto de NULL.
    \param f Función cuyo recorrido se va a calcular.
*/
void FuncionCalculaRecorrido (Funcion f, int Intervalo);


/**
    \brief Guarda el análisis de una función inicializada en un intervalo, en un archivo concreto.
    \pre f es distinto de NULL.
    \pre Intervalo es 3, 4, o 5.
    \param f Función a analizar.
    \param nombre Nombre del archivo donde se va a escribir.
    \param Intervalo Si vale 3, representa el [-1,1], si vale 4 el [-10,10], si vale 5 el [-100,100].

*/
void FuncionGuardaDatos (Funcion f, char * nombre, int Intervalo);

/**
    \brief Función a representar.
    \pre f es distinto de NULL.
    \pre Intervalo debe ser 3, 4 o 5.
    \param f Función a representar.
    \param Intervalo Si vale 3, representa el [-1,1], si vale 4 el [-10,10], si vale 5 el [-100,100].

*/
void FuncionRepresenta (Funcion f, int Intervalo);

/**
    \brief Devuelve la expresión que identifica a una función.
    \pre f es distinto de NULL.
    \param f es la Función cuya expresión devolvemos.
*/
char * FuncionExpresion (Funcion f);

/**
    \brief Devuelve la lista asociada al recorrido de una función.
    \pre f es distinto de NULL.
    \param f Función cuyo recorrido devolvemos.
*/
ListaDouble FuncionRecorrido (Funcion f);

/**
    \brief Devuelve una lista asociada a las raíces de una función, en un intervalo definido por un extremo.
    \pre f es distinto de NULL.
    \pre Extremo debe ser 1, 10, o 100.
    \param f Función cuyas raíces devolvemos.
    \param Extremo valor asociado, respectivamente a los intervalos [-1,1], [-10,10], [-100,100].
*/
ListaDouble Raices (Funcion f, double Extremo);

/**
    \brief Devuelve una lista asociada a los máximos (absolutos y relativos) de una función, en un intervalo definido por un extremo.
    \pre f es distinto de NULL.
    \pre Extremo debe ser 1, 10, o 100.
    \param f Función cuyos máximos devolvemos.
    \param Extremo valor asociado, respectivamente a los intervalos [-1,1], [-10,10], [-100,100].
*/
ListaDouble Maximos (Funcion f, double Extremo);

/**
    \brief Devuelve una lista asociada a los mínimos (absolutos y relativos) de una función, en un intervalo definido por un extremo.
    \pre f es distinto de NULL.
    \pre Extremo debe ser 1, 10, o 100.
    \param f Función cuyos mínimos devolvemos.
    \param Extremo valor asociado, respectivamente a los intervalos [-1,1], [-10,10], [-100,100].
*/
ListaDouble Minimos (Funcion f, double Extremo);

#endif // TDAFUNCION_H_
