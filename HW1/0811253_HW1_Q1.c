#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int leavesLength = 0;

    printf("���l���� = ");
    scanf("%d", &leavesLength);
    printf("%d\n", leavesLength);


    int i;
    int leaves[leavesLength];
    printf("���l = ");
    for(i = 0; i < leavesLength; i++) {
        scanf(" %d", &leaves[i]);
        printf("%d ", leaves[i]);

    }

    int maxstep = 0; // �̪��B��
    int j;
    int k;
    int judge = 0; // 0 ��ܤ���������0�����l�����L�A1��ܸ��o�L
    for(i = 0; i < leavesLength; i++) {
        if(leaves[i] == -1){
            for(j = 0; j < leavesLength; j++){
                if(leaves[j] == 1 && abs(j-i)-1 > maxstep && j-i<0){
                    // �ˬd�������o�L �u�C��b���C�쥪��
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
                    // �ˬd�������o�L �u�C��b���C��k��
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
    printf("\n�̪��B�� = %d", maxstep);

}




