
#ifndef JEU_H
#define JEU_H


#include <stdio.h>
#include<stdlib.h>
#include<errno.h>
#define TAILLE 4 
#define AVOIRQ 15

int ** createGrille (); 
void initGrille ( int ** g );
void liberGrille (int ** g );
int caseVide ( int **g , int i , int j);
int nbCaseVide ( int **g );
int ajouterTuile (int ** g ) ;
void initJeu(int **g, int *score);










#endif