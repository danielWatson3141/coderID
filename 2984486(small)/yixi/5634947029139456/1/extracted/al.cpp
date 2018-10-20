#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
#define LL long long

int TT,n,L,match[200],ee[200],aa[200][200];
LL e[100],a[200],b[200];
string ss;
bool v[200];


struct reco{
	int i,j,cnt;
	LL dis;
}q[40000];

bool cmp(reco a, reco b){
	return a.cnt<b.cnt || (a.cnt==b.cnt && a.dis<b.dis);
}

int find(int x)
{
    for(int i=0; i<ee[x]; i++)
    {
		int y=aa[x][i];
        if(!v[y])
        {
            v[y]=1;
            if(match[y]==-1 || find(match[y]))
            {
                match[y] = x;
                return 1;
            }
        }        
    }
    return 0;
}

bool hasmatch(){
	for (int i=0; i<n; i++) match[i]=-1;
	int s=0;
	for(int i=0; i<n; i++)
    {
		for (int j=0; j<n; j++) v[j]=0;
        if(find(i)) s++;
		if (s>=n) return true;
    }
	return false;
}

int main(){
	scanf("%d",&TT);
	for (int TTT=1; TTT<=TT; TTT++){
		printf("Case #%d: ",TTT);
		scanf("%d%d",&n,&L);
		
		e[0]=1;
		for (int i=1; i<=L; i++) e[i]=e[i-1]*2;
		
		for (int i=0; i<n; i++) {
			cin>>ss;
			a[i]=0;
			for (int j=0; j<L; j++) a[i]+=e[j]*(ss[j]-'0');
		}
		for (int i=0; i<n; i++) {
			cin>>ss;
			b[i]=0;
			for (int j=0; j<L; j++) b[i]+=e[j](ss[j]-'0');
		}
		int m=0;
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++){
				LL dis = (a[i]^b[j]);
				int cnt=0;
				for (int k=0; k<L; k++) 
					if (dis&e[k]) cnt++;
				q[m].cnt=cnt;
				q[m].dis=dis;
				q[m].i=i;
				q[m].j=j;
				m++;
			}
		sort(q,q+m,cmp);
		q[m].cnt=-1; q[m].dis=-1;
	//	for (int i=0; i<m; i++) cout<<q[i].cnt<<" "<<q[i].dis<<" "<<q[i].i<<" "<<q[i].j<<endl;
		
		
		int best = L+1;
		int j=0;
		while (j<m){
			int k=j;
			while (q[k].cnt==q[j].cnt && q[k].dis==q[j].dis) k++;
			
			if (k-j>=n){
				for (int i=0; i<n; i++) ee[i]=0;
				for (int i=j; i<k; i++){
					int x=q[i].i, y = q[i].j;
					aa[x][ee[x]]=y; ee[x]++;
				}
				if (hasmatch()) {
					best = q[j].cnt;
					break; 
				}
			}
			j=k;
		}
		if (best>L) printf("NOT POSSIBLE\n");
		else printf("%d\n",best);
		
	}
}