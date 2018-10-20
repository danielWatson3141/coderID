#include <cstdio>
#include <algorithm>
#include <vector>

typedef long long ll;

using namespace std;

int main() {
	int iC=0, nC;
	scanf("%d", &nC);
	for (iC=1; iC<=nC; iC++) {
		int n, l;
		scanf("%d %d", &n, &l);
		ll outlets[n], tempOutlets[n];
		ll devices[n];
		char temp[l+1];

		int i,j;
		for (i=0; i<n; i++) {
			scanf("%s", temp);
			outlets[i] = 0;
			for (j=0; temp[j] != 0; j++)
				outlets[i] = outlets[i] * 2 + (temp[j] == '1');
		}

		for (i=0; i<n; i++) {
			scanf("%s", temp);
			devices[i] = 0;
			for (j=0; temp[j] != 0; j++)
				devices[i] = devices[i] * 2 + (temp[j] == '1');
		}
		sort(devices, devices+n);

		// let us decide what the first outlet matches to and then check the rest
		int minMoves = l+1;
		for (i=0; i<n; i++) {
			ll xorOfOD = outlets[0] ^ devices[i];
			for (j=0; j<n; j++)
				tempOutlets[j] = outlets[j] ^ xorOfOD;

			sort(tempOutlets, tempOutlets+n);
			for (j=0; j<n; j++) {
				if (devices[j] != tempOutlets[j])
					break;
			}
			if (j != n)
				continue;

			int count = 0;
			while (xorOfOD) {
				count += xorOfOD & 1;
				xorOfOD >>= 1;
			}
			minMoves = min(minMoves, count);
		}

		printf("Case #%d: ", iC);
		if (minMoves == l+1)
			printf("NOT POSSIBLE\n");
		else
			printf("%d\n", minMoves);
	}
	return 0;
}