#include <cstdio>
#include <iostream>

using namespace std;

int n;

int main(){
	int test=0;
	scanf("%d", &test);
	for (int T=1; T<=test; ++T){
		int A=0;
		int tot=0;
		scanf("%d", &n);
		for (int i=0; i<n; ++i){
			int x;
			scanf("%d", &x);
			if (x<i) ++A;
		}
		printf("Case #%d: ", T);
		if (A<485) printf("BAD\n"); else printf("GOOD\n");
	}
}
