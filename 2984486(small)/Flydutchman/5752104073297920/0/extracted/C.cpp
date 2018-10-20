#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<ctime>
#include<map>
#include<string>
#include<vector>
#include<set>

using namespace std;
#define For(i,l,r) for (int i = l; i <= r; ++i)
#define Cor(i,l,r) for (int i = l; i >= r; --i)
#define Fill(a,b) memset(a,b,sizeof(a))
#define FI first
#define SE second
#define MP make_pair
#define PII pair<int,int>
#define flt double
#define INF (0x3f3f3f3f)
#define MaxN 1020304
#define MaxNode 1020304
#define MD 1000000007

int A[1111][1111];
int p[1111];
int n;
int main() {
	srand(time(0));
	n = 1000;
	Fill(A,0);
	For(TIME,1,5000000) {
		if (TIME % 100000 == 0) cerr << TIME << endl;
		For(i,1,n) {
			p[i] = i;
		}
		For(i,1,n) {
			int t = rand() % n + 1;
			swap(p[i],p[t]);
		}
		For(i,1,n) ++A[i][p[i]];
	}
	freopen("temp.txt","w",stdout);
	puts("const int A[1000][1000] = {");
	For(i,1,n) {
		putchar('{');
		For(j,1,n) {
			printf("%d",A[i][j]);
			if (j < n) putchar(','); else putchar('}');
		}
		puts(",");
	}
	return 0;
}