#include <cstdio>
#include <cstdlib>

int tree[1000][1024];
int ne[1000], lev[1000], size[1000], del[1000];
int T, N;

void calc_lev(int v, int l) {
	if (lev[v] >= 0) return;
	lev[v] = l;
	for (int i = 0; i < ne[v]; ++i)
		calc_lev(tree[v][i], l + 1);
}

int calc_size(int v) {
	if (size[v] > 0) return size[v];
	size[v] = 1;
	for (int i = 0; i < ne[v]; ++i) {
		int u = tree[v][i];
		if (lev[u] > lev[v])
			size[v] += calc_size(u);
	}
	return size[v];
}

int calc_del(int v) {
	if (del[v] >= 0) return del[v];
	int deg = ne[v];
	if (lev[v] > 0) --deg;
	if (deg == 1) del[v] = size[v] - 1;
	else if (deg == 0) del[v] = 0;
	else {
		int min1 = 9999, min2 = 9999;
		for (int i = 0; i < ne[v]; ++i) {
			int u = tree[v][i];
			if (lev[u] < lev[v]) continue;
			int tmp = calc_del(u) - size[u];
			if (tmp < min1) {
				min2 = min1;
				min1 = tmp;
			}
			else if (tmp < min2) min2 = tmp;
		}
		del[v] = min1 + min2 + size[v] - 1;
	}
	return del[v];
}

int main() {
	FILE *fin = fopen("B-small-attempt0.in", "r");
	FILE *fout = fopen("out.txt", "w"); 
	fscanf(fin, "%d", &T);
	for (int t = 0; t < T; ++t) {
		fprintf(fout, "Case #%d: ", t + 1);
		fscanf(fin, "%d", &N);
		for (int i = 0; i < N; ++i)
			ne[i] = 0;
		for (int i = 1; i < N; ++i) {
			int x, y;
			fscanf(fin, "%d%d", &x, &y);
			--x;
			--y;
			tree[x][ne[x]++] = y;
			tree[y][ne[y]++] = x;
		}
		int ans = N - 1;
		for (int r = 0; r < N; ++r) {
			for (int i = 0; i < N; ++i) {
				lev[i] = -1;
				size[i] = -1;
				del[i] = -1;
			}
			calc_lev(r, 0);
			calc_size(r);
			calc_del(r);
			if (del[r] < ans) ans = del[r];
		}
		fprintf(fout, "%d\n", ans);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
