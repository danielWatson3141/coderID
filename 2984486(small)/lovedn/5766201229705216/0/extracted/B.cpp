//UESTC_L3

#include <stdexcept>
#include <cstdarg>
#include <iostream>
#include <fstream>
#include <exception>
#include <memory>
#include <locale>
#include <sstream>
#include <set>
#include <list>
#include <bitset>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <string>
#include <utility>
#include <cctype>
#include <climits>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <map>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <vector>
#include <queue>
#include <deque>
#include <cstdlib>
#include <stack>
#include <iterator>
#include <functional>
#include <complex>
#include <valarray>
using namespace std;

const int N=50;
struct Edge{
	int next,to;
	Edge(int to=0,int next=-1):to(to),next(next){
	}
};
Edge edge[N];
int head[N],countedge;

void AddEdge(const int& s,const int& t){
	edge[countedge]=Edge(t,head[s]);
	head[s]=countedge++;
	edge[countedge]=Edge(s,head[t]);
	head[t]=countedge++;
}

void init(){
	countedge=0;
	memset(head,-1,sizeof(head));
}

bool vis[N];
bool judge(int u){
	int son=0;
	for(int temp=head[u];temp!=-1;temp=edge[temp].next){
		if(vis[edge[temp].to])continue;
		vis[edge[temp].to]=true;
		son++;
		if(!judge(edge[temp].to))return false;
	}
	if(son==0||son==2)return true;
	return false;
}

pair<int,int> record[60];
bool flag[30];

int main(){
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B.out","w",stdout);
	int test;
	scanf("%d",&test);
	int ct=0;
	while(test--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<n;i++){
			scanf("%d%d",&record[i].first,&record[i].second);
			record[i].first--;
			record[i].second--;
		}
		
		int ret=0;
		for(int i=0;i<(1<<n);i++){
			int bit=0;
			for(int j=0;j<n;j++){
				if((1<<j)&i){
					flag[j]=1;
					bit++;
				}
				else flag[j]=0;
			}
			
			init();
			for(int j=1;j<n;j++){
				if(flag[record[j].first]&&flag[record[j].second]){
					AddEdge(record[j].first,record[j].second);
				}
			}
			
			for(int j=0;j<n;j++){
				if((1<<j)&i){
					memset(vis,0,sizeof(vis));
					vis[j]=true;
					bool f=judge(j);
					for(int k=0;k<n;k++){
						if(flag[k]&&!vis[k]){
							f=false;
							break;
						}
					}
					if(f){
						ret=max(ret,bit);
					}
				}
			}
		}
		printf("Case #%d: %d\n",++ct,n-ret);
	}
	return 0;
}