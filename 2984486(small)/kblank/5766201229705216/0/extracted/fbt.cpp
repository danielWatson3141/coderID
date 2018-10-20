#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int t, n, answer, x, y;
const int maks = 1111;
int conn[maks];
vector<int> e[maks];
bool removed[maks];
vector<pair<int, int>> v;

int sub(int x, int par) {
  int ans = 1;	
  for (int i = 0; i < e[x].size(); ++i) {
    if (e[x][i] != par) ans+=sub(e[x][i], x);	  
  };
  return ans;
};

int go(int x, int par) {
  int ret = 0;	
  //cout << x << "(" << par << ")" << endl;

  int rem = 0;
  if (par == 0 && conn[x] > 2) rem = conn[x]-2;
  if (par == 0 && conn[x] == 1) rem = 1;
  if (par != 0 && conn[x] > 3) rem = conn[x]-3;
  if (par != 0 && conn[x] == 2) rem = 1;

//if (rem>0) cout << "need to delete " << rem << endl;
  v.clear();
  for (int i = 0; i < e[x].size(); ++i) {
    if (e[x][i] != par) {
      int s = sub(e[x][i], x);	    
//cout << "sub(" << e[x][i] << ")=" << s << endl;      
      v.push_back(pair<int,int>(e[x][i], s));
      sort(v.begin(), v.end());

      for (int k = 0; k < rem; ++k) {
//cout << "del: " << k << " ("<<v[k].first<<","<<v[k].second<<")"<<endl;
        removed[v[k].first]=true;
//cout << "deleting..." << v[k].first << endl;	
        ret += v[k].second; 
      };

      //ret +=
    }; 
  };

  for (int i = 0; i < e[x].size(); ++i) {
//cout << "syn: " << e[x][i] << " rem=" << (removed[e[x][i]]?'y':'n') << endl;	  
    if (e[x][i] != par && !removed[e[x][i]]) ret+=go(e[x][i], x);	  
  };
//cout << x << " returning=" << ret << endl;
  return ret;
}

int main(){
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    //memset(e, sizeof(e), 0);
    //memset(conn, sizeof(conn), 0);
    for (int j = 0; j <= n; ++j){
      e[j].clear();  	    
      conn[j] = 0;
      removed[j] = false;
    };

    for (int j = 0; j < n-1; ++j){
      cin >> x >> y;
      conn[x]++; conn[y]++;
      e[x].push_back(y);
      e[y].push_back(x);
    };
    answer = -1;
    int ans = 0;
    for (int r = 1; r <= n; ++r) {
      //r is root
//cout << r << " is root" << endl;     
      for (int p = 1;p<=n;++p) removed[p]=false;//memset(removed, sizeof(removed), 0);
      ans = go(r, 0);
      if (ans < answer || answer==-1) answer = ans;
    };
    cout << "Case #" << i+1 << ": " << answer << endl;
  };
};
