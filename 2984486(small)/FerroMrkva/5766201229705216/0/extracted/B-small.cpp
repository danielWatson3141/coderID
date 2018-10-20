#include <algorithm>

using namespace std;

int N;
vector<int> M[1000];

int pocet(int cur,int prev){
	int vys=1;
	for(auto x:M[cur]){
		if (x!=prev) vys+=pocet(x,cur);
	}
	return vys;
}

int go(int cur,int prev){
	int deti=0;
	for(auto x:M[cur]){
		if (x!=prev) ++deti;
	}
	if (!deti) return 0;
	if (deti==1){
		for(auto x:M[cur]){
			if (x!=prev) return pocet(x,cur);
		}
	}
	vector<pair<int,int>> v;
	int total=pocet(cur,prev)-1;
	for(auto x:M[cur]){
		if (x!=prev){
			v.push_back(make_pair(pocet(x,cur),go(x,cur)));
		}
	}
	int vys=total;
	for(int i=0;i<v.size();++i){
		for (int j=0;j<i;++j){
			auto x=v[i],y=v[j];
			int p=x.second+y.second+total-x.first-y.first;
			if (p<vys) vys=p;
		}
	}
	return vys;
}

void solve_case(){
	scanf("%d",&N);
	for(int i=1;i<N;++i){
		int x,y;
		scanf("%d %d",&x,&y);
		M[x-1].push_back(y-1);
		M[y-1].push_back(x-1);
	}
	int vys=N;
	for(int root=0;root<N;++root){
		int x=go(root,-1);
		vys=min(vys,x);
	}
	printf("%d\n",vys);
	for(int i=0;i<N;++i) M[i].clear();
}

int main(){
	int cases;
	scanf("%d",&cases);
	for(int t=1;t<=cases;++t){
		printf("Case #%d: ",t);
		solve_case();
	}
	return 0;
}

