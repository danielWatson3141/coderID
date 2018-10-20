#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int main(){
  int T, N, L;
  cin >> T;

  for(int i=1;i<=T;++i){
	cin >> N >> L;
	vector<string> before(N), after(N);
	for(int j=0;j<N;++j){
	  cin >> before[j];
	}
	for(int j=0;j<N;++j){
	  cin >> after[j];
	}
	sort(after.begin(),after.end());

	int res = INT_MAX;
	for(int j=0;j<(1<<L);++j){
	  vector<string> changed = before;
	  for(int t=0;t<L;++t){
		if(((j>>t) & 1) == 1){
		  for(int k=0;k<N;++k){
			changed[k][t] = (before[k][t]=='0')? '1': '0';
		  }
		}
	  }

	  sort(changed.begin(), changed.end());
	  int k;
	  for(k=0;k<N;++k){
		if(after[k] != changed[k]){
		  break;
		}
	  }
	  if(k == N){
		int cnt = 0;
		for(int k=0;k<L;++k){
		  if(((j>>k)&1)==1) ++cnt;
		}
		res = min(res, cnt);
	  }
	}

	if(res != INT_MAX){
	  cout << "Case #" << i << ": " << res<<endl;
	}else{
	  cout << "Case #" << i << ": " << "NOT POSSIBLE" << endl;
	}
  }

  return 0;
}
