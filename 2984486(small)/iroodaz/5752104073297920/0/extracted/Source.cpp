//This code is used to generate 2000000 permutations of both types
//It's output is used in the main code

#include <iostream>
#include <set>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <string>
#include <algorithm>
#include <fstream>
#include <ctime>

using namespace std;

int pG[1010][1010], pB[1010][1010];
int g[1010], b[1010];

int main()
{
	ifstream myif;
	myif.open("res.txt");
	for (int i = 0; i < 1000; i++)
	for (int j = 0; j < 1000; j++)
		myif >> pG[i][j];

	for (int i = 0; i < 1000; i++)
	for (int j = 0; j < 1000; j++)
		myif >> pB[i][j];
	int T, N;
	cin >> T;
	string gorb;
	int gcsum = 0, bcsum = 0;
	for (int tt = 1; tt <= T; tt++)
	{
		int gc = 0, bc = 0;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> g[i];
			if (pG[g[i]][i] < pB[g[i]][i])
				bc++;
			else
				gc++;
		}
		gcsum += gc;
		bcsum += bc;

		cerr << gc << " " << bc << endl;
		if (gc >= 583)
			gorb = "GOOD";
		else
			gorb = "BAD";
		cout << "Case #" << tt << ": " << gorb << endl;
	}
	cerr << (double)gcsum / 120.0 << " " << bcsum / 120 << endl;
}