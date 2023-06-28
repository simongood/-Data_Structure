#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int leavesLength = 0;

    printf("葉子長度 = ");
    scanf("%d", &leavesLength);
    printf("%d\n", leavesLength);


    int i;
    int leaves[leavesLength];
    printf("葉子 = ");
    for(i = 0; i < leavesLength; i++) {
        scanf(" %d", &leaves[i]);
        printf("%d ", leaves[i]);

    }

    int maxstep = 0; // 最長步數
    int j;
    int k;
    int judge = 0; // 0 表示中間有不為0的葉子跳不過，1表示跳得過
    for(i = 0; i < leavesLength; i++) {
        if(leaves[i] == -1){
            for(j = 0; j < leavesLength; j++){
                if(leaves[j] == 1 && abs(j-i)-1 > maxstep && j-i<0){
                    // 檢查跳不跳得過 工青蛙在母青蛙左邊
                    for(k = j+1; k < i; k++){
                        if(leaves[k] == 0){
                            judge = 1;
                        } else{
                            judge = 0;
                            break;
                        }
                    }
                    if (judge == 1) {
                        judge = 0;
                        maxstep = abs(j-i)-1;
                    }
                } else if(leaves[j] == 1 && abs(j-i)-1 > maxstep && j-i>0){
                    // 檢查跳不跳得過 工青蛙在母青蛙右邊
                    for(k = i+1; k < j; k++){
                        if(leaves[k] == 0){
                            judge = 1;
                        } else{
                            judge = 0;
                            break;
                        }
                    }
                    if (judge == 1) {
                        judge = 0;
                        maxstep = abs(j-i)-1;
                    }
                }
            }
        }
    }
    printf("\n最長步數 = %d", maxstep);

}




