//Sodoku có điền sẵn số

#include<stdio.h>

int x[9][9];
int markRow[9][10];
int markCol[9][10];
int markSquare[3][3][10];
int a[9][9];
int cnt;

void Input()
{
    for (int i=0; i<=8; i++)
    {
        for (int j=0; j<=8; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

int Check(int v, int r, int c)
{
    if (markRow[r][v] == 1) return 0;
    if (markCol[c][v] == 1) return 0;
    if (markSquare[r/3][c/3][v] == 1) return 0;
    return 1;
}

void Solution()
{
    cnt++;
    for (int i=0; i<9; i++)
    {
        for (int j=0; j<9; j++)
        {
            printf("%d ", x[i][j]);
        }
        printf("\n");
    }
    printf("----------------------\n");
}

void Try(int r, int c)
{
    for (int v= (a[r][c] > 0 ? a[r][c] : 1); v<= (a[r][c] > 0 ? a[r][c] : 9); v++)
    {
        if (Check(v,r,c))
        {
            x[r][c] = v;
            markRow[r][v] = 1;
            markCol[c][v] = 1;
            markSquare[r/3][c/3][v] = 1;
            if (r == 8 && c==8) Solution();
            else 
            {
                if (c== 8) Try(r+1,0);
                else Try(r,c+1);
            }
            markRow[r][v] = 0;
            markCol[c][v] = 0;
            markSquare[r/3][c/3][v] = 0;
        }
    }
}

int main()
{
    Input();
    for (int v=1; v<=9; v++)
    {
        for (int r=0; r<=8; r++) markRow[r][v] = 0;
        for (int c=0; c<=8; c++) markCol[c][v] = 0;
        for (int i=0;i<=2; i++)
            for (int j=0; j<=2; j++) markSquare[i][j][v] = 0;

    }
    cnt =0;
    Try(0,0);
    printf("%d", cnt);
    return 0;
}