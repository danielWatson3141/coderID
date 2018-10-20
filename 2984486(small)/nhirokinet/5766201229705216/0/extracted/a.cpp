// {{{ Boilerplate Code <--------------------------------------------------
// vim:filetype=cpp:foldmethod=marker:foldmarker={{{,}}}

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

// }}}

int after[1000][1000];
int ct;

int visited;

int judge(int cur, int prev){
	visited|=(1<<cur);
	vector <int> next;
	FOR(i,0,ct){
		if(after[cur][i]==1 && i!=prev)
			next.push_back(i);
	}

	if(next.size()==0)
		return 1;

	if(next.size()!=2)
		return 0;

	FOR(i,0,next.size()){
		if(judge(next[i],cur)==0)
			return 0;
	}
	return 1;
}


int main(){
	int T;
	cin>>T;

	FOR(iteration,0,T){
		cout<<"Case #"<<(iteration+1)<<": ";
		int N;

		cin>>N;

		int m[1000][1000];
		FOR(i,0,N)
			FOR(j,0,N)
				m[i][j]=0;

		FOR(i,0,N-1){
			int x,y;
			cin>>x>>y;

			m[x-1][y-1]=1;
			m[y-1][x-1]=1;
		}

		int ret=N;

		FOR(todel,0,1<<N){
			ct=N;

			FOR(i,0,N){
				if((todel>>i)&1)
					ct--;
			}


			int mv[ct];
			
			int curmv=0;
			FOR(i,0,N){
				if(((todel>>i)&1)==0){
					mv[curmv]=i;
					curmv++;
				}
			}

			FOR(i,0,ct){
				FOR(j,0,ct){
					after[i][j]=m[mv[i]][mv[j]];
				}
			}


			FOR(root,0,ct){
				visited=0;
				if(judge(root,-1) && visited==((1<<ct)-1))
					ret=min(ret,N-ct);
			}
		}


		cout<<ret;
		cout<<endl;
	}

}
