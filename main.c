#include "Pantalla.h"
#include "TDAGrafico.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PantallaAncho 775
#define PantallaAlto 575


#define PantallaAncho 1075
#define PantallaAlto 775


#define FICHERO_GUARDADO "FuncionesAnalizadas.txt"

/**
\mainpage Proyecto para Tecnología de la Programación de Marcos Domínguez Velad, UM, 2016. El proyecto consiste en una aplicación gráfica para representar varias funciones de tipo elemental a través de un gráfico centrado en el origen, así como un breve análisis de la función que incluye raíces y extremos relativos, el cual se verá reflejado en un fichero; poniendo en práctica los conocimientos teóricos adquiridos en la asignatura. Se usa de base gráfica el wrapper Pantalla, de SDL. Se pueden distinguir 3 fases principales en la aplicación, el menú, la ayuda, y el análisis de funciones.
*/

/**
    \file main.c
    \brief Módulo principal de la aplicación.
*/

/**
    \brief Devuelve un entero leído de teclado, de una sola cifra
    \return Un entero de una cifra.
*/
int Pantalla_LeeEntero ()
{
    while(Pantalla_Activa())
    {
    if (Pantalla_TeclaPulsada(SDL_SCANCODE_0))
        return 0;
    if (Pantalla_TeclaPulsada(SDL_SCANCODE_1))
        return 1;
    if (Pantalla_TeclaPulsada(SDL_SCANCODE_2))
        return 2;
    if (Pantalla_TeclaPulsada(SDL_SCANCODE_3))
        return 3;
    if (Pantalla_TeclaPulsada(SDL_SCANCODE_4))
        return 4;
    if (Pantalla_TeclaPulsada(SDL_SCANCODE_5))
        return 5;
    if (Pantalla_TeclaPulsada(SDL_SCANCODE_6))
        return 6;
    if (Pantalla_TeclaPulsada(SDL_SCANCODE_7))
        return 7;
    if (Pantalla_TeclaPulsada(SDL_SCANCODE_8))
        return 8;
    if (Pantalla_TeclaPulsada(SDL_SCANCODE_9))
        return 9;
    Pantalla_Espera (50);
    }
    return 1; //Si hubiera algun error y pantalla dejara de estar activa, devolvemos 1.
}

/**
    \brief Devuelve un booleano en función de si el ratón está sobre un rectángulo definido con los parámetros de entrada.
    \param x Coordenada x de la esquina superior izquierda del rectángulo.
    \param y Coordenada y de la esquina superior izquierda del rectángulo.
    \param w Ancho del rectángulo.
    \param h Altura del rectángulo.
    \return 1 si el ratón está sobre el rectángulo, 0 en otro caso.
*/
int RatonSobreRectangulo(double x, double y, double w, double h)
{
    double a;
    double b;
    Pantalla_RatonCoordenadas(&a, &b);
    return ((a >= x) && (a<=x+w) && (b >= y) && (b<=y+h));
}

/**
    \brief Devuelve un booleano en función de si el ratón está sobre un círculo definido con los parámetros de entrada.
    \param x Coordenada x del centro del círculo.
    \param y Coordenada y del centro del círculo.
    \param r Radio del círculo.
    \return 1 si el ratón está sobre el círculo, 0 en otro caso.
*/
int RatonSobreCirculo(double x, double y, double r)
{
    double a;
    double b;
    Pantalla_RatonCoordenadas(&a, &b);
    return (sqrt((a-x)*(a-x)+(b-y)*(b-y)) <= r);   //Distancia de un punto (a, b) al centro del circulo
}


////////////
/// MENU ///
////////////

/**
    \brief Devuelve un booleano en función de si el usuario ha hecho click para ir a la Ayuda.
    \return 1 si el usuario ha clicado correctamente, 0 si no.
*/
int IrAyuda ()
{       //Colocamos las coordenadas del circulo centrado en Ayuda
    return (Pantalla_RatonBotonPulsado(SDL_BUTTON_LEFT) &&
    RatonSobreCirculo (Pantalla_Anchura()*2/3+20, Pantalla_Altura()*3/4, 40));
}

