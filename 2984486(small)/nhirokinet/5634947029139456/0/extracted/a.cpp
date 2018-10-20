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

int main(){
	int T;
	cin>>T;

	FOR(iteration,0,T){
		cout<<"Case #"<<(iteration+1)<<": ";

		int N,L;
		vector <string> dev;
		vector <string> outlet;

		cin>>N>>L;

		int ret=99999;

		FOR(i,0,N){
			string tmp;
			cin>>tmp;
			dev.push_back(tmp);
		}
		FOR(i,0,N){
			string tmp;
			cin>>tmp;
			outlet.push_back(tmp);
		}

		sort(ALL(dev));



		FOR(i,0,N){
			int s[L];
			FOR(j,0,L){
				if(dev[0][j]==outlet[i][j])
					s[j]=0;
				else
					s[j]=1;
			}

			vector <string> nout;

			FOR(j,0,N){
				string t;
				t=outlet[j];

				FOR(k,0,L){
					if(s[k]==1){
						if(t[k]=='0')
							t[k]='1';
						else
							t[k]='0';
					}
				}
				nout.push_back(t);
			}


			sort(ALL(nout));

			
			int f=0;

			FOR(j,0,N){
				if(dev[j]!=nout[j])
					f=1;
			}

			if(f)
				continue;

			int c=0;
			FOR(j,0,L)
				c+=s[j];

			ret=min(ret,c);



		}

		if(ret==99999)
			cout<<"NOT POSSIBLE";
		else
			cout<<ret;

		cout<<endl;
	}

}
