#include "TDAGrafico.h"

#include <stdlib.h>

struct GraficoRep
{
    Funcion f;
    Grafico sig;
};

Grafico GraficoCrea ()
{
    Grafico g = malloc(sizeof(struct GraficoRep));
    g->sig = NULL;
    return g;
}

void GraficoInserta (Grafico g, Funcion f)
{
    Grafico aux = malloc(sizeof(struct GraficoRep));
    aux->sig=g->sig;
    aux->f=f;
    g->sig=aux;
}

void GraficoEliminaPrimero (Grafico g)
{
    if ((g!=NULL) && (g->sig!=NULL))
    {
        Grafico aux = g->sig;
        g->sig=g->sig->sig;
        FuncionLibera(aux->f);
        free(aux);
    }
}

void GraficoLibera (Grafico g)
{
    if (g!=NULL)
    {
        while (g->sig!=NULL)
        {
            Grafico aux = g->sig;
            g->sig = g->sig->sig;
            FuncionLibera(aux->f);
            free (aux);
        }
    }
}

void GraficoRepresenta (Grafico g, int Intervalo)
{
    if (g!=NULL)
    {
        int i = 0;
        while (g->sig!=NULL)
        {
            g=g->sig;
            switch(i%5)
            {
                case 0: Pantalla_ColorTrazo(255,0,0,255);   break;
                case 1: Pantalla_ColorTrazo(0,255,0,255);   break;
                case 2: Pantalla_ColorTrazo(255,255,0,255); break;
                case 3: Pantalla_ColorTrazo(150,150,255,255); break;
                case 4: Pantalla_ColorTrazo(230,230,230,250);
            }
            FuncionRepresenta(g->f, Intervalo);
            ++i;
        }
    }
}
