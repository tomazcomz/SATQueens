gcc -o queens.o -c queens.c
gcc -o search_queens search_queens.c queens.o
valgrind --leak-check=full --track-origins=yes ./search_queens
