#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void sort(int *a, int n)
{
	for (;;) {
		if (n < 2) return;
		int i = 0;
		int j = n - 1;
		int p;
		if (n > 2) //chose median
		{
			int max, min, id = rand() % n;
			int c[3];
			c[0] = a[id];
			srand(time(NULL));
			for (int i = 1; i < 3; i++)
			{
				id = rand() % n;
				c[i] = a[id];
			}

			if ((c[0] >= c[1] && c[0] <= c[2]) || (c[0] <= c[1] && c[0] >= c[2]))
				p = c[0];
			else if ((c[1] >= c[0] && c[1] <= c[2]) || (c[1] <= c[0] && c[1] >= c[2]))
				p = c[1];
			else
				p = c[2];

		}
		else
			p = a[0];
		//int p = a[(i + j) / 2];//  a[0];
		while (i <= j)
		{
			while (a[i] < p)
				i++;
			while (a[j] > p)
				j--;
			if (i <= j)
			{
				int temp;
				temp = a[i];
				a[i++] = a[j];
				a[j--] = temp;
			}
		}
		if (j + 1 < n - i)
		{
			sort(a, j + 1);
			a = a + i;
			n = n - i;
		}
		else
		{
			sort(a + i, n - i);
			n = j + 1;
		}
	}
}

void main()
{
	int n = 7;
	int b[7] = { 1,10,7,6,10,11,12};

	sort(b, n);

	for (int i = 0; i < n; i++)
	printf("%i\n", b[i]);

	for (int i = 0; i < n - 1; i++)
		if (b[i + 1] < b[i])
		{
			printf("error"); break;
		}
}
