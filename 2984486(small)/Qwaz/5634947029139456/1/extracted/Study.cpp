#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main(){
	freopen("output.txt", "w", stdout);

	int numCase;
	scanf("%d", &numCase);

	int cc;
	for(cc = 1; cc <= numCase; cc++){
		printf("Case #%d: ", cc);

		const int MAX = 200;

		int n, l, res = MAX;
		scanf("%d%d", &n, &l);

		string charge[MAX], device[MAX];

		int i;
		for(i = 0; i<n; i++)
			cin >> charge[i];
		for(i = 0; i<n; i++)
			cin >> device[i];

		int j, k, t;
		for(i = 0; i<n; i++){
			bool flip[MAX], used[MAX];
			int flipCount = 0;
			fill(used, used+n, 0);

			for(j = 0; j<l; j++){
				flip[j] = charge[0][j] != device[i][j];
				flipCount += flip[j];
			}
			used[0] = 1;

			for(j = 1; j<n; j++){
				for(k = 0; k<n; k++){
					for(t = 0; t<l; t++){
						if(charge[j][t] != (device[k][t]^flip[t]))
							break;
					}
					if(t == l){
						used[j] = 1;
						break;
					}
				}
				if(!used[j]) break;
			}

			if(j == n)
				res = min(res, flipCount);
		}

		if(res == MAX) puts("NOT POSSIBLE");
		else printf("%d\n", res);
	}

	return 0;
}