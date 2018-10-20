#include<iostream>

using namespace std;

const int L= 43;
const int N= 153;
const int INF= 0x3fffffff;

struct strManager{
	int i;
	char str[L];
	char mdfStr[L];
};
strManager a[N], b[N];

void xorString(int l, char str1[], char str2[], char str3[]){
	for(int i= 0; i < l; i++){
		int u= str1[i]-'0';
		int v= str2[i]-'0';
		str3[i]= '0'+(u^v);
	}
	str3[l]= 0;
}

void modifyString(int n, int l, int ind, strManager arr[]){
	for(int i= 0; i < n; i++){
		xorString(l, arr[ind].str, arr[i].str, arr[i].mdfStr);
	}
}

int countDiff(int l, char str1[], char str2[]){
	int cnt= 0;
	for(int i= 0; i < l; i++){
		if(str1[i] != str2[i]) cnt++;
	}
	return cnt;
}

bool search(int n, int l, int ind){
	modifyString(n, l, ind, b);
	bool flag1, flag2;
	flag1= true;
	for(int i= 1; i < n; i++){
		flag2= false;
		for(int j= 0; j < n; j++){
			if(j == ind) continue;
			if(strcmp(a[i].mdfStr, b[j].mdfStr) == 0){
				b[j].i= i;
				flag2= true;
				break;
			}
		}
		if(flag2 == false){
			flag1= false;
			break;
		}
	}
	return flag1;
}

int main(){
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int t;
	scanf("%d", &t);
	for(int cas= 1; cas <= t; cas++){
		int n, l;
		scanf("%d%d", &n, &l);
		for(int i= 0; i < n; i++){
			scanf("%s", a[i].str);
		}
		for(int i= 0; i < n; i++){
			scanf("%s", b[i].str);
		}
		modifyString(n, l, 0, a);
		int minn= INF;
		for(int ind= 0; ind < n; ind++){
			if(search(n, l, ind) == false) continue;
			int t= countDiff(l, a[0].str, b[ind].str);
			if(t < minn) minn= t;
		}
		if(minn == INF){
			printf("Case #%d: NOT POSSIBLE\n", cas);
		}
		else{
			printf("Case #%d: %d\n", cas, minn);
		}
	}

	return 0;
}