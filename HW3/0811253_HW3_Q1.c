#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100  // Maximum STACK SIZE
typedef struct{
    int key;
    int scoredP;
} element;
element stack [MAX_STACK_SIZE] = {0};
int top = 0;

void add(int inkey, int inscoredP){
    //  add an item to the global stack
    if (top >= MAX_STACK_SIZE) {
        printf("Too much elements in the stack\n");
        return ;
    }
    stack[++top].key = inkey;
    stack[top].scoredP = inscoredP;
}

void pop(){
    // return the top-1 element from the stack
    if (top == 0){
        printf("stack at the bottom layer\n");
        return;
    }
    stack[top].key = 0;
    stack[top--].scoredP = 0;
}


int main(void) {
    int n, dailyScord;
    scanf("%d", &n);    // the number of days
    int daySpans[n];

    int i;
    stack[0].scoredP = 10000;   // first element initialized
    for(i=1; i<=n; i++){
        scanf(" %d", &dailyScord);
        while (dailyScord > stack[top].scoredP){
            pop();
        }
        daySpans[i-1] = i - stack[top].key;
        add(i, dailyScord);

    }

    // output result
    /*
    for(i=0; i<30; i++){
        printf("key = %d, scoredP = %d\n", stack[i].key, stack[i].scoredP);
    }
    */
    printf("\nthe spans for each day :\n");
    for(i=0; i<n; i++){
        printf("%d ", daySpans[i]);
    }
    printf("\n\n");


    return 0;
}

