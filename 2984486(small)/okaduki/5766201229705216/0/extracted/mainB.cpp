#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main(){
  int testCaseNum, N;
  cin >> testCaseNum;

  for(int caseN=1;caseN<=testCaseNum;++caseN){
	cin >> N;
	int res = INT_MAX;
	vector<vector<bool>> edges(N, vector<bool>(N));
	for(int i=0;i<N-1;++i){
	  int x, y;
	  cin >> x >> y;
	  edges[x-1][y-1] = edges[y-1][x-1] = true;
	}

	for(int root=0;root<N;++root){
	  for(int mask=0;mask<(1<<N);++mask){
		vector<bool> deleted(N);
		int exist = N;
		if((mask >> root) & 1) continue;

		for(int i=0;i<N;++i){
		  if((mask >> i) & 1){
			deleted[i] = true;
			--exist;
		  }
		}
		/*
		//check singleton node
		int i;
		for(i=0;i<N;++i){
		  if(!deleted[i]){
			int k=0;
			for(;k<N;++k){
			  if(!deleted[k] && edges[k][i]) break;
			}

			if(k == N){
			  i = -1;
			  break;
			}
		  }
		}
		if(i == -1) continue;
		*/
		bool success = true;
		queue<int> visit; visit.push(root);
		vector<bool> visited(N);
		visited[root] = true;
		while(!visit.empty()){
		  int node = visit.front(); visit.pop();
		  int cntChild = 0;
		  for(int k=0;k<N;++k){
			if(!deleted[k] && edges[k][node] && !visited[k]){
			  visited[k] = true;
			  visit.push(k);
			  ++cntChild;
			}
		  }
		  if(!(cntChild == 0 || cntChild == 2)){
			success = false;
			break;
		  }
		}
		if(!success) continue;

		int cnt = 0;
		for(int i=0;i<N;++i)
		  if(visited[i]) ++cnt;
		if(cnt != exist) continue;
		res = min(res, N-exist);
	  }
	}
	cout << "Case #" << caseN << ": " << res << endl;
  }

  return 0;
}
