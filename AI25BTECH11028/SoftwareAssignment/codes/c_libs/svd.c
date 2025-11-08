#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "svd.h"
#include "matrix.h"
void simpleSVD(double **A, int r, int c, double **U, double *S, double **V, int k) {
	    for (int comp = 0; comp < k; comp++) {
		            double *v = (double *)malloc(c * sizeof(double));
			            for (int i = 0; i < c; i++) {v[i] = (double)rand() / RAND_MAX;}

				            for (int it = 0; it < 20; it++) {
						                double *u = (double *)calloc(r, sizeof(double));
								            matVec(A, v, u, r, c);
									                normalize(u, r);

											            double *newV = (double *)calloc(c, sizeof(double));
												                for (int j = 0; j < c; j++)
															                for (int i = 0; i < r; i++)
																		                    newV[j] += A[i][j] * u[i];
														            normalize(newV, c);

															                for (int i = 0; i < c; i++) v[i] = newV[i];
																	            free(u); free(newV);
																		            }

					            double *Av = (double *)calloc(r, sizeof(double));
						            matVec(A, v, Av, r, c);
							            double sigma = 0;
								            for (int i = 0; i < r; i++) sigma += Av[i]*Av[i];
									            sigma = sqrt(sigma);
										            S[comp] = sigma;

											            for (int i = 0; i < r; i++) U[i][comp] = (sigma == 0 ? 0 : Av[i] / sigma);
												            for (int i = 0; i < c; i++) V[i][comp] = v[i];

													            for (int i = 0; i < r; i++)
															                for (int j = 0; j < c; j++)
																		                A[i][j] -= sigma * U[i][comp] * V[j][comp];

														            free(Av); free(v);
															        }
}
