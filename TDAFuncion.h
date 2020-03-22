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
   \brief La biblioteca TDAFuncion es un TDA que representa una funci�n de tipo elemental:
    trigonom�trica (seno, coseno, tangente, arcoseno, arcocoseno, arcotangente), logar�tmica (logaritmo en base e), potencias del monomio x, la identidad, y su inversa (hip�rbola).
    Las identifica mediante las constantes definidas como "Codigo...", y las representa seg�n dos ejes cartesianos de tama�o definido por otras constantes. Adem�s se puede manejar el c�lculo de recorrido, m�ximos, m�nimos, y ra�ces de la funci�n.
   \author Marcos Dom�nguez Velad, para Tecnolog�a de la Programaci�n, UM, 2016.
*/

/**
    \brief Tipo de dato abstracto Funci�n
*/
typedef struct FuncionRep * Funcion;

/**
    \brief  Devuelve una funci�n asociada a un c�digo
    \param  Codigo Entero asociado a una funci�n elemental, que permite identificar la funci�n
    \return Retorna una nueva funci�n determinada con el c�digo correspondiente
*/
Funcion FuncionCrea (int Codigo);

/**
    \brief Libera la memoria asociada a una funci�n.
    \param f Funci�n a liberar.
*/
void FuncionLibera (Funcion f);


/**
    \brief Inicializa el recorrido de una funci�n en un intervalo, y se analiza en un documento.
    \pre f es distinto de NULL.
    \pre Intervalo es 3, 4, o 5.
    \param f Funci�n a inicializar.
    \param Intervalo Si vale 3, representa el [-1,1], si vale 4 el [-10,10], si vale 5 el [-100,100].
    \param doc_nombre Nombre del archivo donde se escribe el an�lisis.
*/
void FuncionInicializa (Funcion f, int Intervalo, char * doc_nombre);

/**
    \brief Inicializa la expresi�n que identifica la funci�n.
    \pre f es distinto de NULL.
    \param f Funci�n cuya expresi�n se va a calcular.
*/
void FuncionCalculaExpresion(Funcion f);

/**
    \brief Inicializa una lista que contiene el recorrido de la funci�n.
    \pre f es distinto de NULL.
    \param f Funci�n cuyo recorrido se va a calcular.
*/
void FuncionCalculaRecorrido (Funcion f, int Intervalo);


/**
    \brief Guarda el an�lisis de una funci�n inicializada en un intervalo, en un archivo concreto.
    \pre f es distinto de NULL.
    \pre Intervalo es 3, 4, o 5.
    \param f Funci�n a analizar.
    \param nombre Nombre del archivo donde se va a escribir.
    \param Intervalo Si vale 3, representa el [-1,1], si vale 4 el [-10,10], si vale 5 el [-100,100].

*/
void FuncionGuardaDatos (Funcion f, char * nombre, int Intervalo);

/**
    \brief Funci�n a representar.
    \pre f es distinto de NULL.
    \pre Intervalo debe ser 3, 4 o 5.
    \param f Funci�n a representar.
    \param Intervalo Si vale 3, representa el [-1,1], si vale 4 el [-10,10], si vale 5 el [-100,100].

*/
void FuncionRepresenta (Funcion f, int Intervalo);

/**
    \brief Devuelve la expresi�n que identifica a una funci�n.
    \pre f es distinto de NULL.
    \param f es la Funci�n cuya expresi�n devolvemos.
*/
char * FuncionExpresion (Funcion f);

/**
    \brief Devuelve la lista asociada al recorrido de una funci�n.
    \pre f es distinto de NULL.
    \param f Funci�n cuyo recorrido devolvemos.
*/
ListaDouble FuncionRecorrido (Funcion f);

/**
    \brief Devuelve una lista asociada a las ra�ces de una funci�n, en un intervalo definido por un extremo.
    \pre f es distinto de NULL.
    \pre Extremo debe ser 1, 10, o 100.
    \param f Funci�n cuyas ra�ces devolvemos.
    \param Extremo valor asociado, respectivamente a los intervalos [-1,1], [-10,10], [-100,100].
*/
ListaDouble Raices (Funcion f, double Extremo);

/**
    \brief Devuelve una lista asociada a los m�ximos (absolutos y relativos) de una funci�n, en un intervalo definido por un extremo.
    \pre f es distinto de NULL.
    \pre Extremo debe ser 1, 10, o 100.
    \param f Funci�n cuyos m�ximos devolvemos.
    \param Extremo valor asociado, respectivamente a los intervalos [-1,1], [-10,10], [-100,100].
*/
ListaDouble Maximos (Funcion f, double Extremo);

/**
    \brief Devuelve una lista asociada a los m�nimos (absolutos y relativos) de una funci�n, en un intervalo definido por un extremo.
    \pre f es distinto de NULL.
    \pre Extremo debe ser 1, 10, o 100.
    \param f Funci�n cuyos m�nimos devolvemos.
    \param Extremo valor asociado, respectivamente a los intervalos [-1,1], [-10,10], [-100,100].
*/
ListaDouble Minimos (Funcion f, double Extremo);

#endif // TDAFUNCION_H_
