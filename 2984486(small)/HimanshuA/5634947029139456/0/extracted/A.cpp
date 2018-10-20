#include<iostream>
#include<string>
using namespace std;

void flipper(char &a)
{
	if (a == '0')
		a = '1';
	else
		a = '0';
}

void main()
{
	int T, i, j, k, l, m, N, L, count, mincount;
	char device[11][11], outlet[11][11], flip[11], temp;
	cin >> T;
	for (i = 1; i <= T; i++)
	{
		mincount = -1;
		cin >> N >> L;
		for (j = 0; j < N; j++)
			cin >> outlet[j];
		for (j = 0; j < N; j++)
			cin >> device[j];
		for (j = 0; j < L; j++)
			flip[j] = '0';

		for (j = 0; j < N; j++)
		{
			for (k = 0; k < N; k++)
			{
				if (strcmp(device[j], device[k]) > 0)
				{
					for (l = 0; l < L; l++)
					{
						temp = device[j][l];
						device[j][l] = device[k][l];
						device[k][l] = temp;
					}
				}
				if (strcmp(outlet[j], outlet[k]) > 0)
				{
					for (l = 0; l < L; l++)
					{
						temp = outlet[j][l];
						outlet[j][l] = outlet[k][l];
						outlet[k][l] = temp;
					}
				}
			}
		}
		
		for (j = 0; j < N; j++)
		{
			count = 0;
			for (k = 0; k < L; k++)
			{
				if (device[j][k] != outlet[0][k])
				{
					flipper(flip[k]);
					for (l = 0; l < N; l++)
						flipper(outlet[l][k]);
					count++;
				}
			}

			for (m = 0; m < N; m++)
			{
				for (k = 0; k < N; k++)
				{
					if (strcmp(outlet[m], outlet[k]) > 0)
					{
						for (l = 0; l < L; l++)
						{
							temp = outlet[m][l];
							outlet[m][l] = outlet[k][l];
							outlet[k][l] = temp;
						}
					}
				}
			}

			for (k = 0; k < N; k++)
			if (strcmp(device[k], outlet[k]) != 0)
				break;
			if (k == N)
			if (mincount == -1 || count < mincount)
				mincount = count;
			for (k = 0; k < L; k++)
			{
				if (flip[k] == '1')
				{
					flipper(flip[k]);
					for (l = 0; l < N; l++)
						flipper(outlet[l][k]);
					count++;
				}
			}

			for (m = 0; m < N; m++)
			{
				for (k = 0; k < N; k++)
				{
					if (strcmp(outlet[m], outlet[k]) > 0)
					{
						for (l = 0; l < L; l++)
						{
							temp = outlet[m][l];
							outlet[m][l] = outlet[k][l];
							outlet[k][l] = temp;
						}
					}
				}
			}

		}
		cout << "Case #" << i << ": ";
		if (mincount == -1)
			cout << "NOT POSSIBLE\n";
		else
			cout << mincount << endl;
	}
}