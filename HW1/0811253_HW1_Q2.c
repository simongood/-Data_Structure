#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int row = 0;
    int col = 0;

    printf("���l row col = ");
    scanf("%d %d", &row, &col);

    int i;
    int j;
    int leaves[row][col];
    printf("���l = \n");
    for(i = 0; i < row; i++) {
        for(j = 0; j < col; j++) {
            scanf(" %d", &leaves[i][j]);
        }
    }

    printf("--------------\n");

    printf("sample input : \n");
    printf("%d %d\n", row, col);
    for(i = 0; i < row; i++) {
        for(j = 0; j < col; j++) {
            printf("%d ", leaves[i][j]);
        }
        printf("\n");
    }

    int maxstep = 0; // �̪��B��
    int k;
    int f;
    int judge = 0; // 0 ��ܤ���������0�����l�����L�A1��ܸ��o�L
    // �p���V
    for(i = 0; i < row; i++) {
        for(j = 0; j < col; j++) {
            if(leaves[i][j] == -1){
                for(k = 0; k < col; k++){
                    if(leaves[i][k] == 1 && abs(k-j)-1 > maxstep && k-j < 0){
                        // �ˬd�������o�L �u�C��b���C�쥪��
                        for(f = k+1; f < j; f++){
                            if(leaves[i][f] == 0){
                                judge = 1;
                            } else{
                                judge = 0;
                                break;
                            }
                        }
                        if (judge == 1) {
                            judge = 0;
                            maxstep = abs(k-j)-1;
                        }
                    } else if(leaves[i][k] == 1 && abs(k-j)-1 > maxstep && k-j > 0){
                        // �ˬd�������o�L �u�C��b���C��k��
                        for(f = j+1; f < k; f++){
                            if(leaves[i][f] == 0){
                                judge = 1;
                            } else{
                                judge = 0;
                                break;
                            }
                        }
                        if (judge == 1) {
                            judge = 0;
                            maxstep = abs(k-j)-1;
                        }
                    }
                }
            }
        }
    }

    // �p�⪽�V
    for(j = 0; j < col; j++) {
        for(i = 0; i < row; i++){
            if(leaves[i][j] == -1){
                for(k = 0; k < row; k++){
                    if(leaves[k][j] == 1 && abs(k-i)-1 > maxstep && k-i < 0){
                        // �ˬd�������o�L �u�C��b���C��W��
                        for(f = k+1; f < i; f++){
                            if(leaves[f][j] == 0){
                                judge = 1;
                            } else{
                                judge = 0;
                                break;
                            }
                        }
                        if (judge == 1) {
                            judge = 0;
                            maxstep = abs(k-i)-1;
                        }
                    } else if(leaves[k][j] == 1 && abs(k-i)-1 > maxstep && k-i < 0){
                        // �ˬd�������o�L �u�C��b���C��U��
                        for(f = i+1; f < k; f++){
                            if(leaves[f][j] == 0){
                                judge = 1;
                            } else{
                                judge = 0;
                                break;
                            }
                        }
                        if (judge == 1) {
                            judge = 0;
                            maxstep = abs(k-i)-1;
                        }
                    }
                }
            }
        }
    }
    printf("\n�̪��B�� = %d", maxstep);

}




