#include <stdio.h>

#ifdef _WIN32
    #include <windows.h>
    #define LIB_EXTENSION ".dll"
#else
    #include <dlfcn.h>
    #define LIB_EXTENSION ".so"
#endif

#include "load.h"

// Функция для загрузки библиотеки libarrayproc.
void LoadRunArray(const char *const libName, int *array, int size) {
    void *lib;
    void (*fillArray)(int *, int);
    void (*printArray)(int *, int);
    int (*countNegativeInArray)(int *, int);

#ifdef _WIN32
    // Загрузка библиотеки в память.
    lib = LoadLibrary(libName);
    if (!lib) {
        printf("Не удалось открыть библиотеку '%s'!\n", libName);
        return;
    }
    // Получение указателей на функции из библиотеки.
    fillArray = (void (*)(int *, int)) GetProcAddress((HINSTANCE) lib, "fillArray");
    printArray = (void (*)(int *, int)) GetProcAddress((HINSTANCE) lib, "printArray");
    countNegativeInArray = (int (*)(int *, int)) GetProcAddress((HINSTANCE) lib, "countNegativeInArray");
#else
    // Загрузка библиотеки в память.
    lib = dlopen(libName, RTLD_LAZY);
    if (!lib) {
        printf("cannot open library '%s'\n", libName);
        return;
    }
    // Получение указателей на функции из библиотеки.
    fillArray = (void (*)(int *, int)) dlsym(lib, "fillArray");
    printArray = (void (*)(int *, int)) dlsym(lib, "printArray");
    countNegativeInArray = (int (*)(int *, int)) dlsym(lib, "countNegativeInArray");
#endif

    if (fillArray) {
        fillArray(array, size);
    } else {
        printf("Не удалось получить функцию fillArray!\n");
    }

    if (printArray) {
        printArray(array, size);
    } else {
        printf("Не удалось получить функцию printArray!\n");
    }

    if (countNegativeInArray) {
        int count = countNegativeInArray(array, size);
        printf("Количество отрицательных элементов в массиве: %d\n", count);
    } else {
        printf("Не удалось получить функцию countNegativeInArray!\n");
    }

#ifdef _WIN32
    FreeLibrary((HINSTANCE) lib); // Выгрузка библиотеки.
#else
    dlclose(lib); // Выгрузка библиотеки.
#endif
}

// Функция для загрузки библиотеки libmatrixproc.
void LoadRunMatrix(const char *const libName, int **matrix, int rows, int cols) {
    void *lib;
    void (*fillMatrix)(int **, int, int);
    void (*printMatrix)(int **, int, int);
    int (*countNegativeInMatrix)(int **, int, int);

#ifdef _WIN32
    // Загрузка библиотеки в память.
    lib = LoadLibrary(libName);
    if (!lib) {
        printf("Не удалось открыть библиотеку '%s'!\n", libName);
        return;
    }
    // Получение указателей на функции из библиотеки.
    fillMatrix = (void (*)(int **, int, int)) GetProcAddress((HINSTANCE) lib, "fillMatrix");
    printMatrix = (void (*)(int **, int, int)) GetProcAddress((HINSTANCE) lib, "printMatrix");
    countNegativeInMatrix = (int (*)(int **, int, int)) GetProcAddress((HINSTANCE) lib, "countNegativeInMatrix");
#else
    // Загрузка библиотеки в память.
    lib = dlopen(libName, RTLD_LAZY);
    if (!lib) {
        printf("cannot open library '%s'\n", libName);
        return;
    }
    // Получение указателей на функции из библиотеки.
    fillMatrix = (void (*)(int **, int, int)) dlsym(lib, "fillMatrix");
    printMatrix = (void (*)(int **, int, int)) dlsym(lib, "printMatrix");
    countNegativeInMatrix = (int (*)(int **, int, int)) dlsym(lib, "countNegativeInMatrix");
#endif

    if (fillMatrix) {
        fillMatrix(matrix, rows, cols);
    } else {
        printf("Не удалось получить функцию fillMatrix!\n");
    }

    if (printMatrix) {
        printMatrix(matrix, rows, cols);
    } else {
        printf("Не удалось получить функцию printMatrix!\n");
    }

    if (countNegativeInMatrix) {
        int count = countNegativeInMatrix(matrix, rows, cols);
        printf("Количество отрицательных элементов в матрице: %d\n", count);
    } else {
        printf("Не удалось получить функцию countNegativeInMatrix!\n");
    }

#ifdef _WIN32
    FreeLibrary((HINSTANCE) lib); // Выгрузка библиотеки.
#else
    dlclose(lib); // Выгрузка библиотеки.
#endif
}
