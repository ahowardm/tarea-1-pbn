/** Tarea 1 Programacion de Bajo Nivel
 * @author Andres Howard <aihoward@miuandes.cl>
 */

#include "tarea_1.h"
#include "encriptado.h"

// Administra la ejecucion del programa
int main(){
  int opcion = seleccionaOpcion();
  if (opcion == 1)
    encriptar();
  else if (opcion == 2)
    desencriptar();

  return 0;
}


/**************************
* Métodos de encr/desencr *
***************************/

// Encripta un texto y lo imprime en pantalla
void encriptar(){
  char texto[LARGO_MAXIMO], texto_original[LARGO_MAXIMO];

  inicializaString(texto);
  inicializaString(texto_original);
  leeString(texto, "encriptar");
  strcpy(texto_original, texto);
  
  int caracteres_desplazamiento = inputCaracteresDesplazamiento();
  int caracter_xor = inputCaracteresXor();
  
  cifradoPorDesplazamiento(texto, caracteres_desplazamiento);
  negacionDeBits(texto);
  xor(texto, caracter_xor);

  printf("El texto original es: %s\n", texto_original);
  printf("El texto cifrado es: %s\n", texto);
}

// Desencripta un texto y lo imprime en pantalla
void desencriptar(){
  char texto[LARGO_MAXIMO], texto_original[LARGO_MAXIMO];

  inicializaString(texto);
  inicializaString(texto_original);
  leeString(texto, "desencriptar");
  strcpy(texto_original, texto);
  
  int caracteres_desplazamiento = inputCaracteresDesplazamiento();
  int caracter_xor = inputCaracteresXor();
  
  
  xor(texto, caracter_xor);
  negacionDeBits(texto);
  cifradoPorDesplazamiento(texto, caracteres_desplazamiento);

  printf("El texto original es: %s\n", texto_original);
  printf("El texto descrifrado es: %s\n", texto);
}

/************************
* Métodos de auxiliares *
*************************/

void inicializaString(char texto[]){
  for (int i = 0; i < LARGO_MAXIMO; i++)
    texto[i] = ' ';
}

// Pide al usuario seleccionar la opcion encriptar o desencriptar
int seleccionaOpcion(){
  int opcion = 0;
  // El siguiente ciclo corre hasta que el usuario ingrese una opción válida
  while(1){    
    printf("Desea encriptar (1) o desencriptar (2)? Seleccione el número de la opción: ");
    scanf("%d", &opcion);
    if (opcion == 1 || opcion == 2)
      break;
  }
  return opcion;
}

// Lee input del teclado. Parte limpiando el buffer.
void leeString(char texto[], char funcion[]){
  printf("Ingrese un texto para %s: ", funcion);
  fseek(stdin,0,SEEK_END);
  int i = 0;
  while((texto[i] = getchar()) != '\n' && i < LARGO_MAXIMO){
    ++i;
  }
  texto[i] = '\0';
}