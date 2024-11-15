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

#define ELEMENTS_PER_LINE 7

// Функция для заполнения массива случайными числами.
void fillArray(int *array, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        // Заполнение случайными числа от -50 до 50.
        array[i] = (rand() % 101) - 50;
    }
}

// Функция для подсчёта отрицательных элементов в массиве.
int countNegativeInArray(const int *array, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] < 0) {
            count++;
        }
    }
    return count;
}

// Функция для вывода элементов массива на экран.
void printArray(int *array, int size) {
    printf("Элементы массива D(%d):\n", size);
    printf("[");
    for (int i = 0; i < size; i++) {
        if (i % ELEMENTS_PER_LINE == 0 && i != 0) printf("\n ");
        printf("%3d", array[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

#pragma clang diagnostic pop
