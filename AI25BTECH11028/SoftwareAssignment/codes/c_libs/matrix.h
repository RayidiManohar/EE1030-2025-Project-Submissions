#ifndef MATRIX_H
#define MATRIX_H

double **copymat(double **A, int rows, int cols);
void matVec(double **A, double *v, double *res, int r, int c);
void normalize(double *v, int n);
void reconstruct(double **U, double *S, double **V, double **R, int r, int c, int k);
void frobeniuserror(double **orig, double **recon, int r, int c);
void compressionRatio(int rows, int cols, int k);

#endif
