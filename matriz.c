#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void zeraVec (int n, double* v){
    int i;
    for (i = 0; i < n; i++)
    {
        v[i] = 0.0;
    }
}

void liberamat (int m, double** A) {
    int i = 0;
    for (i = 0; i < m; i++) {
        free(A[i]);
    }
    free(A);
}

void matrizXvetor(int n, double* result, double* x,double*** V){
    int n_elementos;
    zeraVec(result,n);
    for (int i = 0; i < n; i++)
    {
        n_elementos = sizeof(V[i])/(2*sizeof(double));
        for (int j = 0; j < n_elementos; ++j)
        {
            result[i]+=V[i][j][1]*x[V[i][j][0]];
        }
    }
}

double multvvT(int n, double* v, double* w){
    int i = 0;
    double resp=0.0;

    for (i = 0; i < n; i++)
    {
        resp += v[i]*w[i];
    }

    return resp;
}

double*** cria_matriz_esparsa(int n, double** A){
    double*** V = (double***) malloc(n * sizeof(double**));
    int i;
    int j;
    int k;
    int n_elementos = 0;

    for (i = 0; i < n; i++)
    {    
        n_elementos = 0;
        for (j = 0; j < n; j++)
        {
            if(A[i][j]!= 0) n_elementos++;
        }

        V[i] = (double**) malloc(n_elementos * sizeof(double*));
        k = 0;
        for (j = 0; j < n; j++)
        {
            if(A[i][j]!= 0) {
                V[i][k] = (double*) malloc(2 * sizeof(double));
                V[i][k][0] = j;
                V[i][k][1] = A[i][j];
                k++;
            }
        }
    }

    return V;
}

void preenche_matriz_projeto (int n, double** A){
    int i;
    for (i = 0; i < n; ++i)
    {
        zeraVec(n, A[i]);
    }
    for (i = 0; i < n; ++i)
    {
        if(2*i < n){
            A[i][2*i] = 0.5;
            A[2*i][i] = 0.5;
            A[i][i+2] = 0.5;
            A[i+2][i] = 0.5;
            A[i][i+1] = 0.5;
            A[i+1][i] = 0.5;
        } else if( n-i > 2){
            A[i][i+2] = 0.5;
            A[i+2][i] = 0.5;
            A[i][i+1] = 0.5;
            A[i+1][i] = 0.5;
        } else if(n-i > 1){
            A[i][i+1] = 0.5;
            A[i+1][i] = 0.5;
        }
        
        A[i][i] = (i+1.0);
    }
}

void libera_matriz_esparsa(int n, double*** V){
    int i;
    int n_elementos = 0;
    for (i = 0; i < n; i++)
    {    
        n_elementos = sizeof(V[i])/(2*sizeof(double));
        liberamat(n_elementos,V[i]);
    }
    free(V);
}



double** criamat (int m, int n) {
    int i = 0;
    double **mt = (double**) malloc(m * sizeof(double*));
    for (i = 0; i < m; i++) {
        mt[i] = (double*) malloc(n * sizeof(double));
    }
    return mt;
}

double** criamattri (int n) {
    int i = 0;
    double **m = (double**) malloc(n * sizeof(double*));
    for (i = 0; i < n; i++) {
        m[i] = (double*) malloc((i+1) * sizeof(double));
    }
    return m;
}

double** criamattriT (int n) {
    int i = 0;
    double **m = (double**) malloc(n * sizeof(double*));
    for (i = 0; i < n; i++) {
        m[i] = (double*) malloc((n-i-1) * sizeof(double));
    }
    return m;
}

double* criavet (int n) {
    double* v = (double*) malloc(n * sizeof(double));
    return v;
}

void liberavet (double* v) {
    free(v);
}


void matrixprinter (int m,int n, double** A){
	int i = 0;
	int j = 0;

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%.3lf ", A[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void matrixtriprinter (int n, double** A, int T){
	int i = 0;
	int j = 0;

    if (T == 0){

	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("%.2lf ", A[i][j]);
		}
		printf("\n");
	}
	printf("\n");

    } else {
        for (i = 0; i < n; i++)
        {
            
            for (j = 0; j < i; j++)
            {
                printf("     ");
            }
            for (j = i; j < n; j++)
            {
                printf("%.2lf ", A[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }


    return ;
}

void vectprinter (int n, double* A){
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%.2lf\n", A[i]);
		
	}
	printf("\n");

    return ;
}


void transposta (int m, int n, double** A, double** T) {
    int i = 0;
    int j = 0;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            T[j][i] = A[i][j];
        }
    }
}

void transpostatri (int n, double** A, double** T) {
    int i,j;
    for (i = 0; i < n; i++) {
        for (j = 0; j <= i; j++) {
            T[j][i] = A[i][j];
        }
    }
}

double norma2 (int n, double* v) {
    int i = 0;
    double res = 0;
    for (i = 0; i < n; i++) {
        res = res + (v[i]*v[i]);
    }
    return sqrt(res);
}

void multmv (int m, int n, double** A, double* v, double* w) {
    int i,j;
    double aux=0.0;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            aux = aux + (A[i][j] * v[j]);
        }
        w[i] = aux;
        aux = 0.0;
    }

    //vectprinter(m,w);

    return ;
}

void multmm (int m, int n, int q, double** A, double** B, double** C) {
    int i,j,k;
    double aux = 0.0;
    for (i = 0; i < m; i++) {
        for (j = 0; j < q; j++) {
            for (k = 0; k < n; k++) {
                aux = aux + (A[i][k] * B[k][j]);
            }
            C[i][j] = aux;
            aux = 0.0;
        }
    }

    //matrixprinter(m,q,C);

    return ;
}


void multvv(int n, double* v, double* w, double* res){
    int i;

    for (i = 0; i < n; i++)
    {
        res[i] = v[i]*w[i];
    }
}




void multvTm(int n, double* v, double** M, double* res){
    int i = 0;
    int j = 0;

    zeraVec(n,res);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            res[i] += v[i]*M[i][j];
        }
    }

}






