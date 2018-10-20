#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int test(vector<int> P)
{
	int total = 0;
	for(int i = 0; i < 600; i++) total += pow(abs(i - P[i]), 1.5);
	return total < 3950000;
}

vector<int> r()
{
	int N = 1000;
	vector<int> P(N);
	for(int k = 0; k < N; k++) P[k] = k;
	for(int k = 0; k < N; k++)
	{
		int p = k + rand() % (N - k);
		swap(P[k], P[p]);
	}
	return P;
}
vector<int> t()
{
	int N = 1000;
	vector<int> P(N);
	for(int k = 0; k < N; k++) P[k] = k;
	for(int k = 0; k < N; k++)
	{
		int p = rand() % N;
		swap(P[k], P[p]);
	}
	return P;
}

int main()
{
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		cout << "Case #" << t << ": ";
		int N;
		cin >> N;
		vector<int> P(N);
		for(int i = 0; i < N; i++) cin >> P[i];
		//cout << test(P) << endl;
		cout << (test(P) ? "BAD\n" : "GOOD\n");
	}
}

int main3()
{
	srand(time(0));
	int a = 0, b = 0;
	for(int i = 0; i < 60; i++) a += test(r());// cout << test(r()) << ' ';
	cout << endl;
	for(int i = 0; i < 60; i++) b += test(t());// cout << test(t()) << ' ';
	cout << a << ' ' << b;
	cout << endl;
}

int main2()
{
	srand(time(0));
	for(int i = 0; i < 20; i++) cout << test(r()) << ' ';
	cout << endl;
	for(int i = 0; i < 20; i++) cout << test(t()) << ' ';
	cout << endl;
}
