#include <cstdio>
#include <vector>
using namespace std;

int Total, N;

int main() {
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
	scanf("%d", &Total);
	for (int i = 1; i <= Total; i++) {
		printf("Case #%d: ", i);
		scanf("%d", &N);
		int count = 0;
		for (int j = 0; j < N; j++) {
			int temp;
			scanf("%d", &temp);
			if (temp < j) { count++; }
		}
		if (count < 490)
			puts("BAD");
		else
			puts("GOOD");
	}
	return 0;
}
