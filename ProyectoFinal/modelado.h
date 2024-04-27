/*************************************************************************/
/*                                                                       */
/*   modelado.h                                                          */
/*   Rev. 27/10/03   AUTORES: C.Rebollo
/*                                                                       */
/*************************************************************************/

#ifndef MODELADO_H
#define MODELADO_H

#include "glut.h"


/* Identificadores de las display list */
GLuint cuerpo,parabrisas,morro,trenAterrizaje, soporteHelice,helices,cola,parteTrasera,terreno,base;

/* Definición Funciones de modelado */
void IniciaDisplayLists (void);
void CreaCuerpo(void);
void CreaParabrisas(void);
void CreaMorro(void);
void CrearTrenAterrizaje(void);
void CreaSoporteHelice(void);
void CreaHelices(void);
void CreaCola(void);
void CreaParteTrasera(void);
void CreaTerreno(void);
void CreaBase(void);
#endif
