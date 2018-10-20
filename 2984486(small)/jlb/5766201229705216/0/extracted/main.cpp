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
const int MAX_N=1001;
const int MAX_L=41;

vector<int> edges[MAX_N];
int nums[MAX_N][MAX_N];
map<ipair,int> caches;
map<ipair,int> dCaches;

bool masks[MAX_N];

int dfs1(int root,int parent,int N){
	vector<int>& nexts=edges[root];
	int sum=0;
	FOR(i,nexts.size()){
		if(nexts[i]!=parent){
			nums[root][nexts[i]]=dfs1(nexts[i],root,N);
			nums[nexts[i]][root]=N-nums[root][nexts[i]];
			sum+=nums[root][nexts[i]];
		}
	}
	if(parent!=-1){
		nums[parent][root]=sum+1;
	}
	return sum+1;
}

int dfs2(int root,int parent,int N){
	map<ipair,int>::iterator iter=caches.find(MP(parent,root));
	if(iter!=caches.end()){
		return iter->second;
	}
	vector<int>& nexts=edges[root];
	if(parent!=-1&&nexts.size()<3){
		caches[MP(parent,root)]=nums[parent][root]-1;
		return nums[parent][root]-1;
	}
	vector<int> dNum,bNum;
	int sum=0;
	FOR(i,nexts.size()){
		if(nexts[i]!=parent){
			dNum.push_back(nums[root][nexts[i]]);
			bNum.push_back(dfs2(nexts[i],root,N));
			sum+=dNum.back();
		}
	}
	int len=dNum.size();

	int min_val=numeric_limits<int>::max(),val;
	FOR(i,len)REP(j,i+1,len){
		val=sum-dNum[i]-dNum[j]+bNum[i]+bNum[j];
		min_val=min(min_val,val);
	}
	caches[MP(parent,root)]=min_val;
	return min_val;
}

int main(int argc,char** argv){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int TC;
	cin>>TC;
	int N,a,b;
	REP(tc,1,TC+1){
		cin>>N;
		FOR(i,N+1){
			edges[i].clear();
			MF(nums[i],-1);
		}
		FOR(i,N-1){
			cin>>a>>b;
			edges[a].push_back(b);
			edges[b].push_back(a);
		}
		MF(masks,false);
		dfs1(1,-1,N);
		caches.clear();
		int min_val=numeric_limits<int>::max(),val;
		REP(i,1,N+1){
			val=dfs2(i,-1,N);
			min_val=min(min_val,val);
		}
		cout<<"Case #"<<tc<<": "<<min_val<<endl;
	}
	return 0;
}