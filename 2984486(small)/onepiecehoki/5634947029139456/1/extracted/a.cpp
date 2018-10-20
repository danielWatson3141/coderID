#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>

using namespace std;

void printVector(vector<string> v){
	for (int i=0;i<v.size();++i)
		cout << v[i] << " ";
	cout << endl;
}

void printVector(vector<int> v){
	for (int i=0;i<v.size();++i)
		cout << v[i] << " ";
	cout << endl;
}

void getswit(vector<int> &swit, string &s1, string &s2){
	for (int i=0;i<s1.size();i++){
		if (s1[i] != s2[i]) swit.push_back(i);
	
	}
}

string change(vector<int> &swit, string s){
	for (int i=0;i<swit.size();++i){
		int pos = swit[i];
		if (s[pos] == '1') s[pos] = '0';
		else s[pos] = '1';
	}
	return s;
}

int checkPossible(vector<string> v1, vector<string> v2, map<string, int> m,  int N, int L){
	int minswit = 10000;
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	for (int i=0;i<1;++i){
		for (int j=0;j<N;++j){
			vector<int> swit;
			getswit(swit, v1[i], v2[j]);
			int possible = 1;
			vector<string> vtemp;
			for (int k=0;k<N;++k){
				vtemp.push_back(change(swit, v1[k]));
			}
			sort(vtemp.begin(), vtemp.end());
			for (int k=0;k<N;++k){
				if (vtemp[k] != v2[k]) possible = 0;
			}
			if (possible == 1 && swit.size() < minswit) minswit = swit.size();
		
		}
	}
	if (minswit == 10000) minswit = -1;
	return minswit;

}

int main(){
	int T;
	cin >> T;
	for (int t=1;t<=T;++t){
		//Read input
		int N, L;
		cin >> N >> L;
		vector<string> vstr, vcheck;
		map<string, int> mcheck;
		for (int i=0;i<N;++i){
			string temp;
			cin >> temp;
			vstr.push_back(temp);
		}
		for (int i=0;i<N;++i){
			string temp;
			cin >> temp;
			mcheck[temp] = 1;
			vcheck.push_back(temp);
		}
		
		
		int possible = checkPossible(vstr, vcheck, mcheck, N, L);
		cout << "Case #" << t << ": ";
		if (possible >= 0){
			cout << possible << endl;
		}
		else{
			cout << "NOT POSSIBLE" << endl;
		}
			
	}
	return 0;
}