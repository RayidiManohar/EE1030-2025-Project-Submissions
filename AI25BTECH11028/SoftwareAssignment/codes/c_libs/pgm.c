#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "pgm.h"
double **read(char *filename, int *rows, int *cols, int *maxVal, char *format) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) { printf("Error: Cannot open %s\n", filename); 
	    exit(1); }

    fscanf(fp, "%2s", format);
    int c = fgetc(fp);
    while (c == '#') 
    { while (fgetc(fp) != '\n'); c = fgetc(fp); }
    ungetc(c, fp);

    fscanf(fp, "%d %d", cols, rows);
    fscanf(fp, "%d", maxVal);
    fgetc(fp);

    double **imgdata = (double **)malloc((*rows) * sizeof(double *));
    for (int i = 0; i < *rows; i++) 
    {imgdata[i] = (double *)calloc(*cols, sizeof(double));}

        for (int i = 0; i < *rows; i++)
	{
		for (int j = 0; j < *cols; j++) 
		{ 
			unsigned char v; 
		  	fread(&v,1,1,fp); 
		  	imgdata[i][j] = v; 
		}
	}
     

    fclose(fp);
    return imgdata;
}
void write(char *file, double **img, int rows, int cols, int maxVal, char *format) 
{
    FILE *fp = fopen(file, "wb");
    if (fp == NULL) 
    {
	    printf("Error: Cannot write to %s\n", file);
	    exit(1);
    }
    fprintf(fp, "%s\n%d %d\n%d\n", format, cols, rows, maxVal);
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
	{
            int val = (int)round(img[i][j]);
            if (val < 0) val = 0;
            if (val > maxVal) val = maxVal; 
		    unsigned char c = val; 
		    fwrite(&c,1,1,fp); 
        }
    }
    fclose(fp);
