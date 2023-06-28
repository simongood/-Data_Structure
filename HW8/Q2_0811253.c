
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

int length;

int DAGbool(int path[length][length]){
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
            printf("-1");
            return 0;
        }
    }

    printf("true\n");
    return 1;
}

void searchRoad(int path[length][length]) {
    int cnt = 0;
    int book[length];
    for(int i=0; i<length; i++) book[i] = -1;

    for(int j=0; j<length; j++){
        for(int i=0; i<length; i++){
            if (path[i][j] == 1) {
                break;
            }
        }
        book[cnt] = j;
        break;
    }

    int end = 0;


    while (end == 0){
        for(int i=0; i<length; i++){

            if(path[book[cnt]][i] == 1){
                book[++cnt] = i;
                if (i == length-1) end = 1;
                break;
            }
            if (i == length-1) end = 1;
        }

    }

    for(int i=0; i<length; i++){
        //if (book[i] == -1) break;
        printf("%d ", book[i]);
    }

    return ;
}



int main() {
    int roadnum;
    scanf("%d %d", &length, &roadnum);
    // input road data in the 2D matrix
        // initialize
    int path[length][length], path1[length][length]; // path1 is path copy
    for(int i=0; i<length; i++)
        for(int j=0; j<length; j++){
            path[i][j] = 0;
            path1[i][j] = 0;
        }
        // input data
    int start, end;
    for(int i=0; i<roadnum; i++){
        scanf("%d %d", &end, &start);
        path[start][end] = 1;
        path1[start][end] = 1;
    }

/*
        // check data
    for(int i=0; i<length; i++){
        for(int j=0; j<length; j++) printf("%d ", path[i][j]);
        printf("\n");
    }
*/
    int Dbool = DAGbool(path);
    if (Dbool == 1) searchRoad(path1);

    return 0;
}
