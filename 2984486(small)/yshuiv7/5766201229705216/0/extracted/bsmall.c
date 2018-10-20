#include <string.h>
#include <stdio.h>
#include <stdbool.h>
int G[20][20];
int color[20];
void dcolor(int i, int mask){
	if(color[i])
		return;
	color[i] = 1;
	int j;
	for(j=1;j<=G[i][0];j++){
		if(mask & (1<<G[i][j]))
			continue;
		dcolor(G[i][j], mask);
	}
}

int check(int mask, int n){
	int d2 = 0;
	int i,d;
	memset(color, 0, sizeof(color));
	for(i=0; i<n; i++){
		if(mask & (1<<i))
			continue;
		dcolor(i, mask);
		break;
	}
	for(i=0; i<n; i++){
		if(mask & (1<<i))
			continue;
		if(!color[i])
			return false;
		int j;
		d=0;
		for(j=1;j<=G[i][0];j++){
			if(mask & (1<<G[i][j]))
				continue;
			d++;
		}
		if (d == 2){
			if(d2)
				return false;
			d2 = 1;
		}else if(d != 1 && d != 3)
			return false;
	}
	return true;
}
__attribute__((pure)) int countone(int x){
	int ans=0;
	while(x){
		ans+=(x&1);
		x>>=1;
	}
	return ans;
}
int main(){
	int cases, p;
	scanf("%d", &cases);
	for(p=1; p<=cases; p++){
		int m;
		scanf("%d", &m);
		int i;
		for(i=0; i<m; i++)
			G[i][0] = 0;
		for(i=0; i<m-1; i++){
			int x,y;;
			scanf("%d%d", &x, &y);
			x--;
			y--;
			G[x][++G[x][0]] = y;
			G[y][++G[y][0]] = x;
		}
		int best = m-1;
		for(i=0; i<(1<<m); i++)
			if(check(i, m)){
				if(countone(i)<best){
					//printf("%d %d\n", i, countone(i));
					best = countone(i);
				}
			}
		printf("Case #%d: %d\n", p, best);
	}
	return 0;
}
