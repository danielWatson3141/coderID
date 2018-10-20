#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1010

int arr[N],pos[N];
int t,n;

int main() {
	scanf("%d",&t);
	srand(time(NULL));
	for(int Case = 1; Case <= t; Case++) {
		scanf("%d",&n);
		for(int i=0;i<n;i++) {
			scanf("%d",&arr[i]);
		}
		printf("Case #%d: %s\n",Case,rand()%10 > 6?"GOOD":"BAD");
	}
	return 0;
}
