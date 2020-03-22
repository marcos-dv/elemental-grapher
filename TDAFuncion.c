#include "TDAFuncion.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define Precision 500

struct FuncionRep
{
    ListaDouble Recorrido;
    char exp[12];               //12, ya que como máximo tenemos 9 caracteres (arcsin(x)), dejamos otro para la marca de fin, y 2 más por si fueran necesarios al introducir nuevas funciones.
    int Codigo;
};


Funcion FuncionCrea (int Codigo)
{
    Funcion f = malloc(sizeof(struct FuncionRep));
    f->Codigo=Codigo;
    return f;
}

void FuncionLibera (Funcion f)
{
    ListaDoubleLibera (f->Recorrido);
    free (f);
}


void FuncionInicializa (Funcion f, int Intervalo, char * doc_nombre)
{
    FuncionCalculaExpresion (f);
    FuncionCalculaRecorrido (f, Intervalo);
    FuncionGuardaDatos (f, doc_nombre, Intervalo);
}

void FuncionCalculaExpresion (Funcion f)
{
    char str[]="x^";
    char str1[2];
    switch (f->Codigo)
    {
        case CodigoSeno:
            strcpy(f->exp,"sen(x)");
            break;

        case CodigoCoseno:
            strcpy(f->exp,"cos(x)");
            break;

        case CodigoTangente:
            strcpy(f->exp,"tan(x)");
            break;

        case CodigoArcoSeno:
            strcpy(f->exp,"arcsin(x)");
            break;

        case CodigoArcoCoseno:
            strcpy(f->exp,"arccos(x)");
            break;

        case CodigoArcoTangente:
            strcpy(f->exp,"arctan(x)");
            break;

        case CodigoLogaritmo:
            strcpy(f->exp,"log(x)");
            break;

        case CodigoInversa:
            strcpy(f->exp,"1/x");
            break;

        default:
            sprintf(str1,"%d", f->Codigo);
            strcpy(f->exp,strcat(str,str1));    //Formar expresiones de la forma "x^a"
    }
}

void FuncionCalculaRecorrido (Funcion f, int Intervalo)
{
    f->Recorrido = ListaDoubleCrea();
    double Salto;
    double Extremo;
    switch (Intervalo)
    {
        case 3 : Extremo = 1; break;
        case 4 : Extremo = 10; break;
        case 5 : Extremo = 100;
    }
    Salto = 2*Extremo/(double)Precision;
    double valor;
    for (int i = 0; i < Precision; ++i)
    {
        switch (f->Codigo)
        {
        case CodigoSeno:
            valor=sin(-Extremo+i*Salto);
            break;

        case CodigoCoseno:
            valor=cos(-Extremo+i*Salto);
            break;

        case CodigoTangente:
            if (cos(-Extremo+i*Salto)!=0)
                valor=tan(-Extremo+i*Salto);
            else
                valor = NAN;   //Division por 0
            break;

        case CodigoArcoSeno:
            if ((-Extremo+i*Salto<=1)&&(-Extremo+i*Salto>=-1))
                valor=asin(-Extremo+i*Salto);
            else
                valor = NAN;
            break;

        case CodigoArcoCoseno:
            if ((-Extremo+i*Salto<=1)&&(-Extremo+i*Salto>=-1))
                valor=acos(-Extremo+i*Salto);
            else
                valor = NAN;
            break;

        case CodigoArcoTangente:
            valor=atan(-Extremo+i*Salto);
            break;

        case CodigoLogaritmo:
            if(-Extremo+i*Salto>0)
                valor=log(-Extremo+i*Salto);
            else
                valor=NAN;
            break;

        case CodigoInversa:
            if(-Extremo+i*Salto!=0)
                valor=pow(-Extremo+i*Salto, -1);
            else
                valor=NAN;
            break;
        case CodigoIdentidad:
            valor = -Extremo+i*Salto;
            break;
        default:
            if (f->Codigo==0)
                valor = 1;
            else
                valor=pow(-Extremo+i*Salto, f->Codigo);
        }
        ListaDoubleInserta (f->Recorrido, ListaDoubleFin(f->Recorrido), valor);
    }
}

