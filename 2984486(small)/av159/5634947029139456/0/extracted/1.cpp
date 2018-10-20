#include<stdio.h>
#include<math.h>
#include<string.h>
#define mod 1000000
char a[152][42],b[152][42];
int ca[492],cb[492],n,l;

int fun(int p,int d){
	
	int i,j,k,s1=mod,s2=mod,flag,c;
	
	if(p==l){
		/*for(i=0;i<n;i++){
			for(j=0;j<l;j++)
				printf("%d",a[i][j]);
			printf(",");
		}
		printf("\n");
		for(i=0;i<n;i++){
			for(j=0;j<l;j++)
				printf("%d",a[i][j]);
			printf(",");
		}
		printf("\n");*/
		for(i=0;i<n;i++){
			c=0;
			for(j=0;j<n;j++){
				flag=0;
				for(k=0;k<l;k++){
					if(a[i][k]!=b[j][k]){
						flag=1;
						break;
					}
				}
				if(flag==0){
					c=1;
					break;
				}
			}
			if(c==0)
				return mod;
		}
		return d;
	}
	//printf("ca=%d,cb=%d\n",ca[p],cb[p]);
	if(ca[p]==cb[p])	
		s1=fun(p+1,d);
	if(ca[p]==(n-cb[p])){
		for(i=0;i<n;i++)
			a[i][p]=1-a[i][p];
		s2=fun(p+1,d+1);
		for(i=0;i<n;i++)
			a[i][p]=1-a[i][p];
	}
	if(s1<s2)
		return s1;//{printf("s1=%d\n",s1);return s1;}
	return s2;//{printf("s2=%d\n",s1);return s2;}
}

main()
{
	int z,t,i,j,ans;
	
	scanf("%d",&t);
	for(z=1;z<=t;z++)
	{
		scanf("%d %d",&n,&l);
		for(i=0;i<n;i++)
			scanf("%s",a[i]);
		for(i=0;i<n;i++)
			scanf("%s",b[i]);
		
		for(i=0;i<l;i++){ca[i]=0;cb[i]=0;}
		for(i=0;i<n;i++)
			for(j=0;j<l;j++){
				a[i][j]-='0';
				b[i][j]-='0';
			}
		
		for(j=0;j<l;j++){
			for(i=0;i<n;i++)
				ca[j]+=a[i][j];
			//printf("%d,",ca[j]);
		}
		//printf("\n");
		for(j=0;j<l;j++){
			for(i=0;i<n;i++)
				cb[j]+=b[i][j];
			//printf("%d,",cb[j]);
		}
		//printf("\n");
		ans=fun(0,0);
		if(ans==mod)
			printf("Case #%d: NOT POSSIBLE\n",z);
		else
			printf("Case #%d: %d\n",z,ans);
	}
	
	
	return 0;
}






