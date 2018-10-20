#include<bits/stdc++.h>
using namespace std;
long long funcion(vector<string> arr, vector<string> brr, long long temp, long long dev) {
	
	if(temp >= arr[0].length() ) {
		return INT_MAX;
	}
	
	else {
		long long  i;
		if(arr == brr) {
			return dev;
		}
		vector<string> x1 = arr;
		
		for(i = 0;i < arr.size();i++) {
			arr[i][temp]=(1 - (arr[i][temp] - 48) ) + 48;
		}
		sort(arr.begin(), arr.end());
		if(arr == brr) {
			return dev + 1;
		}
		else {
			long long mi = INT_MAX;
			for(i = temp + 1;i < arr[0].length();i++) {
				mi = min(mi, min(funcion(arr, brr, i, dev+ 1), funcion(x1, brr, i, dev)));
			}
			return mi;
		}
	}
	
	return INT_MAX;
}

int main()
{
	long long test,i;
	freopen("inp1.txt", "r", stdin);
	freopen("out1.txt", "w", stdout);
	scanf("%lld",&test);
	for(i = 1; i <= test;i++) {
		long long n, l;
		long long j;
		scanf("%lld",&n);
		scanf("%lld",&l);
		vector <string> arr;
		vector <string> brr;
		
		for(j = 0;j < n;j++) {
			string s1;
			cin>>s1;
			arr.push_back(s1);
		}
		for(j = 0;j < n;j++) {
			string s2;
			cin>>s2;
			brr.push_back(s2);
		}
		
		sort(arr.begin(), arr.end());
		sort(brr.begin(), brr.end());
		
		long long ans = funcion(arr, brr, 0,0);
		
		if(ans !=INT_MAX) {
			printf("Case #%lld: %lld\n", i, ans);
		}
		else {
			printf("Case #%lld: NOT POSSIBLE\n", i);
		}
	}
}


