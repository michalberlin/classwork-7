#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int** createMatrix(int rows, int cols);
void printArray(int* arr, int size);
void printMatrix(int** mat, int rows, int cols);
void swapRows(void** mat, int row1, int row2);
void freeMatrix(int** mat, int rows);
void swapCols(int** mat, int rows, int col1, int col2);


void main()
{
	int** result, cols, rows;
	printf("please enter amount of rows:\n");
	scanf("%d", &rows);
	printf("please enter amount of cols:\n");
	scanf("%d", &cols);
	result = createMatrix(rows, cols);
	printMatrix(result, rows, cols);
	swapRows(result, 0, 2);
	printf("\n");
	printMatrix(result, rows, cols);
	freeMatrix(result, rows);

}
int** createMatrix(int rows, int cols)
{
	int** mat, i, j;
	mat = (int**)calloc(rows, sizeof(int*));
	assert(mat);
	for (i = 0; i < rows; i++)
	{
		mat[i] = (int*)calloc(cols, sizeof(int));
		assert(mat[i]);
		for (j = 0; j < cols; j++)
		{
			mat[i][j] = (i + j + 2) * 3;
		}
	}
	return mat;
}
void printArray(int* arr, int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d\t", arr[i]);
	printf("\n");
}
void printMatrix(int** mat, int rows, int cols)
{
	int i;
	for (i = 0; i < rows; i++)
		printArray(mat[i], cols);
}
void swapRows(void** mat, int row1, int row2)
{
	int* temp;
	temp = mat[row1];
	mat[row1] = mat[row2];
	mat[row2] = temp;
}

void swapCols(int** mat, int rows, int col1, int col2)
{
	int i, temp;
	for (i = 0; i < rows; i++)
	{
		temp = mat[i][col1];
		mat[i][col1] = mat[i][col2];
		mat[i][col2] = temp;
	}
}

void freeMatrix(int** mat, int rows)
{
	int i;
	for (i = 0; i < rows; i++)
	{
		free(mat[i]);
	}
	free(mat);
}