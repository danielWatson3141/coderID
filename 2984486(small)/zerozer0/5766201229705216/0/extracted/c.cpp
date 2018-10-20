/*#include <stdio.h>
#include <string.h>

int n, l, tmp[11],out[11],count[1110],get[1110];
int flip(int x)
{
	int i = 0, j;
	for( i = 0; i < n; i ++ )
	{
		tmp[i] = out[i];
	}
	i = 0;
	while(x)
	{
		if(x&1)
		{
			for( j = 0; j < n; j ++ )
			{
				if((tmp[j]>>i)&1)
					tmp[j]^=(1<<i);
				else
					tmp[j]|=(1<<i);
			}
		}
		x>>=1;
		i++;
	}
	int ok = 1;
	for( i = 0;i < n;  i++ )
	{
		count[tmp[i]]--;
		if(count[tmp[i]] < 0 )
		{
			ok = 0;
		}
	}
	for( i = 0; i < n; i ++ )
		count[tmp[i]]++;
	return ok;
}

int cal(int x)
{
	int ans = 0, i;
	for( i = 0; i < 10; i ++ )
	{
		if((x>>i)&1)
			ans++;
	}
	return ans;
}
int main()
{
	int t, test = 0, i, m, sum, ans, j;
	char str[20];
	freopen("A-small-attempt0 (1).in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&t);
	for( i = 0; i < 1024; i ++)
		get[i] = cal(i);
	while(t--)
	{
		memset(count,0,sizeof(count));
		scanf("%d%d",&n,&l);
		for(i = 0; i < n; i ++)
		{
			scanf("%s",str);
			sum = 0;
			for( j = 0; j < l; j ++ )
				sum=sum*2+str[j]-'0';
			out[i] = sum;
		}
		
		for( i = 0; i < n; i ++ )
		{
			scanf("%s",str);
			sum = 0;
			for( j = 0; j < l; j ++ )
				sum=sum*2+str[j]-'0';
			count[sum]++;
		}
		m = 1<<l;
		ans = 11;
		for( i = 0; i < m; i ++ )
		{	
			if(flip(i))
			{
				if(ans>get[i])
					ans = get[i];
			}
		}
		printf("Case #%d: ",++test);
		if( ans == 11)
			puts("NOT POSSIBLE");
		else
			printf("%d\n",ans);
	}

	return 0;
}*/



#include <stdio.h>
#include <string.h>

int n, to[15][15], ban[15],get[1<<15];
int len[15],tot=0;
int dfs(int x, int p)
{
	int i;
	int count = 0;
	tot++;
	for( i = 0; i < len[x]; i++)
	{
		if(ban[to[x][i]] || to[x][i] == p )
			continue;

		count++;
		if(count>2)
			return 0;
		if(!dfs(to[x][i],x))
			return 0;
	}
	if(count == 1 )
		return 0;
	return 1;
}

int cal(int x)
{
	int ans = 0, i;
	for( i = 0; i < 15; i ++ )
	{
		if((x>>i)&1)
			ans++;
	}
	return ans;
}
int main()
{
	int t, test = 0, i, m, sum, ans, j, x, y;
	freopen("B-small-attempt0 (1).in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&t);
	for( i = 0; i < (1<<15); i ++)
		get[i] = cal(i);
	while(t--)
	{

		scanf("%d",&n);
		for( i = 0; i < n; i ++ )
			len[i] = 0;
		ans = 14;
		for(i = 1; i < n; i ++)
		{
			scanf("%d%d",&x,&y);
			x--,y--;
			to[x][len[x]++] = y;
			to[y][len[y]++] = x;

		}
		m = 1 << n;
		for( i = 0; i < m; i ++ )
		{
			for( j = 0; j < n; j ++)
			{
				if((i>>j)&1)
					ban[j] = 1;
			}
			for( j = 0; j < n; j ++ )
			{
				if(ban[j])
					continue;
				tot = 0;
				if(dfs(j,-1) && tot+get[i]==n)
					break;
			}
			if( j < n && ans > get[i])
				ans = get[i];
			for( j = 0; j < n; j ++)
			{
				if((i>>j)&1)
					ban[j] = 0;
			}
		}
		printf("Case #%d: %d\n",++test,ans);
	}

	return 0;
}