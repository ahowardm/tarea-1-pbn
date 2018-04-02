/** Tarea 1 Programacion de Bajo Nivel
 * @author Andres Howard <aihoward@miuandes.cl>
 */

#ifndef ENCRIPTADO_H
#define ENCRIPTADO_H

#include <stdio.h>
#include <string.h>

void cifradoPorDesplazamiento(char texto[], int posiciones);
void negacionDeBits(char texto[]);
void encriptadoXor(char texto[], int caracter);
void invertirCaracteres(char texto[]);
void noCifradoPorDesplazamiento(char texto[], int posiciones);
void noInvertirCaracteres(char texto[]);
void xor(char texto[], int caracter);

#endif