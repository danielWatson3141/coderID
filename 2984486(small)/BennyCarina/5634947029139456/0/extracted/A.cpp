#include<iostream>
#include<math.h>
#include<vector>
#include<set>
#include<algorithm>
#include<string>
using namespace std;

#define d_pi 57.2957795
#define LL long long
#define LarN 200
int L,N;
LL getbin(){
	LL tmp=0;
	char a;
	for(int i=1;i<=L;i++){
		scanf("%c",&a);
	if(a=='1'){
		tmp<<=1;
		tmp |=1;
	}
	else{
		tmp<<=1;
	}
	}
	scanf("%c",&a);
	return tmp;
}

LL S[LarN],D[LarN];
void init(){
	cin>>N>>L;
	char a;
	scanf("%c",&a);
	for(int i=0;i<N;i++){
		LL tmp=getbin();
		S[i]=tmp;
	}
	for(int i=0;i<N;i++){
		LL tmp=getbin();
		D[i]=tmp;
	}
}
int getans(){
	int ans=1000;
	sort(D,D+N);
	LL T[LarN];
	
	for(int i=0;i<(1<<L);i++){
		for(int j=0;j<N;j++)T[j]=S[j]^LL(i);
		sort(T,T+N);
		bool flag=true;
		for(int j=0;j<N;j++){
			if(T[j]!=D[j]){
				flag=false;
				break;
			}
		}
		if(flag){
			int tmp=i;
			int ta=0;
			while(tmp>0){
				if(tmp&1){
					ta++;
				}
				tmp>>=1;
			}
			if(ta<ans)ans=ta;
		}
	}
	return ans;
}
		

int main(){
	freopen("in.in","r",stdin);
	freopen("out.txt","w",stdout);
	int T_case;

	cin>>T_case;
	for(int i_case=1;i_case<=T_case;i_case++){
		init();
		int ans=getans();
		if(ans>L){
			printf("Case #%d: NOT POSSIBLE\n",i_case);
		}
		else printf("Case #%d: %d\n",i_case,ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}