/**
    \brief Devuelve un booleano en función de si el usuario ha hecho click para ir a Análisis.
    \return 1 si el usuario ha clicado correctamente, 0 si no.
*/
int IrAnalisis()
{       //Colocamos el rectangulo marco de la opcion para ir a representar
    if (Pantalla_RatonBotonPulsado(SDL_BUTTON_LEFT))
    {
        if (RatonSobreRectangulo (Pantalla_Anchura()*2/3, Pantalla_Altura()/3+LetraAlto, 27*LetraAncho, LetraAlto)) return 3;
        if (RatonSobreRectangulo (Pantalla_Anchura()*2/3, Pantalla_Altura()/3+2*LetraAlto, 27*LetraAncho, LetraAlto)) return 4;
        if (RatonSobreRectangulo (Pantalla_Anchura()*2/3, Pantalla_Altura()/3+3*LetraAlto, 27*LetraAncho, LetraAlto)) return 5;
    }
    return 0;
}

/**
    \brief Dibuja el título del menú, autor, y condición de salida del programa.
*/
void MenuTitulo ()
{
    double Pant_Ancho = Pantalla_Anchura();
    double Pant_Alto = Pantalla_Altura();

    Pantalla_ColorTrazo (0, 0, 0, 255);
    Pantalla_ColorRelleno (255, 255, 255, 255);
    Pantalla_DibujaRectangulo(Pant_Ancho/3-5, Pant_Alto/10-5, 356, 22);

    Pantalla_ColorTrazo (0, 0, 0, 150);
    Pantalla_ColorRelleno (255, 255, 255, 255);
    Pantalla_DibujaRectangulo(Pant_Ancho/3-2, Pant_Alto/10-2, 350, 16);      //Enmarca el texto

    Pantalla_ColorTrazo(120,120,255,240);
    Pantalla_DibujaTexto("Analisis y representacion de funciones", Pant_Ancho/3, Pant_Alto/10);  //Titulo

    Pantalla_ColorTrazo(200, 40, 50, 230);                                                  //Autor y salida
    Pantalla_DibujaTexto("De Marcos Dominguez. Pulse q para salir", Pant_Ancho/10, Pant_Alto*3/4-10);
}

/**
    \brief Dibuja las posibles opciones del menú para ir a representar, o a ayuda.
*/
void MenuOpciones()
{
    double Pant_Ancho = Pantalla_Anchura();
    double Pant_Alto = Pantalla_Altura();

    Pantalla_ColorTrazo(200,25,200,255);
    Pantalla_DibujaTexto("Click para representar en:", Pant_Ancho*2/3, Pant_Alto/3);
    Pantalla_DibujaTexto("a) Intervalo (-1, 1)", Pant_Ancho*2/3, Pant_Alto/3+LetraAlto);
    Pantalla_DibujaTexto("b) Intervalo (-10, 10)", Pant_Ancho*2/3, Pant_Alto/3+2*LetraAlto);
    Pantalla_DibujaTexto("c) Intervalo (-100, 100)", Pant_Ancho*2/3, Pant_Alto/3+3*LetraAlto);


    Pantalla_ColorTrazo(250,230,20,220);
    Pantalla_ColorRelleno(250,230,20,220);
    Pantalla_DibujaCirculo(Pant_Ancho*2/3+20, Pant_Alto*3/4, 40);    //Circulo de ayuda

    Pantalla_ColorTrazo(20,230,250,255);
    Pantalla_DibujaTexto("Ayuda", Pant_Ancho*2/3, Pant_Alto*3/4-10);  //Ayuda
}

/**
    \brief Función principal del menú, la cual maneja los eventos en dicha fase.
    \return Devuelve un entero en función de la que será la próxima fase (análisis, ayuda, o salir).
*/
int Menu ()
{
    Pantalla_DibujaRellenoFondo (50, 150, 150, 240);
    MenuTitulo();
    MenuOpciones ();
    Pantalla_Actualiza();
    Pantalla_Espera(100);
    int Fase = 1;
    int Analisis;
    while ((Fase == 1)&&Pantalla_Activa())
    {
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_Q))      //Si 'q' esta pulsado, saldremos
            Fase = 0;
        else if (IrAyuda())
            Fase = 2;
        else
        {
            Analisis = IrAnalisis();
            if (Analisis!=0)
                Fase = Analisis;        //Asi Fase = 3, 4, o 5, dependiendo del intervalo seleccionado
        }
    }
    return Fase;
}

/////////////
/// AYUDA ///
/////////////

