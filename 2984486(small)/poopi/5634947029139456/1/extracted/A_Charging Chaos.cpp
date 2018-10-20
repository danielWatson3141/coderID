										/* in the name of Allah */
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <list>
#include <map>
#include <set>

using namespace std;

#define uint unsigned int
#define int64 long long
#define P pair<int, int>
#define Pss pair<string, string>
#define PLL pair<int64, int64>
#define Inf 1000000
#define Mod 1000000007LL

int n, len;
int64 src[200], des[200];
int64 tmp[200];

int64 toVal(string str){
	int64 ret = 0;
	for(int i = 0; i < str.length(); i++)
		ret = ret * 2 + (str[i] - '0');
	return ret;
}

int main(){
	freopen("A_Charging Chaos.in", "r", stdin);
	freopen("A_Charging Chaos.out", "w", stdout);
	int T, test = 0;
	for(cin >> T; T--; ){
		cin >> n >> len;
		string str;
		for(int i = 0; i < n; i++){
			cin >> str;
			src[i] = toVal(str);
		}
		for(int i = 0; i < n; i++){
			cin >> str;
			des[i] = toVal(str);
		}
		sort(des, des + n);
		int mn = 1000;
		for(int i = 0; i < n; i++){
			int64 dif = src[0] ^ des[i];
			for(int j = 0; j < n; j++)
				tmp[j] = src[j] ^ dif;
			sort(tmp, tmp + n);
			bool can = true;
			for(int j = 0; j < n; j++)
				if(tmp[j] != des[j])
					can = false;
			if(can){
				int cnt = 0;
				while(dif){
					if(dif & 1)
						cnt++;
					dif >>= 1;
				}
				mn = min(mn, cnt);
			}
		}
		cout << "Case #" << ++test << ": ";
		if(mn == 1000)
			cout << "NOT POSSIBLE" << endl;
		else cout << mn << endl;
	}
	return 0;
}
