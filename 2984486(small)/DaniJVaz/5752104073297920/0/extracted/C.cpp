#include <cstdio>
#include <algorithm>
#include <vector>

typedef long long ll;

using namespace std;

int main() {
	int iC=0, nC;
	scanf("%d", &nC);
	for (iC=1; iC<=nC; iC++) {
		int n=0; 
		scanf("%d", &n);

		int array[n];
		int indexes[n];
		for (int i=0; i<n; i++) {
			scanf("%d", array+i);
			indexes[array[i]] = i;
		}

		int count = 0;
		for (int i=0; i<n; i++) {
			if (array[i] != i) {
				int j = indexes[i];
				swap(indexes[array[i]], indexes[i]);
				swap(array[i], array[j]);
				++count;
			}
		}
		printf("Case #%d: %s\n", iC, (count >= 993)?"GOOD":"BAD");
	}
	return 0;
}