/**
    \brief Devuelve un booleano en función de si el usuario ha clicado desde ayuda para ir al menú
    \return 1 si ha procedido correctamente, 0 si no.
*/
int IrMenu ()
{
    return (Pantalla_RatonBotonPulsado(SDL_BUTTON_LEFT) &&
    RatonSobreCirculo (Pantalla_Anchura()/2+4, Pantalla_Altura()*4/5+7, 35));
}

/**
    \brief Dibuja la opción para ir al menú principal desde ayuda.
*/
void AyudaDibujaAtras ()
{
    Pantalla_ColorRelleno(255, 255, 0, 255);
    Pantalla_DibujaCirculo (Pantalla_Anchura()/2+4, Pantalla_Altura()*4/5+7, 35); //Lo redondeamos

    Pantalla_ColorTrazo(40,220,80,230);
    Pantalla_DibujaTexto("ATRAS", Pantalla_Anchura()/2-2*LetraAncho, Pantalla_Altura()*4/5);  //Escribimos Atras
}

/**
    \brief Dibuja el título y las líneas de texto de la ayuda.
*/
void AyudaDibujaTexto ()
{
    double Pant_Alto = Pantalla_Altura();

    Pantalla_ColorTrazo(25,200,100,200);
    Pantalla_DibujaTexto("Descripcion del uso.", 6, Pant_Alto/10-6);   //Titulo
    //Lineas de texto
    Pantalla_DibujaTexto("Esta aplicacion esta dedicada a la representacion sencilla de funciones elementales.",LetraAncho, Pant_Alto/10+1*LetraAlto);      //Separacion lineas = 15
    Pantalla_DibujaTexto("Para ello, desde el menu principal se debe seleccionar el intervalo a representar,",  LetraAncho, Pant_Alto/10+2*LetraAlto);
    Pantalla_DibujaTexto("a elegir entre los centrados en el origen y con radio 1, 10, o 100, de forma que",    LetraAncho, Pant_Alto/10+3*LetraAlto);
    Pantalla_DibujaTexto("el intervalo sera el [-n, n]. Tras esto, debemos introducir una funcion, acudiendo",  LetraAncho, Pant_Alto/10+4*LetraAlto);
    Pantalla_DibujaTexto("para esta tarea a un teclado interactivo, cuyos botones usaremos para seleccionar",   LetraAncho, Pant_Alto/10+5*LetraAlto);
    Pantalla_DibujaTexto("la funcion que queremos representar.",                                                LetraAncho, Pant_Alto/10+6*LetraAlto);
    Pantalla_DibujaTexto("Una vez introducida, veremos la representacion de la funcion en la pantalla,",        LetraAncho, Pant_Alto/10+8*LetraAlto);
    Pantalla_DibujaTexto("y en el fichero 'AnalisisFunciones.txt' podremos encontrar algunos datos de",         LetraAncho, Pant_Alto/10+9*LetraAlto);
    Pantalla_DibujaTexto("la funcion: su expresion, sus raices, y sus extremos tanto relativos como,",          LetraAncho, Pant_Alto/10+10*LetraAlto);
    Pantalla_DibujaTexto("absolutos (maximos y minimos)de esta manera guardando un historial de las ",          LetraAncho, Pant_Alto/10+11*LetraAlto);
    Pantalla_DibujaTexto("representaciones.",                                                                   LetraAncho, Pant_Alto/10+12*LetraAlto);
    Pantalla_DibujaTexto("Nota: para introducir un monomio elevado a un exponente, se debera clicar",           LetraAncho, Pant_Alto/10+14*LetraAlto);
    Pantalla_DibujaTexto("en dicho boton y teclear seguidamente un numero desde teclado. El boton Borra",       LetraAncho, Pant_Alto/10+15*LetraAlto);
    Pantalla_DibujaTexto("elimina funcion introducida mas recientemente.",                                      LetraAncho, Pant_Alto/10+16*LetraAlto);
    //Fin lineas de texto
}

/**
    \brief Función principal de la ayuda, la cual maneja los eventos en dicha fase.
    \return Devuelve un entero en función de la que será la próxima fase (menú o salir).
*/
int Ayuda ()
{
    Pantalla_DibujaRellenoFondo(255,255,255,255);
    AyudaDibujaTexto();
    AyudaDibujaAtras();
    Pantalla_Actualiza();
    Pantalla_Espera (100);
    int Fase = 2;
    while ((Fase==2)&&Pantalla_Activa())
    {
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_Q))      //Si 'q' esta pulsado, saldremos
            Fase = 0;
        else if (IrMenu())
            Fase = 1;
    }
    return Fase;
}


