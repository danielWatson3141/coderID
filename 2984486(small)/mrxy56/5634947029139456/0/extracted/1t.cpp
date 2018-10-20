#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char a[200][50],b[200][50],aa[200][50];
bool d[50];
int T,n,m;
bool judge(){
	for(int i=0;i<n;i++)
       for(int j=0;j<m;j++){
	    if(aa[i][j]!=b[i][j]) return false;
	}
	return true;
}
int cmp_string(const void * _a,const void * _b){
    char *a=(char*)_a;
	char *b=(char*)_b;
	return strcmp(a,b);
}
int main(){
	//freopen("A-small-attempt0.in","r",stdin);
	//freopen("A-small-attempt0.out","w",stdout);
	scanf("%d",&T);
	for(int kase=1;kase<=T;kase++){
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
			scanf("%s",a[i]);
		}
		for(int i=0;i<n;i++){
			scanf("%s",b[i]);
        }
		qsort(b,n,sizeof(b[0]),cmp_string);
		bool flag=false;
		for(int i=0;i<(1<<m);i++){
			int cnt=0;
			memset(d,0,sizeof(d));
			for(int j=0;j<m;j++)
				if((1<<j)&i){
					d[j]=true;
					cnt++;
				}
			for(int i=0;i<n;i++)
				for(int j=0;j<m;j++)
					aa[i][j]=a[i][j];
			for(int j=0;j<m;j++){
			    if(d[j]){
				    for(int i=0;i<n;i++)
						aa[i][j]=aa[i][j]=='0'?'1':'0';
				} 
			}
			qsort(aa,n,sizeof(aa[0]),cmp_string);
			if(judge()){
			    printf("Case #%d: %d\n",kase,cnt);
				flag=true;
				break;
			}
		}
        if(!flag) printf("Case #%d: NOT POSSIBLE\n",kase);
	}
	return 0;
}
