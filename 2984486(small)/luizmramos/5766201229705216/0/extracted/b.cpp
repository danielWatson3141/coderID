#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> M[2000];
int pai[2000];
int conts[2000];
int n;

int contar(int v){
	//printf("contando %d\n", v);
	if(conts[v]!=-1)return conts[v];
	int contador=0;
	for(int i=0;i<M[v].size();i++){
		if(M[v][i]!=pai[v]){
			pai[M[v][i]]=v;
			contador+=contar(M[v][i]);
		}
	}
	//printf("contador=%d\n", contador);
	return (conts[v]=contador+1);
}

int tentar(int v){
	//printf("%d\n", v);
	if(M[v].size()==0)return 0;
	for(int i=0;i<M[v].size();i++){
		if(M[v][i]!=pai[v])pai[M[v][i]]=v;
	}
	if(pai[v]==-1){
		if(M[v].size()==2){
			return tentar(M[v][0])+tentar(M[v][1]);
		}
		if(M[v].size()==1){
			return contar(M[v][0]);
		}
	}
	else{
		if(M[v].size()==1)return 0;
		if(M[v].size()==2){
			for(int i=0;i<2;i++){
				if(M[v][i]!=pai[v])return contar(M[v][i]);
			}
		}
		if(M[v].size()==3){
			int ans=0;
			for(int i=0;i<3;i++){
				if(M[v][i]!=pai[v])ans+=tentar(M[v][i]);		
			}
			//printf("retornando ans %d\n",ans);
			return ans;
		}
	}
	vector<int> tentativas;
	vector<int> contadas;
	vector<pair<int,int> > diff;
	int soma=0;
	for(int i=0;i<M[v].size();i++){
		if(M[v][i]==pai[v])continue;
		tentativas.push_back(tentar(M[v][i]));
		contadas.push_back(contar(M[v][i]));
		soma+=contadas.back();
		diff.push_back({tentativas.back()-contadas.back(),i});
	}
	sort(diff.begin(),diff.end());
	soma+=diff[0].first+diff[1].first;
	return soma;
}


int main(){
	int t;
	scanf("%d",&t);
	for(int xxx=0;xxx<t;xxx++){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			M[i].clear();
		}
		for(int i=0;i<n-1;i++){
			int x,y;
			scanf("%d %d",&x,&y);
			x--;
			y--;
			M[x].push_back(y);
			M[y].push_back(x);
		}
		int minimo=100000;

		for(int i =0;i<n;i++){
			for(int j=0;j<n;j++){
				pai[j]=-1;
				conts[j]=-1;
			}
			//printf("opa\n");
			int tentativa=tentar(i);
			//printf("--->%d %d\n", tentativa,i+1);
			if(minimo>tentativa){
				minimo=tentativa;
			}
		}
		printf("Case #%d: %d\n",xxx+1,minimo);
	}
}