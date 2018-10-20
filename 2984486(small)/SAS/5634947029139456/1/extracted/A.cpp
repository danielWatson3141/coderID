#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
int N,L;
int ini[200][50];
int target[200][50];
int min(int a,int b){
	return a > b ? b:a;
}
int flip(int level){
	for(int i=0;i<N;i++){
		if(ini[i][level] == 1)ini[i][level] = 0;
		else if(ini[i][level] == 0)ini[i][level] = 1;
	}
	return 0;
}
int checkEqual(){	
	for(int i=0;i<L;i++){
		int ini_count = 0;
		int target_count = 0;
		for(int j=0;j<N;j++){
			if(ini[j][i] == 1)ini_count++;
			if(target[j][i] == 1)target_count++;
		}
		if(!(ini_count == target_count || ini_count == N - target_count)){
			return -1;
		}
	}
	return 1;
}

int checkMatch(int level){
	vector<int> ini_num[200];
	vector<int> target_num[200];
	for(int i=0;i<200;i++){
		ini_num[i].resize(level);
		target_num[i].resize(level);
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<level + 1;j++){
			ini_num[i].push_back(ini[i][j]);
			target_num[i].push_back(target[i][j]);
		}
	}
	sort(ini_num, ini_num + N);
	sort(target_num, target_num + N);
	for(int i=0;i<N;i++){
		if(ini_num[i] != target_num[i]){
			return -1;
		}
	}
	return 1;
}
int f(int level){
	// not flip
	int answer = 9999;
	if(level == L )return 0;
	if(checkMatch(level) == 1){
		answer = min(answer,f(level + 1));
	}

	flip(level);
	if(checkMatch(level) == 1){
		answer = min(answer, f(level + 1) + 1);
	}
	flip(level);
	return answer;
}
int main(){
	int T;
	scanf("%d",&T);
	for(int ca = 1; ca <= T ; ca++){
		scanf("%d %d",&N, &L);
		for(int i=0;i<N;i++){
			char c[50];
			scanf("%s",c);
			for(int j=0;j<L;j++){
				ini[i][j] = c[j] - '0';
			}
		}
		for(int i=0;i<N;i++){
			char c[50];
			scanf("%s",c);
			for(int j=0;j<L;j++){
				target[i][j] = c[j] - '0';
			}
		}
		if(checkEqual() == -1){
			printf("Case #%d: NOT POSSIBLE\n",ca);
			continue;
		}
		int a = f(0);
		if(a != 9999){
			printf("Case #%d: %d\n",ca,a);
		}else{
			printf("Case #%d: NOT POSSIBLE\n",ca);
		}
	}
	return 0;
}
