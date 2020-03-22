#include "TDAListaDouble.h"

#include <stdlib.h>

#define Maximo 2000

struct ListaDoubleRep
{
    double elem[Maximo];
    int Tam;
};

ListaDouble ListaDoubleCrea()
{
    ListaDouble l = malloc(sizeof(struct ListaDoubleRep));
    l->Tam = 0;
    return l;
}

void ListaDoubleLibera(ListaDouble l)
{
    free(l);
}

void ListaDoubleInserta(ListaDouble l, int Posic, double d)
{
    for (int i=l->Tam; i > Posic; --i)
        l->elem[i]=l->elem[i-1];
    l->elem[Posic]=d;
    l->Tam++;
}

void ListaDoubleSuprime(ListaDouble l, int Posic)
{
    l->Tam--;
    for(int i=Posic; i < l->Tam ;i++)
        l->elem[i] = l->elem[i+1];
}

double ListaDoubleRecupera(ListaDouble l, int Posic)
{
    return l->elem[Posic];
}

void ListaDoubleAsigna(ListaDouble l, int Posic, double d)
{
    l->elem[Posic] = d;
}

int ListaDoubleLongitud(ListaDouble l)
{
    return l->Tam;
}

int ListaDoubleInicio(ListaDouble l)
{
    return 0;
}

int ListaDoubleFin(ListaDouble l)
{
    return l->Tam;
}

int ListaDoubleSiguiente(ListaDouble l, int Posic)
{
    return Posic+1;
}

int ListaDoubleAnterior(ListaDouble l, int Posic)
{
    return Posic-1;
}

int ListaDoubleLlena(ListaDouble l)
{
    return (l->Tam>=Maximo);
}
