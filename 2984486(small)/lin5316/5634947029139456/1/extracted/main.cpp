//#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <string>
using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");

void qsort(string *a, int x, int y)
{
	// sort a within [x, y]
	if (x >= y) return;
	int m = x, l = x, r = y;
	string mid = a[m];
	a[m] = a[x];
	while (x < y)
	{
		while (x < y && mid <= a[y]) y--;
		if (x < y) a[x++] = a[y];
		while (x < y && mid >= a[x]) x++;
		if (x < y) a[y--] = a[x];
	}
	a[x] = mid;
	qsort(a, l, x - 1);
	qsort(a, x + 1, r);
}

int main(){
	int T, n, l, swit[100];
	string flow[160], devi[160], switched[160];
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> n >> l;
		for (int i = 0; i < n; i++)
			cin >> flow[i];
		for (int i = 0; i < n; i++)
			cin >> devi[i];
		qsort(devi, 0, n - 1);
		int min = 1000, tot;
		for (int i = 0; i < n; i++)
		{
			tot = 0;
			for (int j = 0; j < l; j++)
			{
				if (flow[0][j] != devi[i][j])
				{
					swit[j] = 1;
					tot++;
				}
				else
				{
					swit[j] = 0;
				}
			}
			for (int j = 0; j < n; j++)
			{
				switched[j] = flow[j];
				for (int k = 0; k < l; k++)
				{
					if (swit[k])
					{
						if (switched[j][k] == '1')
							switched[j][k] = '0';
						else
							switched[j][k] = '1';
					}
				}
			}
			qsort(switched, 0, n - 1);
			int sd;
			for (sd = 0; sd < n; sd++)
			{
				if (switched[sd] != devi[sd])
					break;
			}
			if (sd == n)
			{
				if (tot < min)
					min = tot;
			}
		}
		cout << "Case #" << t << ": ";
		if (min == 1000)
			cout << "NOT POSSIBLE" << endl;
		else
			cout << min << endl;
	}
	return 0;
}