#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;

int prob[1000][1000];
int samples = 100000;

int main()
{
	srand(time(NULL));
	int N=1000;
	for(int i=0; i<samples; i++)
	{
		vector<int> a;
		for(int k=0; k<N; k++)
			a.push_back(k);
		for(int k=0; k<N; k++)
		{
			int p = rand()%N;
			int tmp = a[k];
			a[k] = a[p];
			a[p] = tmp;
		}
		for(int k=0; k<N; k++)
			prob[a[k]][k]++;
	}
	int T;
	cin >> T;
	for(int t=1; t<=T; t++)
	{
		cin >> N;
		double p2=1.0;
		for(int i=0; i<N; i++)
		{
			int permu;
			cin >> permu;
			p2 *= prob[permu][i]*N;
			//cout << prob[permu][i] << endl;
			p2 /= samples;
		}
		printf("Case #%d: ", t);
		if(p2 < 1.0)
			cout << "GOOD" << endl;
		else
			cout << "BAD" << endl;
	}
}
