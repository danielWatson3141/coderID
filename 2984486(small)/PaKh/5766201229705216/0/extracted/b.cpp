#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 1500;
int T;
vector<int> d[maxn];
bool done[maxn];
int n;

int dfs(int v){
	done[v] = 1;	
	
  int deg = 0;
  for(int i=0;i<d[v].size();i++)
	if(!done[d[v][i]])
		deg++;
	//cout << "DFS " << v+1 << " deg: " << deg <<"," << d[v].size() << endl; 
  if(deg<2){
	 //cout << v+1 << " --> " << 1 << endl;
    return 1;
	}
  vector<int> dd;
  for(int i=0;i<d[v].size();i++)
    if(!done[d[v][i]])
      dd.push_back(dfs(d[v][i]));
  sort(dd.begin(),dd.end());
  int x = dd.size();
  //cout << v+1 << " -> " << dd[x-1]+dd[x-2]+1 << endl;
  return dd[x-1]+dd[x-2]+1;

}
void clear(){
  for(int i=0;i<maxn;i++)
    done[i]=false;
}
int main(){
  cin >> T;
  for(int t=0;t<T;t++){
 	 for(int i=0;i<maxn;i++)
		d[i].clear();
    cin >> n;
	 //cout << "_--------------------------" << n << endl;
    for(int i=0;i<n-1;i++){
      int a,b;
      cin >> a >> b;
      a--;b--;
      d[a].push_back(b);
      d[b].push_back(a);
    }
    int ans = n-1;
    for(int i=0;i<n;i++){
      clear();
      int cur = dfs(i);
		
		//cout << "**" << i+1 << " " << n << "-" <<  cur << endl;
	
		cur = n-cur;
      if(cur < ans)
			ans = cur;
    }

    cout << "Case #" << t+1 << ": " << ans << endl;
  }
  return 0;
}
