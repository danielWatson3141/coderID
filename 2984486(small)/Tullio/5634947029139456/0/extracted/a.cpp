#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

#define f first
#define s second
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rep(a,b) fr(a,0,b)
#define db if(1)
#define pb push_back

typedef long long ll;

int n, l, res;
string num[2][110];

bool read(){
    if(scanf("%d%d", &n, &l) == EOF) return false;
	char lixo[50];
	rep(i, n) {
		scanf("%s", lixo);
		num[0][i] = lixo;
	}
	rep(i, n) {
		scanf("%s", lixo);
		num[1][i] = lixo;
	}
    return true;
}

int cn = 1;

void process(){
	res = 0;
	
	rep(i, l){
		int cont[] = {0, 0};
		rep(j, n){
			if (num[0][j][i] == '1') cont[0]++;
			if (num[1][j][i] == '1') cont[1]++;
		}

		if (cont[0] == cont[1]) {
			
		} else if (cont[0] == (n-cont[1])) {
			res++;
			rep(j, n){
				if (num[0][j][i] == '1') {
					num[0][j][i] = '0';
				} else {
					num[0][j][i] = '1';
				}
			}
		} else {
			printf("Case #%d: NOT POSSIBLE\n", cn++);
			return;
		}
	}
	sort(num[0], num[0]+n);
	sort(num[1], num[1]+n);
	
	rep(i, n) {
		if (num[0][i].compare(num[1][i])) {
			printf("Case #%d: NOT POSSIBLE\n", cn++);
			return;
		}
	}
	printf("Case #%d: %d\n", cn++, res);
}

int main(){  
	int t = -1;
	
	scanf("%d", &t);

    while(t-- && read()){
        process();
    }
    
    return 0;
}
