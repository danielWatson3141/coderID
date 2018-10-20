#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char a[200][50],b[200][50],aa[200][50];
bool d[50];
bool visit[200];
int T,n,m;
bool check(int x,int y){
    for(int i = 0;i<m;i++){
        if(aa[x][i] != b[y][i])return false;
    }return true;
}
bool judge(){
	memset(visit,false,sizeof(visit));
	for(int i = 0;i<n;i++){
        bool flag = false;
        for(int j = 0;j<n;j++){
            if((!visit[j]) && check(i,j)){
                visit[j] = true;
                flag = true;
                break;
            }
        }
        if(!flag)return false;
	}
	return true;
}
int cmp_string(const void * _a,const void * _b){
    char *a=(char*)_a;
	char *b=(char*)_b;
	return strcmp(a,b);
}
int main(){
	//freopen("A-small-attempt7.in","r",stdin);
	//freopen("out.out","w",stdout);
	scanf("%d",&T);
	for(int kase=1;kase<=T;kase++){
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
			scanf("%s",a[i]);
		}
		for(int i=0;i<n;i++){
			scanf("%s",b[i]);
        }
		//qsort(b,n,sizeof(b[0]),cmp_string);
		bool flag=false;
		int ans = n;
		for(int i=0;i<(1<<m);i++){
			int cnt=0;
			memset(d,0,sizeof(d));
			for(int j=0;j<m;j++)
				if((1<<j)&i){
					d[j]=true;
					cnt++;
				}
			for(int f=0;f<n;f++)
				for(int j=0;j<m;j++)
					aa[f][j]=a[f][j];
			for(int j=0;j<m;j++){
			    if(d[j]){
				    for(int f=0;f<n;f++)
						aa[f][j]= (a[f][j]=='0'?'1':'0');
				}
			}
			//qsort(aa,n,sizeof(aa[0]),cmp_string);
			if(judge()){
			    //printf("Case #%d: %d\n",kase,cnt);
				flag=true;
				ans = min(ans , cnt);
				//break;
			}
		}
        if(!flag) printf("Case #%d: NOT POSSIBLE\n",kase);
        else printf("Case #%d: %d\n",kase,ans);
	}
	return 0;
}
