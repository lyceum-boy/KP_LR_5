/* Аносов Илья Борисович
 * Группа О737Б
 * Компьютерный практикум
 * Лабораторная работа №3
 * Вариант 4 */

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"

#include <stdio.h>
#include <stdlib.h>
#include "load.h"

#define ARRAY_LIB_NAME "libarrayproc"
#define MATRIX_LIB_NAME "libmatrixproc"

#ifdef _WIN32
    #define LIB_EXTENSION ".dll"
#else
    #define LIB_EXTENSION ".so"
#endif

#define SYSTEM_PAUSE() do { printf("Press any key to continue . . . "); getchar(); } while (0)

#define ARRAY_SIZE 42
#define MATRIX_ROWS 6
#define MATRIX_COLS 9

int main(void) {
#ifdef _WIN32
    // Локализация для вывода на экран русскоязычного текста.
    system("chcp 65001");
    // Очистка окна на Windows. Для Linux используется system ("clear").
    system("cls");
#else
    system("clear");
#endif

    int array[ARRAY_SIZE];
    int *matrix[MATRIX_ROWS];
    for (int i = 0; i < MATRIX_ROWS; i++) {
        matrix[i] = (int *) malloc(MATRIX_COLS * sizeof(int));
    }

    int choice = 0, isRunning = 1;
    while (isRunning) {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
        printf("Выберите библиотеку:\n");
        printf("1. Библиотека для работы с массивами\n");
        printf("2. Библиотека для работы с матрицами\n");
        printf("3. Выйти\n");
        printf("Введите пункт меню: ");

        // Контроль ввода.
        // Пропускаем символ после введенного числа (пункта меню).
        if (scanf("%d%*c", &choice) != 1) {
            printf("Ошибка: введите целое число!\n");
            while (getchar() != '\n'); // Очистка буфера ввода.
#ifdef _WIN32
            system("pause");
#else
            SYSTEM_PAUSE();
#endif
            continue;
        }

        printf("\n");

        switch (choice) {
            case 1: {
                LoadRunArray(ARRAY_LIB_NAME LIB_EXTENSION, array, ARRAY_SIZE);
                break;
            }
            case 2: {
                LoadRunMatrix(MATRIX_LIB_NAME LIB_EXTENSION, matrix, MATRIX_ROWS, MATRIX_COLS);
                break;
            }
            case 3: {
                isRunning = 0;
                break;
            }
            default: {
                printf("Неверный выбор! Повторите попытку.\n");
                break;
            }
        }

        printf("\n");

#ifdef _WIN32
        system("pause");
#else
        SYSTEM_PAUSE();
#endif
    }

    // Освобождение памяти.
    for (int i = 0; i < MATRIX_ROWS; i++) {
        free(matrix[i]);
    }

    return 0;
}

#pragma clang diagnostic pop
