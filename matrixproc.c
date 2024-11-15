//
// Created by anoso on 05.11.2024.
//

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc50-cpp"
#pragma ide diagnostic ignored "cert-msc51-cpp"
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Функция для заполнения матрицы случайными числами.
void fillMatrix(int **matrix, int rows, int cols) {
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Заполнение случайными числа от -50 до 50.
            matrix[i][j] = (rand() % 101) - 50;
        }
    }
}

// Функция для подсчёта отрицательных элементов в матрице.
int countNegativeInMatrix(int **matrix, int rows, int cols) {
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] < 0) {
                count++;
            }
        }
    }
    return count;
}

// Функция для вывода элементов матрицы на экран.
void printMatrix(int **matrix, int rows, int cols) {
    printf("Элементы матрицы A(%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
}

#pragma clang diagnostic pop
