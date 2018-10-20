#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;

vector< vector<char> > vec , req;

int n , Min = INT_MAX , m;
bool check(){
	sort(vec.begin(),vec.end());
	sort(req.begin(),req.end());

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if(vec[i][j] != req[i][j]) return false;
		}
	}
	return true;

}

void rec(int index , int re){
	if(index == m){
		if(check()){
			if(re < Min){
				Min = re;
			}
		}
		return;
	}

	rec(index + 1 , re);
	for (int i = 0; i < n; i++)
	{
		vec[i][index] = vec[i][index] == '0' ? '1' : '0';
	}
	rec(index + 1 , re + 1);
	for (int i = 0; i < n; i++)
	{
		vec[i][index] = vec[i][index] == '0' ? '1' : '0';
	}

}
int main(){
	freopen("in.txt" , "r" , stdin);
	freopen("out.txt" , "w" , stdout);

	int T;
	scanf("%d" , &T);
	for (int i = 0; i < T; i++)
	{
		Min = INT_MAX;
		printf("Case #%d: " , i+1);
		scanf("%d%d" , &n , &m);
		vec.clear();
		req.clear();
		vec.resize(n);
		req.resize(n);
		for (int j = 0; j < n; j++)
		{
			char x;
			for (int k = 0; k < m; k++)
			{
				cin >> x;
				vec[j].push_back(x);
			}
		}
		for (int j = 0; j < n; j++)
		{
			char x;
			for (int k = 0; k < m; k++)
			{
				cin >> x;
				req[j].push_back(x);
			}
		}

		rec(0,0);
		if(Min != INT_MAX) printf("%d\n" , Min);
		else printf("NOT POSSIBLE\n");
	}


	return 0;
}