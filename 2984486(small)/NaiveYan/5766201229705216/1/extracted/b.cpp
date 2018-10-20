#include <fstream>

using namespace std;

struct{
	int data, next;
} e[2000];

int tr[1001], sz[1001], f[1001], stck[1000][1001];

int fbt(int d, int a, int p) {
	int m[2], tmp, i, j, k;
	stck[d][0] = 0;
	i = tr[a];
	while(i >= 0) {
		if(e[i].data != p) {
			stck[d][0]++;
			stck[d][stck[d][0]] = e[i].data;
			fbt(d + 1, e[i].data, a);
		}
		i = e[i].next;
	}
	sz[a] = 1;
	for(i = 1; i <= stck[d][0]; i++) sz[a] += sz[stck[d][i]];
	switch(stck[d][0]) {
		case 0:
			f[a] = 0;
			break;
		case 1:
			f[a] = sz[a] - 1;
			break;
		case 2:
			f[a] = f[stck[d][1]] + f[stck[d][2]];
			break;
		default:
			m[0] = 0;
			m[1] = 0;
			for(i = 1; i <= stck[d][0]; i++) if(sz[stck[d][i]] - f[stck[d][i]] > m[1]) {
				m[1] = sz[stck[d][i]] - f[stck[d][i]];
				if(m[0] < m[1]) {
					tmp = m[0];
					m[0] = m[1];
					m[1] = tmp;
				}
			}
			f[a] = sz[a] - m[0] - m[1] - 1;
	}
	return f[a];
}

int main () {
	ifstream fin("b.in");
	ofstream fout("b.out");
	int t, n, x, y, xi, yi, ee, ty, i, j, k;
	fin >> t;
	for(x = 1; x <= t; x++) {
		fin >> n;
		for(i = 1; i <= n; i++) tr[i] = -1;
		ee = -1;
		for(i = 1; i < n; i++) {
			fin >> xi >> yi;
			ee++;
			e[ee].data = xi;
			e[ee].next = tr[yi];
			tr[yi] = ee;
			ee++;
			e[ee].data = yi;
			e[ee].next = tr[xi];
			tr[xi] = ee;
		}
		y = n;
		for(i = 1; i <= n; i++) {
			for(j = 1; j <= n; j++) {
				sz[j] = 0;
				f[j] = 0;
			}
			ty = fbt(0, i, 0);
			if(y > ty) y = ty;
		}
		fout << "Case #" << x << ": " << y << "\n";
	}
	return 0;
}
