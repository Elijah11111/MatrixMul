#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 100  // Maximum matrix size

int main(int argc, char *argv[]) {
    int rows, cols, i, j, k;
    int matrix1[MAX_ROWS][MAX_ROWS], matrix2[MAX_ROWS][MAX_ROWS], result[MAX_ROWS][MAX_ROWS];
    FILE *fp;

    // Determine input method
    if (argc == 3) {  // Command-line arguments: two file names
        fp = fopen(argv[1], "r");
        if (fp == NULL) {
            fprintf(stderr, "Error opening file %s\n", argv[1]);
            exit(1);
        }
        if (fscanf(fp, "%d %d", &rows, &cols) != 2) {
            fprintf(stderr, "Invalid format in file %s\n", argv[1]);
            exit(1);
        }
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                if (fscanf(fp, "%d", &matrix1[i][j]) != 1) {
                    fprintf(stderr, "Invalid format in file %s\n", argv[1]);
                    exit(1);
                }
            }
        }
        fclose(fp);

        fp = fopen(argv[2], "r");
        if (fp == NULL) {
            fprintf(stderr, "Error opening file %s\n", argv[2]);
            exit(1);
        }
        if (fscanf(fp, "%d %d", &rows, &cols) != 2 || cols != matrix1[0][cols - 1]) {
            fprintf(stderr, "Invalid format or incompatible matrices\n");
            exit(1);
        }
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                if (fscanf(fp, "%d", &matrix2[i][j]) != 1) {
                    fprintf(stderr, "Invalid format in file %s\n", argv[2]);
                    exit(1);
                }
            }
        }
        fclose(fp);
    } else if (argc == 2) {  // Command-line argument: integer (size of matrices)
        sscanf(argv[1], "%d", &rows);
        cols = rows;
        srand(time(NULL));  // Seed random number generator
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                matrix1[i][j] = rand() % 100;  // Generate random numbers 0-99
            }
        }
        fp = fopen("matrix1.txt", "w");
        if (fp == NULL) {
            fprintf(stderr, "Error creating file matrix1.txt\n");
            exit(1);
        }
        fprintf(fp, "%d %d\n", rows, cols);
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                fprintf(fp, "%d ", matrix1[i][j]);
            }
            fprintf(fp, "\n");
        }
        fclose(fp);

        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                matrix2[i][j] = rand() % 100;
            }
        }
        fp = fopen("matrix2.txt", "w");
        if (fp == NULL) {
            fprintf(stderr, "Error creating file matrix2.txt\n");
            exit(1);
        }
        fprintf(fp, "%d %d\n", rows, cols);
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                fprintf(fp, "%d "

