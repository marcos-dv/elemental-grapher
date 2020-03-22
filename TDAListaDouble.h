#ifndef __TDAListaDouble_H__
#define __TDAListaDouble_H__

/**
   \file TDAListaDouble.h
   \brief Permite utilizar multitud de funciones básicas para el manejo de listas, con datos de tipo double.
   \author Marcos Domínguez Velad, para Tecnología de la Programación, UM, 2016.
*/
/**
    \brief Tipo de Dato Abstracto ListaDouble
*/
typedef struct ListaDoubleRep * ListaDouble;

/**
    \brief Devuelve una nueva lista vacía.
    \return Una lista vacía.
*/
ListaDouble ListaDoubleCrea();

/**
    \brief Libera la memoria asociada a la lista l.
    \param l Lista a liberar.
*/
void ListaDoubleLibera(ListaDouble l);

/**
    \brief Inserta un double, en una posición concreta de una lista, aumentando su tamaño.
    \pre l es distinto de NULL.
    \pre Posic es una posición válida de la lista.
    \param l Lista en la que insertar.
    \param Posic Posición de la lista l donde se realiza la inserción.
    \param d Valor a insertar.
*/
void ListaDoubleInserta(ListaDouble l, int Posic, double d);

/**
    \brief Suprime una posición concreta de una lista, desplazando el resto de posiciones posteriores, y disminuyendo su tamaño.
    \pre l es distinto de NULL.
    \pre Posic es una posición válida de la lista.
    \param l Lista donde suprimir.
    \param Posic Posición de la lista a suprimir.
*/
void ListaDoubleSuprime(ListaDouble l, int Posic);

/**
    \brief Recupera el double asociado a una posición concreta de la lista.
    \pre l es distinto de NULL.
    \pre Posic es una posición válida de la lista.
    \param l Lista donde se recupera el elemento.
    \param Posic Posición donde se encuentra el elemento a recuperar, de la lista
    \return double asociado a la posición Posic de l.
*/
double ListaDoubleRecupera(ListaDouble l, int Posic);

/**
    \brief Asigna un valor a una posición de una lista.
    \pre l es distinto de NULL.
    \pre Posic es una posición válida de la lista.
    \param l Lista donde se asigna el valor
    \param Posic Posición en la cual se realiza la asignación
    \param d valor que se asignará en la posición.
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
    \brief Devuelve la primera posición de la lista.
    \pre l es distinto de NULL.
    \param l Lista a procesar.
    \return La primera posición de la lista.
*/
int ListaDoubleInicio(ListaDouble l);

/**
    \brief Devuelve la última posición de la lista.
    \pre l es distinto de NULL.
    \param l Lista a procesar.
    \return La última posición de la lista.
*/
int ListaDoubleFin(ListaDouble l);

/**
    \brief Devuelve la posición posterior a una dada, pertenecientes a una lista.
    \pre l es distinto de NULL.
    \pre Posic no es la última posición de la lista.
    \param l Lista a procesar.
    \param Posic Posición cuya posición posterior se halla.
    \return Posición posterior a la dada.
*/
int ListaDoubleSiguiente(ListaDouble l, int Posic);

/**
    \brief Devuelve la posición anterior a una dada, pertenecientes a una lista.
    \pre l es distinto de NULL.
    \pre Posic no es la primera posición de la lista.
    \param l Lista a procesar.
    \param Posic Posición cuya posición anterior se halla.
    \return Posición anterior a la dada.
*/
int ListaDoubleAnterior(ListaDouble l, int Posic);

/**
    \brief Devuelve si una lista está o no llena. Está llena si su tamaño es superior o igual a una constante (sólo para listas acotadas).
    \pre l es distinto de NULL.
    \param l Lista a procesar.
    \return 1 si la lista está llena.
    \return 0 si la lista no está llena.
*/
int ListaDoubleLlena(ListaDouble l);

#endif
