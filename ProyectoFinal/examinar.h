/*************************************************************************/
/*                                                                       */
/*   examinar.h                                                          */
/*   Rev. 2.0  01/01/2002   AUTORES: O. Belmonte, M. Chover, J. Ribelles */
/*                                                                       */
/*************************************************************************/

#ifndef EXAMINAR_H
#define EXAMINAR_H


/* Funcion de conversion de grados a radianes */
#define  grad2rad(x)  ((float) (3.14159 * x) / 180.0)
#define PASO 0.5 /* Definicion del paso para el movimiento del observador */

#define WALK 1
#define EXAMINAR 2
#define FLY 3

// ox: 18.73 , oy 6.29 , oz 13.18 ,ix 18.30 , iy 6.14 , iz 12.93

/* Variables Globales del modulo */
int VentanaAncho = 500, VentanaAlto = 500; /* Tamanyo de la ventana */
int VentanaX = 100, VentanaY = 100; /* Posicion de la ventana */
GLdouble  alfa = 240.0, beta = 0.0, gamma=0.0, z=0.0;
GLuint cuadrica;
double ox= 12.11, oy= 7.70, oz= -5.88; /* Posicion del observador */
double ix= 11.67, iy= 7.54, iz= -5.63 -PASO; /* Posicion del punto de interes  iz antes estaba a 5*/
int w=1, a=1;
int modo = WALK;
float on = 1;
float angleHelices = 0.0;
int tiempo1 = 0;//milisegundos

/* Abre una ventana OpenGL */
void AbreVentana (int numeroArgumentos, char ** listaArgumentos);

/* Inicia parametros de la OpenGL */
void IniciaOpenGL (void);

/* Funcion de dibujado */
void Dibuja(void);

/* Establece el area visible */
void TamanyoVentana (int alto, int ancho);

/* Inicia las funciones de Callback */
void IniciaFuncionesCallback (void);

/* Define las acciones tras una pulsacion del teclado */
void Teclado (unsigned char tecla, int x, int y);

void Dibuja_helicoptero(void);
void Dibuja_cuerpo(void);
void Dibuja_Helices(void);
void Dibuja_TrenAterrizaje(void);
void Animacion(int ms);
#endif