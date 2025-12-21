
#ifndef JEU_H
#define JEU_H


#include <stdio.h>
#include<stdlib.h>
#include<errno.h>
#include <time.h>
#define TAILLE 4 
#define AVOIRQ 15

int ** createGrille (); 
void initGrille ( int ** g );
void liberGrille (int ** g );
int caseVide ( int **g , int i , int j);
int nbCaseVide ( int **g );
int ajouterTuile (int ** g ) ;
void initJeu(int **g, int *score);
int calcul(int ligne[TAILLE], int *score) ;
void inverserLigne ( int  ligne [TAILLE]);
int movGauche(int **g , int *score) ;







#endif