#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
#include "Projeto.h"

int GradConjPre (int n, double*** A, double* b, double* x, double tol) {
  zeraVec(n,x);
  double* Ax0 = criavet(n);
  matrizXvetor(n, Ax0, x, A);
  double* r = criavet(n);
  for (int i = 0; i < n; ++i)
  {
    r[i] = b[i] - Ax0[i];
  }

}
