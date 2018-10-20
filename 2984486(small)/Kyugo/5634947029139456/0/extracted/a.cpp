#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long int ll;
const int INF = 1e8;
int T,N,L;

ll func(string str){
  ll ret = 0;
  for(int i = 0 ; i < str.size() ; i++){
    if(str[i] == '1')ret |= (1 << i);    
  }
  return ret;
}

int main(){
  cin >> T;
  for(int tc = 1 ; tc <= T ; tc++){
    cin >> N >> L;
    vector<int>vec[2];
    for(int i = 0 ; i < 2 ; i++){
      for(int j = 0 ; j < N ; j++){
	string tmp;
	cin >> tmp;
	vec[i].push_back(func(tmp));
      }
      sort(vec[i].begin(),vec[i].end());
    }


    int res = INF;

    for(int i = 0 ; i < N ; i++){
      for(int j = 0 ; j < N ; j++){
	ll tmp = vec[0][i] ^ vec[1][j];
	vector<int>v;
	for(int k = 0 ; k < N ; k++){
	  v.push_back(vec[0][k] ^ tmp);
	}

	sort(v.begin(),v.end());
	if(v == vec[1]){
	  res = min(res,__builtin_popcountll(tmp));
	}
      }
    }
    cout << "Case #" << tc << ": ";
    if(res != INF)cout << res << endl;
    else cout << "NOT POSSIBLE" << endl;
  }
  return 0;
}
