#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long LL;
int n, L;
LL a[1000], b[1000];
LL c[1000];
LL change(){
	string s ;
	cin>>s;
	LL x = 0;
	for (int i = 0; i<L; i++){
		x = ((x<<1)|(s[i] == '1'));
	}
	return x;
}

int main(){
	int T, cas = 0;
	for (cin>>T; T--; ){
		++cas;
		cout<<"Case #"<<cas<<": ";
		cin>>n>>L;
		for (int i = 0; i<n; i++){
			a[i] = change();
		}
		for (int j = 0; j<n; j++){
			b[j] = change();
		}
		sort(b, b+n);
		int minbit = 9999;
		for (int j = 0; j<n; j++){
			LL xxr = (a[0] ^ b[j]);
			for (int k = 0; k<n; k++) c[k] = (a[k] ^ xxr);
			sort(c, c+n);
			bool fit = true;
			for (int k = 0; k<n && fit; k++) if (c[k] != b[k]) fit = false;

			if (fit){
				int bits = 0;
				LL txxr = xxr;
				while (txxr){
					bits += (txxr&1);
					txxr >>=1;
				}
				minbit = min(minbit, bits);
			}
		}
		if (minbit > L){
			cout<<"NOT POSSIBLE"<<endl;
		}else{
			cout<<minbit<<endl;
		}
	}
	return 0;
}
