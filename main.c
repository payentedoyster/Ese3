//Funzione contenente l'implementazione del programma
//Direttiva di inclusione della libreria vettore.h
#include "vettore.h"
#include <stdio.h>
#include <stdlib.h>

//Dichiarazione costante M
#define M 20

//Dichiarazione prototipo funzione run_test
int run_test(char* tc, int n);

//Dichiarzione funzione main
int main (int argc, char* argv[]){

    //Dichiarazione FILE
    FILE *test_suite;
    FILE *result;

    //variabile stringa contenente il nome del file di test
    char tc[M];

    int n,pass;

    //controllo se ci sono tutti i file
    if(argc<3){
        printf("Nomi file non presenti\n");
        return 1;
    }

    //apro i file in lettura e in scrittura
    //lettura
    test_suite = fopen(argv[1],"r");
    //scrittura
    result = fopen(argv[2],"w");

    //controllo sui file
    if(test_suite==NULL && result==NULL){
        printf("Errore nell'apertura dei file\n");
        return 1;
    }

    //ciclo che prende in input i file di test e il numero di elementi
    while(fscanf(test_suite,"%s%d",tc,&n)==2){
        pass=run_test(tc,n);

        fprintf(result,"%s",tc);
        if(pass==1)
            fprintf(result,"PAS\n");
        else
            fprintf(result,"FAIL\n");
    }

    //chiudo o file
    fclose(test_suite);
    fclose(result);
}

//Dichiarazione funzione run_test
int run_test(char* tc,int n){
    //Stringhe contenenti i nomi dei file inout,oracle,output
    char input_name[M],output_name[M],oracle_name[M];

    //Dichiarazione FILE
    FILE *input=fopen(input_name,"r");
    FILE *oracle=fopen(oracle_name,"r");
    FILE *output=fopen(output_name,"w");

    //alloco memoria per array di input
    int *a=calloc(n,sizeof(int));

    //carico in input
    finput_array(input_name,a,n);

    //ordino l'array
    ordina(a,n);

    //scrivo per l'output
    foutput_array(output_name,a,n);

    //array oracle_a
    int *oracle_a=calloc(n,sizeof(int));

    //carico oracle e confronto
    finput_array(oracle_name,oracle_a,n);

    //confronto
    if(confronta_array(a,oracle_a,n)){
        printf("PASS\n");
        return 1;
    }
    else{
        printf("FAIL\n");
        return 0;
    }

}