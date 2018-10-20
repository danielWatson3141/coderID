#include <stdio.h>
#include <algorithm>

const int N = 155;
const int LEN = 45;

int main()
{
	int T, C;
	int n, l, tmp, ans;
	char out[N][LEN], dev[N][LEN];
	long long iout[N], idev[N];
	int ocnt[LEN], dcnt[LEN];
	int i, j, k;
	bool flag, dif;
	
	scanf("%d", &T);
	for (C = 1; C <= T; C++)
	{
		scanf("%d %d", &n, &l);
		for (i = 0; i < l; i++) ocnt[i] = dcnt[i] = 0;
		for (i = 0; i < n; i++)
		{
			scanf("%s", out[i]);

			for (j = 0; j < l; j++)
				if (out[i][j] - '0')
					ocnt[j]++;
		}
		for (i = 0; i < n; i++)
		{
			scanf("%s", dev[i]);

			for (j = 0; j < l; j++)
				if (dev[i][j] - '0')
					dcnt[j]++;
		}

		flag = true;
		ans = 0;
		for (j = 0; j < l; j++)
		{
			if (dcnt[j] != ocnt[j] && dcnt[j] == n - ocnt[j])
			{
				for (i = 0; i < n; i++)
					out[i][j] = (out[i][j] == '0' ? '1' : '0');
				ans++;
			}
			else if (dcnt[j] != ocnt[j])
			{
				flag = false;
				break;
			}
		}

		if (flag)
		{
			for (i = 0; i < n; i++)
			{
				iout[i] = idev[i] = 0;

				for (j = 0; j < l; j++)
				{
					iout[i] = iout[i] * 2 + out[i][j] - '0';
					idev[i] = idev[i] * 2 + dev[i][j] - '0';
				}
			}


			std::sort(iout, iout + n);
			std::sort(idev, idev + n);


			for (j = 0; j < l; j++)
			{
				dif = false;	
				for (i = 0; i < n; i++)
				{
					if ((iout[i] & (1ll<<j)) != (idev[i] & (1ll<<j)))
						dif = true;
				}
				if (dif)
				{
					if (ocnt[j] == n - dcnt[j])
						ans++;
					else
					{
						flag = false;
						break;
					}
				}
			}
		}
		
		printf("Case #%d: ", C);
		if (flag) printf("%d\n", ans);
		else puts("NOT POSSIBLE");
	}
	return 0;
}
