#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <utility>
#include <algorithm>
#include <iterator>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define FOR(i,n) for(int i=0;i<(int)(n);++i)
#define REP(i,m,n) for(int i=(int)(m);i<(int)(n);i++)
#define FORR(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define FORE(i,n) for(int i=0;i<=(int)(n);++i)
#define MP(X,Y) make_pair(X,Y)
typedef pair<int,int> ipair;
typedef long long int64;
#define MF(X,val) memset(X,val,sizeof(X))
const double eps=1.0e-6;


//const int MAX_N=1000001;
const int MAX_N=151;
const int MAX_L=41;

string input[MAX_N];
string output[MAX_N];
int iOne[MAX_L];
int oOne[MAX_L];
int min_step;

bool dfs(int cur,int step,int N,int L,vector<int>& pos){
	if(cur==pos.size()){
		sort(input,input+N);		
		FOR(i,N)if(input[i]!=output[i]){
			return false;
		}
		min_step=min(min_step,step);
		return true;
	}
	bool flag=false;
	if(dfs(cur+1,step,N,L,pos))flag=true;
	FOR(i,N){
		input[i][pos[cur]]=(input[i][pos[cur]]=='1')?'0':'1';
	}
	if(dfs(cur+1,step+1,N,L,pos))flag=true;
	FOR(i,N){
		input[i][pos[cur]]=(input[i][pos[cur]]=='1')?'0':'1';
	}
	return flag;
}

bool check(int N,int L,int& step){
	step=0;
	vector<int> pos1,pos2;
	sort(output,output+N);
	FOR(i,L){
		if(iOne[i]==oOne[i]){
			pos2.push_back(i);
		}else if(iOne[i]+oOne[i]==N){
			pos1.push_back(i);
		}else{
			return false;
		}
	}
	FOR(i,pos1.size()){
		FOR(j,N){
			input[j][pos1[i]]=(input[j][pos1[i]]=='1')?'0':'1';
		}
	}
	step=pos1.size();
	min_step=numeric_limits<int>::max();

	if(dfs(0,0,N,L,pos2)){
		step+=min_step;
		return true;
	}
	return false;
}

int main(int argc,char** argv){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int TC;
	cin>>TC;
	int N,L;
	REP(tc,1,TC+1){
		cin>>N>>L;
		MF(iOne,0);
		MF(oOne,0);
		FOR(i,N){
			//scanf("%s",input[i]);
			cin>>input[i];
			FOR(j,L){
				iOne[j]+=(input[i][j]=='1');
			}
		}
		FOR(i,N){
			//scanf("%s",output[i]);
			cin>>output[i];
			FOR(j,L){
				oOne[j]+=(output[i][j]=='1');
			}
		}
		int step;
		if(check(N,L,step)){
			printf("Case #%d: %d\n",tc,step);
		}else{
			printf("Case #%d: NOT POSSIBLE\n",tc);
		}
		
	}
	cout<<endl;
	return 0;
}