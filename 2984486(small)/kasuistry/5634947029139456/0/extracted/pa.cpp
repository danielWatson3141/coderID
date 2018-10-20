
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>

using namespace std;

int count(int x){
	
	int sum = 0;

	while(x){
		x &= (x-1);
		++ sum;
	}
	return sum;
}

int conv(char *buf){
	
	int sum = 0;

	for(int i=0; buf[i] != '\0'; ++i){
		sum = sum*2 + buf[i]-'0';
	}

	return sum;
}

int main(){
	
	int testcase; scanf("%d", &testcase);

	int s[10], r[10];
	int p[10];
	char buf[1000];

	for(int t=1; t<=testcase; ++t){
		int n, b; scanf("%d %d", &n, &b);
		for(int i=0; i<n; ++i){
			scanf("%s", buf);
			s[i] = conv(buf);
		}
		for(int i=0; i<n; ++i){
			scanf("%s", buf);
			r[i] = conv(buf);
		}
		int found = -1;
		sort(r, r+n);
		for(int i=0; i<pow(2, b); ++i){
			for(int j=0; j<n; ++j){
				p[j] = s[j]^i;
			}
			sort(p, p+n);
			int yes = 1;
			for(int j=0; j<n; ++j){
				if(r[j] != p[j]){
					yes = 0;
					break;
				}
			}
			if(yes){
				if(found == -1 || found > count(i)){
					found = count(i);
				}
			}
		}
		printf("Case #%d: ", t);
		if(found ==-1){
			printf("NOT POSSIBLE\n");
		}else{
			printf("%d\n", found);
		}
	}

	return 0;
}
