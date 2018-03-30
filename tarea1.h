/** Tarea 1 Programacion de Bajo Nivel
 * @author Andres Howard <aihoward@miuandes.cl>
 */

#include <stdio.h>
#include <string.h>
#include "encriptado.h"

#define LARGO_MAXIMO 100

void cifradoPorDesplazamiento(char texto[], int posiciones);
void negacionDeBits(char texto[]);
void encriptadoXor(char texto[], int caracter);
void invertirCaracteres(char texto[]);
void noCifradoPorDesplazamiento(char texto[], int posiciones);
void noInvertirCaracteres(char texto[]);
void leeString(char texto[], char funcion[]);
int seleccionaOpcion();
void encriptar();
void desencriptar();
int inputCaracteresDesplazamiento();
int inputCaracteresXor();
void inicializaString(char texto[]);