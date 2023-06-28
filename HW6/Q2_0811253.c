#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#define max 9999

typedef struct treeNode {
    int data;
    struct treeNode* left;
    struct treeNode* right;
} treeNode;

// queue
treeNode* q[max]={NULL};
int front = 0;              // top of q
int rear = 0;               // bottom of q
int itemcount = 0;          // number of item in q

bool isEmpty() {
    return itemcount == 0;
}

bool isFull() {
    return itemcount == max;
}

treeNode *pop(){
    return q[front++];
}

void push(treeNode *data){
    if(!isFull()){
        q[rear++] = data;
        itemcount++;
    }
}

void clear() {
    memset(q, 0, max);
    front = rear = itemcount = 0;
}

treeNode *CreateNode(int data){
    treeNode *temp;
    temp = (treeNode *)malloc(sizeof(treeNode));
    temp -> data = data;
    temp -> left = temp -> right = NULL;
    return temp;
}

void InsertLevelOrder(treeNode *node, int data){
    clear();
    push(node);

    while(!isEmpty()){
        treeNode *temp = pop();

        if (temp->left != NULL){
            push(temp->left);
        } else {
            temp->left = CreateNode(data);
            return;
        }

        if (temp->right != NULL){
            push(temp -> right);
        } else {
            temp->right = CreateNode(data);
            return;
        }
    }
    return;
}

treeNode *input() {
    int total, data; // total number of treeNode, treeNode data

    scanf("%d", &total);
    scanf(" %d", &data);
    treeNode *root = CreateNode(data);

    for (int i=1; i<total; i++) {
        scanf(" %d", &data);
        InsertLevelOrder(root, data);
    }
    return root;
}



void outputTarget(treeNode *root) {
    int step=0, term, min_depth=10000, max_element=-1, i=0;  // i = while counter
    int dep[max] = {[0 ... max-1] = 10000};

    void SearchPreOrder(treeNode* parent, int depth){
        // search Target as Preorder
        treeNode *ptr = parent;
        if(ptr){
            dep[ptr->data] = depth;
            if (depth < min_depth) min_depth = depth;
            if (ptr->data > max_element) max_element = ptr->data;

            depth--;
            if (ptr->left) SearchPreOrder(ptr->left, depth);
            if(ptr->right) SearchPreOrder(ptr->right, depth);
            depth ++;
        }
    }

    scanf("%d", &term);
    treeNode *parent;
    while(1) {
        // search Parent (as level order)
        clear();
        push(root);
        while(!isEmpty()){
            parent = pop();
            if (parent->left){
                push(parent->left);
                if (parent->left->data == term){
                    if (i == 0) parent = parent->left;
                    else parent->left = NULL;
                    break;
                }
            } else break;
            if (parent->right){
                push(parent->right);
                if (parent->right->data == term){
                    if(i == 0) parent = parent->right;
                    else parent->right = NULL;
                    break;
                }
            } else break;
        }

        SearchPreOrder(parent, step--);  // search Target
        i++;
        if(parent->data == root->data) break;
    }



    if (min_depth == 10000) printf("Null");
    for(int j=max_element; j>=0; j--){
        if (dep[j] == min_depth) printf("%d ", j);
    }
}


int main(){
    treeNode *root = input();
    outputTarget(root);
    return 0;
}


