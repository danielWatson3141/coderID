#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <vector>
#include <cassert>
#include <algorithm>
#include <cctype>
#include <iomanip>
#include <queue>
#define INF 200000000000LL
#define M 1000000007LL

using namespace std;

int n = 1000;
int a[2000];

int abs(int x)
{
	x>0? x : -x;
}

void shuffle1()
{
	for (int i = 1; i<=n; i++){
		int k = rand()%(n-i+1);
		//cout<<"K"<<k<<endl;
		swap(a[i], a[i+k]);
	}
}

void shuffle2()
{
	for (int i = 1; i<=n; i++){
		int k = rand()%n;
		swap(a[i], a[1+k]);
	}
}

double sqr(double x)
{
	return x*x*x;
}
/*
int main()
{
	int Z = 0;
	double z1, z2;
	z1 = z2 = 0;
	while (Z<10){
	Z++;
	for (int i = 1; i<=1000; i++) a[i] = i;
	shuffle1();
	double dis = 0;
	for (int i = 1; i<=1000; i++){
		dis += abs(a[i]-i);
	}
	dis /= 1000.0;
	double res = 0;
	for (int i = 1; i<=1000; i++){
		res += sqr(abs(a[i]-i)-dis);
	}
	z1 += res;
	for (int i = 1; i<=1000; i++) a[i] = i;
	shuffle2();
	dis = 0;
	for (int i = 1; i<=1000; i++){
		dis += abs(a[i]-i);
	}
	dis /= 1000.0;
	res = 0;
	for (int i = 1; i<=1000; i++){
		res += sqr(abs(a[i]-i)-dis);
	}
	z2 += res;
	}
	cout<<z1/Z<<endl;
	cout<<z2/Z<<endl;
}
*/

int main()
{
	int T;
	int cnt = 0;
	cin>>T;
	int ttt = 0;
	double judge = -3.78573e+09;
	while (T--){
		ttt++;
		cin>>n;
		int dis = 0;
		for (int i = 1; i<=n; i++) cin>>a[i];
//		for (int i = 1; i<=1000; i++) a[i] = i;
//		shuffle1();
		for (int i = 1; i<=n; i++) dis += abs(a[i]-i);
		dis /= 1000.0;
		double res = 0;
		for (int i = 1; i<=n; i++){
			res += sqr(abs(a[i]-i)-dis);
		}
		cout<<"Case #"<<ttt<<": ";
		if (res>judge){
			cout<<"GOOD"<<endl; cnt++;
		}
		else cout<<"BAD"<<endl;
	}
}
