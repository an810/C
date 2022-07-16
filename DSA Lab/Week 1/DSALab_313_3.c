#include<stdio.h>
#include<string.h>
#define Max 100 

int main()
{
    char s1[Max];
    printf("Enter the string:\n");
    gets(s1);
    char c1, c2;
    printf("Enter the char 1:\n");
    scanf(" %c", &c1);
    printf("Enter the char 2:\n");
    scanf(" %c", &c2);
    for (int  i = 0; i < strlen(s1); i++)
    {
        if (s1[i] == c1) 
        {
            s1[i] = c2;
        }
    }
    printf("%s",s1);
    return 0;

    
    //gets doc den khi gap enter >< scanf doc den khi gap dau cach hoac dau enter

}