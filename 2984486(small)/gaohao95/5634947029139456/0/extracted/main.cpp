#include <cstdio>
#include <cstdlib>
long long input[151];
long long output[151];
long long change[151];

long long twol(int l)
{
	long long result = 1;
	for(int i = 0; i < l; i++)
	{
		result *= 2;
	}
	return result;
}

int cmp(const void *a, const void *b)
{
	return *((long long *)a) - *((long long *)b);
}

int ct(long long a, int n)
{
	int result = 0;
	for(int i = 0; i < n; i++)
	{
		if((a & (1ll << i)) != 0)
			result ++;
	}
	return result;
}	

int main()
{
	int t;
	scanf("%d",&t);
	for(int tt = 1; tt <= t; tt++)
	{
		int n,l;
		scanf("%d %d",&n,&l);
		for(int i = 0; i < n; i++)
		{
			char temp[100];
			scanf("%s",temp);
			long long sum = 0;
			for(int j = 0; j < l - 1; j++)
			{
				sum = sum + (temp[j] - '0');
				sum *= 2;
			}
			sum += (temp[l - 1] - '0');
			input[i] = sum;
		}
		for(int i = 0; i < n; i++)
		{
			char temp[100];
			scanf("%s",&temp);
			long long sum = 0;
			for(int j = 0; j < l - 1; j++)
			{
				sum = sum + (temp[j] - '0');
				sum *= 2;
			}
			sum += (temp[l - 1] - '0');
			output[i] = sum;
		}

		int min = 1000;
		qsort(output, n, sizeof(long long), cmp);

		long long upper_bound = twol(l);
		for(long long i = 0; i < upper_bound; i++)
		{
			for(int j = 0; j < n; j++)
			{
				change[j] = input[j] ^ i;
			}

			qsort(change, n, sizeof(long long), cmp);
			bool isSame = true;

			for(int j = 0; j < n; j++)
			{
				if(change[j] != output[j])
				{
					isSame = false;
					break;
				}
			}

			if(isSame && ct(i, l) < min)
				min = ct(i, l);
		}
		if(min == 1000)
			printf("Case #%d: NOT POSSIBLE\n", tt);
		else
			printf("Case #%d: %d\n", tt, min);
	}
	return 0;
}