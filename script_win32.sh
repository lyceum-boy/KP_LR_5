#!/usr/bin/env sh

# Файлы *.c необходимо скомпилировать в объектные файлы,
# при этом рекомендуется использовать параметр -fPIC:
gcc -c -o arrayproc.o -fPIC arrayproc.c
gcc -c -o matrixproc.o -fPIC matrixproc.c

# Создадим динамические библиотеки из arrayproc.c и matrixproc.c.
gcc -shared -o libarrayproc.dll arrayproc.o
gcc -shared -o libmatrixproc.dll matrixproc.o

# Создадим динамическую библиотеку из load.c:
gcc -c -o load.o -fPIC load.c
gcc -shared -o load.dll load.o

# Скомпилируем и запустим полученную программу:
gcc -c -o main.o -fPIC main.c
gcc -o main.exe main.o -L./ -lload
start main.exe
