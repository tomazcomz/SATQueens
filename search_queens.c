#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "queens.h"
#include <time.h>


//TODO estou a escrever em null



bool queens_dfs(Node* root,Node* father, int f){
    if (root == NULL){
        return false;
    }
    //printf("J equals %d and I equals %d \n",root->state->j,f);
    
    if (root->state->j==root->state->n){
        printBoard(root->state);
        printSolution(root->state);
        return true;
    }
    
    int n=root->state->n;
    int j=root->state->j;
    
    for (int i = 0;  i < n; i++){
        if (place(root->state,i))
            root->children[i]=newNode(root->state,i);
    }
    
    // recursion on each children
    for (int i = 0; i < n; i++)
    {
        if (queens_dfs(root->children[i],root,i)){
            //printf("Returned True Queens\n");      
            return true;
        }
        //printf("Returned False Queens\n");  
        //if (!root->children[i])
            //printf("Null Pointer AH!\n");
        
        
    }
    freeNode(root);
    if (father)
        father->children[f]=NULL;
        //printf("Nulling Children\n");
    return false;
}

bool base_dfs(Node* root){
    for (int i = root->state->j;i < root->state->n; i++){
        root->children[i]=newNode(root->state,i);
    }
    return queens_dfs(root,NULL,0);
}


int main(){
    int n;
    printf("How many Queens? \n");
    scanf("%d",&n);
    printf("Performing DFS in %d Queens\n",n);
    time_t begin = time(NULL);
    Queens* s=emptyQueens(n);
    Node* root = (Node*)malloc(sizeof(Node));
    root->state = s;
    root->children=(Node**)malloc(sizeof(Node*)*n);
    for (int i = 0; i < s->n; i++){
        root->children[i]=NULL;
    }
    bool res=base_dfs(root);
    if (!res)
        printf("No solution found.");
    time_t end = time(NULL);
    double time_spent = difftime(end, begin);
    printf("Took %d seconds to find a solution", time_spent);
    freeNode(root);
    return 0;
}

//TODO iterate cycle for n queens and print plot.