////////////////
/// ANALISIS ///
////////////////

/**
    \brief Dibuja un teclado interactivo con los botones en los que podrá hacer click el usuario para representar funciones.
*/
void MuestraTeclado ()
{
    double Pant_Ancho = Pantalla_Anchura();
    double Pant_Alto = Pantalla_Altura();
    //Dibujar contorno
    Pantalla_ColorTrazo(255, 255, 255, 230); //Mismo que ejes
    Pantalla_ColorRelleno(10,10,10,30); //Mismo que el fondo
    Pantalla_DibujaRectangulo(30, Pant_Alto-EjeYAlto-30, Pant_Ancho-60, EjeYAlto); //Margen de 60 a los lados

    //Dibujar botones

    double AnchoColumna = (Pant_Ancho-65)/7;    //La coord X de cada es i * Ancho; (con i = columna)
    double AltoFila = (EjeYAlto)/6;             //La coord Y de cada es i * Alto; (con i = Fila)

    //Coordenada origen: (30, Pant_Alto-EjeYAlto-30)

    //Enmarcar los botones

    Pantalla_ColorTrazo (255, 255, 255, 210);
    Pantalla_ColorRelleno(50,50,50,90);
    //Fila 1
    Pantalla_DibujaRectangulo(27+AnchoColumna, Pant_Alto-EjeYAlto-33+AltoFila, 6*LetraAncho,1.5*LetraAlto);
    Pantalla_DibujaRectangulo(27+2*AnchoColumna, Pant_Alto-EjeYAlto-33+AltoFila, 6*LetraAncho,1.5*LetraAlto);
    Pantalla_DibujaRectangulo(27+3*AnchoColumna, Pant_Alto-EjeYAlto-33+AltoFila, 6*LetraAncho,1.5*LetraAlto);
    Pantalla_DibujaRectangulo(27+4*AnchoColumna, Pant_Alto-EjeYAlto-33+AltoFila, 6*LetraAncho,1.5*LetraAlto);
    Pantalla_DibujaRectangulo(27+5*AnchoColumna, Pant_Alto-EjeYAlto-33+AltoFila, 6*LetraAncho,1.5*LetraAlto);

    //Fila 2
    Pantalla_DibujaRectangulo(27+AnchoColumna, Pant_Alto-EjeYAlto-33+2*AltoFila, 6*LetraAncho,1.5*LetraAlto);
    Pantalla_DibujaRectangulo(27+2*AnchoColumna, Pant_Alto-EjeYAlto-33+2*AltoFila, 6*LetraAncho,1.5*LetraAlto);
    Pantalla_DibujaRectangulo(27+3*AnchoColumna, Pant_Alto-EjeYAlto-33+2*AltoFila, 6*LetraAncho,1.5*LetraAlto);
    Pantalla_DibujaRectangulo(27+4*AnchoColumna, Pant_Alto-EjeYAlto-33+2*AltoFila, 6*LetraAncho,1.5*LetraAlto);
    Pantalla_DibujaRectangulo(27+5*AnchoColumna, Pant_Alto-EjeYAlto-33+2*AltoFila, 6*LetraAncho,1.5*LetraAlto);

    //Fila 3
    Pantalla_DibujaRectangulo(27+AnchoColumna, Pant_Alto-EjeYAlto-33+3*AltoFila, 40*LetraAncho,1.5*LetraAlto);

    //Texto interior//

    Pantalla_ColorTrazo (255, 255, 255, 255);
    //Fila 1
    Pantalla_DibujaTexto("sen", 30+AnchoColumna, Pant_Alto-EjeYAlto-30+AltoFila);
    Pantalla_DibujaTexto("sen", 30+AnchoColumna, Pant_Alto-EjeYAlto-30+AltoFila);
    Pantalla_DibujaTexto("cos", 30+2*AnchoColumna, Pant_Alto-EjeYAlto-30+AltoFila);
    Pantalla_DibujaTexto("tan", 30+3*AnchoColumna, Pant_Alto-EjeYAlto-30+AltoFila);
    Pantalla_DibujaTexto("asen", 30+4*AnchoColumna, Pant_Alto-EjeYAlto-30+AltoFila);
    Pantalla_DibujaTexto("acos", 30+5*AnchoColumna, Pant_Alto-EjeYAlto-30+AltoFila);

    //Fila 2
    Pantalla_DibujaTexto("atan", 30+AnchoColumna, Pant_Alto-EjeYAlto-30+2*AltoFila);
    Pantalla_DibujaTexto("log", 30+2*AnchoColumna, Pant_Alto-EjeYAlto-30+2*AltoFila);
    Pantalla_DibujaTexto("1/x", 30+3*AnchoColumna, Pant_Alto-EjeYAlto-30+2*AltoFila);
    Pantalla_DibujaTexto("x", 30+4*AnchoColumna, Pant_Alto-EjeYAlto-30+2*AltoFila);
    Pantalla_DibujaTexto("Borra", 30+5*AnchoColumna, Pant_Alto-EjeYAlto-30+2*AltoFila);
    //Fila 3
    Pantalla_DibujaTexto("x^a (click y pulse una cifra)", 30+AnchoColumna, Pant_Alto-EjeYAlto-30+3*AltoFila);
}

