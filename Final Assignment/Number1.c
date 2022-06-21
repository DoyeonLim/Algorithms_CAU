#include <stdio.h>

int rod[11] = { 0, };
int price[11] = { 0, 1, 4, 5, 7, 9, 11, 13, 13, 15, 16 };

int cutting_rod(int price[11], int num, int rod[11]) 
{
	int rev;
	int ans;
	int nth = -1;

	if (rod[num] >= 0)
	{
		return rod[num];
	}

	if (num == 0)
	{
		rev = 0;
	}
		
	else 
	{
		rev = -1e9;

		for (int i = 1; i <= num; i++) 
		{
			ans = rev;

			if (rev > price[i] + cutting_rod(price, num - i, rod))
			{
				rev = rev;
			}

			else
			{
				rev = price[i] + cutting_rod(price, num - i, rod);
			}

			if (ans != rev) 
			{
				nth = i;
			}
		}

		if (nth != -1)
		{
			printf("Rod's length is %d(%d + %d) and value is %d.\n", num, nth, num - nth, rev);
		}
			
	}

	rod[num] = rev;

	return rev;
}

int main() 
{
	int n = 10;

	for (int i = 0; i <= n; i++)
	{
		rod[i] = -1e9;
	}

	printf("\n-> Maximum amount : %d", cutting_rod(price, n, rod));

	return 0;
}