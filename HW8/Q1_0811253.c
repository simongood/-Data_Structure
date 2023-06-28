#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

int length;

void DAGbool(int path[length][length]){
    int book[length];  // if path[i][] = 0 ; book[i] = 0;
    for(int i=0; i<length; i++) book[i] = 1;

    void clearPath(){
        for(int j=0; j<length; j++){
            if(book[j] == 0) return;

            for(int i=0; i<length; i++){
                if (path[i][j] == 1) {
                    book[j] = 1;
                    break;
                } else book[j] = 0;
            }

            if (book[j] == 0) {
                for(int k=0; k<length; k++) path[j][k] = 0;
                clearPath();
            }
        }
        return;
    }

    clearPath();
    for(int i=0; i<length; i++){
        if(book[i] == 1){
            printf("false");
            return;
        }
    }

    printf("true");
    return;
}

int main() {
    int roadnum;
    scanf("%d %d", &length, &roadnum);
    // input road data in the 2D matrix
        // initialize
    int path[length][length];
    for(int i=0; i<length; i++)
        for(int j=0; j<length; j++)
            path[i][j] = 0;
        // input data
    int start, end;
    for(int i=0; i<roadnum; i++){
        scanf("%d %d", &end, &start);
        path[start][end] = 1;
    }

/*
        // check data
    for(int i=0; i<length; i++){
        for(int j=0; j<length; j++) printf("%d ", path[i][j]);
        printf("\n");
    }
*/
    DAGbool(path);

    return 0;
}
