#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <stdlib.h>
#include <time.h>

using namespace std;

int good_freqs[1000][1000];
int bad_freqs[1000][1000];

int a[1000];
int SZ = 10000000;

int rand_int(int a, int b)
{
	return (rand() % (b - a + 1)) + a;
}

void init()
{
	for (int i = 0; i < 1000; i++)
		a[i] = i;
}

void good_shuffle()
{
	init();
	for (int i = 0; i < 1000; i++)
	{
		int p = rand_int(i, 999);
		int temp = a[i];
		a[i] = a[p];
		a[p] = temp;
	}
}

void bad_shuffle()
{
	init();
	for (int i = 0; i < 1000; i++)
	{
		int p = rand_int(0, 999);
		int temp = a[i];
		a[i] = a[p];
		a[p] = temp;
	}
}

void preprocess()
{
	// for (int i = 0; i < SZ; i++)
	// {
	// 	if (i % 1000 == 0)
	// 		cout << i << endl;
	// 	good_shuffle();
	// 	for (int j = 0; j < 1000; j++)
	// 		good_freqs[j][a[j]]++;
	// 	bad_shuffle();
	// 	for (int j = 0; j < 1000; j++)
	// 		bad_freqs[j][a[j]]++;
	// }




}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	// ofstream fout("table.txt");

	// preprocess();

	// for (int i = 0; i < 1000; i++)
	// {
	// 	for (int j = 0; j < 1000; j++)
	// 		fout << good_freqs[i][j] << " ";
	// 	fout << endl;
	// }

	// for (int i = 0; i < 1000; i++)
	// {
	// 	for (int j = 0; j < 1000; j++)
	// 		fout << bad_freqs[i][j] << " ";
	// 	fout << endl;
	// }


	// int total = 0;
	// for (int i = 0; i < 1000; i++) 
	// 	for (int j = 0; j < 1000; j++)
	// 		if (bad_freqs[i][j] == 0 || good_freqs[i][j] == 0)
	// 			total++;

	// cout << total << endl;

	ifstream fin("table.txt");

	for (int i = 0; i < 1000; i++)
		for (int j = 0; j < 1000; j++)
			fin >> good_freqs[i][j];

	for (int i = 0; i < 1000; i++)
		for (int j = 0; j < 1000; j++)
			fin >> bad_freqs[i][j];

	int T; cin >> T;
	int ans = 0;
	int nigga = 0;
	for (int t = 0; t < T; t++)
	{
		cout << "Case #" << t + 1 << ": ";

		int penis; cin >> penis;

		int b[1000];
		for (int i = 0; i < 1000; i++)
			cin >> b[i];

		double good = 0.0;
		double bad = 0.0;

		for (int i = 0; i < 1000; i++)
		{
			good += log(good_freqs[i][b[i]]);
			bad += log(bad_freqs[i][b[i]]);
		}
//
		// cout << good << " " << bad << endl;

		if (abs(good - bad) < 4)
			nigga++;

		if (good > bad)
		{
			cout << "GOOD\n";
			ans++;
		}
		else
			cout << "BAD\n";


		

	}
	// cout << ans << endl;
	// cout << nigga << endl;
}