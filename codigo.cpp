#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#define N 4

void print(int C[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << C[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

void zero(int C[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
        }
    }
}

void classic(int A[N][N], int B[N][N], int C[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void blocks(int A[N][N], int B[N][N], int C[N][N], int b) {
    for (int ii = 0; ii < N; ii+=b) {
        for (int jj = 0; jj < N; jj+=b) {
            for (int kk = 0; kk < N; kk+=b) {
                for (int i = ii * b; i < (ii + 1) * b; i++) {
                    for (int j = jj * b; j < (jj + 1) * b; j++) {
                        for (int k = kk * b; k < (kk + 1) * b; k++) {
                            C[i][j] += A[i][k] * B[k][j];
                        }
                    }
                }
            }
        }
    }
}

int main() {
    
    srand (time(NULL));
    
    // Set up A
    int A[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
          A[i][j] = rand() % 10;
        }
    } 

    // Set up B
    int B[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
          B[i][j] = rand() % 10;
        }
    }

    // Set up C to zero
    int C[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
          C[i][j] = 0;
        }
    }

    std::cout << "Matrix A:\n";
    print(A);
    std::cout << "Matrix B:\n";
    print(B);
    std::cout << "Matrix C:\n";
    classic(A,B,C);
    print(C);
    
    zero(C);
    
    std::cout << "Matrix C:\n";
    blocks(A,B,C,2);
    print(C);
  
  return 0;
}

