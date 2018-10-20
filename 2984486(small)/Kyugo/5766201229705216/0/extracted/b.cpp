#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MAX = 1010;

int T,N;
vector<int> G[MAX];
const int INF = 1e8;
typedef pair<int,int>P; // num,del

bool cmp(P p1,P p2){
  return (p1.first - p1.second) > (p2.first - p2.second);
}

P func(int now,int pre){

  /*
  if(pre == -1 && G[now].size() == 1){
    return P(N,N-1); // root
  }
  */
  vector<P>vec;
  for(int i = 0 ; i < G[now].size() ; i++){
    int next = G[now][i];
    if(next == pre)continue;
    vec.push_back(func(next,now));
  }
  sort(vec.begin(),vec.end(),cmp);

  /*
  cout << "now =  " << now+1 << " pre = " << pre+1 << endl;
  for(int i = 0 ; i < vec.size() ; i++){
    cout << "vec[i] : " << vec[i].first << ' ' << vec[i].second << endl;
  }
  */

  if(vec.size() == 0)return P(1,0);
  if(vec.size() == 1)return P(vec[0].first+1,vec[0].first);

  P ret = P(1,0);
  for(int i = 0 ; i < vec.size() ; i++)ret.first += vec[i].first;
  for(int i = 0 ; i < 2 ; i++)ret.second += vec[i].second;
  for(int i = 2 ; i < vec.size() ; i++)ret.second += vec[i].first;
  return ret;
}


int main(){
  cin >> T;
  for(int tc = 1 ; tc <= T ; tc++){
    cout << "Case #" << tc << ": ";
    cin >> N;
    for(int i = 0 ; i < N ; i++)G[i].clear();
    for(int i = 0 ; i < N-1 ; i++){
      int x,y;
      cin >> x >> y;
      x--,y--;
      G[x].push_back(y);
      G[y].push_back(x);
    }
    int res = INF;
    for(int i = 0 ; i < N ; i++){
      //cout << "i = " << i+1 << endl;
      P p = func(i,-1);
      res = min(res,p.second);
      //cout << "p.second = " << p.second << endl;
    }
    cout << res << endl;
  }
  return 0;
}
