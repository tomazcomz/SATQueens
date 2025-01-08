#include <stdbool.h>
#include <stdio.h>

// Disclosure: there is code adapted from GeeksForGeeks in this library

//TODO: how to declare undifined sized array
// #define SIZE 4

typedef struct
{
    int n,j;                        // j is where next queen is to be put
    bool** board;
    int* solution;      // should come as sequence of placements
} Queens;

typedef struct node{
    Queens* state;
    struct node** children;
} Node;


void copyBoard(bool** copiee,bool** copier, int size);
void copySolution(int* copiee, int* copier, int size);
void alloQueens(Queens* q);
void freeNode(Node* n);
void freeQueens(Queens* q);
Queens* emptyQueens(int n);
Queens* newQueens(Queens* state,int i);


// This function operates on the assumption that queen j is placed after queen j-1
// where j is the row number
bool place(Queens* q, int row);
void printSolution(Queens* q);
void printBoard(Queens* q);



Node* newNode(Queens* state,int j);


