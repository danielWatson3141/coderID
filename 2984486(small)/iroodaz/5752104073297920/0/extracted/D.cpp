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

int pG[1010][1010],pB[1010][1010];
int g[1010],b[1010];

void goodshuf()
{
	int k,p;
	for (k = 0; k < 1000; k++)
	{
		p = rand() % (1000 - k);
		p += k;
		swap(g[k], g[p]);
	}
}

void badshuf()
{
	int k, p;
	for (k = 0; k < 1000; k++)
	{
		p = rand() % 1000;
		swap(b[k], b[p]);
	}

}

int main()
{
	for (int i = 0; i < 1000;i++)
	for (int j = 0; j < 1000; j++)
		pG[i][j] = pB[1][j];
	int i, j, k;
	srand(time(NULL));
	for (int c = 0; c < 2000000; c++)
	{
		
		cerr << c << endl;
		for (int j = 0; j < 1000; j++)
			g[j] = b[j] = j;
		goodshuf(); badshuf();
		for (i = 0; i < 1000; i++)
		{
			pG[g[i]][i]++;
			pB[b[i]][i]++;
		}
	}
	ofstream myof;
	myof.open("res.txt");
	for (i = 0; i < 1000; i++)
	{
		for (j = 0; j < 1000; j++)
		{
			myof << pG[i][j] << " ";
		}
	}

	myof << endl;

	for (i = 0; i < 1000;i++)
	for (j = 0; j < 1000; j++)
		myof << pB[i][j] << " ";
	myof << endl;

	myof.close();

}
