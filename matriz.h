#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void zeraVec (int n, double* v);

void liberamat (int m, double** A);

void matrizXvetor(int n, double* result, double* x,double*** V);

double multvvT(int n, double* v, double* w);

double*** cria_matriz_esparsa(int n, double** A);
void preenche_matriz_projeto (int n, double** A);
void libera_matriz_esparsa(int n, double*** V);

double** criamat (int m, int n);

double** criamattri (int n);

double** criamattriT (int n);

double* criavet (int n) ;

void liberavet (double* v) ;

void matrixprinter (int m,int n, double** A);

void matrixtriprinter (int n, double** A, int T);

void vectprinter (int n, double* A);

void transposta (int m, int n, double** A, double** T);

void transpostatri (int n, double** A, double** T) ;

double norma2 (int n, double* v);

void multmv (int m, int n, double** A, double* v, double* w) ;

void multmm (int m, int n, int q, double** A, double** B, double** C) ;

void multvv(int n, double* v, double* w, double* res);

void multvTm(int n, double* v, double** M, double* res);