////////////// Funciones que devuelven 1, 0, en funcion de si el raton esta en una posicion determinada /////////////////

/**
    \brief Devuelve un booleano en función de si el usuario ha clicado para ir al teclado interactivo.
    \return 1 si el usuario ha clicado en el recuadro correctamente, 0 en otro caso.
*/
int AnalisisIntroducirFuncion ()
{    return (RatonSobreRectangulo(7, 7, 20*LetraAncho, LetraAlto)&&Pantalla_RatonBotonPulsado(SDL_BUTTON_LEFT)); }

/**
    \brief Devuelve un booleano en función de si el ratón está sobre el botón de Seno.
    \return 1 si el ratón se encuentra sobre ese botón, 0 en otro caso.
*/
int SobreSeno ()
{    return (RatonSobreRectangulo(27+(Pantalla_Anchura()-65)/7, Pantalla_Altura()-EjeYAlto-33+(EjeYAlto)/6, 6*LetraAncho, 1.5*LetraAlto));    }

/**
    \brief Devuelve un booleano en función de si el ratón está sobre el botón de Coseno.
    \return 1 si el ratón se encuentra sobre ese botón, 0 en otro caso.
*/
int SobreCoseno ()
{    return (RatonSobreRectangulo(27+2*(Pantalla_Anchura()-65)/7, Pantalla_Altura()-EjeYAlto-33+(EjeYAlto)/6, 6*LetraAncho, 1.5*LetraAlto));   }

/**
    \brief Devuelve un booleano en función de si el ratón está sobre el botón de Tangente.
    \return 1 si el ratón se encuentra sobre ese botón, 0 en otro caso.
*/
int SobreTangente ()
{    return (RatonSobreRectangulo(27+3*(Pantalla_Anchura()-65)/7, Pantalla_Altura()-EjeYAlto-33+(EjeYAlto)/6, 6*LetraAncho, 1.5*LetraAlto));  }

/**
    \brief Devuelve un booleano en función de si el ratón está sobre el botón de Arcoseno.
    \return 1 si el ratón se encuentra sobre ese botón, 0 en otro caso.
*/
int SobreArcoSeno ()
{    return (RatonSobreRectangulo(27+4*(Pantalla_Anchura()-65)/7, Pantalla_Altura()-EjeYAlto-33+(EjeYAlto)/6, 6*LetraAncho, 1.5*LetraAlto));  }

/**
    \brief Devuelve un booleano en función de si el ratón está sobre el botón de Arcocoseno.
    \return 1 si el ratón se encuentra sobre ese botón, 0 en otro caso.
*/
int SobreArcoCoseno ()
{    return (RatonSobreRectangulo(27+5*(Pantalla_Anchura()-65)/7, Pantalla_Altura()-EjeYAlto-33+(EjeYAlto)/6, 6*LetraAncho, 1.5*LetraAlto));  }

/**
    \brief Devuelve un booleano en función de si el ratón está sobre el botón de Arcotangente.
    \return 1 si el ratón se encuentra sobre ese botón, 0 en otro caso.
*/
int SobreArcoTangente ()
{    return (RatonSobreRectangulo(27+(Pantalla_Anchura()-65)/7, Pantalla_Altura()-EjeYAlto-33+2*(EjeYAlto)/6, 6*LetraAncho, 1.5*LetraAlto));   }

