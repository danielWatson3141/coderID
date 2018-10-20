#include<stdio.h>

bool con[1000][1000]={0};
bool check[1000]={0};
int size[1000]={0};
int n;
void get_size(int idx){
	int i;
	check[idx] = true;
	size[idx] = 1;
	for(i=0;i<n;i++){
		if(!check[i] && con[idx][i]){
			get_size(i);
			size[idx] += size[i];
		}
	}
}
int make_bt(int idx){
	check[idx] = true;
	int i,t,sum=0;
	int ch1=-10000,ch2=-10000;
	for(i=0;i<n;i++){
		if(!check[i] && con[idx][i]){
			sum += size[i];
			t = make_bt(i);
			if(size[i]-t>=ch1){
				ch2 = ch1;
				ch1 = size[i]-t;
			}
			else if(size[i]-t>ch2){
				ch2 = size[i]-t;
			}
		}
	}
	if(ch1==-10000 && ch2==-10000) return 0;
	else if(ch2==-10000) return sum;
	else return sum-ch1-ch2;
}
int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	int t,t2,i,j,a,b,ans=10000;
	scanf("%d",&t);
	for(t2=1;t2<=t;t2++){
		ans = 100000;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			for(j=0;j<n;j++) con[i][j] = 0;
			size[i] = 0;
		}
		for(i=0;i<n-1;i++){
			scanf("%d%d",&a,&b);
			con[a-1][b-1] = con[b-1][a-1] = 1;
		}
		for(i=0;i<n;i++){
			for(j=0;j<n;j++) check[j] = false;
			get_size(i);
			for(j=0;j<n;j++) check[j] = false;
			a = make_bt(i);
			if(a < ans) ans = a;
		}
		printf("Case #%d: %d\n",t2,ans);
	}
	return 0;
}