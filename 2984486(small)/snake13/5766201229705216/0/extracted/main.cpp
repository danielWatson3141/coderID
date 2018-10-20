#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <fstream>
#include <math.h>
#include <map>
#include <string>
#include <ctime>
#define LL long long int
#define double long double
using namespace std;

bool graph[101][101];
bool graph1[101][101];
int n;
int Count;
bool OK (int v, int p)
{
	int i, a=0;
	Count++;
	bool flag = 1;
	for (i=1; i<=n; i++)
	{
		if (graph1[v][i] && i!=p)
		{
			flag = flag && OK(i, v);
			a++;
		}
	}
	if (a!=2 && a) 
	{
		//cout << v << " " << p<< " " << a<<endl;
		return false;
	}
	return flag;
}
bool correct_tree()
{
	bool flag = 0;
	int i;
	for (i=1; i<=n; i++)
		flag = flag || OK(i, -1);
	return flag;
}

void solve (int T)
{
	int i,j,k,a,b;
	cin >> n;
	for (i=1; i<=n; i++)
		for (j=1; j<=n; j++)
			graph[i][j] = 0;
	for (i=0; i<n-1; i++)
	{
		cin>>a>>b;
		graph[a][b] = graph[b][a] = 1;
	}
	
	int MAX = -1, kol = 1;
	for (i=0; i<n; i++) kol*=2;
	vector <bool> help(kol+1);
	for (i=0; i<kol; i++)
	{
		for (j=1; j<=n; j++)
		for (k=1; k<=n; k++)
			graph1[j][k] = graph[j][k];
		int N = i;
		for (j=0; j<n; j++)
		{
			help[j+1] = N%2;
			N/=2;
		}
		/*cout << i << endl;
		for (k=1; k<=n; k++) cout<<help[k]<<" "; cout<<endl; cout<<endl;*/
		for (j=1; j<=n; j++)
			if (!help[j])
				for (k = 1; k<=n; k++)
					graph1[j][k] = graph1[k][j] = 0;
		/*for (j=1; j<=n; j++)
		{
			for (k=1; k<=n; k++) cout<<graph1[j][k]<<" ";
			cout<<endl;
		}
		cout<<endl;*/
		for (j=1; j<=n; j++)
		{
			Count = 0;
			if (OK(j, -1) && Count > MAX) 
			{
				MAX = Count;
				//for (k=1; k<=n; k++) cout<<help[k]<<" "; cout<<endl;
				//cout << j << " "<<Count<<endl;
			}
		}
	}
	cout <<"Case #"<<T<<": ";
	cout << n - MAX<< endl;
}

int main()
{
	freopen("B-small-attempt0.in", "r", stdin); freopen("output.txt", "w", stdout);
	int i, t;
	cin>>t;
	for (i=1; i<=t; i++)
		solve(i);
	return 0;
}