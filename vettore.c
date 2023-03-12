//File contenente le dichiarazioni delle funzioni presenti nella libreria vettore.c
//Direttive di inclusione
#include <stdio.h>
#include <stdlib.h>

//Direttiva di inclusione della libreria vettore.h
#include "vettore.h"

//Dichiarazine funzione confronta_array
int confronta_array(int a[],int b[],int n){

    //dichiaro le variabili utili alla ricerca
    int i=0, trovato=0;

    //ciclo di confronto
    while(i<n&&!trovato){
        if(a[i]!=b[i])
            trovato=1;
        else
            i++;
    }

    return (trovato) ? 0 : 1;
}

//Dichiarazione funzione foutput_array
void foutput_array(char* file_name, int a[], int n){

    int i;
    FILE* fd;

    //apro file in scrittura
    fd = fopen(file_name,"w");

    //controllo dell'apertura del file e tramite la funzione  fprintf carico a in fd
    if(fd==NULL)
        printf("Errore nell'apertura del file %s \n",file_name);
    else
        for(i=0;i<n;i++)
            fprintf(fd,"%d\n",a[i]);

    //chiudo il file
    fclose(fd);
}

//Dichiarazione funzione finput_array
void finput_array(char* file_name, int a[], int n){

    int i;
    FILE* fd;

    //apro file in scrittura
    fd = fopen(file_name,"r");

    //controllo dell'apertura del file e leggo il contenuto da scrivere in a
    if(fd==NULL)
        printf("Errore nell'apertura del file %s \n",file_name);
    else
        for(i=0;i<n;i++)
            fscanf(fd,"%d",&a[i]);

    //chiudo il file
    fclose(fd);
}

//Dichiarazione funzione ordina
void ordina(int a[],int n){
    int i,j,k;

    //ciclo di ordinamento
    for(i=1;i<n;i++){
        k=a[i];
        j=i-1;
        while(j>=0&&a[j]>k){
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=k;
    }
}