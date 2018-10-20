#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <map>
#include <vector> 
using namespace std;

const int N = 5;
double stat[N][N];

struct perm
{
	int arr[N];
	perm (void)
	{
		for (int i = 0; i < N; i++)
			arr[i] = i;
	}
	void random (void)
	{
		for (int i = 0; i < N; i++)
		{
			int p = rand() % N;
			swap(arr[i], arr[p]);
		}
	}
	bool operator < (const perm& a) const
	{
		for (int i = 0; i < N; i++) if (arr[i] != a.arr[i]) return arr[i] < a.arr[i];
		return false;
	}
};

map<perm, int> pp;

int main ()
{
	pp.clear();
	int TRY = 20000000, STD = TRY / (2 * 3 * 4 * 5);
	for (int i = 0; i < TRY; i++)
	{
		perm a;
		a.random();
		pp[a]++;
		if (i % 100000 == 0) printf("TRIED %d\n", i);
	}
	int arr[N];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) stat[i][j] = 0;
	for (int i = 0; i < N; i++) arr[i] = i;
	int mt = 0;
	for (map<perm, int>::iterator ite = pp.begin(); ite != pp.end(); ++ite)
	{
		if (ite->second > STD)
		{
			int tt = 0;
			int rr = 0;
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < i; j++) if (arr[j] > arr[i]) ++tt;
				rr += i * arr[i];
				stat[i][arr[i]] += ite->second;
				printf("%d ", arr[i]);
			}
			printf(": %d (%d %d) STD = %d\n", ite->second, tt, rr, STD);
			++mt;
		}
		next_permutation(arr, arr + N);
	}
	for (int i = 0; i < N; i++)
	{
		printf("DIGIT %d\n", i);
		for (int j = 0; j < N; j++)
		{
			printf("-- %d: %f\n", j, (double)stat[i][j] / TRY);
		}
	}
	system("pause");
	return 0;
}