void FuncionGuardaDatos (Funcion f, char * nombre, int Intervalo)
{
    double Extremo;
    switch (Intervalo)
    {
        case 3 : Extremo = 1;   break;
        case 4 : Extremo = 10;  break;
        case 5 : Extremo = 100;
    }
    ListaDouble R = Raices(f, Extremo);
    ListaDouble Maxim = Maximos(f, Extremo);
    ListaDouble Minim = Minimos (f, Extremo);
    FILE * doc = fopen (nombre, "a");
    fprintf (doc, "\nLa expresion de la funcion es: %s.\nAnalisis en [-%.0f, %.0f], los puntos del dominio donde se anula: ", f->exp, Extremo, Extremo);
    if ((f->Codigo!=CodigoArcoCoseno)&&(f->Codigo!=0)&&(f->Codigo!=CodigoLogaritmo)&&(f->Codigo!=CodigoInversa)){       //Nuestro algoritmo no es válido
                                                                                                                        //para el arcocoseno, el logaritmo, 1/x, y la constante y=1
    for(int i=0; i < ListaDoubleLongitud(R)-1 ;i++)             //Impresion de las raices
        fprintf(doc, "%.2f, ", ListaDoubleRecupera (R, i));
    if (ListaDoubleLongitud(R)!=0)                              //Si no hubiera raices, no se hace.
        fprintf (doc, "%.2f.", ListaDoubleRecupera(R, ListaDoubleLongitud(Maxim)-1));}    //Impresion de la ultima raiz

    fprintf (doc, "\nLos maximos son: ");                       //Impresion de los maximos
    for(int i=0; i < ListaDoubleLongitud(Maxim)-1 ;i++)
        fprintf(doc, "%.2f, ", ListaDoubleRecupera (Maxim, i));
    if (ListaDoubleLongitud(Maxim)!=0)                          //Si no hubiera maximos
        fprintf (doc, "%.2f.", ListaDoubleRecupera(Maxim, ListaDoubleLongitud(Maxim)-1));

    fprintf (doc, "\nLos minimos son: ");                       //Impresion de los minimos
    for(int i=0; i < ListaDoubleLongitud(Minim)-1 ;i++)
        fprintf(doc, "%.2f, ", ListaDoubleRecupera (Minim, i));
    if (ListaDoubleLongitud(Minim)!=0)                          //Si no hubiera minimos
        fprintf (doc, "%.2f.", ListaDoubleRecupera(Minim, ListaDoubleLongitud(Minim)-1));
    fprintf (doc, "\nFin del analisis.\n");

    fclose (doc);
}

void FuncionRepresenta (Funcion f, int Intervalo)
{
    double SaltoX = (double)EjeXLargo/Precision;
    double Extremo;
    switch (Intervalo)
    {
        case 3 :
            Extremo = 1;
            break;
        case 4 :
            Extremo = 10;
            break;
        case 5 :
            Extremo = 100;
    }
    double SaltoY = (double)EjeYAlto/(2*Extremo);
    for (int i = 1; i<Precision; ++i)
        if((ListaDoubleRecupera(f->Recorrido, i)!=NAN)&&(ListaDoubleRecupera(f->Recorrido, i)<Extremo)&&(ListaDoubleRecupera(f->Recorrido, i)>-Extremo))
            Pantalla_DibujaPunto(Pantalla_Anchura()/2-EjeYAlto/2+i*SaltoX, Pantalla_Altura()-EjeYAlto/2-20-SaltoY*ListaDoubleRecupera(f->Recorrido, i));
}

char * FuncionExpresion (Funcion f)
{
    return f->exp;
}

ListaDouble FuncionRecorrido (Funcion f)
{
    return f->Recorrido;
}

ListaDouble Raices (Funcion f, double Extremo)
{
    ListaDouble Raiz = ListaDoubleCrea ();
    double Salto = 2*Extremo/(double)Precision;
    for (int i = 1; (i < Precision); ++i)
    {
        if (ListaDoubleRecupera(f->Recorrido, i-1) == 0)
            ListaDoubleInserta (Raiz, ListaDoubleFin(Raiz), -Extremo+i*Salto);                        //Raiz hallada en el punto x = -Extremo + i*Salto
        else if ((ListaDoubleRecupera(f->Recorrido, i)*ListaDoubleRecupera(f->Recorrido, i-1)) < 0)   //Teorema de Bolzano
            ListaDoubleInserta (Raiz, ListaDoubleFin(Raiz), -Extremo+i*Salto - Salto/2);              //El punto medio de ambos puntos del dominio
    }
    if ((ListaDoubleRecupera(f->Recorrido, Precision) == 0))
        ListaDoubleInserta (Raiz, ListaDoubleFin(Raiz), Extremo); //Comprobamos si el ultimo punto es raiz.
    return Raiz;
}


ListaDouble Maximos (Funcion f, double Extremo)               //Los extremos no pueden ser maximos/minimos
{
    ListaDouble Maxim = ListaDoubleCrea ();
    double Salto = 2*Extremo/(double)Precision;
    for (int i = 1; i < Precision-1; ++i)
        if ((ListaDoubleRecupera(f->Recorrido, i-1) < ListaDoubleRecupera(f->Recorrido, i))
        && (ListaDoubleRecupera(f->Recorrido, i) > ListaDoubleRecupera (f->Recorrido, i+1)))  //Recorrido[i] es maximo
            ListaDoubleInserta (Maxim, ListaDoubleFin(Maxim), -Extremo+i*Salto);
    return Maxim;
}

ListaDouble Minimos (Funcion f, double Extremo)               //Los extremos no pueden ser maximos/minimos
{
    ListaDouble Minim = ListaDoubleCrea ();                     //La lista esta acotada ok
    double Salto = 2*Extremo/Precision;
    for (int i = 1; i < Precision-1; ++i)
        if ((ListaDoubleRecupera(f->Recorrido, i-1) > ListaDoubleRecupera(f->Recorrido, i))
        && (ListaDoubleRecupera(f->Recorrido, i) < ListaDoubleRecupera (f->Recorrido, i+1))
        && (ListaDoubleRecupera(f->Recorrido, i) <= Extremo))  //Recorrido[i] es maximo
            ListaDoubleInserta (Minim, ListaDoubleFin(Minim), -Extremo+i*Salto);
    return Minim;
}
