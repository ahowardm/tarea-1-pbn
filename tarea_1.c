/** Tarea 1 Programacion de Bajo Nivel
 * @author Andres Howard <aihoward@miuandes.cl>
 */

#include "tarea_1.h"
#include "encriptado.h"

// Administra la ejecucion del programa
int main(){
  FILE * in;
  char texto[LARGO_MAXIMO], file_path[LARGO_MAXIMO], out_path[LARGO_MAXIMO];

  printf("Ingrese el nombre de un archivo: ");
  scanf("%s", file_path);

  if((in = fopen(file_path, "r")) == NULL)
    fprintf(stderr, "No existe el archivo\n");

  printf("Ingrese el nombre del archivo para guardar: ");
  scanf("%s", out_path);
  FILE * out = fopen(out_path, "w");

  int opcion = seleccionaOpcion();
  int caracteres_desplazamiento = inputCaracteresDesplazamiento();
  int caracter_xor = inputCaracteresXor();

  inicializaString(texto);
  if (opcion == 1){
    while(fgets(texto, LARGO_MAXIMO - 1, in) != 0){
      encriptar(texto, caracteres_desplazamiento, caracter_xor);
      fprintf(out, "%s", texto);
      inicializaString(texto);
    }
  }
  else if (opcion == 2){
    while(fgets(texto, LARGO_MAXIMO - 1, in) != 0){
      desencriptar(texto, caracteres_desplazamiento, caracter_xor);
      fprintf(out, "%s", texto);
      inicializaString(texto);
    }
  }

  fclose(in);
  fclose(out);
  return 0;
}


/**************************
* Métodos de encr/desencr *
***************************/

// Encripta un texto y lo imprime en pantalla
void encriptar(char * texto, int caracteres_desplazamiento, int caracter_xor){
  invertirCaracteres(texto);
  cifradoPorDesplazamiento(texto, caracteres_desplazamiento);
  negacionDeBits(texto);
  xor(texto, caracter_xor);
}

// Desencripta un texto y lo imprime en pantalla
void desencriptar(char * texto, int caracteres_desplazamiento, int caracter_xor){
  xor(texto, caracter_xor);
  negacionDeBits(texto);
  noCifradoPorDesplazamiento(texto, caracteres_desplazamiento);
  invertirCaracteres(texto);
}

/************************
* Métodos de auxiliares *
*************************/

void inicializaString(char texto[]){
  for (int i = 0; i < LARGO_MAXIMO; i++)
    texto[i] = '\0';
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
void leeStringFuncion(char texto[], char funcion[]){
  printf("Ingrese un texto para %s: ", funcion);
  fseek(stdin,0,SEEK_END);
  int i = 0;
  while((texto[i] = getchar()) != '\n' && i < LARGO_MAXIMO){
    ++i;
  }
  texto[i] = '\0';
}

// Lee input del teclado. Parte limpiando el buffer.
void leeString(char texto[]){
  printf("Ingrese un texto: ");
  fseek(stdin,0,SEEK_END);
  int i = 0;
  while((texto[i] = getchar()) != '\n' && i < LARGO_MAXIMO){
    ++i;
  }
  texto[i] = '\0';
}