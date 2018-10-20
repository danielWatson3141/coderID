#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
#include <ctime>
#include <cmath>

using namespace std;

#define forn(I,N) for (int I=0; I<N; I++)
#define fornd(I,N) for (int I=N-1; I>=0; I--)
#define forab(I,A,B) for (int I=A; I<=B; I++)
#define forabd(I,A,B) for (int I=B; I>=A; I--)
#define FOREACH(I,A) for (__typeof__(A)::iterator I=A.begin(); I<A.end(); I++)
#define pb push_back
#define mp make_pair

typedef long long int ll;

int main()
{
	int T;
	cin >> T;
	forn (i, T)
	{
		int N;
		cin >> N;
		
		vector <vector <int> > edge(N);
		int t1, t2;
		forn (j, N-1)
		{
			cin >> t1 >> t2;
			edge[t1-1].pb(t2-1);
			edge[t2-1].pb(t1-1);
		}
		//cout <<"test" << endl;
		int ans = N-1;
		forn (j, N)
		{
			vector <int> parent (N, -1);
			vector <vector <int> > child (N);
			vector <int> childNum(N);
			vector <int> toDelete(N);
			vector <int> next;
			next.pb(j);
			int ct = 0;
			while (ct < next.size())
			{
				int current = next[ct];
				forn (k, edge[current].size()) if (edge[current][k]!=parent[current])
				{
					child[current].pb(edge[current][k]);
					parent[edge[current][k]] = current;
					//cout << edge[current][k] << " " << current << endl;
					next.pb(edge[current][k]);
				}
				ct++;
			}
			//cout << "pass" << endl;
			reverse(next.begin(), next.end());
			//forn (k, next.size())
			//	cout << next[k] << " ";
			//cout << endl;
			//cout << next.size() << endl;
			forn (k, N)
			{
				int current = next[k];
				if (parent[current]!=-1)
				{
					childNum[parent[current]] += childNum[current] + 1;
				}
			}
			
			//cout << "pass2" << endl;
			forn (k, N)
			{
				int current = next[k];
				if (child[current].size()==1)
				{
					toDelete[current] = childNum[current];
				}
				else if (child[current].size()>=2)
				{
					vector <int> temp(child[current].size());
					int count = 0;
					forn (l, temp.size())
					{
						count += childNum[child[current][l]] + 1;
						temp[l] = toDelete[child[current][l]] - childNum[child[current][l]] - 1;
					}
					sort(temp.begin(), temp.end());
					toDelete[current] = temp[0] + temp[1] + count;
				}
			}
			//cout << "pass3" << endl;
			if (ans > toDelete[j])
				ans = toDelete[j];
		}
		
		cout << "Case #" << i+1 << ": " << ans << endl;
	}
	
	return 0;
}