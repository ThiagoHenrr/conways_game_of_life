#!/bin/bash

gcc -Wall -Wextra -g -c Conway.c -o Conway.o
gcc -Wall -Wextra -g -c main.c -o main.o
gcc -Wall -Wextra Conway.o main.o -o conway
