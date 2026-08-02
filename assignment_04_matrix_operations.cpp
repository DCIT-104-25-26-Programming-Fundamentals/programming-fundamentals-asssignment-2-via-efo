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


void readMatrix(int matrix[10][10], int rows, int cols, string label)
{
    cout << "Enter " << label << " (" << rows << "x" << cols << "):" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(int matrix[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

void transposeMatrix(int matrix[10][10], int rows, int cols, int result[10][10])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[j][i] = matrix[i][j];
        }
    }
}

void addMatrices(int a[10][10], int b[10][10], int rows, int cols, int result[10][10])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiplyMatrices(int a[10][10], int b[10][10], int m, int n, int p, int result[10][10])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            int total = 0;
            for (int k = 0; k < n; k++)
            {
                total += a[i][k] * b[k][j];
            }
            result[i][j] = total;
        }
    }
}

int main()
{
    int matrix[10][10], result[10][10];
    int a[10][10], b[10][10], sum[10][10];
    int c[10][10], d[10][10], product[10][10];
    int rows, cols, rowsB, colsB, m, n, p;

    cout << "--- Part A: Transpose a Matrix ---" << endl;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
    readMatrix(matrix, rows, cols, "matrix");

    cout << endl
         << "Original Matrix:" << endl;
    printMatrix(matrix, rows, cols);

    transposeMatrix(matrix, rows, cols, result);
    cout << endl
         << "Transposed Matrix:" << endl;
    printMatrix(result, cols, rows);

    cout << endl
         << "--- Part B: Add Two Matrices ---" << endl;
    cout << "Enter number of rows: ";
    cin >> rowsB;
    cout << "Enter number of columns: ";
    cin >> colsB;
    readMatrix(a, rowsB, colsB, "matrix A");
    readMatrix(b, rowsB, colsB, "matrix B");

    addMatrices(a, b, rowsB, colsB, sum);
    cout << endl
         << "Sum:" << endl;
    printMatrix(sum, rowsB, colsB);

    cout << endl
         << "--- Part C: Multiply Two Matrices ---" << endl;
    cout << "Enter rows of matrix A: ";
    cin >> m;
    cout << "Enter columns of matrix A / rows of matrix B: ";
    cin >> n;
    cout << "Enter columns of matrix B: ";
    cin >> p;
    readMatrix(c, m, n, "matrix A");
    readMatrix(d, n, p, "matrix B");

    multiplyMatrices(c, d, m, n, p, product);
    cout << endl
         << "Product:" << endl;
    printMatrix(product, m, p);

    return 0;
}