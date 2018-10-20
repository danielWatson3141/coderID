#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

LL readB(LL l){
	char b[50];
	cin >> b;
	LL r = 0;
	for (int i = 0; i < l; i++){
		if (b[i]=='1')
			r = r | ((LL)1 << (l-i-1));
		
	}
	return r;
}
int main() {
	LL t;
	LL n, l, a[155], b[155];
	cin >> t;
	
	
	for (LL cs = 1; cs <= t;cs++){
		map<LL, LL> m1, m2;
		map<LL, LL> *ma, *mb, *tmp;
		cin >> n >> l;
		for (LL i = 0; i < n; i++)
			a[i] = readB(l);
		for (LL i = 0; i < n; i++)
			b[i] = readB(l);
		ma = &m1, mb = &m2;
		for (LL j = 0; j < n; j++){
			LL x = a[0] ^ b[j];
			LL &p = (*ma)[x];
			p=1;
		}
		for (LL i = 1; i < n; i++){
			tmp = ma, ma = mb, mb = tmp;

			for (LL j = 0; j < n; j++){
				LL x = a[i] ^ b[j];
				LL &pp = (*mb)[x];
				if (pp){
					LL &p = (*ma)[x];
					p=1;
				}
			}
			mb->clear();
		}
		LL minZ = 1<<30;
		for (map<LL, LL>::iterator it = ma->begin(); it != ma->end(); it++){
			LL n = it->first;
			LL z = 0;
			for (LL i = 0; i < l;i++)
			if ((n&(1 << i)) != 0) z++;
			minZ = min(minZ, z);
		}
		cout << "Case #" << cs << ": ";
		if (minZ == (1 << 30)) cout << "NOT POSSIBLE"<<endl;
		else cout << minZ << endl;
	}
	return 0;
}