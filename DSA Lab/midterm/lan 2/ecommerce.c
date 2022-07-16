#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max(a,b) (a) > (b) ? (a) : (b)

int main()
{
    int ans=0;
    int a[12] = {0};
    char data[256];
    while (1)
    {
        scanf("%s",data);
        if (!strcmp(data,"#")) break;
        else{
            int year, month, day;
            sscanf(data, "%d-%d-%d",&year, &month, &day);
            a[month-1]++;
            ans = max(ans,a[month-1]);
        }
        
    }
    printf("%d", ans);
    return 0;
}
