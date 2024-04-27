/*************************************************************************/
/*                                                                       */
/*   examinar.c                                                          */
/*   Rev. 2.0  01/01/2002   AUTORES: O. Belmonte, M. Chover, J. Ribelles */
/*                                                                       */
/*************************************************************************/

/***************** INCLUDES DE LAS LIBRERIAS NECESARIAS ******************/
#include "glut.h"
#include <stdio.h>
#include <math.h>
#include "examinar.h"
#include "glig.h"
#include "luces.h"
#include "material.h"
#include "modelado.h"


/******************************************************************************************/
/* Establece el area visible y el tipo de proyeccion                                      */
/* Parametros: int ancho --> Ancho del area visible                                       */
/*             int alto --> Alto del area visible                                         */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void TamanyoVentana (GLsizei ancho, GLsizei alto)
{
    /* Definicion del viewport */
	glViewport(0, 0, ancho, alto);  

    /* Definicion de la vista */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	gluPerspective (60.0, (GLdouble)alto/(GLdouble)ancho, 1.0, 400.0);
}

/******************************************************************************************/
/* Abre una ventana OpenGL                                                                */
/* Parametros: int numeroArgumentos --> El numero de argumentos en la llamada al programa */
/*             char ** listaArgumentos --> Vector de cadenas con cada argumento           */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void AbreVentana (int numeroArgumentos, char ** listaArgumentos)
{
	glutInit(&numeroArgumentos, listaArgumentos);
	/* Cambia los parametros para utilizar doble buffer */
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize (VentanaAncho, VentanaAlto);
	glutInitWindowPosition (VentanaX, VentanaY);
	glutCreateWindow (listaArgumentos[0]);
	glutDisplayFunc (Dibuja);
	glutReshapeFunc (TamanyoVentana);
}


/******************************************************************************************/
/* Define las acciones tras una pulsacion del teclado                                     */
/* Parametros: unsigned char key --> Codigo de la tecla pulsada                           */
/*             int x --> Coordenada x del cursor en el momento de pulsar la tecla         */
/*             int y --> Coordenada y del cursor en el momento de pulsar la tecla         */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void Teclado (unsigned char tecla, int x, int y)
{
	switch (tecla)
	{
		case 27 : /* Codigo de la tecla de Escape */
			exit (0);
			break;

		case 'w' :
			modo = WALK;
			printf ("Modo = WALK      \r");
			break;

		case 'e' :
			modo = EXAMINAR;
			printf ("Modo = EXAMINAR    \r");
			break;

		case 'f' :
			modo = FLY;
			printf ("Modo = FLY      \r");
			break;
		case ' ': /* Pulsacion cursor abajo del teclado ampliado */
			on = !on;
			/*int tiempo2 = glutGet(GLUT_ELAPSED_TIME);
			int lapse = tiempo2 - tiempo1;
			printf_s("LLEGA A OnIdle");
			if (lapse > 0 & on == 1) {
				Animacion(lapse);
				
			}
			Animacion(0);*/
			glutPostRedisplay();
			break;
	}
}


