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

int T;
int N,L;
char c;
vector<bool> outlet[150];
vector<bool> outlet_mod[150];
vector<bool> device[150];
set<vector<bool> > mod_set;
int min_moves;

int main()
{
	cin >> T;
	for(int t=1; t<=T; t++)
	{
		cin >> N >> L;
		min_moves = L+1;
		for(int i=0; i<N; i++)
		{
			outlet[i].resize(L);
			outlet_mod[i].resize(L);
			device[i].resize(L);
		}
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<L; j++)
			{
				cin >> c;
				//cout << c << endl;
				if(c == '1')
					outlet[i][j] = true;
				else
					outlet[i][j] = false;
			}
		}
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<L; j++)
			{
				cin >> c;
				//cout << c << endl;;
				if(c == '1')
					device[i][j] = true;
				else
					device[i][j] = false;
			}
		}
		for(int i=0; i<N; i++)
		{
			int moves=0;
			for(int j=0; j<L; j++)
			{
				if(outlet[0][j] == device[i][j])
				{
					for(int k=0; k<N; k++)
						outlet_mod[k][j] = outlet[k][j];
				}
				else
				{
					moves++;
					for(int k=0; k<N; k++)
						outlet_mod[k][j] = !outlet[k][j];
				}
			}
			mod_set.clear();
			for(int k=0; k<N; k++)
			{
				mod_set.insert(outlet_mod[k]);
			}
			bool possible=true;
			for(int k=0; k<N; k++)
			{
				if(mod_set.find(device[k]) == mod_set.end())
					possible=false;
			}
			if(possible)
				min_moves = min(min_moves,moves);
		}
		printf("Case #%d: ", t);
		if(min_moves == L+1)
			cout << "NOT POSSIBLE" << endl;
		else
			cout << min_moves << endl;
	}
}
