#include<stdio.h>
#include <time.h>
#include<stdlib.h>

/*void matrix_multiple(int *a, int *c, int n, int m) {
    int **b = (int **)malloc(n * sizeof(int *));
    for(int i = 0; i < n; i++) {
        b[i] = (int *)malloc(m * sizeof(int));
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            b[i][j] = 0;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < m; k++) {
                b[i][j] += a[i * m + k] * c[k * m + j];
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, m;
    printf("Enter row:");
    scanf("%d", &n);
    printf("Enter col:");
    scanf("%d", &m);
    int *a = (int *)malloc(n * m * sizeof(int));
    int *c = (int *)malloc(n * m * sizeof(int));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("enter first element- (%d,%d):", i, j);
            scanf("%d", &a[i * m + j]);
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("enter second element- (%d,%d):", i, j);
            scanf("%d", &c[i * m + j]);
        }
    }
      clock_t start = clock();
    matrix_multiple(a, c, n, m);
     clock_t end = clock();
     double elapsed_time = (double)(end - start);// / CLOCKS_PER_SEC;
      printf("Execution time: %f \n", elapsed_time);
    free(a);
    free(c);
    return 0;
}*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 35000

// Function to multiply two matrices
void multiply_matrices(double **matrix1, double **matrix2, double **result, int rows1, int cols1, int cols2) {
    clock_t start_time, end_time;
    double execution_time;

    start_time = clock();

    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            result[i][j] = 0.0;
            for (int k = 0; k < cols1; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    end_time = clock();
    execution_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Execution time: %.2lf seconds\n", execution_time);
}

int main() {
    int choice, rows1, cols1, rows2, cols2;

    printf("Enter choice (1 to 5): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            rows1 = cols1 = 1000;
            break;
        case 2:
            rows1 = cols1 = 2000;
            break;
        case 3:
            rows1 = cols1 = 2500;
            break;
        case 4:
            rows1 = cols1 = 3000;
            break;
        case 5:
            rows1 = cols1 = 3500;
            break;
        default:
            printf("Invalid choice.\n");
            return 1;
    }

    rows2 = cols2 = rows1;  // Ensure square matrices
int size = rows1 * cols1;
printf("Matrix size (elements): %d\n", size);

   
    double **matrix1 = (double **)malloc(rows1 * sizeof(double *));
    for (int i = 0; i < rows1; ++i) {
        matrix1[i] = (double *)malloc(cols1 * sizeof(double));
    }

    double **matrix2 = (double **)malloc(rows2 * sizeof(double *));
    for (int i = 0; i < rows2; ++i) {
        matrix2[i] = (double *)malloc(cols2 * sizeof(double));
    }

    double **result = (double **)malloc(rows1 * sizeof(double *));
    for (int i = 0; i < rows1; ++i) {
        result[i] = (double *)malloc(cols2 * sizeof(double));
    }

  
    srand(time(NULL));
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols1; ++j) {
            matrix1[i][j] = ((double)rand()) / RAND_MAX;
            matrix2[i][j] = ((double)rand()) / RAND_MAX;
        }
    }

    multiply_matrices(matrix1, matrix2, result, rows1, cols1, cols2);



    return 0;
}
