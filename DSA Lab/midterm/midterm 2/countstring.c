#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//the number of 1-strings, 0-strings
int main()
{
    char s[999999];
    scanf("%s", s);
    int n = strlen(s);
    int count1 = 0;
    int count0 = 0;
    int index = 0;
    while (index < n)
    {
        if (s[index] == '1')
        {
            while (s[index] == '1')
            {
                index++;
            }
            count1++;
        }
        else
        {
            while (s[index] == '0')
            {
                index++;
            }
            count0++;
        }
    }
    printf("%d %d", count0, count1);
    return 0;
}