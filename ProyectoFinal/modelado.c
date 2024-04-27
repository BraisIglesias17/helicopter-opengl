/*************************************************************************/
/*                                                                       */
/*   modelado.c                                                          */
/*   27/10/03  AUTORES: C.Rebollo                                        */
/*                                                                       */
/*************************************************************************/

/***************** INCLUDES DE LAS LIBRERIAS NECESARIAS ******************/
#include "glig.h"
#include "modelado.h"
#include "math.h"

/******************************************************************************************/
/* Crea los distintos objetos. En este caso iun abeto, si tuviese mas objetos, los pòndría*/
/* a continuación.                                                                        */
/* Parametros: ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void IniciaDisplayLists (void)
{
    CreaCuerpo();
	CreaParabrisas();
	CreaMorro();
	CreaParteTrasera();
	CreaTerreno();
	CreaCuerpo();
	CreaParabrisas();
	CreaMorro();
	CrearTrenAterrizaje();
	CreaSoporteHelice();
	CreaHelices();
	CreaCola();
	CreaParteTrasera();
	CreaTerreno();
	CreaBase();
	
}


void CreaCuerpo(void) {
	cuerpo = glGenLists(1);
	if (cuerpo != 0) /* Cero no es un identificador valido para una display list */
	{
		glNewList(cuerpo, GL_COMPILE);

		glPushMatrix();
		    
		
			glPushMatrix();
				glScalef(0.4f, 0.4f, 0.4f);
				glBegin(GL_POLYGON);
					glTexCoord2f(0, 1);
					glVertex3f(2.5f, 0.0f, 1.5f);
					glTexCoord2f(1.0, 1.0);
					glVertex3f(2.5f, 0.0f, -1.5f);
					glTexCoord2f(1.0,0.0);
					glVertex3f(2.5f, 2.7f, -1.5f);
					glTexCoord2f(0.0, 0.0);
					glVertex3f(2.5f, 2.7f, 1.5f);
					//glTexCoord2f(0, 0);
				
					
				glEnd();

			glPopMatrix();
			
			glPushMatrix();
				glScalef(0.4f, 0.4f, 0.4f);
				glBegin(GL_POLYGON);
			       glTexCoord2f(1.0,1.0);
					glVertex3f(2.5f, 2.7f, 1.5f);
					glTexCoord2f(0.0,1.0);
					glVertex3f(-4.5f, 2.7f, 1.5f);
					glTexCoord2f(0.0, 0.7f);
					glVertex3f(-4.5f, 2.3f, 1.5f);
					glTexCoord2f(0.3f, 0.0);
					glVertex3f(-2.5f, 0.0f, 1.5f);
					glTexCoord2f(1.0, 0.0);
					glVertex3f(2.5f, 0.0f, 1.5f);
				glEnd();

			glPopMatrix();
			
			//parte de arriba
			glPushMatrix();
				glScalef(0.4f, 0.4f, 0.4f);
				glBegin(GL_POLYGON);

				glTexCoord2f(1.0, 1.0);
					glVertex3f(2.5f, 2.7f, -1.5f);
					glTexCoord2f(0.0, 0.0);
					glVertex3f(-4.5f, 2.7f,-1.5f);
					glTexCoord2f(0.0, 1.0);
					glVertex3f(-4.5f, 2.7f, 1.5f);
					glTexCoord2f(1.0,0.0);
					glVertex3f(2.5f, 2.7f, 1.5f);
	
				glEnd();

			glPopMatrix();

			glPushMatrix();
				glScalef(0.4f, 0.4f, 0.4f);
				glBegin(GL_POLYGON);

				glTexCoord2f(0.0f, 0.0f);
					glVertex3f(2.5f, 0.0f, -1.5f);
					glTexCoord2f(0.7f, 0.0f);
					
					glVertex3f(-2.5f, 0.0f, -1.5f);
					glTexCoord2f(1.0f, 0.7f);
					
					glVertex3f(-4.5f, 2.3f, -1.5f);
					glTexCoord2f(1.0f, 1.5f);
					
					glVertex3f(-4.5f, 2.7f, -1.5f);
					glTexCoord2f(1.0f, 0.0f);
					
					glVertex3f(2.5f, 2.7f, -1.5f);
					
				glEnd();

			glPopMatrix();
			

			
			glPopMatrix();

			glPushMatrix();
				glScalef(0.4f, 0.4f, 0.4f);
				glBegin(GL_POLYGON);

				glTexCoord2f(0.0, 0.0);
					glVertex3f(-4.5f, 2.3f, 1.5f);
					glTexCoord2f(0.0, 1.0);
					glVertex3f(-4.5f, 2.3f, -1.5f);
					glTexCoord2f(1.0, 1.0);
					glVertex3f(-4.5f, 2.7f, -1.5f);
					glTexCoord2f(1.0, 0.0);
					glVertex3f(-4.5f, 2.7f, 1.5f);
				glEnd();

			glPopMatrix();
			
			glPushMatrix();
				glScalef(0.4f, 0.4f, 0.4f);
				glBegin(GL_POLYGON);

				glTexCoord2f(0.0, 0.0);
					glVertex3f(-4.5f, 2.3f, 1.5f);
					glTexCoord2f(0.0, 1.0);
					glVertex3f(-4.5f, 2.3f, -1.5f);
					glTexCoord2f(1.0,1.0);
					glVertex3f(-2.5f, 0.0f, -1.5f);
					glTexCoord2f(1.0, 0.0);
					glVertex3f(-2.5f, 0.0f, 1.5f);
				glEnd();
			glPopMatrix();
			
			//extension
			
			
			glPushMatrix();
				glScalef(0.4f, 0.4f, 0.4f);
				glBegin(GL_POLYGON);
				glTexCoord2f(0.0,0.0);
					glVertex3f(-4.5f, 2.7f, 1.5f);
					glTexCoord2f(0.0, 1.0);
					glVertex3f(-5.7f, 3.0f, 1.5f);
					glTexCoord2f(1.0, 1.0);
					glVertex3f(-5.7f, 2.6f, 1.5f);
					glTexCoord2f(1.0, 0.0);
					glVertex3f(-4.5f, 2.3f, 1.5f);
				glEnd();
			glPopMatrix();
			
			glPushMatrix();
				glScalef(0.4f, 0.4f, 0.4f);
				glBegin(GL_POLYGON);

				glTexCoord2f(0.0, 0.0);
					glVertex3f(-4.5f, 2.3f, -1.5f);
					glTexCoord2f(0.0, 1.0);
					glVertex3f(-5.7f, 2.6f, -1.5f);
					glTexCoord2f(1.0, 1.0);
					glVertex3f(-5.7f, 3.0f, -1.5f);
					glTexCoord2f(1.0, 0.0);
					glVertex3f(-4.5f, 2.7f, -1.5f);
				glEnd();
			glPopMatrix();
			
			glPushMatrix();
				glScalef(0.4f, 0.4f, 0.4f);
				glBegin(GL_POLYGON);
				glTexCoord2f(0.0, 0.0);
					glVertex3f(-5.7f, 3.0f, 1.5f);
					glTexCoord2f(0.0,1.0);
					glVertex3f(-4.5f, 2.7f, 1.5f);
					glTexCoord2f(1.0, 1.0);
					glVertex3f(-4.5f, 2.7f, -1.5f);
					glTexCoord2f(1.0, 0.0);
					glVertex3f(-5.7f, 3.0f, -1.5f);
				glEnd();
			glPopMatrix();
			
			glPushMatrix();
				glScalef(0.4f, 0.4f, 0.4f);
				glBegin(GL_POLYGON);
				glTexCoord2f(0.0, 0.0);
					glVertex3f(-5.7f, 2.6f, -1.5f);
					glTexCoord2f(0.0,1.0);
					glVertex3f(-4.5f, 2.3f, -1.5f);
					glTexCoord2f(1.0, 1.0);
					glVertex3f(-4.5f, 2.3f, 1.5f);
					glTexCoord2f(1.0, 0.0);
					glVertex3f(-5.7f, 2.6f, 1.5f);
			
				glEnd();
			glPopMatrix();
			
			//parabrisas
			
			textura5();
			glPushMatrix();
				glScalef(0.4f, 0.4f, 0.4f);
				glBegin(GL_POLYGON);
				glTexCoord2f(0.0, 0.0);
					glVertex3f(2.5f, 1.5f, 1.5f);
					glTexCoord2f(0.0, 1.0);
					glVertex3f(3.5f, 1.5f, 1.0f);
					glTexCoord2f(1.0, 1.0);
					glVertex3f(2.5f, 2.7f, 1.5f);
				glEnd();
			glPopMatrix();

			glPushMatrix();
				glScalef(0.4f, 0.4f, 0.4f);
				glBegin(GL_POLYGON);
				glTexCoord2f(0.0, 0.0);
					glVertex3f(2.5f, 2.7f, -1.5f);
					glTexCoord2f(0.0, 1.0);
					glVertex3f(3.5f, 1.5f, -1.0f);
					glTexCoord2f(1.0, 1.0);
					glVertex3f(2.5f, 1.5f, -1.5f);
				glEnd();
			glPopMatrix();

			glPushMatrix();
				glScalef(0.4f, 0.4f, 0.4f);
				glBegin(GL_POLYGON);
				
				glTexCoord2f(0.0, 0.0);
				glVertex3f(2.5f, 2.7f, 1.5f);
				glTexCoord2f(1.0, 0.0);
				glVertex3f(3.5f, 1.5f, 1.0f);
				glTexCoord2f(1.0, 1.0);
				glVertex3f(3.5f, 1.5f, -1.0f);
				glTexCoord2f(0.0, 1.0);
				glVertex3f(2.5f, 2.7f, -1.5f);
				glEnd();
			glPopMatrix();

			textura3();
			//FALTA PARTE SUPERIOR Y PARTE INFERIOR

			//superior
			glPushMatrix();
				glScalef(0.4f, 0.4f, 0.4f);
				glBegin(GL_POLYGON);
					//cambiado ya correctamente
				glTexCoord2f(0.0, 0.0);
					glVertex3f(2.5f, 2.7f, 1.5f);
					glTexCoord2f(0.0, 1.0);
					glVertex3f(3.5f, 1.5f, 1.0f);
					glTexCoord2f(1.0, 1.0);
					glVertex3f(3.5f, 1.5f, -1.0f);
					glTexCoord2f(1.0, 0.0);
					glVertex3f(2.5f, 2.7f, -1.5f);
				glEnd();
			glPopMatrix();
			
			// Parte Inferior
			glPushMatrix();
				glScalef(0.4f, 0.4f, 0.4f);
				glBegin(GL_POLYGON);	
					//Cambiado ya correctamente
				glTexCoord2f(0.0, 0.0);
					glVertex3f(-2.5f, 0.0f, -1.5f);
					glTexCoord2f(0.0, 1.0);
					glVertex3f(2.5f, 0.0f, -1.5f);
					glTexCoord2f(1.0, 1.0);
					glVertex3f(2.5f, 0.0f, 1.5f);
					glTexCoord2f(1.0, 0.0);
					glVertex3f(-2.5f, 0.0f, 1.5f);
				glEnd();
			glPopMatrix();

			//PARA ABRIR LA PUERTA DE ATRÁS
			/*glPushMatrix();
				glScalef(0.4f, 0.4f, 0.4f);
				glBegin(GL_POLYGON);
					glVertex3f(-2.5f, 0.0f, -1.5f);
					glVertex3f(-4.5f, 1.5f, -1.5f);
					glVertex3f(-4.5f, 1.5f, 1.5f);
					glVertex3f(-2.5f, 0.0f, 1.5f);
					glVertex3f(-2.5f, 0.0f, -1.5f);
				glEnd();
			glPopMatrix();*/


			//Salientes laterales
			
			glPushMatrix();
				glScalef(0.4f, 0.4f, 0.4f);
				glBegin(GL_POLYGON);
				glTexCoord2f(0.0, 0.0);
					glVertex3f(-2.4f, 0.0f, 1.5f);
					glTexCoord2f(0.0, 1.0);
					glVertex3f(-1.8f, 0.0f, 2.5f);
					glTexCoord2f(1.0, 1.0);
					glVertex3f(-1.8f, 1.5f, 2.5f);
					glTexCoord2f(1.0, 0.0);
					glVertex3f(-2.4f, 1.5f, 1.5f);
					
				glEnd();
			glPopMatrix();
			
			glPushMatrix();
				glScalef(0.4f, 0.4f, 0.4f);
					glBegin(GL_POLYGON);
					glTexCoord2f(0.0, 0.0);
					glVertex3f(0.9f, 1.5f, 1.5f);
					glTexCoord2f(0.0, 1.0);
					glVertex3f(0.2f, 1.5f, 2.5f);
					glTexCoord2f(1.0, 1.0);
					glVertex3f(0.2f, 0.0f, 2.5f);
					glTexCoord2f(1.0, 0.0);
					glVertex3f(0.9f, 0.0f, 1.5f);
					
				glEnd();
			glPopMatrix();
			
			glPushMatrix();
				glScalef(0.4f, 0.4f, 0.4f);
				glBegin(GL_POLYGON);
				glTexCoord2f(0.0, 0.0);
					glVertex3f(-2.4f, 1.5f, 1.5f);
					glTexCoord2f(0.0, 1.0);
					glVertex3f(-1.8f, 1.5f, 2.5f);
					glTexCoord2f(1.0, 1.0);
					glVertex3f(0.2f, 1.5f, 2.5f);
					glTexCoord2f(1.0, 0.0);
					glVertex3f(0.9f, 1.5f, 1.5f);
				glEnd();
			glPopMatrix();
			
			glPushMatrix();
				glScalef(0.4f, 0.4f, 0.4f);
				glBegin(GL_POLYGON);
				glTexCoord2f(0.0, 0.0);
					glVertex3f(0.9f, 0.0f, 1.5f);
					glTexCoord2f(0.0, 1.0);
					glVertex3f(0.2f, 0.0f, 2.5f);
					glTexCoord2f(1.0, 1.0);
					glVertex3f(-1.8f, 0.0f, 2.5f);
					glTexCoord2f(1.0, 0.0);
					glVertex3f(-2.4f, 0.0f, 1.5f);
				glEnd();
			glPopMatrix();
			
			glPushMatrix();
				glScalef(0.4f, 0.4f, 0.4f);
				glBegin(GL_POLYGON);
				glTexCoord2f(0.0, 0.0);
					glVertex3f(0.2f, 1.5f, 2.5f);
					glTexCoord2f(0.0, 1.0);
					glVertex3f(-1.8f, 1.5f, 2.5f);
					glTexCoord2f(1.0, 1.0);
					glVertex3f(-1.8f, 0.0f, 2.5f);
					glTexCoord2f(1.0, 0.0);
					glVertex3f(0.2f, 0.0f, 2.5f);
				glEnd();
			glPopMatrix();
			
			glPushMatrix();
				glScalef(0.4f, 0.4f, 0.4f);
				glBegin(GL_POLYGON);
				glTexCoord2f(0.0, 0.0);
					glVertex3f(-2.4f, 1.5f, 1.5f);
					glTexCoord2f(0.0, 1.0);
					glVertex3f(-1.8f, 1.5f, 2.5f);
					glTexCoord2f(1.0, 1.0);
					glVertex3f(-1.8f, 0.0f, 2.5f);
					glTexCoord2f(1.0, 0.0);
					glVertex3f(-2.4f, 0.0f, 1.5f);
				glEnd();
			glPopMatrix();
			
			glPushMatrix();
				glScalef(0.4f, 0.4f, 0.4f);
					glBegin(GL_POLYGON);
					glTexCoord2f(0.0, 0.0);
					glVertex3f(0.9f, 1.5f, 1.5f);
					glTexCoord2f(0.0, 1.0);
					glVertex3f(0.2f, 1.5f, 2.5f);
					glTexCoord2f(1.0, 1.0);
					glVertex3f(0.2f, 0.0f, 2.5f);
					glTexCoord2f(1.0, 0.0);
					glVertex3f(0.9f, 0.0f, 1.5f);
				glEnd();
			glPopMatrix();
			
			glPushMatrix();
				glScalef(0.4f, 0.4f, 0.4f);
				glBegin(GL_POLYGON);
				glTexCoord2f(0.0, 0.0);
					glVertex3f(-2.4f, 1.5f, 1.5f);
					glTexCoord2f(1.0, 0.0);
					glVertex3f(-1.8f, 1.5f, 2.5f);
					glTexCoord2f(1.0, 1.0);
					glVertex3f(0.2f, 1.5f, 2.5f);
					glTexCoord2f(0.0, 1.0);
					glVertex3f(0.9f, 1.5f, 1.5f);
				glEnd();
			glPopMatrix();
			
			glPushMatrix();
				glScalef(0.4f, 0.4f, 0.4f);
				glBegin(GL_POLYGON);
					
					glTexCoord2f(0.0, 0.0);
					glVertex3f(0.9f, 0.0f, 1.5f);
					glTexCoord2f(0.0, 1.0);
					glVertex3f(0.2f, 0.0f, 2.5f);
					glTexCoord2f(1.0, 1.0);
					glVertex3f(-1.8f, 0.0f, 2.5f);
					glTexCoord2f(1.0, 0.0);
					glVertex3f(-2.4f, 0.0f, 1.5f);
				glEnd();
			glPopMatrix();
			
			glPushMatrix();
				glScalef(0.4f, 0.4f, 0.4f);
				glBegin(GL_POLYGON);
	
				glTexCoord2f(0.0, 0.0);
					glVertex3f(0.2f, 1.5f, 2.5f);
					glTexCoord2f(0.0, 1.0);
					glVertex3f(-1.8f, 1.5f, 2.5f);
					glTexCoord2f(1.0, 1.0);
					glVertex3f(-1.8f, 0.0f, 2.5f);
					glTexCoord2f(1.0, 0.0);
					glVertex3f(0.2f, 0.0f, 2.5f);
				glEnd();
			glPopMatrix();
			
			
			
			glPushMatrix();
				glScalef(0.4f, 0.4f, 0.4f);
				glBegin(GL_POLYGON);
				glTexCoord2f(0.0, 0.0);
					glVertex3f(-2.4f, 1.5f, -1.5f);
					glTexCoord2f(0.0, 1.0);
					glVertex3f(-1.8f, 1.5f, -2.5f);
					glTexCoord2f(1.0, 1.0);
					glVertex3f(-1.8f, 0.0f, -2.5f);
					glTexCoord2f(1.0, 0.0);
					glVertex3f(-2.4f, 0.0f, -1.5f);
					
				glEnd();
			glPopMatrix();
			
			glPushMatrix();
				glScalef(0.4f, 0.4f, 0.4f);
					glBegin(GL_POLYGON);
					//esta bien
					glTexCoord2f(0.0, 0.0);
					glVertex3f(0.9f, 0.0f, -1.5f);
					glTexCoord2f(0.0, 1.0);
					glVertex3f(0.2f, 0.0f, -2.5f);
					glTexCoord2f(1.0, 1.0);
					glVertex3f(0.2f, 1.5f, -2.5f);
					glTexCoord2f(1.0, 0.0);
					glVertex3f(0.9f, 1.5f, -1.5f);
				glEnd();
			glPopMatrix();
			
			glPushMatrix();
				glScalef(0.4f, 0.4f, 0.4f);
					glBegin(GL_POLYGON);
					glTexCoord2f(0.0, 0.0);
					glVertex3f(0.9f, 1.5f, -1.5f);
					glTexCoord2f(0.0, 1.0);
					glVertex3f(0.2f, 1.5f, -2.5f);
					glTexCoord2f(1.0, 1.0);
					glVertex3f(-1.8f, 1.5f, -2.5f);
					glTexCoord2f(1.0, 0.0);
					glVertex3f(-2.4f, 1.5f, -1.5f);
				glEnd();
			glPopMatrix();
			
			glPushMatrix();
				glScalef(0.4f, 0.4f, 0.4f);
				glBegin(GL_POLYGON);
				glTexCoord2f(0.0, 0.0);
					glVertex3f(-2.4f, 0.0f, -1.5f);
					glTexCoord2f(1.0, 0.0);
					glVertex3f(-1.8f, 0.0f, -2.5f);
					glTexCoord2f(1.0, 1.0);
					glVertex3f(0.2f, 0.0f, -2.5f);
					glTexCoord2f(0.0, 1.0);
					glVertex3f(0.9f, 0.0f, -1.5f);
				glEnd();
			glPopMatrix();
			
			glPushMatrix();
				glScalef(0.4f, 0.4f, 0.4f);
				glBegin(GL_POLYGON);
					//ESTA BIEN YA
				glTexCoord2f(0.0, 0.0);
					glVertex3f(0.2f, 0.0f, -2.5f);
					glTexCoord2f(0.0, 1.0);
					glVertex3f(-1.8f, 0.0f, -2.5f);
					glTexCoord2f(1.0, 1.0);
					glVertex3f(-1.8f, 1.5f, -2.5f);
					glTexCoord2f(1.0, 0.0);
					glVertex3f(0.2f, 1.5f, -2.5f);
				glEnd();
			glPopMatrix();
			

			//Conector helices
			
			glPushMatrix();
				glScalef(1.0f, 0.4f, 1.0f);
				glTranslatef(0.0f,2.85f, 0.0f);
				glScalef(0.5f, 0.3f, 4.5f);
				glFrontFace(GL_CW);
				igSolidCube(1);
				glFrontFace(GL_CCW);
			glPopMatrix();

			/*glPushMatrix();
				glScalef(1.0f, 0.4f, 1.0f);
				glTranslatef(0.0f, 2.68f, 2.25f);
				glScalef(0.5f, 0.3f, 4.5f);
				glBegin(GL_POLYGON);
				
					glVertex3f(0.5f, 0.0f, 0.0f);
					glVertex3f(0.5f, 1.0f, 0.0f);
					glVertex3f(-0.5f, 1.0f, 0.0f);
					glVertex3f(-0.5f, 0.0f, 0.0f);
				glEnd();
			glPopMatrix();*/
			
			glPushMatrix();
				glScalef(1.0f, 0.4f, 1.0f);
				glTranslatef(0.0f, 2.7f,  2.25f);
				glScalef(0.5f, 0.3f, 4.5f);
				glBegin(GL_POLYGON);	
				glTexCoord2f(0.0, 0.0);
					glVertex3f(0.5f, 0.0f, 0.0f);
					glTexCoord2f(0.0, 1.0);
					glVertex3f(0.25f, 1.0f, 0.25f);
					glTexCoord2f(1.0, 1.0);
					glVertex3f(-0.25f, 1.0f, 0.25f);
					glTexCoord2f(1.0, 0.0);
					glVertex3f(-0.5f, 0.0f, 0.0f);
				glEnd();
			glPopMatrix();
			
			glPushMatrix();
				glScalef(1.0f, 0.4f, 1.0f);
				glTranslatef(0.0f, 2.7f, 2.25f);
				glScalef(0.5f, 0.3f, 4.5f);
				glBegin(GL_POLYGON);
				glTexCoord2f(0.0, 0.0);
					glVertex3f(-0.5f, 1.0f, 0.0f);
					glTexCoord2f(0.0, 1.0);
					glVertex3f(-0.25f, 1.0f, 0.25f);
					glTexCoord2f(1.0, 1.0);
					glVertex3f(0.25f, 1.0f, 0.25f);
					glTexCoord2f(1.0, 0.0);
					glVertex3f(0.5f, 1.0f, 0.0f);
				glEnd();
			glPopMatrix();
			
			glPushMatrix();
				glScalef(1.0f, 0.4f, 1.0f);
				glTranslatef(0.0f, 2.7f, 2.25f);
				glScalef(0.5f, 0.3f, 4.5f);
				glBegin(GL_POLYGON);
				glTexCoord2f(0.0, 0.0);
					glVertex3f(0.5f, 0.0f, 0.0f);
					glTexCoord2f(0.0, 1.0);
					glVertex3f(0.5f, 1.0f, 0.0f);
					glTexCoord2f(1.0, 1.0);
					glVertex3f(0.25f, 1.0f, 0.25f);
					glTexCoord2f(1.0, 0.0);
					glVertex3f(0.5f, 0.0f, 0.0f);
					
				glEnd();
			glPopMatrix();
			
			glPushMatrix();
				glScalef(1.0f, 0.4f, 1.0f);
				glTranslatef(0.0f, 2.7f, 2.25f);
				glScalef(0.5f, 0.3f, 4.5f);
				glBegin(GL_POLYGON);
				glTexCoord2f(0.0, 1.0);
					glVertex3f(-0.5f, 0.0f, 0.0f);
					glTexCoord2f(1.0, 1.0);
					glVertex3f(-0.25f, 1.0f, 0.25f);
					glTexCoord2f(1.0, 0.0);
					glVertex3f(-0.5f, 1.0f, 0.0f);
					glTexCoord2f(0.0, 0.0);
					glVertex3f(-0.5f, 0.0f, 0.0f);
			glEnd();
			glPopMatrix();
			
			//segundo extremo de conector
			glPushMatrix();
				glScalef(1.0f, 0.4f, 1.0f);
				glTranslatef(0.0f, 2.68f, -2.25f);
				glScalef(0.5f, 0.3f, 4.5f);
				glBegin(GL_POLYGON);
				glTexCoord2f(0.0, 0.0);
					glVertex3f(0.5f, 0.0f, 0.0f);	
					glTexCoord2f(0.0, 1.0);
					glVertex3f(0.5f, 1.0f, 0.0f);
					glTexCoord2f(1.0, 1.0);
					glVertex3f(-0.5f, 1.0f, 0.0f);
					glTexCoord2f(1.0, 0.0);
					glVertex3f(-0.5f, 0.0f, 0.0f);
				
				glEnd();
			glPopMatrix();
			
			glPushMatrix();
				glScalef(1.0f, 0.4f, 1.0f);
				glTranslatef(0.0f, 2.7f, -2.25f);
				glScalef(0.5f, 0.3f, 4.5f);
				glBegin(GL_POLYGON);
				glTexCoord2f(0.0, 0.0);
					glVertex3f(-0.5f, 0.0f, 0.0f);
					glTexCoord2f(0.0, 1.0);

					glVertex3f(-0.25f, 1.0f, -0.25f);
					glTexCoord2f(1.0, 1.0);
					glVertex3f(0.25f, 1.0f, -0.25f);
					glTexCoord2f(1.0, 0.0);
					glVertex3f(0.5f, 0.0f, 0.0f);
				glEnd();
			glPopMatrix();
			
			glPushMatrix();
				glScalef(1.0f, 0.4f, 1.0f);
				glTranslatef(0.0f, 2.7f, -2.25f);
				glScalef(0.5f, 0.3f, 4.5f);
				glBegin(GL_POLYGON);
				glTexCoord2f(0.0, 0.0);
					glVertex3f(0.5f, 1.0f, 0.0f);
					glTexCoord2f(0.0, 1.0);
					glVertex3f(0.25f, 1.0f, -0.25f);
					glTexCoord2f(1.0, 1.0);
					glVertex3f(-0.25f, 1.0f, -0.25f);
					glTexCoord2f(1.0, 0.0);
					glVertex3f(-0.5f, 1.0f, 0.0f);
				glEnd();
			glPopMatrix();
			
			glPushMatrix();
				glScalef(1.0f, 0.4f, 1.0f);
				glTranslatef(0.0f, 2.7f, -2.25f);
				glScalef(0.5f, 0.3f, 4.5f);
				glBegin(GL_POLYGON);
				glTexCoord2f(0.0, 0.0);
					glVertex3f(0.5f, 0.0f, 0.0f);
					glTexCoord2f(0.0, 1.0);
					glVertex3f(0.25f, 1.0f, -0.25f);
					glTexCoord2f(1.0, 1.0);
					glVertex3f(0.5f, 1.0f, 0.0f);
					
				glEnd();
			glPopMatrix();
			
			glPushMatrix();
				glScalef(1.0f, 0.4f, 1.0f);
				glTranslatef(0.0f, 2.7f, -2.25f);
				glScalef(0.5f, 0.3f, 4.5f);
				glBegin(GL_POLYGON);
				glTexCoord2f(0.0, 0.0);
					glVertex3f(-0.5f, 1.0f, 0.0f);
					glTexCoord2f(0.0, 1.0);
					glVertex3f(-0.25f, 1.0f, -0.25f);
					glTexCoord2f(1.0, 1.0);
					glVertex3f(-0.5f, 0.0f, 0.0f);
				glEnd();
			glPopMatrix();
			
		glPopMatrix();
		

		glEndList();
	}
}
void CreaParabrisas(void) {
	parabrisas = glGenLists(1);
	if (parabrisas != 0) /* Cero no es un identificador valido para una display list */
	{
		glNewList(parabrisas, GL_COMPILE);

		glPushMatrix();

		glPushMatrix();
		glScalef(0.8f, 0.8f, 0.8f);
			glBegin(GL_POLYGON);
				glVertex3f(-1.25f,0.0f,1.25f);
				glVertex3f(1.25f, 0.0f, 1.25f);
				glVertex3f(0.5f, 2.0f, 0.25f);
				glVertex3f(-0.5f, 2.0f, 0.25f);
				glVertex3f(-1.25f, 0.0f, 1.25f);
			glEnd();

		glPopMatrix();

		glPushMatrix();
		glScalef(0.8f, 0.8f, 0.8f);
		glBegin(GL_POLYGON);
			glVertex3f(1.25f, 0.0f, 1.25f);
			glVertex3f(1.75f, 0.0f, 0.5f);
			glVertex3f(0.5f, 2.0f, 0.25f);
		glEnd();

		glPopMatrix();

		glPopMatrix();

		glPushMatrix();
		glScalef(0.8f, 0.8f, 0.8f);
		glBegin(GL_POLYGON);
			glVertex3f(-1.25f, 0.0f, 1.25f);
			glVertex3f(-1.75f, 0.0f, 0.5f);
			glVertex3f(-0.5f, 2.0f, 0.25f);
		glEnd();

		glPopMatrix();
		glPopMatrix();

		glEndList();
	}
}
void CreaMorro(void) {
	//TODO Cmbiado
	morro = glGenLists(1);
	if (morro != 0) /* Cero no es un identificador valido para una display list */
	{
		glNewList(morro, GL_COMPILE);

		glPushMatrix();
			glRotatef(270, 0.0, 1.0, 0.0);
			
			glScalef(0.4f, 0.4f, 0.4f);
			glBegin(GL_POLYGON);
			//PUESTA A HORARIO APOSTA

			glTexCoord2f(0.0, 0.0);
				glVertex3f(0.0f, 2.7f, 1.5f);
				glTexCoord2f(0.0, 1.0);
				glVertex3f(0.0f, 2.7f, -1.5f);
				glTexCoord2f(1.0, 1.0);
				glVertex3f(0.0f, 0.0f, -1.5f);
				glTexCoord2f(1.0, 0.0);
				glVertex3f(0.0f, 0.0f, 1.5f);
			
			glEnd();

			glBegin(GL_POLYGON);
				//ya cambiado
			glTexCoord2f(0.0, 0.0);
				glVertex3f(1.5f, 0.35f, 1.0f);
				glTexCoord2f(1.0, 0.0);
				glVertex3f(1.5f, 0.35f, -1.0f);
				glTexCoord2f(1.0, 1.0);
				glVertex3f(1.5f, 1.25f, -1.0f);
				glTexCoord2f(0.0, 1.0);
				glVertex3f(1.5f, 1.25f, 1.0f);
				
			glEnd();

			glBegin(GL_POLYGON);

			glTexCoord2f(0.0, 0.0);
				glVertex3f(0.0f, 0.0f, 1.5f);
				glTexCoord2f(0.0, 1.0);
				glVertex3f(0.0f, 0.0f, -1.5f);
				glTexCoord2f(1.0, 1.0);
				glVertex3f(1.5f, 0.35f, -1.0f);
				glTexCoord2f(1.0, 0.0);
				glVertex3f(1.5f, 0.35f, 1.0f);
			
			glEnd();

			glBegin(GL_POLYGON);
			glTexCoord2f(0.0, 0.0);
				glVertex3f(1.5f, 1.25f, 1.0f);
				glTexCoord2f(0.0, 1.0);
				glVertex3f(1.5f, 1.25f, -1.0f);
				glTexCoord2f(1.0, 1.0);
				glVertex3f(1.0f, 1.5f, -1.0f);
				glTexCoord2f(1.0, 0.0);
				glVertex3f(1.0f, 1.5f, 1.0f);
			glEnd();


			glBegin(GL_POLYGON);

			glTexCoord2f(0.0,0.0);
				glVertex3f(1.5f, 1.25f, -1.0f);
				glTexCoord2f(0.0, 1.0);
				glVertex3f(1.5f, 0.35f, -1.0f);
				glTexCoord2f(1.0,1.0);
				glVertex3f(0.0f, 0.0f, -1.5f);
				glTexCoord2f(1.0, 0.3);
				glVertex3f(0.0f, 1.5f, -1.5f);
				glTexCoord2f(0.3, 0.3);
				glVertex3f(1.0f, 1.5f, -1.0f);
				
			glEnd();

			glBegin(GL_POLYGON);
			glTexCoord2f(0.0, 0.0);
				glVertex3f(1.0f, 1.5f, 1.0f);
				glTexCoord2f(0.0, 1.0);
				glVertex3f(0.0f, 1.5f, 1.5f);
				glTexCoord2f(1.0, 1.0);
				glVertex3f(0.0f, 0.0f, 1.5f);
				glTexCoord2f(1.0, 0.3);
				glVertex3f(1.5f, 0.35f, 1.0f);
				glTexCoord2f(0.3, 0.3);
				glVertex3f(1.5f, 1.25f, 1.0f);
				
			glEnd();

		glPopMatrix();

		/*
		glPushMatrix();
			glScalef(0.39f, 0.30f, 0.4f);
			glTranslatef(0.0f, 2.0f, 0.0f);
			CreaParabrisas();
		glPopMatrix();*/
		glEndList();
	}
}
void CrearTrenAterrizaje(void) {
	trenAterrizaje = glGenLists(1);
	if (trenAterrizaje != 0) /* Cero no es un identificador valido para una display list */
	{
		glNewList(trenAterrizaje, GL_COMPILE);
		glPushMatrix();
		glScalef(0.5f, 0.5f, 0.5f);
		

		glPushMatrix();
		glScalef(0.5f, 0.5f, 0.5f);

		textura5();
		glPushMatrix();
		glutSolidTorus(1, 2, 20,20);
		glPopMatrix();

		textura3();
		//tapacubos :)
		glPushMatrix();
			glPushMatrix();
				glTranslatef(0.0f, 0.0f, 1.0f);
				glScalef(2.0, 2.0, 0.0f);
				igSolidSphere(50,50,1);
			glPopMatrix();

	
			glPushMatrix();
				glTranslatef(0.0f, 0.0f, -1.0f);
				glScalef(2.0, 2.0, 0.0f);
				igSolidSphere(50, 50, 1);
			glPopMatrix();
		glPopMatrix();

		glPopMatrix();

		//Segunda rueda
		
		glPushMatrix();
		glScalef(0.5f, 0.5f, 0.5f);
		glTranslatef(0.0,0.0,4.0f);

		textura5();
		glPushMatrix();
		glutSolidTorus(1, 2, 20, 20);
		glPopMatrix();

		textura3();

		//tapacubos :)
		glPushMatrix();
		glPushMatrix();
			glTranslatef(0.0f, 0.0f, 1.0f);
			glScalef(2.0, 2.0, 0.0f);
			glFrontFace(GL_CW);
			igSolidSphere(50, 50, 1);
			glFrontFace(GL_CCW);
		glPopMatrix();


		glPushMatrix();
			glTranslatef(0.0f, 0.0f, -1.0f);
			glScalef(2.0, 2.0, 0.0f);
			glFrontFace(GL_CW);
			igSolidSphere(50, 50, 1);
			glFrontFace(GL_CCW);
			glPopMatrix();
		glPopMatrix();

		glPopMatrix();


		//Conexiones rueda-rueda-cuerpo
		
		glPushMatrix();
			glScalef(0.55,0.35,1.5f);
			glTranslatef(0.0,0.0,0.6);
			glFrontFace(GL_CW);
			igSolidCube();
			glFrontFace(GL_CCW);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0.0,1.1,1.0);
			glScalef(0.4f, 2.5f,0.4f);
			glFrontFace(GL_CW);
			igSolidCube();
			glFrontFace(GL_CCW);
		glPopMatrix();


		glPopMatrix();
		glEndList();
	}
}
void CreaHelices(void)
{
	helices = glGenLists(1);
	if (helices != 0) /* Cero no es un identificador valido para una display list */
	{
		glNewList(helices, GL_COMPILE);
		/*  Código para dibujar el abeto */

		glPushMatrix();

		glScalef(0.5f, 0.5f, 0.5f);

		textura5();
		glPushMatrix();
			//hélice
			glScalef(5.0f, 0.1f, 0.4f);
			glTranslatef(0.0f, 6.0f, 0.0f);
			//glRotatef(15,0.0,0.0,0.0);
			glFrontFace(GL_CW);
			igSolidCube();
			glFrontFace(GL_CCW);

		glPopMatrix();

		glPushMatrix();

			glScalef(0.4f, 0.1f, 5.0f);
			glTranslatef(0.0f, 6.0f, 0.0f);
			glFrontFace(GL_CW);
			igSolidCube();
			glFrontFace(GL_CCW);

		glPopMatrix();

		textura3();
		glPushMatrix();

			glScalef(0.35f, 0.8f, 0.35f);
			glRotatef(9.89f, 0.0f, 1.0f, 0.0f);
			glTranslatef(0.0f, 0.5f, 0.0f);
			glFrontFace(GL_CW);
				igSolidSemiSphere(10, 10);
			glFrontFace(GL_CCW);

		glPopMatrix();

		glPopMatrix();
		glEndList();


	}
}


