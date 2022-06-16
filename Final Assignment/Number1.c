#include <stdio.h>

int cutting_rod(int price[11], int num, int rod[11])
{
	int rev;

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
			rev = -1e9;

			for (int i = 1; i <= num; i++)
			{
				if (rev > price[i] + cutting_rod(price, num - i, rod))
				{
					rev = rev;
				}

				else
				{
					rev = price[i] + cutting_rod(price, num - i, rod);
				}
			}
		}
	}

	rod[num] = rev;

	return rev;
}

int main()
{
	int num = 10;
	int rod[11] = { 0, };
	int price[11] = { 0,1,4,5,7,9,11,13,13,15,16 };

	for (int i = 0; i <= num; i++)
	{
		rod[i] = -1e9;
	}

	printf("maximum amount = %d", cutting_rod(price, num, rod));

	return 0;
}