/**
    \brief Devuelve un booleano en función de si el ratón está sobre el botón de Logaritmo.
    \return 1 si el ratón se encuentra sobre ese botón, 0 en otro caso.
*/
int SobreLogaritmo ()
{    return (RatonSobreRectangulo(27+2*(Pantalla_Anchura()-65)/7, Pantalla_Altura()-EjeYAlto-33+2*(EjeYAlto)/6, 6*LetraAncho, 1.5*LetraAlto)); }

/**
    \brief Devuelve un booleano en función de si el ratón está sobre el botón de Inversa.
    \return 1 si el ratón se encuentra sobre ese botón, 0 en otro caso.
*/
int SobreInversa ()
{    return (RatonSobreRectangulo(27+3*(Pantalla_Anchura()-65)/7, Pantalla_Altura()-EjeYAlto-33+2*(EjeYAlto)/6, 6*LetraAncho, 1.5*LetraAlto));    }

/**
    \brief Devuelve un booleano en función de si el ratón está sobre el botón de Identidad.
    \return 1 si el ratón se encuentra sobre ese botón, 0 en otro caso.
*/
int SobreIdentidad ()
{    return (RatonSobreRectangulo(27+4*(Pantalla_Anchura()-65)/7, Pantalla_Altura()-EjeYAlto-33+2*(EjeYAlto)/6, 6*LetraAncho, 1.5*LetraAlto));   }

/**
    \brief Devuelve un booleano en función de si el ratón está sobre el botón de Borra.
    \return 1 si el ratón se encuentra sobre ese botón, 0 en otro caso.
*/
int SobreBorra ()
{    return (RatonSobreRectangulo(27+5*(Pantalla_Anchura()-65)/7, Pantalla_Altura()-EjeYAlto-33+2*(EjeYAlto)/6, 6*LetraAncho, 1.5*LetraAlto));   }

/**
    \brief Devuelve un booleano en función de si el ratón está sobre el botón de potencia de x.
    \return 1 si el ratón se encuentra sobre ese botón, 0 en otro caso.
*/
int SobreMonomio ()
{    return (RatonSobreRectangulo(27+(Pantalla_Anchura()-65)/7, Pantalla_Altura()-EjeYAlto-33+3*(EjeYAlto)/6, 40*LetraAncho, 1.5*LetraAlto));   }

/**
    \brief Devuelve una función dependiendo del botón pulsado mediante el teclado interactivo.
    \return Devuelve una función elemental determinada, o NULL si se ha pulsado Borra.
*/
Funcion AnalisisLeeFuncion()
{
    int FuncionSeleccionada = 100;  //100 es un codigo arbitrario, que no puede coincidir con ningun codigo de funcion
    while (Pantalla_Activa() && FuncionSeleccionada==100)
    {
        if (Pantalla_RatonBotonPulsado(SDL_BUTTON_LEFT))
        {
            if (SobreSeno())
                FuncionSeleccionada=CodigoSeno;

            if (SobreCoseno())
                FuncionSeleccionada=CodigoCoseno;

            if (SobreTangente())
                FuncionSeleccionada=CodigoTangente;

            if (SobreArcoSeno())
                FuncionSeleccionada=CodigoArcoSeno;

            if (SobreArcoCoseno())
                FuncionSeleccionada=CodigoArcoCoseno;

            if (SobreArcoTangente())
                FuncionSeleccionada=CodigoArcoTangente;

            if (SobreLogaritmo())
                FuncionSeleccionada=CodigoLogaritmo;

            if (SobreInversa())
                FuncionSeleccionada=CodigoInversa;

            if (SobreIdentidad())
                FuncionSeleccionada=CodigoIdentidad;

            if (SobreBorra())
                FuncionSeleccionada=CodigoBorra;

            if (SobreMonomio())
                FuncionSeleccionada=Pantalla_LeeEntero();
        }
        Pantalla_Espera(50);
        }
    Pantalla_Espera(100);
    if (FuncionSeleccionada!=CodigoBorra)    //Solo si al introducir exponente pulsamos Q para salir
        return FuncionCrea(FuncionSeleccionada);
    return NULL;
}

/**
    \brief Dibuja las opciones de la fase de análisis, para introducir función, o volver al menú.
*/

