#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#define max 9999

typedef struct treeNode
{
    int data;
    struct treeNode *left;
    struct treeNode *right;
} treeNode;

//queue
treeNode* q[max]={NULL};
int front=0;
int rear=0;
int itemcount=0;

treeNode* pop(){
	front++;
	return q[front-1];
}

bool isEmpty(){
	return itemcount == 0;
}

bool isFull(){
	return itemcount == max;
}

void push(treeNode* data){
	if(!isFull()){
		q[rear] = data;
		rear++;
		itemcount++;
	}
}

void clear(){
	memset(q, 0, max);
	front=0;
    rear=0;
    itemcount=0;
}

//node
treeNode* CreateNode(int data){
    treeNode* temp;
    temp = (treeNode *)malloc(sizeof(treeNode));
    temp -> data = data;
    temp -> left = temp -> right = NULL;
    return temp;
}

treeNode* InsertLevelOrder(treeNode *node, int data){
	if (node == NULL) {
    	node = CreateNode(data);
    	return node;
    }
    clear();
    push(node);

    while (!isEmpty()) {
        treeNode* temp = pop();

        if (temp->left != NULL)
            push(temp->left);
        else {
            temp->left = CreateNode(data);
            return temp->left;
        }

        if (temp->right != NULL)
            push(temp->right);
        else {
            temp->right = CreateNode(data);
            return temp->right;
        }
    }
	return NULL;
}

//hint: you can use InsertLevelOrder()
//you can modify this function
treeNode* input(){
	treeNode* root = CreateNode(0);
	treeNode* red = InsertLevelOrder(root, 1);
	treeNode* black = InsertLevelOrder(root, 1);
	//TODO
	// scan data
	int i,j;                // counter
	int n, data, total;      // round, data, total number
	scanf("%d", &n);
    total = pow(2, n+2);

	for (i=4; i<total; i++) {
        int start_Lnumber = pow(2, (int)log2(i));
        int next_Lnumber = pow(2, (int)log2(i)+1);
        int half_levelTotal = ( next_Lnumber - start_Lnumber )/2;

        if ((int)log2(i)%2 != 0) {
            // black -> red
            for(j=0; j< next_Lnumber - start_Lnumber; j++, i++) {
                scanf(" %d", &data);
                if (j < half_levelTotal) {
                    treeNode* new_node = InsertLevelOrder(black, data);
                } else {
                    treeNode* new_node = InsertLevelOrder(red, data);
                }
            }
        } else {
            // red -> black
            for(j=0; j< next_Lnumber - start_Lnumber; j++, i++) {
                scanf(" %d", &data);
                if (j < half_levelTotal) {
                    treeNode* new_node = InsertLevelOrder(red, data);
                } else {
                    treeNode* new_node = InsertLevelOrder(black, data);
                }
            }
        }
	}
	return root;

}


bool CanGoHome(treeNode *root){
	//TODO

	// save red
	clear();
	int red[max], i=0;
    push(root->left);

    while (!isEmpty()) {
        treeNode* temp = pop();

        if (temp->right == NULL)
            break;
        red[i++] = temp->right->data;
        red[i++] = temp->left->data;
        push(temp->right);
        push(temp->left);
    }

    // compare black
    clear();
    push(root->right);
    i = 0;

    while (!isEmpty()) {
        treeNode* temp = pop();
        if (temp->left == NULL)
            return false;
        else if (temp->left->data != red[i++] || temp->right->data != red[i++])
            return true;
        push(temp->left);
        push(temp->right);
    }
}

//DO NOT modify main function
int main(){
	treeNode *root = input();
	if(CanGoHome(root)) printf("true");
	else printf("false");
	return 0;
}