/******************************************************************************************/
/* Define las acciones tras una pulsacion del teclado ampliado                            */
/* Parametros: unsigned char key --> Codigo de la tecla pulsada                           */
/*             int x --> Coordenada x del cursor en el momento de pulsar la tecla         */
/*             int y --> Coordenada y del cursor en el momento de pulsar la tecla         */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void TecladoAmpliado (int tecla, int x, int y)
{
	switch (tecla)
	{
		case GLUT_KEY_PAGE_UP :
			if (modo == FLY)
			{
				beta = beta + 1.50;
				if (beta > 360.0) beta = beta - 360.0;
				iy = oy + PASO * sin (grad2rad (beta));
			}
			break;
		case GLUT_KEY_UP : /* Pulsacion cursor arriba del teclado ampliado */
			if (modo == WALK || modo == FLY)
			{
				ox = ix;
				oz = iz;
				ix = ox + PASO * sin(grad2rad(alfa));
				iz = oz - PASO * cos(grad2rad(alfa));
				if (modo == FLY)
				{
					oy = iy;
					iy = iy + PASO * sin (grad2rad (beta));
				}
			}
			else if (modo == EXAMINAR)
			{
				beta = beta + 1.50;
				if (beta > 360.0) beta = beta - 360.0;
				iy = oy + PASO * sin (grad2rad (beta));
			}
			break;

		case GLUT_KEY_PAGE_DOWN :
			if (modo == FLY)
			{
				beta = beta - 1.50;
				if (beta > 360.0) beta = beta - 360.0;
				iy = oy + PASO * sin (grad2rad (beta));
			}
			break;
		case GLUT_KEY_DOWN : /* Pulsacion cursor abajo del teclado ampliado */
			if (modo == WALK || modo == FLY)
			{
				ox = ox - (ix-ox);
				oz = oz - (iz-oz);
				ix = ox + PASO * sin(grad2rad(alfa));
				iz = oz - PASO * cos(grad2rad(alfa));
				if (modo == FLY)
				{
					iy = oy;
					oy = oy - PASO * sin (grad2rad (beta));
				}
			}
			else if (modo == EXAMINAR)
			{
				beta = beta - 1.50;
				if (beta < 0.0) beta = beta + 360.0;
				iy = oy + PASO * sin (grad2rad (beta));
			}
			break;

		case GLUT_KEY_RIGHT : /* Pulsacion cursor derecha del teclado ampliado */
			alfa = alfa + 15.0;
			if (alfa > 360.0) alfa = alfa - 360.0;
			ix = ox + PASO * sin(grad2rad(alfa));
			iz = oz - PASO * cos(grad2rad(alfa));
			break;

		case GLUT_KEY_LEFT : /* Pulsacion cursor izquierda del teclado ampliado */
			alfa = alfa - 15.0;
			if (alfa < 0.0) alfa = alfa + 360.0;
			ix = ox + PASO * sin(grad2rad(alfa));
			iz = oz - PASO * cos(grad2rad(alfa));
			break;
	}
	glutPostRedisplay ();
}


/* Rutina de definición de eventos */
/******************************************************************************************/
/* Inicia las funciones de callback                                                       */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void IniciaFuncionesCallback (void)
{
	glutKeyboardFunc (Teclado);
	glutSpecialFunc (TecladoAmpliado);
	
}
/******************************************************************************************/
/* Funcion de dibujado                                                                    */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void Dibuja (void)
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 
    /* Transformacion de la camara */
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//glDisable(GL_LIGHTING);

	
	gluLookAt(ox, oy, oz, ix, iy, iz, 0, 1, 0);
	/* Defino y activo las luces */
	Luz0 ();
	//Luz1 ();
	//Luz2 ();
	/* Llamadas a las display lists */

	//Animacion de hélices
	if (on) {
		//si esta encendido activo helices
		//angleHelices += 60.0f*ms/1000.0f;
		angleHelices += 30.0f;
		if (angleHelices > 360.0) {
			angleHelices = angleHelices - 360.0;
		}
	}
	glPushMatrix();
		textura3();
		glTranslated(0.0, 1.1, 0.0);
		glScalef(2.7, 2.7, 2.7);
		Dibuja_helicoptero();
	glPopMatrix();

	glPushMatrix();
		textura1();
		glScaled(3.0f,3.0f, 3.0f);
		glTranslatef(0.0, 0.32, 0.0);
		glCallList(base);
	glPopMatrix();

	

	glPushMatrix();
		textura0();
		glCallList(terreno);
	glPopMatrix();
	
	/* Utiliza la funcion de la glut que intercambia los buffers */
	glutSwapBuffers ();
	glutPostRedisplay();
}

