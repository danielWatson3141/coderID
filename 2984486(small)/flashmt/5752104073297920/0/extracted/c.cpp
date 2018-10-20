#include <bits/stdc++.h>
using namespace std;
const int TRIAL = 20000;

int n, iteration, flag[1010];

int evaluate(vector <int> a)
{
	int res = 0;
	iteration++;
	for (int i = 0; i < n; i++) 
		if (flag[i] != iteration && a[i] != i)
		{
			int x = a[i];
			flag[i] = iteration;
			while (1)
			{
				if (flag[x] == iteration) break;
				flag[x] = iteration;
				x = a[x];
				res++;
			}
		}
	return res;
}

vector <int> reverseBad(vector <int> p)
{
	vector <int> res = p;
	for (int i = n - 1; i >= 0; i--)
	{
		int x = rand() % n;
		swap(res[i], res[x]);
	}
	return res;
}

vector <int> reverseGood(vector <int> p)
{
	vector <int> res = p;
	for (int i = n - 1; i >= 0; i--)
	{
		int x = rand() % (n - i) + i;
		swap(res[i], res[x]);
	}
	return res;
}

int main()
{
	srand(time(NULL));
	freopen("c2.in", "r", stdin); 
	freopen("c2.out", "w", stdout);
	int test;
	cin >> test;
	vector <int> p = vector <int>(1000);
	for (int noTest = 1; noTest <= test; noTest++)
	{
		cerr << noTest << endl;
		cin >> n;
		for (int i = 0; i < n; i++) cin >> p[i];
		
		long long badScore = 0, goodScore = 0;
		for (int i = 0; i < TRIAL; i++)
		{
			badScore += evaluate(reverseBad(p));
			goodScore += evaluate(reverseGood(p));
		}
		
		printf("Case #%d: ", noTest);
		cout << (goodScore < badScore ? "GOOD" : "BAD") << endl;
	}
}
