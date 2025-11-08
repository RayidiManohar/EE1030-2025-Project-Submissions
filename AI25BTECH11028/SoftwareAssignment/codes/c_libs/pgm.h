#ifndef PGM_H
#define PGM_H

double **read(char *filename, int *rows, int *cols, int *maxVal, char *format);
void write(char *file, double **img, int rows, int cols, int maxVal, char *format);

#endif
