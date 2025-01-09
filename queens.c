#include "queens.h"
#include <stdlib.h>
#include <stdbool.h>



void copyBoard(bool** copiee, bool** copier, int size){
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            copiee[i][j]=copier[i][j];
        }
        
    }
    
}

void copySolution(int* copiee, int* copier, int size){
    for (int i = 0; i < size; i++)
    {
        copiee[i]=copier[i];
    }
    
}

// Assumes q already has q
void alloQueens(Queens* q){
    q->board=(bool**)malloc(sizeof(bool*)*q->n);
    q->solution=(int*)malloc(sizeof(int)*q->n);
    for (int i = 0; i < q->n; i++)
    {
        q->board[i]=(bool*)malloc(sizeof(bool)*q->n);
        q->solution[i]=0;
        for (int j = 0; j < q->n; j++)
        {
            q->board[i][j]=false;
        }
    }
    
}

void freeQueens(Queens* q){
    free(q->board);
    free(q->solution);
    free(q);
}

// Assumes children were already freed
void freeNode(Node* no){
    if (!no->state)
        printf("Null Queens AH!\n");
    freeQueens(no->state);
    free(no);
}

Queens* emptyQueens(int n){
    Queens* q = (Queens*)malloc(sizeof(Queens));
    q->n=n;
    q->j=0;
    alloQueens(q);
    return q;
}

Queens* newQueens(Queens* state,int i)
{
    Queens* q = emptyQueens(state->n);   
    copyBoard(q->board,state->board,q->n);
    copySolution(q->solution,state->solution,q->n);
    q->board[i][state->j]=true;
    q->solution[state->j]=i;
    q-> j=state->j+1;
    return (q);
}

// This function operates on the assumption that queen j is placed after queen j-1
// where j is the row number
bool place(Queens* p, int row){
    int i,j;

    // Check this row on left side
    for (i = 0; i < p->j; i++){
        if (p->board[row][i])
            return false;
    }

    // Check upper diagonal on left side
    for (i = row, j = p->j; i >= 0 && j >= 0; i--, j--)
        if (p->board[i][j])
            return false;

    // Check lower diagonal on left side
    for (i = row, j = p->j; j >= 0 && i < p->n; i++, j--)
        if (p->board[i][j])
            return false;

    return true;
    
}

Node* newNode(Queens* state,int j)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->state = newQueens(state,j);
    node->children=(Node**)malloc(sizeof(Node*)*state->n);
    for (int i = 0; i < state->n; i++)
    {
        node->children[i]=NULL;
    }
    return (node);
}

void printSolution(Queens* q){
    for (int i = 0; i < q->n; i++)
    {
        printf("%d ",q->solution[i]);
    }
    printf("\n\n");
}

void printBoard(Queens* q){
    for (int i = 0; i < q->n; i++)
    {
        for (int j = 0; j < q->n; j++)
        {
            printf("%d ",q->board[i][j]);
        }
        printf("\n");
    }
    printf("\n");

}