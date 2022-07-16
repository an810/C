#include<stdio.h>
#define MAX 26


int main()
{
    int i, count[MAX]={0};
    char c = '\0';
    printf("Please enter a line of text: \n");
    c = getchar();
    while (c != '\n')
    {
        if (c <= 'z' && c >= 'a')
        {
            ++ count[c - 'a']; 
        }
         c = getchar();
    }
    for (int i=0; i< MAX; i++)
    {
        if (count[i] > 0)
        {
            printf("The letter '%c' appears %d time(s)\n", 'a'+i, count[i]);
        }
    }
    return 0;
}