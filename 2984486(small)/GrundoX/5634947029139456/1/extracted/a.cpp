#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;


void conv(char * str, ll & a){
	ll ret = 0;
	for(int i = strlen(str)-1; i >= 0; i--){
		ret *= 2;
		ret += str[i]-'0';
	}
	a = ret;
}

int main(){
	int tc;
	scanf("%d",&tc);
	for(int x = 1; x <= tc; x++){
		printf("Case #%d: ", x);
		bool pos = 0;
		int n, l, ans = 1000000; 
		ll out[155], dev[155];
		char temp[50];
		scanf("%d%d",&n,&l);
		for(int i = 0; i < n; i++){
			scanf(" %s ", temp);
		  	//printf("%s\n", temp);	
			conv(temp, out[i]);
		}
		for(int i = 0; i < n; i++){
			scanf(" %s ", temp);
		  	//printf("%s\n", temp);	
			conv(temp, dev[i]);
		}
		sort(dev, dev+n);

		for(int i = 0; i < n; i++){
			vector<int> tofix;
			ll nout[155];
			int tr = 0;
			bool yes = 1;
			for(int j = 0; j < l; j++){
				int a = (1<<j)&dev[0];
				int b = (1<<j)&out[i];
				if(a != b){
				   tr++;
				   tofix.push_back(j);
				}
			}
			for(int j = 0; j < n; j++){
				nout[j] = out[j];
				for(int k = 0; k < (int)tofix.size(); k++){
					nout[j] = (nout[j] ^ (1<<tofix[k]));
				}
			}
			sort(nout, nout+n);
			for(int j = 0; j < n; j++){
				if(nout[j] != dev[j]){
					yes = 0;
					break;
				}
			}
			if(yes){
				pos = 1;
				if(tr < ans) ans = tr;
			}
		}

		if(pos) printf("%d\n", ans);
		else printf("NOT POSSIBLE\n");
	}
	return 0;
}
