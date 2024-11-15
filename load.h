//
// Created by anoso on 05.11.2024.
//

#ifndef KP_LR_3_LOAD_H
#define KP_LR_3_LOAD_H

// Функция для загрузки библиотеки libarrayproc.
void LoadRunArray(const char *libName, int *array, int size);

// Функция для загрузки библиотеки libmatrixproc.
void LoadRunMatrix(const char *libName, int **matrix, int rows, int cols);

#endif //KP_LR_3_LOAD_H
