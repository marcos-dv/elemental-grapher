#ifndef __TDAListaDouble_H__
#define __TDAListaDouble_H__

/**
   \file TDAListaDouble.h
   \brief Permite utilizar multitud de funciones b�sicas para el manejo de listas, con datos de tipo double.
   \author Marcos Dom�nguez Velad, para Tecnolog�a de la Programaci�n, UM, 2016.
*/
/**
    \brief Tipo de Dato Abstracto ListaDouble
*/
typedef struct ListaDoubleRep * ListaDouble;

/**
    \brief Devuelve una nueva lista vac�a.
    \return Una lista vac�a.
*/
ListaDouble ListaDoubleCrea();

/**
    \brief Libera la memoria asociada a la lista l.
    \param l Lista a liberar.
*/
void ListaDoubleLibera(ListaDouble l);

/**
    \brief Inserta un double, en una posici�n concreta de una lista, aumentando su tama�o.
    \pre l es distinto de NULL.
    \pre Posic es una posici�n v�lida de la lista.
    \param l Lista en la que insertar.
    \param Posic Posici�n de la lista l donde se realiza la inserci�n.
    \param d Valor a insertar.
*/
void ListaDoubleInserta(ListaDouble l, int Posic, double d);

/**
    \brief Suprime una posici�n concreta de una lista, desplazando el resto de posiciones posteriores, y disminuyendo su tama�o.
    \pre l es distinto de NULL.
    \pre Posic es una posici�n v�lida de la lista.
    \param l Lista donde suprimir.
    \param Posic Posici�n de la lista a suprimir.
*/
void ListaDoubleSuprime(ListaDouble l, int Posic);

/**
    \brief Recupera el double asociado a una posici�n concreta de la lista.
    \pre l es distinto de NULL.
    \pre Posic es una posici�n v�lida de la lista.
    \param l Lista donde se recupera el elemento.
    \param Posic Posici�n donde se encuentra el elemento a recuperar, de la lista
    \return double asociado a la posici�n Posic de l.
*/
double ListaDoubleRecupera(ListaDouble l, int Posic);

/**
    \brief Asigna un valor a una posici�n de una lista.
    \pre l es distinto de NULL.
    \pre Posic es una posici�n v�lida de la lista.
    \param l Lista donde se asigna el valor
    \param Posic Posici�n en la cual se realiza la asignaci�n
    \param d valor que se asignar� en la posici�n.
*/
void ListaDoubleAsigna(ListaDouble l, int Posic, double d);

/**
    \brief Devuelve la cantidad de elementos de una lista.
    \pre l es distinto de NULL.
    \param l Lista cuya longitud se halla.
    \return Longitud de la lista.
*/
int ListaDoubleLongitud(ListaDouble l);

/**
    \brief Devuelve la primera posici�n de la lista.
    \pre l es distinto de NULL.
    \param l Lista a procesar.
    \return La primera posici�n de la lista.
*/
int ListaDoubleInicio(ListaDouble l);

/**
    \brief Devuelve la �ltima posici�n de la lista.
    \pre l es distinto de NULL.
    \param l Lista a procesar.
    \return La �ltima posici�n de la lista.
*/
int ListaDoubleFin(ListaDouble l);

/**
    \brief Devuelve la posici�n posterior a una dada, pertenecientes a una lista.
    \pre l es distinto de NULL.
    \pre Posic no es la �ltima posici�n de la lista.
    \param l Lista a procesar.
    \param Posic Posici�n cuya posici�n posterior se halla.
    \return Posici�n posterior a la dada.
*/
int ListaDoubleSiguiente(ListaDouble l, int Posic);

/**
    \brief Devuelve la posici�n anterior a una dada, pertenecientes a una lista.
    \pre l es distinto de NULL.
    \pre Posic no es la primera posici�n de la lista.
    \param l Lista a procesar.
    \param Posic Posici�n cuya posici�n anterior se halla.
    \return Posici�n anterior a la dada.
*/
int ListaDoubleAnterior(ListaDouble l, int Posic);

/**
    \brief Devuelve si una lista est� o no llena. Est� llena si su tama�o es superior o igual a una constante (s�lo para listas acotadas).
    \pre l es distinto de NULL.
    \param l Lista a procesar.
    \return 1 si la lista est� llena.
    \return 0 si la lista no est� llena.
*/
int ListaDoubleLlena(ListaDouble l);

#endif
