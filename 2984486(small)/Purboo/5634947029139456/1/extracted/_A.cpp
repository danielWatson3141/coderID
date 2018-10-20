#include <stdio.h>
#include <algorithm>

#define MAX_M 110

using std::sort;

struct DNA
{
	int idx;
	int unsorted;
	char seq[51];
};

int m;
DNA dna[MAX_M];

bool cmp(const DNA &A, const DNA &B)
{
	if (A.unsorted == B.unsorted) return A.idx < B.idx;

	return A.unsorted < B.unsorted;
}

int compute_unsorted(const char *s)
{
	int i, j, unsorted = 0;

	for (j = 0; s[j]; j++) {
		for (i = j + 1; s[i]; i++) {
			if (s[j] > s[i]) unsorted++;
		}
	}

	return unsorted;
}

bool read()
{
	int n, i;

	if (scanf("%d%d", &n, &m) == EOF) return false;

	for (i = 0; i < m; i++) {
		dna[i].idx = i;
		scanf("%s", dna[i].seq);
		dna[i].unsorted = compute_unsorted(dna[i].seq);
	}

	return true;
}

void solve()
{
	int i;

	sort(dna, dna + m, cmp);
	for (i = 0; i < m; i++) {
		printf("%s\n", dna[i].seq);
	}
}

int main()
{
	while (read()) {
		solve();
	}
	return 0;
}

