// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
const int MAX = 10;

// Function to display a matrix neatly
void displayMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
}

// Part A — Transpose a Matrix
void transposeMatrix(int matrix[MAX][MAX], int rows, int cols) {
    int transposed[MAX][MAX];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
    cout << "\nTransposed Matrix:\n";
    displayMatrix(transposed, cols, rows);
}

// Part B — Add Two Matrices
void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int rows, int cols) {
    int sum[MAX][MAX];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum[i][j] = A[i][j] + B[i][j];
        }
    }
    cout << "\nSum of Matrices:\n";
    displayMatrix(sum, rows, cols);
}

// Part C — Multiply Two Matrices
void multiplyMatrices(int A[MAX][MAX], int B[MAX][MAX], int rowsA, int colsA, int colsB) {
    int product[MAX][MAX] = {0};
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < colsA; k++) {
                product[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    cout << "\nProduct of Matrices:\n";
    displayMatrix(product, rowsA, colsB);
}

int main() {
    int M, N;
    int matrix[MAX][MAX];

    // Part A — Transpose
    cout << "Enter number of rows: ";
    cin >> M;
    cout << "Enter number of columns: ";
    cin >> N;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    cout << "\nOriginal Matrix:\n";
    displayMatrix(matrix, M, N);
    transposeMatrix(matrix, M, N);

    // Part B — Add Two Matrices
    int A[MAX][MAX], B[MAX][MAX];
    cout << "\nMatrix Addition:\n";
    cout << "Enter rows and columns (same for both matrices): ";
    cin >> M >> N;

    cout << "Enter elements for Matrix A:\n";
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            cin >> A[i][j];

    cout << "Enter elements for Matrix B:\n";
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            cin >> B[i][j];

    addMatrices(A, B, M, N);

    // Part C — Multiply Two Matrices
    int rowsA, colsA, rowsB, colsB;
    int matA[MAX][MAX], matB[MAX][MAX];
    cout << "\nMatrix Multiplication:\n";
    cout << "Enter rows and columns for Matrix A: ";
    cin >> rowsA >> colsA;
    cout << "Enter rows and columns for Matrix B: ";
    cin >> rowsB >> colsB;

    if (colsA != rowsB) {
        cout << "Error: Number of columns in A must equal number of rows in B." << endl;
        return 0;
    }

    cout << "Enter elements for Matrix A:\n";
    for (int i = 0; i < rowsA; i++)
        for (int j = 0; j < colsA; j++)
            cin >> matA[i][j];

    cout << "Enter elements for Matrix B:\n";
    for (int i = 0; i < rowsB; i++)
        for (int j = 0; j < colsB; j++)
            cin >> matB[i][j];

    multiplyMatrices(matA, matB, rowsA, colsA, colsB);

    return 0;
}


