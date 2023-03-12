/*File contenente le funzioni utili per l'automatizzazione
del testing con il relativo confronto e ordinamento*/

//Direttiva contenente la libreria utile.h 
#include "utile.h"

//Dichiarazione prototipi funzione
int confronta_array(int a[],int b[],int n);
void foutput_array(char* file_name,int a[],int n);
void finput_array(char* file_name,int a[],int n);
void ordina(int a[],int n);