void AnalisisOpciones ()
{
    Pantalla_ColorTrazo(255, 255, 255, 200);
    Pantalla_DibujaTexto("Introducir funcion", 7, 7);     //Margen superior izquierdo

    Pantalla_DibujaTexto("Volver", Pantalla_Anchura()-10*LetraAncho, Pantalla_Altura()-2*LetraAlto); //Margen inferior derecho
}

/**
    \brief Dibuja los ejes cartesianos en función de unas constantes, así como 5 marcas en cada eje (el origen, el punto medio del intervalo (origen, extremo), el extremo, y sus simétricos negativos).
    \pre Intervalo debe ser 3, 4, o 5.
    \param Intervalo En función del intervalo se dibujan unas marcas u otras. Si es 3 dibuja las del [-1,1], si es 4 las del [-10,10], si es 5 las del [-100,100].
*/

void AnalisisEjes (int Intervalo)
{
    double Pant_Ancho = Pantalla_Anchura();
    double Pant_Alto = Pantalla_Altura();
    Pantalla_ColorTrazo(255, 255, 255, 230);                //Eje X y Eje Y, respectivamente
    Pantalla_DibujaLinea(Pant_Ancho/2-EjeXLargo/2, Pantalla_Altura()-EjeYAlto/2-20, Pant_Ancho/2+EjeXLargo/2, Pantalla_Altura()-EjeYAlto/2-20); //Margen 20 (abajo)
    Pantalla_DibujaLinea (Pant_Ancho/2, Pantalla_Altura()-EjeYAlto-20, Pant_Ancho/2, Pantalla_Altura()-20);

    //Cada eje tiene 5 marcas orientativas, el origen, y 2 a cada lado, simetricas.
    Pantalla_ColorTrazo(255, 255, 255, 255);
    Pantalla_DibujaTexto("0", Pant_Ancho/2+3, Pant_Alto-EjeYAlto/2-10);
    switch (Intervalo)  //Dibujamos las marcas del intervalo en el eje X, y en el eje Y
    {
        case 3: //(-1, 1)
            //X
        Pantalla_DibujaTexto("-1", Pant_Ancho/2-EjeYAlto/2, Pant_Alto-EjeYAlto/2-10);
        Pantalla_DibujaTexto("-0.5", Pant_Ancho/2-EjeYAlto/4, Pant_Alto-EjeYAlto/2-10);
        Pantalla_DibujaTexto("1", Pant_Ancho/2+EjeYAlto/2, Pant_Alto-EjeYAlto/2-10);
        Pantalla_DibujaTexto("0.5", Pant_Ancho/2+EjeYAlto/4, Pant_Alto-EjeYAlto/2-10);
            //Y
        Pantalla_DibujaTexto("-1", Pant_Ancho/2+3, Pant_Alto-20);
        Pantalla_DibujaTexto("-0.5", Pant_Ancho/2+3, Pant_Alto-EjeYAlto/4-20);
        Pantalla_DibujaTexto("1", Pant_Ancho/2+3, Pant_Alto-EjeYAlto-20);
        Pantalla_DibujaTexto("0.5", Pant_Ancho/2+3, Pant_Alto-3*EjeYAlto/4-20);
        break;

        case 4: //(-10, 10)
            //X
        Pantalla_DibujaTexto("-10", Pant_Ancho/2-EjeYAlto/2, Pant_Alto-EjeYAlto/2-10);
        Pantalla_DibujaTexto("-5", Pant_Ancho/2-EjeYAlto/4, Pant_Alto-EjeYAlto/2-10);
        Pantalla_DibujaTexto("10", Pant_Ancho/2+EjeYAlto/2, Pant_Alto-EjeYAlto/2-10);
        Pantalla_DibujaTexto("5", Pant_Ancho/2+EjeYAlto/4, Pant_Alto-EjeYAlto/2-10);
            //Y
        Pantalla_DibujaTexto("-10", Pant_Ancho/2+3, Pant_Alto-20);
        Pantalla_DibujaTexto("-5", Pant_Ancho/2+3, Pant_Alto-EjeYAlto/4-20);
        Pantalla_DibujaTexto("10", Pant_Ancho/2+3, Pant_Alto-EjeYAlto-20);
        Pantalla_DibujaTexto("5", Pant_Ancho/2+3, Pant_Alto-3*EjeYAlto/4-20);
        break;

        case 5: //(-100, 100)
            //X
        Pantalla_DibujaTexto("-100", Pant_Ancho/2-EjeYAlto/2, Pant_Alto-EjeYAlto/2-10);
        Pantalla_DibujaTexto("-50", Pant_Ancho/2-EjeYAlto/4, Pant_Alto-EjeYAlto/2-10);
        Pantalla_DibujaTexto("100", Pant_Ancho/2+EjeYAlto/2, Pant_Alto-EjeYAlto/2-10);
        Pantalla_DibujaTexto("50", Pant_Ancho/2+EjeYAlto/4, Pant_Alto-EjeYAlto/2-10);
            //Y
        Pantalla_DibujaTexto("-100", Pant_Ancho/2+3, Pant_Alto-20);
        Pantalla_DibujaTexto("-50", Pant_Ancho/2+3, Pant_Alto-EjeYAlto/4-20);
        Pantalla_DibujaTexto("100", Pant_Ancho/2+3, Pant_Alto-EjeYAlto-20);
        Pantalla_DibujaTexto("50", Pant_Ancho/2+3, Pant_Alto-3*EjeYAlto/4-20);
        break;
    }
}

