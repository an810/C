#include<stdio.h>

void HanoiTower(int n, char aStart, char cEnd, char bSpare)
{
    if (n==1) {
        printf("Move disk from %c to %c\n", aStart, cEnd);
    } else {
        //Step 1: (n-1) disk from a to b
        HanoiTower(n-1,aStart,bSpare,cEnd);
        //Step 2: move largest disk from a to c 
        HanoiTower(1,aStart,cEnd,bSpare);
        //Step 3: (n-1) disk from b to c
        HanoiTower(n-1,bSpare,cEnd, aStart);
    }
}

int main()
{
    int n=5;
    HanoiTower(n,'A','B','C');
    return 0;
}