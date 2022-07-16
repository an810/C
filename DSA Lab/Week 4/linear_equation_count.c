// count linear equation solution
#include <stdio.h>

#define N 50

int n, T, M;
int x[N];
int a[N];
int count = 0;

int check(int v, int k)
{
	if (k == n)
	{
		return T + v * a[k] == M;
	}
	return 1;
}

void Try(int k)
{
	for (int v = 1; v <= M - T - (n - k); v++)
	{
		if (check(v, k))
		{
			x[k] = v;
			T += (v * a[k]);
			if (k == n)
			{
				count++;
			}
			else
			{
				Try(k + 1);
			}
			T -= (v * a[k]);
		}
	}
}

int main(void)
{
	scanf("%d%d", &n, &M);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}

	Try(1);
	printf("%d\n", count);

	return 0;
}