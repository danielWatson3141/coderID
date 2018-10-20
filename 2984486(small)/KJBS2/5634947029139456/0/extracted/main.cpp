#include <stdio.h>
using namespace std;

int T;
int N, L;
char Outlet[301][50];
char Answer[301][50];
char Now[301][50];

char change(char x) {
	if(x=='1') return '0';
	else return '1';
}

int Get_Ans() {
	int i, j, k, l;
	char temp[300];
	scanf("%d %d",&N, &L);
	for(i=1; i<=N; i++) {
		scanf("%s", Outlet[i]);
	}
	for(i=1; i<=N; i++) {
		scanf("%s", Answer[i]);
	}

	int ans=2100000000, now_ans=0, check, flag;
	for(k=1; k<=N; k++) {
		for(i=1; i<=N; i++)
			for(j=0; j<L; j++)
				Now[i][j]=Outlet[i][j];
		now_ans=0;
		for(j=0; j<L; j++) {
			if(Now[1][j]!=Answer[k][j]) {
				now_ans++;
				for(i=1; i<=N; i++)
					Now[i][j]=change(Now[i][j]);
			}
		}
		for(i=1; i<=N; i++) {
			flag=0;
			for(j=1; j<=N; j++) {
				check=0;
				for(l=0; l<L; l++) {
					if(Now[i][l]!=Answer[j][l]) {
						check=1;
						break;
					}
				}
				if(check==0) {
					flag=1;
					break;
				}
			}
			if(flag==0) break;
		}
		if(flag==1) {
			if(ans>now_ans) ans=now_ans;
		}
	}
	return ans;
}

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	int i, temp;
	for(i=1; i<=T; i++) {
		temp=Get_Ans();
		if(temp==2100000000)
			printf("Case #%d: NOT POSSIBLE\n", i);
		else
			printf("Case #%d: %d\n", i, temp);
	}
}
