#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<iostream>
using namespace std;

#define MAXN 1010

struct Vect{
	int b[MAXN];
	int dist;
	int label;
	}p[MAXN*20];

int T, tt;
int n, tot = 0;
int a[MAXN], b[MAXN];

int getDist(int x[], int y[])
{
	int sum = 0;
	for (int i = 0; i < n; ++i)
		sum += (x[i] - y[i]) * (x[i] - y[i]);
	return sum;
	}

bool cmp(Vect a, Vect b)
{
	return a.dist < b.dist;
	}

int main()
{
	T = 10000;
	n = 1000;
	tt = T;
	while (tt--){
		for (int i = 0; i < n; ++i) a[i] = i;
		for (int i = 0; i < n; ++i)
			{
				int p = i + rand()%(n-i);
				swap(a[i], a[p]);
				}
		for (int i = 0; i < n; ++i) b[a[i]] = abs(a[i] - i);
		for (int i = 0; i < n; ++i) p[tot].b[i] = b[i];
		p[tot].label = 1;
		tot++;
		}
	tt = T;
	while (tt--){
		for (int i = 0; i < n; ++i) a[i] = i;
		for (int i = 0; i < n; ++i)
			{
				int p = rand()%n;
				swap(a[i], a[p]);
				}
		for (int i = 0; i < n; ++i) b[a[i]] = abs(a[i] - i);
		for (int i = 0; i < n; ++i) p[tot].b[i] = b[i];
		p[tot].label = 0;
		tot++;
		}
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &T);
	tt = 0;
	while (T--){
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		for (int i = 0; i < n; ++i) b[a[i]] = abs(a[i] - i);
		for (int i = 0; i < tot; ++i) p[i].dist = getDist(b, p[tot].b);
		sort(p, p+n, cmp);
		int k = n / 2;
		int sum = 0;
		for (int i = 0; i < k; ++i)
			sum += p[i].label;
		printf("Case #%d: ", (++tt));
		if (sum > k - sum) printf("GOOD\n");
		else printf("BAD\n");
		}
	return 0;
	}
