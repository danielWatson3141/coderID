#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cfloat>
#include <iomanip>
#include <climits>
#include <algorithm>

using namespace std;


int getans(vector<unsigned long long> &s, vector<unsigned long long> &e, int L){
	vector<int> ans;
	int N = s.size();
	vector<unsigned long long> a(N);
	do{
		bool flag = true;
		int count=0;
		for(int k=0; k<N; k++){
			a[k] = s[k] ^ e[k];
		}
		for(int k=0; k<N-1; k++){
			if(a[k] != a[k+1]) flag = false;
		}
		if(flag){
			for(int k=0; k<L; k++){
				if((a[k] >> k) & 1) count++;
			}
		}
		if(flag){
			ans.push_back(count);
			ans.push_back(L-count);
		}
	}while( next_permutation(e.begin(), e.end()));
	if(ans.size() > 0) {
		sort(ans.begin(), ans.end());
		return ans[0];
	}else return -1;
}


int main(int argc, char *argv[]){
	int T;
	
	ifstream ifs(argv[1]);
	ofstream ofs("output.txt");

	ifs >> T;
	
	for(int i=0; i<T; i++){
		int N, L;
		ifs >> N >> L;
		vector<unsigned long long> s(N);
		for(int j=0; j<N; j++){
			ifs >> s[j];
		}
		sort(s.begin(), s.end());
		
		vector<unsigned long long> e(N);
		for(int j=0; j<N; j++){
			ifs >> e[j];
		}
		sort(e.begin(), e.end());

		int ans = getans(s,e,L);
		
		cout << "Case #" << i+1 << ": " ;
		ofs << "Case #" << i+1 << ": " ;
		if(ans<0){
			cout << "NOT POSSIBLE" << endl;
			ofs << "NOT POSSIBLE" << endl;
		}else{
			cout << ans << endl;
			ofs << ans << endl;
		}
		
	}
	return 0;
}