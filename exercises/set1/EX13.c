/**
Write a recursive function
void generate (char *name, int n);
which stores in the file name all decimal integers of n digits for which:
 the digits of weights 100 , 102 , 104 , 106 , etc., have an even value (e.g., 0, 2, 4, 6, 8)
 the digits of weights 101 , 103 , 105 , 107 , etc., have an odd value (e.g., 1, 3, 5, 7, 9)
 the sum of all even digits equals the sum of all odd digits.
For example, with n=4 digits, the following numbers satisfy specified properties: 1430 (with sum 0 + 4 = 3 + 1 = 4),
3652 (with sum 2 + 6 = 5 + 3 = 8), 5676 (with sum 6 + 6 = 7 + 5 = 12).
The solution must prune the recursion tree as soon as possible, i.e., solutions that generate all integer numbers of n
digits and display only the numbers satisfying the requested properties will be penalized in terms of the final mark.
Write the entire program using standard C libraries but implement all required personal libraries. Modularize the
program adequately, and report a brief description of the data structure and the logic adopted in plain English.
Unclear or awkward programs, complex or impossible to understand, will be penalized in terms of the final evaluation.
*/
#include <stdio.h>
#include <stdlib.h>

void recursiveGenerate(int *num, int size, int i, int evenSum, int oddSum, FILE *f);
void generate (char *name, int n);

int main() {
    generate("output.txt", 5);
    return 0;
}

//Wrapper function
void generate (char *name, int n) {
    int *num;
    FILE *f;
    if((f = fopen(name, "w")) == NULL) return;

    num = calloc(n, sizeof(int));
    if(num == NULL) return;

    recursiveGenerate(num, n, 0,  0, 0, f);
    free(num);
}

void recursiveGenerate(int *num, int size, int i, int evenSum, int oddSum, FILE *f) {
    if(i >= size) {                             //After we have generated enough digits
        if(evenSum == oddSum) {                 //If the sum of odds and even digit is the same
            for(int j = 0; j < size; j++)       //We write all the digits in the file
                fprintf(f,"%d", num[j]);
            fprintf(f,"\n");
        }
        return;                                 //And return
    }

    int isOdd = (i+1)%2;                       //1 means we are on an odd index, 0 means we are on an even one. A +1 is needed because of 0-indexing

    for(int j = 0; j < 10; j+=2) {              //Generation of the digits 0 2 4 6 8
        num[i] = j+isOdd;                       //If we are at an odd index we add 1, so we will insert 1 3 5 7 9

        if(isOdd == 1) oddSum += j+1;           //We add values to either the odd or even counter
        else evenSum += j;                      //depending on the index we are on

        recursiveGenerate(num, size, i+1, evenSum, oddSum,f); //We call the function recursively going to the next index

        if(isOdd == 1) oddSum -= (j+1);         //We decrease either counter by the same amount we incremented before
        else evenSum -= j;
    }
    return;
}