void Dibuja_helicoptero(void) {
	
	glPushMatrix();
		glPushMatrix();
			glScalef(0.55, 0.55, 0.55);
			glTranslatef(0.0, 1.3, 0.0);
			glPushMatrix();
				glScalef(1.4, 1.1, 0.6);
			Dibuja_cuerpo();
			glPopMatrix();
		glPopMatrix();

		glScalef(0.55, 0.55, 0.55);
		glTranslatef(0.0, 1.3, 0.0);
		//dibujar hélices en movimiento
		Dibuja_Helices(angleHelices);
		
		Dibuja_TrenAterrizaje();
	glPopMatrix();
}
void Dibuja_cuerpo(void) {

	glPushMatrix();
		//Escalar aqui el cuerpo entero 	
		glPushMatrix();	
			glCallList(cuerpo);
		glPopMatrix();
		glPushMatrix();
			glScalef(1.0, 1.0, 2.2);
			glTranslatef(-2.28, 1.0, 0.48);
			glRotatef(180, 0.0, 1.0, 0.0);
			glCallList(parteTrasera);
			glPopMatrix();
		glPushMatrix();
			glTranslatef(1.0, 0.0, 0.0);
			glRotatef(90, 0.0, 1.0, 0.0);
			glCallList(morro);
		glPopMatrix();
	glPopMatrix();


}
void Dibuja_TrenAterrizaje(void) {

	glPushMatrix();
		glTranslatef(0.8, -0.24, -0.1);
		glScalef(0.2, 0.2, 0.2);
		glCallList(trenAterrizaje);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.7, -0.24, -0.5);
		glScalef(0.2, 0.2, 0.2);
		glCallList(trenAterrizaje);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.7, -0.24, 0.3);
		glScalef(0.2, 0.2, 0.2);
		glCallList(trenAterrizaje);
	glPopMatrix();
}
void Dibuja_Helices() {

	glPushMatrix();
		glScalef(0.8, 0.8, 0.8);
		glTranslatef(0.0, 1.2, 2.7);
		glPushMatrix();
		glScalef(0.5f, 0.5f, 0.5f);
		glCallList(soporteHelice);
		glPopMatrix();

		glPushMatrix();
		glRotatef(angleHelices, 0.0, 1.0, 0.0);
		glTranslatef(0.0, 0.6, 0.0);
		glCallList(helices);
		glPopMatrix();
		glPopMatrix();

		glPushMatrix();
		glScalef(0.8, 0.8, 0.8);
		glTranslatef(0.0, 1.2, -2.7);
		glPushMatrix();
		glScalef(0.5f, 0.5f, 0.5f);
		glCallList(soporteHelice);
		glPopMatrix();

		glPushMatrix();
		glRotatef(angleHelices, 0.0, 1.0, 0.0);
		glTranslatef(0.0, 0.6, 0.0);
		glCallList(helices);
		glPopMatrix();
	glPopMatrix();
}

/******************************************************************************************/
/* Inicia caracteristicas de la visualizacion OpenGL                                      */
/* Parametros: Ninguno.                                                                   */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void IniciaOpenGL (void)
{
	glClearColor (0.0f, 0.0f, 0.0f, 0.0f); /* Establece el color de borrado */
	//glColor3f (1.0f, 1.0f, 1.0f); /* Establece el color de dibujo */

	/* Especifica el tipo de la comparación en el Z-buffer */
	//glDepthFunc (GL_LEQUAL);

	/* Activa el Z-buffer */
	glEnable (GL_DEPTH_TEST);

	/* Habilita eliminación de caras */
	//glCullFace (GL_BACK);
	glEnable (GL_CULL_FACE);

	/* Elige las caras a eliminar y define que se va a pintar en sentido horario*/
	glFrontFace (GL_CCW);
	
	/* Inicia las luces */
	//IniciaLuces();

	/* Inicia los materiales */
	IniciaMaterial();
}



/******************************************************************************************/
/* Funcion principal                                                                      */
/* Parametros: int numeroArgumentos --> El numero de argumentos en la llamada al programa */
/*             char ** listaArgumentos --> Vector de cadenas con cada argumento           */
/* Salida: Un entero que se devuelve al sistema al acabar la ejecucion del programa       */
/******************************************************************************************/
int main(int numArgumentos, char ** listaArgumentos)
{	
	/* Creación de la ventana de la aplicación */
	AbreVentana (numArgumentos, listaArgumentos);

	/* Llamada a las funciones de inicializacion */
	IniciaOpenGL ();

	/* Rutinas para el control de eventos */
    IniciaFuncionesCallback ();

	initTextura0 ("oceano.tga");
	initTextura1 ("metal_oxidado.tga");
	initTextura2("cielo.tga");
	initTextura3("metal_cuerpo_1.tga");
	initTextura4("cristal_naranja.tga");
	initTextura5("helices.tga");
	/* Creo la display list de la escena */
	//CreaEscenaIluminacion ();

	IniciaDisplayLists();
	printf ("Modo = WALK\r");
	
	/* A la espera de eventos.... */
	glutMainLoop();

	return (0);
}

