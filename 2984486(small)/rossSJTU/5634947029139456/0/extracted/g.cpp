#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int s[20];
int t[20];
char str[20];
int test[20];
int main ()
{
	int T,n,l,ans,cnt,qq;
	scanf("%d",&T);
	for(int icase=1;icase<=T;icase++){
		printf("Case #%d: ",icase);
		memset(s,0,sizeof(s));
		memset(t,0,sizeof(t));
		scanf("%d%d",&n,&l);
		for(int i=0;i<n;i++){
			scanf("%s",str);
			for(int j=0;j<l;j++){
				s[i] = (s[i]<<1)|(str[j]=='1');
				//printf("%c %d\n",str[j],s[i]);
			}
		}
		for(int i=0;i<n;i++){
			scanf("%s",str);
			for(int j=0;j<l;j++){
				t[i] = t[i]<<1|(str[j]=='1');
			}
		}
		ans = 50;
		sort(t,t+n);
		for(int i=0;i<(1<<l);i++){
			cnt =0;
			for(int tt=0;tt<l;tt++){
				if(i&(1<<tt)) cnt++; 
			}
			if(cnt>=ans) continue;
			for(int j=0;j<n;j++){
				test[j] = s[j]^i;
			}
			sort(test,test+n);
			for(qq=0;qq<n;qq++){
				if(test[qq]!=t[qq]) break;
			}
			if(qq==n)
			ans= cnt;
		}
		if(ans==50)
		printf("NOT POSSIBLE\n");
		else
		printf("%d\n",ans);
	}
	return 0;
}