/**
    \brief Devuelve un booleano en función de si el usuario ha clicado para volver al menú.
    \return 1 si el usuario ha procedido correctamente, 0 en otro caso.
*/
int VolverMenu ()
{
    return (Pantalla_RatonBotonPulsado(SDL_BUTTON_LEFT)&&RatonSobreRectangulo(Pantalla_Anchura()-10*LetraAncho, Pantalla_Altura()-2*LetraAlto, 6*LetraAncho, LetraAlto));
}

/**
    \brief Función principal que maneja la fase de análisis.
    \pre Intervalo debe ser 3, 4, o 5.
    \param Intervalo nos indica el intervalo en el que vamos a representar, según sea 3 [-1,1], 4 [-10,10], o 5 [-100,100].
    \return Devuelve un entero que indica la próxima fase a ejecutar en la aplicación (menú o salir).
*/
int Analisis (int Intervalo)
{
    Pantalla_DibujaRellenoFondo(10,10,10,30);
    AnalisisOpciones ();        //Nueva funcion, volver al menu
    AnalisisEjes(Intervalo);    //Dibuja los ejes en funcion del intervalo
    Pantalla_Actualiza();
    Pantalla_Espera (50);

    Grafico graf = GraficoCrea();  //Creamos un nuevo grafico
    int Fase = Intervalo;   //Fase sera 3, 4 o 5
    while ((Fase != 0)&&(Fase != 1) && Pantalla_Activa())
    {
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_Q))      //Si 'q' esta pulsado, saldremos
            Fase = 0;
        else if (VolverMenu())
            Fase = 1;
        else if (AnalisisIntroducirFuncion ())          //Iniciamos el proceso para introducir una funcion
        {
            Pantalla_DibujaRellenoFondo(10,10,10,30);
            MuestraTeclado();                           //Muestra el teclado interactivo con las funciones
            Pantalla_Actualiza();
            Funcion f = AnalisisLeeFuncion();
            if (f != NULL)                              //Si hemos introducido correctamente la funcion
            {
                FuncionInicializa(f, Intervalo, FICHERO_GUARDADO);
                GraficoInserta(graf, f);
            }
            else
                GraficoEliminaPrimero(graf);
            Pantalla_DibujaRellenoFondo(10,10,10,30);
            AnalisisOpciones ();
            AnalisisEjes(Intervalo);
            GraficoRepresenta(graf, Intervalo);         //Dibujamos el grafico y todas sus funciones asociadas
        }
        Pantalla_Actualiza();
        Pantalla_Espera (100);
    }
    GraficoLibera(graf);
    return Fase;
}

int main (int argc, char ** argv)
{
    Pantalla_Crea("Funciones", PantallaAncho, PantallaAlto);
    int Finalizar = 0;
    int Fase = 1;           //0, 1, 2: Salir, Menu, Ayuda.
    while (!Finalizar && Pantalla_Activa())
    {
        switch (Fase)
        {
            case 0 :    Finalizar = 1;      //Salida
                        break;
            case 1 :    Fase = Menu();
                        break;
            case 2 :    Fase = Ayuda();
                        break;
            default :   Fase = Analisis(Fase);  //Fase solo puede ser 3, 4 o 5, dependiendo del intervalo seleccionado
                        break;
        }
        Pantalla_Espera(50);
    }
    Pantalla_Libera();
    return 0;
}
