/** Tarea 1 Programacion de Bajo Nivel
 * @author Andres Howard <aihoward@miuandes.cl>
 */

/***********************
* Métodos aulixiliares *
************************/

// Lee caracter para hacer el desplazamiento
int inputCaracteresDesplazamiento(){
  int caracteres_desplazamiento;
  printf("Ingrese la cantidad de caracteres para hacer el desplazamiento: ");
  scanf("%d", &caracteres_desplazamiento);
  return caracteres_desplazamiento;
}

// Lee caracter para hacer XOR del teclado
int inputCaracteresXor(){
  fseek(stdin,0,SEEK_END);
  printf("Ingrese un caracter para hacer XOR: ");
  int caracter_xor;
  scanf("%d", &caracter_xor);
  return caracter_xor;
}

/************************
* Métodos de encriptado *
*************************/

void cifradoPorDesplazamiento(char texto[], int posiciones){
  for (int i = 0; i < strlen(texto); i++)
    texto[i] = texto[i] + posiciones;
}

void negacionDeBits(char texto[]){
  for (int i = 0; i < strlen(texto); i++)
    texto[i] = ~texto[i];
}

void xor(char texto[], int caracter){
  for (int i = 0; i < strlen(texto); i++)
    texto[i] = texto[i] ^ caracter;
}

void invertirCaracteres(char texto[]){
  return;
}

/************************
* Métodos de desencriptado *
*************************/

void noCifradoPorDesplazamiento(char texto[], int posiciones){
  for (int i = 0; i < strlen(texto); i++)
    texto[i] = texto[i] - posiciones;
  //return texto;
}

void noInvertirCaracteres(char texto[]){
  return;
}