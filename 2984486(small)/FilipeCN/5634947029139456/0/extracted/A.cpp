#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

int outlets[15], devices[15];

int read(char c[], int L){
	int p = 1, n = 0;
	for(int l = L-1; l >= 0; l--){
		if(c[l] == '1') n += p;
		p *= 2;
	}
	return n;
}

int main(){
	int T, N, L; cin >> T;
	for(int i = 1; i <= T; i++){
		cin >> N >> L;
		for(int j = 0; j < N; j++){
			char c[15]; scanf(" %s ", c);
			outlets[j] = read(c,L);
		}
		for(int j = 0; j < N; j++){
			char c[15]; scanf(" %s ", c);
			devices[j] = read(c,L);
		}
		sort(devices,devices+N);
		int M = L+1;
		for(unsigned int k = 0; k <= (0xffffffff >> (32 - L)); k++){
			unsigned int m = (max(0,(int)k-1)) ^ k;
			//cout << "m " << last << " " << k << " -> " << m << endl;
			unsigned int tmp = k;
			int count = 0;
			while(tmp){
				if(tmp & 1) count++;
				tmp /= 2;
			}
			int ind = 1;
			for(int z = 0; z <= L; z++){
				if(m & ind){
					for(int j = 0; j < N; j++){
			//			cout << "xor " << outlets[j] << " com " << ind;
						outlets[j] ^= ind;
			//			cout << " = " << outlets[j] << endl;
					}
				}
				ind = ind << 1;
			}
			sort(outlets,outlets+N);
			//cout << "outlets\n";
			//for(int z = 0; z < N; z++)
			//	cout << outlets[z] << " "; cout << endl;
			int flag = 0;
			for(int z = 0; z < N; z++){
			//	cout << outlets[z] << " " << devices[z] << endl;
				if(outlets[z] != devices[z]){
					flag = 1; break;
				}
			}
			//cout << "\n";
			if(!flag)
				M = min(M, count);	
		}
		cout << "Case #" << i << ": ";
		if(M > L) cout << "NOT POSSIBLE\n";
		else cout << M << endl;
	}
	return 0;
}