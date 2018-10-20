#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<deque>
#include<queue>
#include<string>
#include<math.h>
#include<fstream>
#include<string>
#include<algorithm>
#include<math.h>
#include<map>
#include<set>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<time.h>
#include<random>

#define pb push_back
#define endl '\n'
#define vvi vector<vector<int> >
#define str string
#define vi vector<int>
#define vs vector<string>
#define vll vector<long long>
#define ll long long
#define mp make_pair
#define ld long double
#define itn int 
#define vvll vector<vector<long long> >


const clock_t tl = 0.5 * CLOCKS_PER_SEC;
double start;

#pragma comment(linker, "/STACK:25600000")
using namespace std;
int foo(ll a, vll &f, vll &s){
	map<ll, ll> p;
	for(int i = 0; i < f.size(); i++){
		p[f[i]^a]++;
	}
	for(itn i = 0; i < s.size(); i++){
		if(!p[s[i]]){
			return 1e+9;
		}
		p[s[i]]--;
	}
	int k =0 ;
	while(a){
		if(a % 2)
			k++;
		a/=2;
	}
	return k;
}
int fun(ll a){
	int k =0 ;
	while(a){
		if(a % 2)
			k++;
		a/=2;
	}
	return k;
}
int main(){
	//freopen("road.in", "r", stdin);
	//freopen("road.out", "w", stdout);
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for(int q = 0; q < t; q++){
		int n;
		cin >> n;
		itn f, l;
		vi v(n);
		for(itn i = 0; i < n; i++){
			cin >> v[i];
		}
		cout << "Case #"<<q+1<<": ";
		f = v[0];
		l = v[1];
		if(f == 0){
			cout << "BAD";
			cout << endl;
			continue;
		}
		if(l == n-1){
			cout << "GOOD";
			cout << endl;
			continue;
		}
		for(int i = 0; i < n/2; i++){
			if(v[i] == i){
				cout << "BAD";
				cout << endl;
				f = -1;
				break;
			}
			if(l == n-1){
				cout << "GOOD";
				f = -1;
				cout << endl;
				break;
			}
		}
		if(f == -1)
			continue;
		f = rand()%2;
		if(f){
			cout << "GOOD";
			cout << endl;
			continue;;
		}
		cout << "BAD";
			cout << endl;
			continue;
	}
	return 0;
}