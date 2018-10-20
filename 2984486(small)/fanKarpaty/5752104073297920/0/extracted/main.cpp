#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
#define MAX(x,y) (x > y ? x : y)
#define MIN(x,y) (x > y ? y : x)
int mem[1001][1001];
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n = 1000;
	srand(141);
	memset(mem,0,sizeof(mem));
	int k = 1000000;
	for (int t = 0; t < k ; t++) {
		
		int arr[1000];
		for (int j = 0; j < n; j++) arr[j]=j;
		for(int i = 0; i < n; i ++) {
			int j = rand()%(n);
			swap(arr[i],arr[j]);
		}
		for(int j = 0 ; j < n; j++)mem[j][arr[j]]++;
	}
	int T;
	cin>>T;
	double ans[135];
	double tans[135];
	for (int idx = 1; idx <= T; idx++) {
		int N;
		cin>>N;
		int mas[1001];
		double P=1.0;
		for(int i = 0;i < N; i++) {
			cin>>mas[i];
			double temp = ((double) mem[i][mas[i]])/(k/N);
			P*=temp;
		}
		ans[idx] = P;
		tans[idx] = P;
	}
	sort(tans+1,tans+1+T);
	double pok = (tans[60] + tans[61])/2.0;
	for (int idx = 1; idx<=T;idx++) {
		string ret = (ans[idx] > pok ? "BAD" : "GOOD");
		cout << "Case #"<< idx<< ": "<<ret<< endl;
	}
	return 0;
}