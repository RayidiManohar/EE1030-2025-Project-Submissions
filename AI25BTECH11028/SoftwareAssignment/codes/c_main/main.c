#include <stdio.h>
#include <stdlib.h>
#include "pgm.h"
#include "matrix.h"
#include "svd.h"
nt main() {
    char inFile[200], outFile[200], fmt[3];
    int rows, cols, maxVal, k;

    printf("Enter input PGM file: "); scanf("%199s", inFile);
    double **A_orig = read(inFile, &rows, &cols, &maxVal, fmt);
    double **A_work = copymat(A_orig, rows, cols);
printf("Enter number of singular values to keep (k): "); scanf("%d", &k);
    if (k > cols) k = cols;

    double **U = (double **)malloc(rows * sizeof(double *));
    double **V = (double **)malloc(cols * sizeof(double *));
    for (int i = 0; i < rows; i++) U[i] = (double *)calloc(k, sizeof(double));
    for (int i = 0; i < cols; i++) V[i] = (double *)calloc(k, sizeof(double));
    double *S = (double *)calloc(k, sizeof(double));
    simpleSVD(A_work, rows, cols, U, S, V, k);
FILE *sf = fopen("singular_values.txt", "w");
for (int i = 0; i < k; i++)
    fprintf(sf, "%d %f\n", i+1, S[i]);
fclose(sf);

printf("Singular values saved to singular_values.txt\n");
    
    double **R = (double **)malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++) R[i] = (double *)calloc(cols, sizeof(double));
    reconstruct(U, S, V, R, rows, cols, k);
	printf("Enter output PGM file: "); scanf("%199s", outFile);
    write(outFile, R, rows, cols, maxVal, fmt);
    frobeniuserror(A_orig, R, rows, cols);
    compressionratio(rows,cols,k);
    for (int i = 0; i < rows; i++) { free(A_orig[i]); free(A_work[i]); free(U[i]); free(R[i]); }
    for (int i = 0; i < cols; i++) free(V[i]);
    free(A_orig); free(A_work); free(U); free(V); free(R); free(S);
	return 0;
}