void CreaSoporteHelice(void)
{
	soporteHelice = glGenLists(1);
	if (soporteHelice != 0) /* Cero no es un identificador valido para una display list */
	{
		glNewList(soporteHelice, GL_COMPILE);
		/*  Código para dibujar el abeto */

		glPushMatrix();
		glPushMatrix();
			glTranslatef(0.0,1.1,0.0);
			//glScalef(0.5f, 0.5f, 0.5f);
			glScalef(0.6f, 1.0f, 0.6f);
			
			glFrontFace(GL_CW);
			 igSolidCube();
			glFrontFace(GL_CCW);
		glPopMatrix();
		

		glPushMatrix();
			glRotatef(45, 0.0f, 1.0f, 0.0f);
			glScalef(0.7f, 1.5f, 0.7f);
			glFrontFace(GL_CW);
			igCreateSolidQuadricObject(50.0f, 50.0f, 1.0f, 1.5f, 1.0f, 0.5f, 1.5f);
			glFrontFace(GL_CCW);
			
		glPopMatrix();

		glPopMatrix();
		glEndList();


	}
}
void CreaCola(void)
{	// TODO LISTO
	cola = glGenLists(1);
	if (cola != 0) /* Cero no es un identificador valido para una display list */
	{
		glNewList(cola, GL_COMPILE);
		glPushMatrix();
		glScalef(0.5, 0.5, 0.5);
		
		//lateral
		glBegin(GL_POLYGON);

			glTexCoord2f(0.0,0.0);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0, 0.7);
			glVertex3f(0.0f, 1.0f, 0.0f);
			glTexCoord2f(1.0, 1.0);
			glVertex3f(2.0f, 3.0f, 0.0f);
			glTexCoord2f(1.0, 0.0);
			glVertex3f(2.0f, 0.0f, 0.0f);
			glVertex3f(0.0f, 0.0f, 0.0f);
		glEnd();
		
		//frontal
		glBegin(GL_POLYGON);
		
			glTexCoord2f(0.0, 0.0);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glTexCoord2f(1.0, 0.0);
			glVertex3f(0.0f, 0.0f, 0.8f);
			glTexCoord2f(1.0, 0.5);
			glVertex3f(0.0f, 1.0f, 0.8f);
			glTexCoord2f(0.0, 0.5);
			glVertex3f(0.0f, 1.0f, 0.0f);
			glVertex3f(0.0f, 0.0f, 0.0f);
		glEnd();
		

		//LATERAL
		glBegin(GL_POLYGON);

		glTexCoord2f(0.0, 0.0);
			glVertex3f(0.0f, 0.0f, 0.8f);
			glTexCoord2f(0.0, 1.0);
			glVertex3f(2.0f, 0.0f, 0.8f);
			glTexCoord2f(1.0, 1.0);
			glVertex3f(2.0f, 3.0f, 0.8f);
			glTexCoord2f(1.0, 0.0);
			glVertex3f(0.0f, 1.0f, 0.8f);
			glVertex3f(0.0f, 0.0f, 0.8f);
		glEnd();
		
		//tapa de abajo
		glBegin(GL_POLYGON);
			
		glTexCoord2f(0.0, 0.0);
			glVertex3f(0.0f, 0.0f, 0.8f);
			glTexCoord2f(0.0,1.0);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glTexCoord2f(0.75, 1);
			glVertex3f(2.0f, 0.0f, 0.0f);
			glTexCoord2f(1.0, 0.5);
			glVertex3f(2.5f, 0.0f, 0.4f);
			glTexCoord2f(0.75, 0.0);
			glVertex3f(2.0f, 0.0f, 0.8f);
			glTexCoord2f(0.0, 0.0);
			glVertex3f(0.0f, 0.0f, 0.8f);

		glEnd();
		
		//tapas laterales
		glBegin(GL_POLYGON);


		glTexCoord2f(0.0,0.0);
			glVertex3f(2.0f, 0.0f, 0.8f);
			glTexCoord2f(0.0,1.0);
			glVertex3f(2.5f, 0.0f, 0.4f);
			glTexCoord2f(1.0,1.0);
			glVertex3f(2.5f, 3.0f, 0.4f);
			glTexCoord2f(1.0,0.0);
			glVertex3f(2.0f, 3.0f, 0.8f);
			glVertex3f(2.0f, 0.0f, 0.8f);
		glEnd();
		
		//tapas laterales
		glBegin(GL_POLYGON);
			
		glTexCoord2f(0.0, 0.0);
			glVertex3f(2.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0, 1.0);
			glVertex3f(2.0f, 3.0f, 0.0f);
			glTexCoord2f(1.0, 1.0);
			glVertex3f(2.5f, 3.0f, 0.4f);
			glTexCoord2f(1.0, 0.0);
			glVertex3f(2.5f, 0.0f, 0.4f);
			glVertex3f(2.0f, 0.0f, 0.0f);
		glEnd();
		
		//tapas superior
		glBegin(GL_POLYGON);

		glTexCoord2f(0.0,0.0);
			glVertex3f(0.0f, 1.0f, 0.0f);
			glTexCoord2f(1.0, 0.0);
			glVertex3f(0.0f, 1.0f, 0.8f);
			glTexCoord2f(1.0, 0.8);
			glVertex3f(2.0f, 3.0f, 0.8f);
			glTexCoord2f(0.5,1.0);
			glVertex3f(2.5f, 3.0f, 0.4f);
			glTexCoord2f(0.0, 0.8);
			glVertex3f(2.0f, 3.0f, 0.0f);
			glVertex3f(0.0f, 1.0f, 0.0f);

		glEnd();
		
		glBegin(GL_POLYGON);


			glVertex3f(2.0f, 3.0f, 0.0f);
			glVertex3f(2.5f, 3.0f, 0.4f);
			glVertex3f(2.0f, 3.0f, 0.8f);
			glVertex3f(2.0f, 0.0f, 0.8f);
			glVertex3f(2.5f, 0.0f, 0.4f);
			glVertex3f(2.0f, 0.0f, 0.0f);
			
		glEnd();
		
		glPopMatrix();

		glEndList();
	}
}
void CreaParteTrasera(void)
{
	parteTrasera = glGenLists(1);
	if (parteTrasera != 0) /* Cero no es un identificador valido para una display list */
	{	
		glNewList(parteTrasera, GL_COMPILE);

			glPushMatrix();
			glScalef(0.5, 0.5, 0.5);
				glPushMatrix();
					glScalef(1.1, 1.0, 0.5);
					glCallList(cola);
				glPopMatrix();

				glPushMatrix();
					
					glTranslatef(0.0f, 0.0, 1.7f);
					glScalef(1.1, 1.0, 0.5);
					glCallList(cola);
				glPopMatrix();

				glPushMatrix();
		
					glTranslatef(0.5f, 0.4, 0.95f);
					glScalef(1.0, 0.2, 1.5);
					glFrontFace(GL_CW);
						igSolidCube();
					glFrontFace(GL_CCW);
				glPopMatrix();
			glPopMatrix();
		glEndList();
	}
}
void CreaTerreno(void) {
	float vertices[4][3] = { {0.5f, 0.5f, 0.5f}, {0.5f, 0.5f, -0.5f}, {-0.5f, 0.5f, -0.5f}, {-0.5f, 0.5f, 0.5f}};

	float verticesHorizonte[4][3] = { {-0.5f, 0.5f, 0.5f}, {-0.5f, -0.5f, 0.5f}, {-0.5f, -0.5f, -0.5f}, {-0.5f, 0.5f, -0.5f} };
	float verticesHorizonte2[4][3] = { {-0.5f, -0.5f, 0.5f}, {-0.5f, 0.5f, 0.5f}, {0.5f, 0.5f, 0.5f}, {0.5f, -0.5f, 0.5f} };

	float desplazamiento = 49.5f;
	float area = 100.0f;
	terreno = glGenLists(1);
	if (terreno != 0) /* Cero no es un identificador valido para una display list */
	{
		glNewList(terreno, GL_COMPILE);

		glPushMatrix();
			
		glPushMatrix();
				//glColor3f(0.12f, 0.26, 0.55);//forest green
				glScalef(area, 0.0f, area);
				glBegin(GL_QUADS);
					glNormal3f(0.0f, -1.0f, 0.0f);
					glTexCoord2f(0.0, 0.0);
					glVertex3fv(vertices[0]);
					glTexCoord2f(0.0, 1.0);
					glVertex3fv(vertices[1]);
					glTexCoord2f(1.0, 1.0);
					glVertex3fv(vertices[2]);
					glTexCoord2f(1.0, 0.0);
					glVertex3fv(vertices[3]);
				glEnd();
			//igSolidCube(1);
			glPopMatrix();

			glPushMatrix();
				//PLano de fondo
				textura2();
				glScalef(1.0f, 30.0f, area);
				glTranslatef(-desplazamiento,0.5f,0.0f);
					glBegin(GL_QUADS);
				
					glTexCoord2f(1.0, 1.0);
					glVertex3fv(verticesHorizonte[0]);
					glTexCoord2f(1.0, 0.0);
					glVertex3fv(verticesHorizonte[1]);
					glTexCoord2f(0.0, 0.0);
					glVertex3fv(verticesHorizonte[2]);
					glTexCoord2f(0.0, 1.0);
					glVertex3fv(verticesHorizonte[3]);
				glEnd();
			glPopMatrix();

			//glColor3f(0.12f, 0.26, 0.55);//forest green
				glScalef(area, 0.0f, area);
				glBegin(GL_QUADS);
					glNormal3f(0.0f, -1.0f, 0.0f);
					glTexCoord2f(0.0, 0.0);
					glVertex3fv(vertices[0]);
					glTexCoord2f(0.0, 1.0);
					glVertex3fv(vertices[1]);
					glTexCoord2f(1.0, 1.0);
					glVertex3fv(vertices[2]);
					glTexCoord2f(1.0, 0.0);
					glVertex3fv(vertices[3]);
				glEnd();
			//igSolidCube(1);
			glPopMatrix();

			glPushMatrix();
			
			glScalef(area, 30.0f, area);
			glBegin(GL_QUADS);
			glNormal3f(0.0f, -1.0f, 0.0f);
			glTexCoord2f(0.0, 0.0);
			glVertex3fv(vertices[3]);
			glTexCoord2f(0.0, 1.0);
			glVertex3fv(vertices[2]);
			glTexCoord2f(1.0, 1.0);
			glVertex3fv(vertices[1]);
			glTexCoord2f(1.0, 0.0);	
			glVertex3fv(vertices[0]);
			glEnd();
			//igSolidCube(1);
			glPopMatrix();

			glPushMatrix();
			//PLano de fondo
			textura2();
			glScalef(1.0f, 30.0f, area);
			glTranslatef(desplazamiento, 0.5f, 0.0f);
			glBegin(GL_QUADS);

				glTexCoord2f(0.0, 0.0);
				glVertex3fv(verticesHorizonte[3]);
				glTexCoord2f(0.0, 1.0);
				glVertex3fv(verticesHorizonte[2]);
				glTexCoord2f(1.0, 1.0);
				glVertex3fv(verticesHorizonte[1]);
				glTexCoord2f(1.0, 0.0);
				glVertex3fv(verticesHorizonte[0]);
				glEnd();
			glPopMatrix();

			glPushMatrix();
			//PLano de fondo
			textura2();
			glScalef(area, 30.0f, 1.0f);
			glTranslatef(0.0f, 0.5f, -desplazamiento);
			glBegin(GL_QUADS);
		
			glTexCoord2f(0.0, 1.0);
			glVertex3fv(verticesHorizonte2[3]);
			glTexCoord2f(0.0, 0.0);
			glVertex3fv(verticesHorizonte2[2]);
			glTexCoord2f(1.0, 0.0);
			glVertex3fv(verticesHorizonte2[1]);
			glTexCoord2f(1.0, 1.0);
			glVertex3fv(verticesHorizonte2[0]);
			glEnd();
			glPopMatrix();


			glPushMatrix();
			//PLano de fondo
			textura2();
			glScalef(area, 30.0f, 1.0f);
			glTranslatef(0.0f, 0.5f,desplazamiento);
			glBegin(GL_QUADS);

			glTexCoord2f(1.0, 0.0);
			glVertex3fv(verticesHorizonte2[0]);
			glTexCoord2f(1.0, 1.0);
			glVertex3fv(verticesHorizonte2[1]);
			glTexCoord2f(0.0, 1.0);
			glVertex3fv(verticesHorizonte2[2]);
			glTexCoord2f(0.0, 0.0);
			glVertex3fv(verticesHorizonte2[3]);
			glEnd();
			glPopMatrix();



			//glColor3f(1.0f, 1.0f, 1.0f);
		glPopMatrix();

		glEndList();
	}

}
void CreaBase() {

	base = glGenLists(1);
	if (base = !0) {
		glNewList(base, GL_COMPILE);
	
		glPushMatrix();
			
			glTranslatef(0.0,0.5,0.0);
			
				//Patas a tierra
				GLUquadricObj* quadratic1;
				quadratic1 = gluNewQuadric();
				
				gluQuadricTexture(quadratic1,1);
				glPushMatrix();
					
					glTranslatef(0.7, 0.0, 0.0);
					glScalef(0.1f, 1.5f, 0.1f);
					glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
				
					gluCylinder(quadratic1, 1.0f, 1.0f, 1.0f, 32, 32);
					
				glPopMatrix();


				glPushMatrix();
					glTranslatef(-0.7, 0.0, 0.0);
					glScalef(0.1f, 1.5f, 0.1f);
					glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
					gluCylinder(quadratic1, 1.0f, 1.0f, 1.0f, 32, 32);
				glPopMatrix();

				
				glPushMatrix();
					glTranslatef(0.0, 0.0, 0.7);
					glScalef(0.1f, 1.5f, 0.1f);
					glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
					gluCylinder(quadratic1, 1.0f, 1.0f, 1.0f, 32, 32);
				glPopMatrix();


				glPushMatrix();
					glTranslatef(0.0, 0.0, -0.7);
					glScalef(0.1f, 1.5f, 0.1f);
					glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
					gluCylinder(quadratic1, 1.0f, 1.0f, 1.0f, 32, 32);
				glPopMatrix();

				
			glPushMatrix();
				GLUquadricObj* quadratic;
				quadratic = gluNewQuadric();
				gluQuadricTexture(quadratic, 1);

				glTranslatef(0.0f, 0.0f, 0.0f);
				glScalef(1.0, 0.2f, 1.0f);
				glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
				
				//gluQuadricTexture(quadratic1, 1);
			
				gluCylinder(quadratic, 1.0f, 1.0f, 1.0f, 32, 32);
				
			glPopMatrix();
			 
			//Conectores
			
			glPushMatrix();
				glTranslatef(0.0f, -0.1f, 0.0f);
				glScalef(2.25f, 0.1f, 0.1f);
				glFrontFace(GL_CW);
					igSolidCube();
				glFrontFace(GL_CCW);
			glPopMatrix();


			glPushMatrix();
				glTranslatef(0.0f, -0.1f, 0.0f);
					glScalef(0.1f, 0.1f, 2.25f);
					glFrontFace(GL_CW);
						igSolidCube();
					glFrontFace(GL_CCW);
			glPopMatrix();

				glPushMatrix();
				
					glScalef(1.0, 0.0f, 1.0f);
					//glutSolidSphere(1.0f,15,15);
					igSolidSphere(30,30);

					glTranslatef(0.0f, -0.2f, 0.0f);
					igSolidSphere(15, 15);
					//glutSolidSphere(1.0f, 15, 15);
				glPopMatrix();

				glPushMatrix();
					
					//glColor3f(0.91f, 0.92f,0.87f);//white
					
				textura5();
					glPushMatrix();
						glTranslatef(0.0, -0.1, 0.0);
						glScalef(0.25f, 0.15f, 0.25f);
						glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
						glutSolidTorus(0.5f,5.0f,20,20);
					glPopMatrix();

					textura4();
					//Luces
					//glColor3f(1.0f, 0.5f, 0.02f);//red
					glPushMatrix();

						glTranslatef(1.25, -0.03, 0.0);
						glScalef(0.05, 0.15, 0.05);
						glFrontFace(GL_CW);
						igSolidSemiSphere(20, 20);
						glFrontFace(GL_CCW);
					glPopMatrix();
					//Luces

					glPushMatrix();

						glTranslatef(-1.25, -0.03, 0.0);
						glScalef(0.05, 0.15, 0.05);

						glFrontFace(GL_CW);
						igSolidSemiSphere(20, 20);
						glFrontFace(GL_CCW);
					glPopMatrix();
					//Luces

					glPushMatrix();

						glTranslatef(0.0, -0.03, 1.25);
						glScalef(0.05, 0.15, 0.05);

						glFrontFace(GL_CW);
						igSolidSemiSphere(20, 20);
						glFrontFace(GL_CCW);
					glPopMatrix();
					//Luces

					glPushMatrix();

						glTranslatef(0.0, -0.03, -1.25);
						glScalef(0.05, 0.15, 0.05);

						glFrontFace(GL_CW);
						igSolidSemiSphere(20, 20);
						glFrontFace(GL_CCW);
					glPopMatrix();
			
				glPopMatrix();

			glPopMatrix();
		glEndList();
	}
}
