#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

#define INF 1000000000

int N,L,T;
string tmps;
long long int outlets[200],devices[200], tmp[200];

int main(){
	int i,j,k,t;
	cin >> T;
	for(t =1;t<=T;t++){
		cout<<"Case #"<<t<<": ";
		cin >> N >> L;
		for(i = 0;i < N; i++){
			cin >> tmps;
			
			outlets[i] = 0;
			for(j = 0; j < L; j++){
				if(tmps[j] == '1'){
					outlets[i] |= (1ll << j);
				}
			}
			//cout << tmps << " " << outlets[i] << endl;
		}
		for(i = 0;i < N; i++){
			cin >> tmps;
			devices[i] = 0;
			
			for(j = 0; j < L; j++){
				if(tmps[j] == '1'){
					devices[i] |= (1ll << j);
				}
			}
		}
		
		int best = INF;
		int key;
		sort(devices, devices + N);
		for(i = 0; i < N; i++){
			key = devices[0] ^ outlets[i];
			for(j = 0; j < N; j++){
				tmp[j] = outlets[j] ^ key;
			}
			sort(tmp, tmp + N);
			if(equal(devices, devices + N, tmp)){
				best = min(best, __builtin_popcount(key));
			}
		}
		
		if(best == INF){
			cout << "NOT POSSIBLE" << endl;
		}
		else{
			cout << best << endl;
		}
	}
}
		