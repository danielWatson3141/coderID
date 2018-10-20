#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;

char S[200][50], SS[200][50];
string tmp[200], tmpS[200];
int N, L, ans;

void solve(int dep, int s){
	if (dep >= L){
		for (int i =0; i < N; i ++){
			tmp[i] = "";
			for (int j = 0; j < L; j ++)
				tmp[i] += S[i][j];	
		}
		sort(tmp, tmp + N);
		for (int i = 0; i < N; i ++) 
			if (tmp[i] != tmpS[i])
				return ;
		if (s < ans) ans = s;	
	}else{
		for (int i = 0; i < N; i ++)	
			if (S[i][dep] == '0'){
				S[i][dep] = '1';	
			}else S[i][dep] = '0';
		solve(dep + 1, s + 1);
		for (int i = 0; i < N; i ++)	
			if (S[i][dep] == '0'){
				S[i][dep] = '1';	
			}else S[i][dep] = '0';
		solve(dep + 1, s);

	}
}

int main(){
	int T;
	scanf("%d", &T);	
	for (int i = 0; i < T; i ++){
		scanf("%d%d\n", &N, &L);
		for (int j = 0; j < N; j ++){
			scanf("%s", S[j]);		
		}
		for (int j = 0; j < N; j ++){
			scanf("%s", SS[j]);		
		}
		for (int j = 0; j < N; j ++){
			tmpS[j] = "";	
			for (int k = 0; k < L; k ++)
				tmpS[j] += SS[j][k]; 
		}
		sort(tmpS, tmpS + N);
		ans = 2 * L;
		solve(0, 0);
		printf("Case #%d: ", i + 1);
		if (ans > L) printf("NOT POSSIBLE\n");
			else printf("%d\n", ans);
	}
}

