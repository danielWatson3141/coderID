#include<stdio.h>

int main()
{
	freopen("A-small-attempt3.in","r",stdin);
	freopen("output.txt","w",stdout);
	int t,t2;
	char s[150][50]={0},s2[150][50]={0};
	int cnt[50]={0},cnt2[50]={0};
	int n,l,i,j,k,p,ch=0,ans=0;
	bool check[200]={0};
	scanf("%d",&t);
	for(t2=1;t2<=t;t2++){
		scanf("%d%d",&n,&l);
		for(i=0;i<l;i++) cnt[i] = cnt2[i] = 0;
		for(i=0;i<n;i++){
			scanf("%s",&s[i]);
			for(j=0;j<l;j++){
				if(s[i][j] == '1') cnt[j]++;
			}
		}
		for(i=0;i<n;i++){
			scanf("%s",&s2[i]);
			for(j=0;j<l;j++){
				if(s2[i][j] == '1') cnt2[j]++;
			}
		}

		ch=ans=0;
		for(i=0;i<l;i++){
			if(cnt[i] != cnt2[i] && cnt[i] + cnt2[i] != n){
				ch=1;
				break;
			}
			else if(cnt[i] != cnt2[i] && cnt[i] + cnt2[i] == n){
				ans++;
				for(j=0;j<n;j++){
					if(s[j][i]=='1') s[j][i] = '0';
					else s[j][i] ='1';
				}
				for(j=0;j<n;j++) check[j] = false;
				for(j=0;j<n;j++){
					for(k=0;k<n;k++){
						if(check[k]) continue;
						for(p=0;p<=i;p++){
							if(s[j][p] != s2[k][p]) break;
						}
						if(p==i+1){
							check[k] = true;
							break;
						}
					}
					if(k==n){
						ch=1;
						break;
					}
				}
				if(ch) break;
			}
			else if(cnt[i] == cnt2[i] && cnt[i] + cnt2[i] == n){
				for(j=0;j<n;j++) check[j] = false;
				for(j=0;j<n;j++){
					for(k=0;k<n;k++){
						if(check[k]) continue;
						for(p=0;p<=i;p++){
							if(s[j][p] != s2[k][p]) break;
						}
						if(p==i+1){
							check[k] = true;
							break;
						}
					}
					if(k==n){
						ch=1;
						break;
					}
				}
				if(ch){
					ch=0;
					ans++;
					for(j=0;j<n;j++){
						if(s[j][i]=='1') s[j][i] = '0';
						else s[j][i] ='1';
					}
					for(j=0;j<n;j++) check[j] = false;
					for(j=0;j<n;j++){
						for(k=0;k<n;k++){
							if(check[k]) continue;
							for(p=0;p<=i;p++){
								if(s[j][p] != s2[k][p]) break;
							}
							if(p==i+1){
								check[k] = true;
								break;
							}
						}
						if(k==n){
							ch=1;
							break;
						}
					}
				}
				if(ch) break;
			}
		}
		if(ch){
			printf("Case #%d: NOT POSSIBLE\n",t2);
			continue;
		}
		for(i=0;i<n;i++) check[i] = false;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(check[j]) continue;
				for(k=0;k<l;k++){
					if(s[i][k] != s2[j][k]) break;
				}
				if(k==l){
					check[j] = true;
					break;
				}
			}
			if(j==n){
				ch=1;
				break;
			}
		}
		if(ch){
			printf("Case #%d: NOT POSSIBLE\n",t2);
			continue;
		}
		else{
			printf("Case #%d: %d\n",t2,ans);
		}
	}
	return 0;
}