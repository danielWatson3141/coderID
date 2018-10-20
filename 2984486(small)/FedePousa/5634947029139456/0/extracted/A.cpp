#define Federico using
#define Javier namespace
#define Pousa std;
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <queue>
#include <cstring>
#include <sstream>


Federico Javier Pousa

long long int toNum(string S){
	long long int pot = 1LL;
	long long int ret = 0LL;
	for(int i=S.size()-1;i>=0;i--){
		if(S[i]=='1')ret += pot;
		pot<<=1;
	}
	return ret;
}

int main(){
	long long int T, N, L;
	string S;
	cin >> T;
	for(int caso=1;caso<=T;caso++){
		cin >> N >> L;
		vector<long long> dev, out, mask;
		for(int i=0;i<N;i++){
			cin >> S;
			out.push_back(toNum(S));
		}
		for(int i=0;i<N;i++){
			cin >> S;
			dev.push_back(toNum(S));
		}
		for(int i=0;i<N;i++){
			mask.push_back(out[0]^dev[i]);
		}
		int mini = 10000;
		int usado[300];
		for(int i=0;i<N;i++){
			memset(usado, 0, sizeof usado);
			for(int a=0;a<N;a++){
				for(int b=0;b<N;b++){
					if((out[a]^mask[i])==dev[b]){
						usado[b] = 1;
						break;
					}
				}
			}
			int cuantos = 0;
			for(int a=0;a<N;a++){
				if(usado[a])cuantos++;
			}
			if(cuantos==N){
				mini = min(mini,__builtin_popcountll(mask[i]));
			}
		}
		
		cout << "Case #" << caso << ": ";
		if(mini == 10000){
			cout << "NOT POSSIBLE" << endl;
		}else{
			cout << mini << endl;
		}
		
		
	}
	
	
	return 0;
}
