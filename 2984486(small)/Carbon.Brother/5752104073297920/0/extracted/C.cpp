
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

int a[1024];
int T,n;

void rand1() {
	for (int i=0;i<1000;i++) a[i]=i;
	for (int i=0;i<1000;i++) {
		int t=rand()%(1000-i)+i;
		swap(a[i],a[t]);
	}
}

void rand2() {
	for (int i=0;i<1000;i++) a[i]=i;
	for (int i=0;i<1000;i++) {
		int t=rand()%1000;
		swap(a[i],a[t]);
	}
}

int main() {
	/*for (int i=1;i<=100;i++) {
		rand2();
		int cl=0,ce=0,cg=0;
		for (int i=0;i<1000;i++)
			if (a[i]<i) cl++;
			else if (a[i]==i) ce++;
			else cg++;
		printf("%d\n",max(cg-cl,0));
	}*/
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&T);
	for (int ww=1;ww<=T;ww++) {
		printf("Case #%d: ",ww);
		scanf("%d",&n);
		for (int i=0;i<n;i++) scanf("%d",a+i);
		int cl=0,ce=0,cg=0;
		for (int i=0;i<1000;i++)
			if (a[i]<i) cl++;
			else if (a[i]==i) ce++;
			else cg++;
		if (cg-cl>=30) printf("BAD\n");
		else printf("GOOD\n");
	}
	return 0;
}
