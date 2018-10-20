#include<iostream>
using namespace std;
void main()
{
	int T, N, a[1000], j, i, count;
	cin >> T;
	for (i = 1; i <= T; i++)
	{
		cin >> N;
		count = 0;
		for (j = 0; j < N; j++)
		{
			cin >> a[j];
			if (j == a[j])
				count++;
			if (j != 0 && a[j]>a[j - 1])
				count++;
		}
		if (count > N / 2)
			cout << "Case #" << i << ": " << "BAD\n";
		else
			cout << "Case #" << i << ": " << "GOOD\n";
	}
}