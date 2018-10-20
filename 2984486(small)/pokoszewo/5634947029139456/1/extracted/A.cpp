#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 155;
const int MAXL = 45;

int n, l;
string a[MAXN], b[MAXN], c[MAXN];
char s[MAXL];
vector<int> positions;

void Reverse() {
	for (int i = 0; i < positions.size(); i++) {
		int x = positions[i];
		for (int j = 0; j < n; j++)
			a[j][x] = (a[j][x] == '0' ? '1' : '0');
	}
}

bool Check() {
	for (int i = 0; i < n; i++)
		c[i] = a[i];
	sort(c, c+n);
	for (int i = 0; i < n; i++)
		if (c[i] != b[i])
			return false;
	return true;
}

void Solve() {
	int result = 0;

	scanf("%d%d", &n, &l);
	result = l+1;
	for (int i = 0; i < n; i++) {
		scanf("%s", s);
		a[i] = s;
	}
	for (int i = 0; i < n; i++) {
		scanf("%s", s);
		b[i] = s;
	}

	sort(b, b+n);

	for (int i = 0; i < n; i++) {
		positions.clear();
		for (int j = 0; j < l; j++)
			if (a[0][j] != b[i][j])
				positions.push_back(j);

		Reverse();

		if (Check())
			result = min(result, (int)positions.size());

		Reverse();
	}

	if (result >= l+1)
		printf("NOT POSSIBLE\n");
	else
		printf("%d\n", result);
}

int main() {
	int q, caseId = 0;
	scanf("%d", &q);
	while (q--) {
		caseId++;
		printf("Case #%d: ", caseId);
		Solve();
	}
	return 0;
}
