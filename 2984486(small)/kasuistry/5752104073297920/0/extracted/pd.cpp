
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>

using namespace std;

int main(){
	
	int testcase; scanf("%d", &testcase);
	int s[1000];

	for(int t=1; t<=testcase; ++t){
		long long n;
		scanf("%lld", &n);
		for(int i=0; i<n; ++i){
			scanf("%d", &s[i]);
		}
		long long sum = 0;
		long long tot = (n*(n-1)*(n-2))/6;
		for(int i=0; i<n; ++i){
			for(int j=i+1; j<n; ++j){
				if(s[i] > s[j]){
					for(int k=j+1; k<n; ++k){
						if(s[j] > s[k]){
							++ sum;
						}
					}
				}
			}
		}
		printf("Case #%d: ", t);
		if(((double)sum)/tot >= 0.163){
			printf("GOOD\n");
		}else{
			printf("BAD\n");
		}
	}

	return 0;
}
