#include<stdio.h>
#include<stdlib.h>
#include<string.h>



int main()
{
    FILE* p = fopen("input.txt", "r");
    char line[100];
    char class_code[11];
    char course_code[11];
    char time_location[50];
    while(1)
    {
        fscanf(p, "%s", class_code);
        fscanf(p, "%s\n", course_code);
        fscanf(p, "%[^\n]", time_location);
        printf("%s %s %s\n", class_code, course_code, time_location);
        if (feof(p)) break;

    }
    fclose(p);
    return 0;
}