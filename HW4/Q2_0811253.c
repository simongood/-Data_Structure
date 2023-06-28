#include <stdio.h>
#include <stdlib.h>

// You MUST NOT modify this!
struct Snake {
    int ratWeight;
    struct Snake *nextRat;
};

struct Snake* digestMiddle(struct Snake* head) {
    // initialize
    struct Snake* current = head->nextRat;

    // count number of rats which behind the head
    int cnt = 0;
    for (; current; current = current->nextRat) cnt += 1;
    current = head->nextRat;

    // count number of digest rats
    int i=0, trailNumber;     // which in front of digest number

    if (cnt == 1) return current->nextRat;
    else if( cnt % 2 == 0) trailNumber = cnt/2;
    else trailNumber = (cnt-1) / 2;

    // delete node
    while(++i < trailNumber) {
        current = current->nextRat;
    }
    struct Snake* node = current->nextRat;
    current->nextRat = node->nextRat;
    free(node);
    return head;

}

int** vomitAndCrawl(int rows, int cols, struct Snake* head, int digestInterval) {
        // initialize 2D array
    int **RATarray = (int**)malloc(sizeof(int*)*rows);
    for (int i=0; i<rows; i++) {
        RATarray[i] = (int*)malloc(sizeof(int)*cols);
        for (int j=0; j<cols; j++) RATarray[i][j] = -1;
    }

    // compute
    int rowi = 0, coli = 0, direct = 1, cnt=0;
    struct Snake* current = head;

    for (; current; current = current -> nextRat) {
        if (direct == 1) {
            // right
            if (coli == cols-1 || RATarray[rowi][coli+1] != -1){
                RATarray[rowi++][coli] = current -> ratWeight;
                direct = 2;
            }
            else RATarray[rowi][coli++] = current -> ratWeight;

        } else if (direct == 2){
            // down
            if (rowi == rows-1 || RATarray[rowi+1][coli] != -1){
                RATarray[rowi][coli--] = current -> ratWeight;
                direct = 3;
            }
            else RATarray[rowi++][coli] = current -> ratWeight;

        } else if (direct == 3){
            // left
            if (coli == 0 || RATarray[rowi][coli-1] != -1){
                RATarray[rowi--][coli] = current -> ratWeight;
                direct = 4;
            }
            else RATarray[rowi][coli--] = current -> ratWeight;

        } else if (direct == 4){
            // up
            if (RATarray[rowi-1][coli] != -1){
                RATarray[rowi][coli++] = current -> ratWeight;
                direct = 1;
            }
            else RATarray[rowi--][coli] = current -> ratWeight;
        }

        if (++cnt == digestInterval && current->nextRat) {
            cnt = 0;
            current = digestMiddle(current);
        }

    }

    /*
    for (; current; current = current -> nextRat) {
        if (coli == cols-1){
                RATarray[rowi++][coli] = current -> ratWeight;
                coli = 0;
            }
        else RATarray[rowi][coli++] = current -> ratWeight;
    }
    */

    return RATarray;
}

// You MUST NOT modify this!
int main()
{
    int rows, cols, numOfRats, digestInterval;
    scanf("%d %d %d", &rows, &cols, &numOfRats);

    struct Snake* head = (struct Snake*)malloc(sizeof(struct Snake));
    struct Snake* current = head;

    for(int i=0; i<numOfRats ; i++)
    {
        scanf("%d", &current->ratWeight);
        if(i < numOfRats - 1)
        {
            struct Snake* nextRat = (struct Snake*)malloc(sizeof(struct Snake));
            current->nextRat = nextRat;
            current = current->nextRat;
        }
    }
    current->nextRat = NULL;

    scanf("%d", &digestInterval);

    int** terrarium = vomitAndCrawl(rows, cols, head, digestInterval);

    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            printf("%d", terrarium[i][j]);
            if(j < cols-1)
                printf(" ");
        }
        if(i < rows-1)
            printf("\n");
    }

    for(int i=0; i<rows; i++)
    {
        free(terrarium[i]);
    }
    free(terrarium);

    return 0;
}

