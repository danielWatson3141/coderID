#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef unsigned long long ul;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef vector<ii> vii;

ul one = 1;

int t,n,temp;
int arr[1010];
int cur[1010];
int id[1010];
bool ok;

int main(){
	scanf("%d",&t);
	for (int jj=1; jj<=t; jj++){
		scanf("%d",&n);
		memset(arr,-1,sizeof arr);
		memset(cur,-1,sizeof cur);
		memset(id,-1,sizeof id);
		for (int i=0; i<n; i++){
			cur[i] = i;
			id[i] = i;
			scanf("%d",&arr[i]);
		}
		ok = true;
		for (int i=0; i<n; i++){
			temp = id[arr[i]];
			if (temp < i){
			//cout << temp << "  " << i << endl;
				ok = false;
				break;
			}
			cur[temp] = cur[i];
			cur[i] = arr[i];
			id[i] = temp;
			id[arr[i]] = i;
		}
		printf("Case #%d: ",jj);
		if (ok) printf("GOOD\n");
		else printf("BAD\n");
	}
	return 0;
}
