#include<algorithm>
#include<vector>
#include<bitset>
#include<string>
using namespace std;

int code[222], elec[222], n, l;
char tmp[222];
bool used[222];

int main(){
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("out_small.txt", "w", stdout);

	int t;
	scanf("%d",&t);
	for(int tc=1; tc<=t; tc++){
		int n, l;
		scanf("%d%d",&n, &l);
		for(int i=0; i<n; i++){
			scanf("%s",&tmp);
			code[i] = bitset<40>(tmp).to_ulong();
		}
		for(int i=0; i<n; i++){
			scanf("%s",&tmp);
			elec[i] = bitset<40>(tmp).to_ulong();
		}

		sort(code, code+n);
		sort(elec, elec+n);

		int ans = 222;

		for(int st=0; st<n; st++){
			fill(used,used+n, false);
			int offset = code[0]^elec[st];
			used[st] = true;
			for(int i=1; i<n; i++){
				int now = offset^code[i];
				if( binary_search(elec, elec+n, now) ){
					int diff = lower_bound(elec, elec+n, now) - elec;
					if(!used[diff]){
						used[diff] = true;
					}
					else break;
				}
				else break;
			}

			bool found = true;
			for(int i=0; i<n; i++)
				if(!used[i]) found = false;

			if(found){
				ans = min((int)bitset<40>(offset).count(), ans);
			}
		}

		printf("Case #%d: ", tc);
		if(ans > 100){
			printf("NOT POSSIBLE\n");
		}
		else{
			printf("%d\n", ans);
		}
	}
}