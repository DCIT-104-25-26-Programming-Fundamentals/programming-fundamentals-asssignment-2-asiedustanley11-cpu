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

const int MAX_SIZE = 10;
 
// Prompts the user to enter every element of a rows x cols matrix,
// filling it in one element at a time.
void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}
 
// Prints a matrix in a neat, aligned grid using setw() for spacing.
void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, const string& title) {
    cout << "\n" << title << ":" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(6) << matrix[i][j];
        }
        cout << endl;
    }
}
 
// -----------------------------------------------------------------------------
// PART A — Transpose
// -----------------------------------------------------------------------------
// Fills "result" with the transpose of "matrix" (rows and columns swapped).
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols,
                      int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}
 
// -----------------------------------------------------------------------------
// PART B — Addition
// -----------------------------------------------------------------------------
// Fills "result" with the element-wise sum of matrixA and matrixB.
void addMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE],
                  int rows, int cols, int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}
 
// -----------------------------------------------------------------------------
// PART C — Multiplication
// -----------------------------------------------------------------------------
// Fills "result" with the matrix product of matrixA (m x n) and matrixB (n x p).
void multiplyMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE],
                       int m, int n, int p, int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            int total = 0;
            for (int k = 0; k < n; k++) {
                total += matrixA[i][k] * matrixB[k][j];
            }
            result[i][j] = total;
        }
    }
}
 
// Reads a positive integer for a dimension (rows/cols), returning true
// on success and false if the input was invalid.
bool readPositiveInt(const string& prompt, int& value) {
    cout << prompt;
    cin >> value;
 
    if (cin.fail() || value <= 0 || value > MAX_SIZE) {
        return false;
    }
    return true;
}
 
int main() {
    int rows, cols;
 
    // -------------------------------------------------------------------
    // PART A — Transpose
    // -------------------------------------------------------------------
    cout << "--- Part A: Transpose a Matrix ---" << endl;
 
    if (!readPositiveInt("Enter number of rows: ", rows) ||
        !readPositiveInt("Enter number of columns: ", cols)) {
        cout << "Error: dimensions must be positive integers up to " << MAX_SIZE << "." << endl;
        return 1;
    }
 
    int matrix[MAX_SIZE][MAX_SIZE];
    readMatrix(matrix, rows, cols);
    displayMatrix(matrix, rows, cols, "Original Matrix");
 
    int transposed[MAX_SIZE][MAX_SIZE];
    transposeMatrix(matrix, rows, cols, transposed);
    displayMatrix(transposed, cols, rows, "Transposed Matrix");
 
    // -------------------------------------------------------------------
    // PART B — Addition
    // -------------------------------------------------------------------
    cout << "\n--- Part B: Add Two Matrices ---" << endl;
 
    int rowsB, colsB;
    if (!readPositiveInt("Enter number of rows for both matrices: ", rowsB) ||
        !readPositiveInt("Enter number of columns for both matrices: ", colsB)) {
        cout << "Error: dimensions must be positive integers up to " << MAX_SIZE << "." << endl;
        return 1;
    }
 
    int matrixA[MAX_SIZE][MAX_SIZE];
    int matrixB[MAX_SIZE][MAX_SIZE];
 
    cout << "Matrix A:" << endl;
    readMatrix(matrixA, rowsB, colsB);
    cout << "Matrix B:" << endl;
    readMatrix(matrixB, rowsB, colsB);
 
    displayMatrix(matrixA, rowsB, colsB, "Matrix A");
    displayMatrix(matrixB, rowsB, colsB, "Matrix B");
 
    int sumMatrix[MAX_SIZE][MAX_SIZE];
    addMatrices(matrixA, matrixB, rowsB, colsB, sumMatrix);
    displayMatrix(sumMatrix, rowsB, colsB, "Sum (A + B)");
 
    // -------------------------------------------------------------------
    // PART C — Multiplication
    // -------------------------------------------------------------------
    cout << "\n--- Part C: Multiply Two Matrices ---" << endl;
 
    int m, n, p;
    if (!readPositiveInt("Enter rows for Matrix A: ", m) ||
        !readPositiveInt("Enter columns for Matrix A (= rows for Matrix B): ", n) ||
        !readPositiveInt("Enter columns for Matrix B: ", p)) {
        cout << "Error: dimensions must be positive integers up to " << MAX_SIZE << "." << endl;
        return 1;
    }
 
    int matrixC[MAX_SIZE][MAX_SIZE];
    int matrixD[MAX_SIZE][MAX_SIZE];
 
    cout << "Matrix A:" << endl;
    readMatrix(matrixC, m, n);
    cout << "Matrix B:" << endl;
    readMatrix(matrixD, n, p);
 
    displayMatrix(matrixC, m, n, "Matrix A");
    displayMatrix(matrixD, n, p, "Matrix B");
 
    int productMatrix[MAX_SIZE][MAX_SIZE];
    multiplyMatrices(matrixC, matrixD, m, n, p, productMatrix);
    displayMatrix(productMatrix, m, p, "Product (A x B)");
 
    return 0;
}