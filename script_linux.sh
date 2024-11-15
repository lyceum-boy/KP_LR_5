#!/usr/bin/env sh

# Файлы *.c необходимо скомпилировать в объектные файлы,
# при этом рекомендуется использовать параметр -fPIC:
gcc -c -o arrayproc.o -fPIC arrayproc.c
gcc -c -o matrixproc.o -fPIC matrixproc.c

# Создадим динамические библиотеки из arrayproc.c и matrixproc.c.
gcc -shared -o libarrayproc.so arrayproc.o
gcc -shared -o libmatrixproc.so matrixproc.o

# Создадим динамическую библиотеку из load.c:
gcc -c -o load.o -fPIC load.c
gcc -shared -o libload.so load.o

# Скомпилируем и запустим полученную программу:
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/anoso/Desktop/KP_LR_3/
gcc -c -o main.o -fPIC main.c
gcc -o main main.o -L./ -lload -ldl
./main
