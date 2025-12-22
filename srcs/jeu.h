#ifndef JEU_H
#define JEU_H


#include <stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
#include <time.h>
#include<string.h>
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
int movDroite(int **g, int *score);
int enHaut(int **g, int *score);
int enBas(int **g , int *score);
int deplacer(int **g);
int estTermine(int **g);
int gagner(int **g) ;
int	saveStateToFile(char *fileName, int **g);
char *ft_strjoin(char *s1, char *s2);
size_t ft_strlen(const char *a);
char *ft_itoa(int n);
void ft_str_replace(char *st, char bef, char aft);
char *initSaveFile();
void affichageGrille(int **g);
int replayGame(char *fileName);
int ft_atoi(const char *nprt);
char *ft_strappend(char *str, char ap);
void outputLine(char *line);


#endif
