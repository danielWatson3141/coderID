#include <set>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;


vector<int> adj[1005];
int memo[1005];

int count(int n,int p){
	if(memo[n]!=-1) return memo[n];

	int ans = 1;
	for(int i=0;i<adj[n].size();i++){
		if(adj[n][i]!=p) ans += count(adj[n][i],n);
	}

	memo[n] = ans;
//	cout<<"memo "<<n<<": "<<ans<<endl;
	return ans;
}

int dfs(int n,int p){
	//no children
	if(adj[n].size()==0){
		return 0;
	} else if(adj[n].size()==1 && p!=-1){
		return 0;
	} else if(adj[n].size()==1){
		return count(adj[n][0],n);
	} else if(adj[n].size()==2 && p!=-1){
		if(adj[n][0]==p) return count(adj[n][1],n);
		else return count(adj[n][0],n);
	} else if(adj[n].size()==2){
		return dfs(adj[n][0],n) + dfs(adj[n][1],n);
	} else if(adj[n].size()==3 && p!=-1){
		int ans = 0;
		for(int i=0;i<adj[n].size();i++){
			if(adj[n][i]!=p) ans += dfs(adj[n][i],n);
		}
		return ans;
	} else if(adj[n].size()>=3){
		int costs[adj[n].size()];
		for(int i=0;i<adj[n].size();i++){
			costs[i] = 99999;
			if(adj[n][i]!=p)
				costs[i] = dfs(adj[n][i],n);
		}
		int best = 99999;
		
		int c = count(n,p);
		c--;
	//	cout<<n<<" "<<c<<endl;
		for(int i=0;i<adj[n].size();i++){
			for(int j=i+1;j<adj[n].size();j++){
			
				int ans = c + costs[i]+costs[j] - count(adj[n][i],n) - count(adj[n][j],n);
			//	cout<<"   "<<i<<", "<<j<<": "<<ans<<endl;
				best = min(best,ans);
			}
		}
		return best;
	}
}

int main(){
	int T;
	cin >> T;
	for(int t=0;t<T;t++){
		int N; 
		cin >> N;

		for(int i=0;i<1005;i++){
			adj[i] = vector<int>();
		}


		for(int i=0;i<N-1;i++){
			int X,Y;
			cin >> X >> Y;
			X--,Y--;
			adj[X].push_back(Y);
			adj[Y].push_back(X);
		}
		
		//fix root
		int best = 9999999;
		for(int i=0;i<N;i++){
			for(int j=0;j<1005;j++){
				memo[j] = -1;
			}
			count(i,-1);
			int ans = dfs(i,-1);
			best = min(best,ans);
		//	cout<<i<<": "<<ans<<endl;
		}
		cout<<"Case #"<<t+1<<": "<<best<<endl;
	}
}
