#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrix.h"
double **copymat(double **A, int row, int cols) 
{
	    double **B = (double **)malloc(row * sizeof(double *));
	        for (int i = 0; i < row; i++) 
			    {
				            B[i] = (double *)malloc(cols * sizeof(double));
					            for (int j = 0; j < cols; j++) 
							    	{B[i][j] = A[i][j];}
						        }
		    return B;
}
void matVec(double **A, double *v, double *res, int r, int c) 
{
	    for (int i = 0; i < r; i++) 
		        {
				        double s = 0.0;
					        for (int j = 0; j < c; j++) 
								{s += A[i][j] * v[j];}
						        res[i] = s;
							    }
}

void normalize(double *v, int n) {
	    double s = 0;
	        for (int i = 0; i < n; i++) 
			    	{s += v[i]*v[i];}
		    double norm = sqrt(s);
		        if (norm < 1e-12) return;
			    for (int i = 0; i < n; i++) 
				        	{v[i] /= norm;}
}
void reconstruct(double **U, double *S, double **V, double **R, int r, int c, int k) {
	    for (int i = 0; i < r; i++)
		            for (int j = 0; j < c; j++) {
				                double s = 0;
						            for (int t = 0; t < k; t++) s += S[t] * U[i][t] * V[j][t];
							                R[i][j] = s;
									        }
}
void frobeniuserror(double **orig, double **recon, int r, int c) {
	    double sum = 0.0;
	        for (int i = 0; i < r; i++)
			        for (int j = 0; j < c; j++) {
					            double d = orig[i][j] - recon[i][j];
						                sum += d * d;
								        }
		    double err = sqrt(sum);
		        printf("\nFrobenius norm of reconstruction error: %.6f\n", err);
}
void compressionratio(int row, int col, int k) {
	    double ogSize = (double)(row * col);
	        double newSize = (double)(row * k + col * k + k);
		    double ratio = ogSize / newSize;

		        printf("\nCompression ratio : %.4f\n", ratio);
}
