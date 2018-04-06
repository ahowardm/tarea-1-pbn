/** Tarea 1 Programacion de Bajo Nivel
 * @author Andres Howard <aihoward@miuandes.cl>
 */

#ifndef TAREA1_H
#define TAREA1_H

#include <stdio.h>
#include <string.h>

#define LARGO_MAXIMO 100

void leeStringFuncion(char texto[], char funcion[]);
void leeString(char texto[]);
int seleccionaOpcion();
void encriptar();
void desencriptar();
int inputCaracteresDesplazamiento();
int inputCaracteresXor();
void inicializaString(char texto[]);

#endif