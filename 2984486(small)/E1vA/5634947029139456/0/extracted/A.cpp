#include <cstdio>
#include <vector>
#include <string>
#include <set>
using namespace std;

int Total = 0, N, L;
vector <string> outlet, device;

bool check(vector <int> flip) {
	vector <string> outlettemp;
	set <string> A, B;
	for (int i = 0; i < outlet.size(); i++)
		outlettemp.push_back(outlet[i]);
	for (int i = 0; i < flip.size(); i++) {
		for (int j = 0; j < N; j++) {
			if ('0' == outlettemp[j][flip[i]])
				outlettemp[j][flip[i]] = '1';
			else
				outlettemp[j][flip[i]] = '0';
		}
	}
	for (int i = 0; i < device.size(); i++) {
		A.insert(outlettemp[i]);
		B.insert(device[i]);
	}
	return A == B ? true : false;

}

int main() {
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	scanf("%d", &Total);
	for (int i = 1; i <= Total; i++) {
		outlet.clear();
		device.clear();
		printf("Case #%d: ", i);
		scanf("%d %d", &N, &L);
		char temp;
		scanf("%c", &temp);
		int min = 100;
//		printf("N = %d, L = %d\n", N, L);
		for (int j = 0; j < N; j++) {
			outlet.push_back("");
			for (int k = 0; k < L; k++) {
				scanf("%c", &temp);
				outlet[j] += temp;
		//		printf("%c\n", temp);
			}
			scanf("%c", &temp);
		}
//		for (int j = 0; j < outlet.size(); j++)
//			printf("%s", outlet[j].c_str());
		for (int j = 0; j < N; j++) {
			device.push_back("");
			for (int k = 0; k < L; k++) {
				scanf("%c", &temp);
				device[j] += temp;
				//printf("%c", temp);
			}
			scanf("%c", &temp);
		}
		for (int j = 0; j < N; j++) {
			vector <int> flip;
			int flips = 0;
			for (int k = 0; k < L; k++) {
				if (outlet[j][k] != device[0][k]) {
					flip.push_back(k);
					flips++;
				}
			}
			if (check(flip) && (min > flips))
				min = flips;
		}
		if (min < 100) {
			printf("%d\n", min);
		} else {
			puts("NOT POSSIBLE");
		}
	}

	return 0;
}
