/** Tarea 1 Programacion de Bajo Nivel
 * @author Andres Howard <aihoward@miuandes.cl>
 */

#ifndef TAREA1_H
#define TAREA1_H

#include <stdio.h>
#include <string.h>

#define LARGO_MAXIMO 100

void leeString(char texto[], char funcion[]);
int seleccionaOpcion();
void encriptar();
void desencriptar();
int inputCaracteresDesplazamiento();
int inputCaracteresXor();
void inicializaString(char texto[]);

#endif