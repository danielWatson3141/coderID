#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;

#define MAXN 160
#define LL long long

int T, tt = 0;
int n, L;
LL a[MAXN], b[MAXN], c[MAXN];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &T);
	char ch;
	while (T--){
		scanf("%d%d", &n, &L);
		scanf("%c", &ch);
		for (int i = 0; i < n; ++i)
			{
				a[i] = 0;
				for (int j = 0; j < L; ++j)
				{
					scanf("%c", &ch);
					a[i] = a[i] * 2 + ch - 48;
				}
				scanf("%c", &ch);
				}
		for (int i = 0; i < n; ++i)
			{
				b[i] = 0;
				for (int j = 0; j < L; ++j)
				{
					scanf("%c", &ch);
					b[i] = b[i] * 2 + ch - 48;
				}
				scanf("%c", &ch);
				}		
		sort(b, b+n);
		int ans = L+1;
		for (int i = 0; i < n; ++i)
			{
				LL change = a[0] ^ b[i];
				for (int j = 0; j < n; ++j)
					c[j] = a[j] ^ change;
				sort(c, c + n);
				bool flag = true;
				for (int j = 0; j < n; ++j)
					if (c[j] != b[j]) flag = false;
				if (flag){
					int tot = 0;
					while (change){
						if (change % 2) tot++;
						change /= 2;
					}
					ans = min (ans, tot);
					}
				}
		printf("Case #%d: ", (++tt));
		if (ans > L) printf("NOT POSSIBLE\n");
		else printf("%d\n", ans);
		}
	return 0;
	}
