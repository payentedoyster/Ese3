//Implementazione della funzione scambia presente nella libreria utile.h
//Dichiarazione funzione

void scambia(int* x,int* y){

    /* Dichiaro due variabili di supporto
    e gli assegno i valori degli indirizzi 
    puntati da x e y */

    int t1=*x, t2=*y;

    /* Successivamente assegno t2 contenente il valore
    di y a x e t1 contenente il valore di x a y */

    x=&t2;
    y=&t1;


}