#include<cstdio>
#include<algorithm>
#include<string>

#define INF 1<<28
#define MAX 160

using namespace std;
int n, l, res, casos;
char aux[MAX];
string v[MAX], cp[MAX], de[MAX];

int main(){
	int cnt;
	bool pode;
	scanf(" %d", &casos);
	for(int inst=1;inst<=casos;inst++){
		scanf(" %d %d", &n, &l);
		for(int i=0;i<n;i++){ scanf(" %s", aux); v[i] = aux; }
		for(int i=0;i<n;i++){ scanf(" %s", aux); de[i] = aux; }
		
		res = INF;
		for(int i=0;i<(1<<l);i++){
			for(int k=0;k<n;k++) cp[k] = v[k];
			for(int k=0;k<n;k++){
				for(int j=0;j<l;j++)
					if((1<<j)&i) cp[k][j] = (cp[k][j] == '0') ? '1' : '0';
			}
			
			for(int k=0;k<n;k++){
				pode = false;
				for(int j=0;j<n;j++) if(de[j] == cp[k]) pode = true;
				if(!pode) break;
			}
			if(pode){
				cnt = 0;
				for(int j=0;j<l;j++) if((1<<j)&i) cnt++;
				res = min(cnt, res);
			}
		}
		printf("Case #%d: ", inst);
		if(res == INF) printf("NOT POSSIBLE\n");
		else printf("%d\n", res);
	}
	return 0;
}