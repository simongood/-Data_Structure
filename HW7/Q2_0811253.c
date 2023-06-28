#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#define inf 99999

int length;


int minDistanse(int start, int end, int path[length][length]){
    int minDis = inf;     // minimum distance
    int book[99] = {0};

    void count(int cur, int roadMaxDis){
        if (roadMaxDis > minDis) return;
        if (cur == end) {
            if (roadMaxDis < minDis) {
                minDis = roadMaxDis;
                return;
            }
        }
        for (int i=1; i < length; i++){
            if (path[cur][i] != inf && book[i] == 0){
                book[i] = 1;
                if (path[cur][i] > roadMaxDis) roadMaxDis = path[cur][i];
                count(i, roadMaxDis);
                book[i] = 0;
            }
        }
        return;
    }

    count(start, 0);

    return minDis;
}




int main() {
    int roadnum, Qnum;
    scanf("%d %d %d", &length, &roadnum, &Qnum);
    length ++;
    // input road data in the 2D matrix
    int path[length][length];
    for(int i=0; i<length; i++) {
        for(int j=0; j<length; j++) {
            if( i==j ) path[i][j] = 0;
            else if( i == 0) path[i][j] = j;
            else if( j == 0) path[i][j] = i;
            else path[i][j] = inf;
        }
    }
    int start, end, len;
    for(int i=1; i<=roadnum; i++){
        scanf("%d %d %d", &start, &end, &len);
        path[start][end] = len;
        path[end][start] = len;
    }

    // Question
    int minDistan[Qnum];
    for(int i=0; i<Qnum; i++){
        scanf("%d %d", &start, &end);
        minDistan[i] = minDistanse(start, end, path);
    }
    for(int i=0; i<Qnum; i++){
        if (minDistan[i] == inf) printf("no path\n");
        else printf("%d\n", minDistan[i]);
    }

    return 0;
}
