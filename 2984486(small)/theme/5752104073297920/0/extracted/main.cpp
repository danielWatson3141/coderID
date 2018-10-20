#include <cstdio>

using namespace std;

const int error=20;

int n;
int badCount,goodCount;

int main() {
	int cases;
	scanf("%d",&cases);
	for(int round=1; round<=cases; round++) {
		scanf("%d",&n);
		badCount=0;
		goodCount=0;
		for(int i=0; i<n; i++) {
			int x;
			scanf("%d",&x);
			if(x>i)
				badCount++;
			if(x<i)
				goodCount++;
		}
		printf("Case #%d: ",round);
		if(badCount-goodCount>error)
			printf("BAD\n");
		else
			printf("GOOD\n");
	}
	return 0;
}
