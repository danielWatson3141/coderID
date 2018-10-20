#include <cstdio>
//using namespace std;

int N, nedges[1000], edgelist[1000][1000];

int s(int * t, int e, int p) {
	int i, s0, t0, s1, t1, s2, t2;
	if (nedges[e] == 1) {
		*t = 1;
		return 0;
	}
	*t = 0;
	t0 = t1 = 0;
	s0 = s1 = 0;
	for (i = 0; i < nedges[e]; ++i) {
		if (edgelist[e][i] != p) {
			s2 = s(&t2, edgelist[e][i], e);
			if (t2 - s2 > t1 - s1) {
				*t += t1;
				if (t2 - s2 > t0 - s0) {
					t1 = t0;
					s1 = s0;
					t0 = t2;
					s0 = s2;
				} else {
					t1 = t2;
					s1 = s2;
				}
			} else {
				*t += t2;
			}
		}
	}
	if (t1 == 0) {
		*t = t0 + 1;
		return t0;
	}
	s2 = *t + s0 + s1;
	*t += t0 + t1 + 1;
	return s2;
}

int main() {
	FILE * fin = fopen("B.in", "r"), * fout = fopen("B.out", "w");
	int T, t, i, a, b, ans;
	fscanf(fin, "%d", &T);
	for (t = 1; t <= T; ++t) {
		fscanf(fin, "%d", &N);
		for (i = 0; i < N; ++i) {
			nedges[i] = 0;
		}
		for (i = 0; i < N - 1; ++i) {
			fscanf(fin, "%d%d", &a, &b);
			--a;
			--b;
			edgelist[a][nedges[a]] = b;
			++nedges[a];
			edgelist[b][nedges[b]] = a;
			++nedges[b];
		}
		ans = N - 1;
		for (i = 0; i < N; ++i) {
			if (nedges[i] > 1) {
				a = s(&b, i, -1);
				if (a < ans) {
					ans = a;
				}
			}
		}
		fprintf(fout, "Case #%d: %d\n", t, ans);
	}
	return 0;
}
