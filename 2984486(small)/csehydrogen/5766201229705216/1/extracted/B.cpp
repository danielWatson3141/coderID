#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN=1111;
const int INF=987654321;

vector<vector<int>> g;
bool visited[MAXN];

int countchild(int index){
	visited[index]=1;
	int i,j,len=g[index].size(),ret=1;
	for(i=0;i<len;i++){
		j=g[index][i];
		if(!visited[j]){
			ret+=countchild(j);
		}
	}
	visited[index]=0;
	return ret;
}

int mindelete(int index){
	visited[index]=1;
	int i,j,len=g[index].size(),s=0,tmp0,tmp1;
	vector<int> tmp2;
	for(i=0;i<len;i++){
		j=g[index][i];
		if(!visited[j]){
			tmp0=countchild(j);
			tmp1=mindelete(j);
			s+=tmp0;
			tmp2.push_back(tmp0-tmp1);
		}
	}
	visited[index]=0;
	len=tmp2.size();
	if(len==0) return 0;
	if(len==1) return s;


	sort(tmp2.begin(),tmp2.end());
	return s-tmp2[len-1]-tmp2[len-2];
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t,ti,n,x,y,i,m,tmp2;
	scanf("%d",&t);
	for(ti=1;ti<=t;ti++){
		scanf("%d",&n);

		g.clear();
		g.resize(n);
		for(i=0;i<n-1;i++){
			scanf("%d%d",&x,&y);
			x--; y--;
			g[x].push_back(y);
			g[y].push_back(x);
		}

		// i is root
		m=INF;
		for(i=0;i<n;i++){
			tmp2=mindelete(i);
			if(m>tmp2) m=tmp2;
		}

		printf("Case #%d: %d\n",ti,m);
	}
	return 0;
}