#include <stdio.h>

int T;
int N;
int List[1111][1111];
int Check[1111];
int Number[1111];

int How(int v, int root) {
	int i, x, cnt=0, max1=-1, max2=-1, temp;
	Check[v]=root;
	Number[v]=1;
	for(i=1; i<=List[v][0]; i++) {
		x=List[v][i];
		if(Check[x]!=root) {
			cnt++;
			temp=How(x, root);
			temp=Number[x]-temp;
			Number[v]+=Number[x];
			if(max1<=temp) {
				max2=max1;
				max1=temp;
			}else if(max2<temp) {
				max2=temp;
			}
		}
	}
	if(cnt==0) return 0;
	else if(cnt==1) return Number[v]-1;
	else if(cnt>=2) return Number[v]-1-max1-max2;

}

int Get_Ans() {
	scanf("%d", &N);
	int i;
	int x, y;
	for(i=1; i<=N; i++) List[i][0]=Check[i]=0;
	for(i=1; i<N; i++) {
		scanf("%d %d", &x, &y);
		List[x][++List[x][0]]=y;
		List[y][++List[y][0]]=x;
	}
	int temp, ans=2100000000;
	for(i=1; i<=N; i++) {
		temp=How(i, i);
		if(ans>temp) ans=temp;
	}
	return ans;
}

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	int i;
	for(i=1; i<=T; i++)
		printf("Case #%d: %d\n", i, Get_Ans());

}
