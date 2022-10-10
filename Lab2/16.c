#include <stdio.h>
#include <stdlib.h>

#define KOL 3

void read_matrix(int matrix[][KOL], int n, int m);
void print_matrix(const int matrix[][KOL], int n, int m);
void transpose_matrix(const int matrix[][KOL], int n, int m, int transposed[][KOL]);
void multiply_matrix(const int matrix[][KOL], int n, int m,
                     const int matrix2[][KOL], int n2, int m2, int product[][KOL]);

int main() {

  int matrix[3][KOL] = {0};
  printf("Input matrix(9 numbers):\n");
  read_matrix(matrix, 3, 3);
  printf("-----------------------------------------------\n");
  printf("Matrix:\n");
  print_matrix(matrix, 3, KOL);
  printf("-----------------------------------------------\n");
  printf("Transposed matrix:\n");
  int transposed[3][3] = {0};
  transpose_matrix(matrix, 3, 3, transposed);
  print_matrix(transposed, 3, 3);
  printf("-----------------------------------------------\n");
  printf("Product matrix:\n");
  int second_matrix[3][KOL] = {0};
  printf("Input second matrix(9 numbers):\n");
  read_matrix(second_matrix, 3, 3);
  printf("Multiplied matrix:\n");
  int product[3][KOL] = {0};
  multiply_matrix(matrix, 3, 3, second_matrix, 3, 3, product);
  print_matrix(product, 3, 3);

  return 0;
}

void read_matrix(int matrix[][KOL], int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &matrix[i][j]);
    }
  }
}

void print_matrix(const int matrix[][KOL], int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

void transpose_matrix(const int matrix[][KOL], int n, int m,
                      int transposed[][KOL]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      transposed[i][j] = matrix[j][i];
    }
  }
}

void multiply_matrix(const int matrix[][KOL], int n, int m,
                     const int matrix2[][KOL], int n2, int m2, int product[][KOL]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m2; j++) {
      for (int k = 0; k < m; k++) {
        product[i][j] += matrix[i][k] * matrix2[k][j];
      }
    }
  }
}
