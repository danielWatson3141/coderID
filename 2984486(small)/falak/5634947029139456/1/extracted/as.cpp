#include <bits/stdc++.h>

using namespace std;


int readB(int l){
	int b;
	cin >> b;
	int r = 0;
	for (int i = 0; i < l; i++){
		if (b % 10)
			r = r | (1 << i);
		b /= 10;
	}
	return r;
}
int main() {
	int t;
	int n, l, a[155], b[155];
	cin >> t;
	
	
	for (int cs = 1; cs <= t;cs++){
		map<int, int> m1, m2;
		map<int, int> *ma, *mb, *tmp;
		cin >> n >> l;
		for (int i = 0; i < n; i++)
			a[i] = readB(l);
		for (int i = 0; i < n; i++)
			b[i] = readB(l);
		ma = &m1, mb = &m2;
		for (int j = 0; j < n; j++){
			int x = a[0] ^ b[j];
			int &p = (*ma)[x];
			p=1;
		}
		for (int i = 1; i < n; i++){
			tmp = ma, ma = mb, mb = tmp;

			for (int j = 0; j < n; j++){
				int x = a[i] ^ b[j];
				int &pp = (*mb)[x];
				if (pp){
					int &p = (*ma)[x];
					p=1;
				}
			}
			mb->clear();
		}
		int minZ = 1<<30;
		for (map<int, int>::iterator it = ma->begin(); it != ma->end(); it++){
			int n = it->first;
			int z = 0;
			for (int i = 0; i < l;i++)
			if ((n&(1 << i)) != 0) z++;
			minZ = min(minZ, z);
		}
		cout << "Case #" << cs << ": ";
		if (minZ == (1 << 30)) cout << "NOT POSSIBLE"<<endl;
		else cout << minZ << endl;
	}
	return 0;
}