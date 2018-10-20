#include<stdio.h>
#include<string.h>
char str[50];
int sum[50];
int cmp[50];
int main ()
{
	int T,n,l,ans;
	scanf("%d",&T);
	for(int _ =1;_<=T;_++){
		printf("Case #%d: ",_);
		memset(sum,0,sizeof(sum));
		memset(cmp,0,sizeof(cmp));
		scanf("%d%d",&n,&l);
		for(int i=0;i<n;i++){
			scanf("%s",str);
			for(int j=0;j<l;j++){
				if(str[j]=='1')
					sum[j]++;
			}
		}
		for(int i=0;i<n;i++){
			scanf("%s",str);
			for(int j=0;j<l;j++){
				if(str[j]=='1')
					cmp[j]++;
			}
		}
		ans =0;
		for(int i=0;i<l;i++)
		{	
			if(cmp[i]==sum[i]) continue;
			if(cmp[i]+sum[i]!=n){ ans =-1;break;}
			ans++;
		}
		if(ans>=0)
		printf("%d\n",ans);
		else
		printf("NOT POSSIBLE\n");
		
	}
	return 0;
}
