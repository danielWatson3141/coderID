#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cfloat>
#include <iomanip>
#include <climits>
#include <algorithm>

using namespace std;


int search(vector< vector<int> > &g, int root, int child){
	int n=g[child].size();
	if(n==1 || (n==2 && root!=-1) ){
		return 1;
	}else{
		int ans = 1;
		for(int i=0; i<n-1; i++){
			if(g[child][i] == root) continue;
			for(int j=i+1; j<n; j++){
				if(g[child][j] == root) continue;
				ans = max(ans, search(g, child, g[child][i]) + search(g, child, g[child][j]));
			}
		}
		return ans+1;
	}
}

int main(int argc, char *argv[]){
	int T;
	
	ifstream ifs(argv[1]);
	ofstream ofs("output.txt");

	ifs >> T;
	
	for(int i=0; i<T; i++){
		int N;
		ifs >> N ;
		vector< vector<int> > g(N);
		for(int j=0; j<N-1; j++){
			int x,y;
			ifs >> x >> y;
			g[x-1].push_back(y-1);
			g[y-1].push_back(x-1);
		}
		int ans=1;
		for(int j=0; j<N; j++){
			ans = max(ans, search(g, -1, j));
		}
		
		cout << "Case #" << i+1 << ": " << N-ans << endl;
		ofs << "Case #" << i+1 << ": "  << N-ans << endl;
	}
	return 0;
}