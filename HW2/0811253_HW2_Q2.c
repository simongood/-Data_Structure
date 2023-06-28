#include <stdio.h>
#include <stdlib.h>


#define MAX_TERMS 100
/*size of terms array*/
typedef struct{
    float coef;
    int expon;
}polynomial;
// set global variable
polynomial terms [MAX_TERMS]={0};
int avail = 0;


int COMPARE(int A, int B){
// compare function
    if (A < B) return -1;
    else if(A == B) return 0;
    else if(A > B) return 1;
}

void attach(float coefficient, int exponent){
// add a new term to the polynomial D(x)
    if (avail >= MAX_TERMS) {
        fprintf(stderr, "Too much  terms in the polynomial\n");
        exit(1);
    }
    terms[avail].coef = coefficient;
    terms[avail++].expon = exponent;
}


void padd(int starta, int finisha, int startb, int finishb, int *startd, int *finishd, int lenA, int lenB){
// Polynomial function add
// add A(x) and B(x) to obtain D(x)
    float coefficient;
    *startd = avail;
    while(starta <= finisha && startb <= finishb){
        switch(COMPARE(terms[starta].expon, terms[startb].expon)) {
            case -1: // A < B
                attach(terms[startb].coef, terms[startb].expon);
                startb++;
                break;
            case 0: // A = B
                coefficient = terms[starta].coef + terms[startb].coef;
                if (coefficient) attach(coefficient, terms[starta].expon);
                starta++;
                startb++;
                break;
            case 1: // A > B
                attach(terms[starta].coef, terms[starta].expon);
                starta++;
        }
    }
    //add in remaining terms of A(x) and B(x)
    for(; starta <= finisha; starta++)
        attach(terms[starta].coef, terms[starta].expon);
    for(; startb <= finishb; startb++)
        attach(terms[startb].coef, terms[startb].expon);
    *finishd = avail - 1;
}

void pmult(int starta, int finisha, int startb, int finishb) {
    float coefficient;
    int expon;
    for(starta=0; starta <= finisha; starta++){
        for(int k=startb; k <= finishb; k++){
            coefficient = terms[starta].coef * terms[k].coef;
            expon = terms[starta].expon + terms[k].expon;
            attach(coefficient, expon);
        }
    }
}


int main(void){

    // input
    int lenA, lenB;
    scanf("%d %d", &lenA, &lenB);
    int i;
    for(i=0; i<lenA+lenB; i++) {
        scanf("%f %d", &terms[i].coef, &terms[i].expon);
    }

    // calculate
    avail = lenA + lenB;
        // multiple
    pmult(0, lenA-1, lenA, lenA+lenB-1);
        // add
    int startd=0, finishd=-1;
    padd(
        lenA+lenB, lenA+2*lenB-1
        , startd, finishd
        , &startd, &finishd
        , lenA, lenB
        );
    for(i=1; i<lenA; i++){
        padd(
            lenA+lenB+lenB*i, lenA+2*lenB-1+lenB*i
            , startd, finishd
            , &startd, &finishd
            , lenA, lenB
            );
    }


    // output
    for(int j=0; j < 30; j++) {
        printf("%f %d\n", terms[j].coef, terms[j].expon);
    }
    printf("-----------------\n-----------------\n\n-------Answer--------\n");
    for(;startd <= finishd; startd++) {
        printf("%f %d\n", terms[startd].coef, terms[startd].expon);
    }

    return 0;
}
