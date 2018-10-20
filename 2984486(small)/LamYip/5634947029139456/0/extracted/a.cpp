#include "stdio.h"
#include "iostream"
#include "stdlib.h"
#include "algorithm"
#include "math.h"
#include "string.h"
#include "stdlib.h"
#include "set"
#include "vector"
#include "queue"
#include "map"
#include "list"
#include "string"
using namespace std;
#define ll int
#define rep(i,n) for(ll i=0;i<n;i++)
#define all(x) x.begin(),x.end()
#define clr(a,b) memset(a,b,sizeof(a))
#define si(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
#define ss(x) scanf("%s",x)
#define sc(x) scanf("%c",&x)
#define line puts("");
#define IN freopen("i.txt","r",stdin);
#define OUT freopen("o.txt","w",stdout);
#define BITCOUNT(x) (((BX_(x)+(BX_(x)>>4)) & 0x0F0F0F0F) % 255)
#define BX_(x) ((x) - (((x)>>1)&0x77777777) \
- (((x)>>2)&0x33333333) \
- (((x)>>3)&0x11111111))
#define N 200
#define L 50
//lower_bound binary_search push_back insert

ll a,b,i,j,n,m,k,p[N],q,l,r,temp,T,ans,len,C,f[1<<16];
char str[N][L],tar[N][L];
int convert(char arr[]){
	int sum=0;
	rep(i,k){
		if(i)sum*=2;
		sum+=arr[i]-'0';
	}
	return sum;
}
void Filp(int num){
	int col=0;
	while(num){
		if(num%2){
			q++;
			rep(i,n){
				if(str[i][col]=='0')
					str[i][col]='1';
				else
					str[i][col]='0';			
			}
		}		
		col++;
		num/=2;
	}
}
bool check(){
	rep(i,n){if(!f[p[i]])return 0;f[p[i]]--;}
	return 1;
}
int main(){
	 // IN 
	 // OUT
	si(T);C=1;
	while(T--){
		printf("Case #%d: ",C++);
		clr(f,0);
		si(n);si(k);
		rep(i,n){
			ss(str[i]);
			f[convert(str[i])]++;
		}
		rep(i,n){
			ss(tar[i]);
			p[i]=convert(tar[i]);
		}
		if(check()){
			printf("0\n");		
		}
		else{
			ans=k;temp=0;
			rep(i,1<<k){
				q=0;
				Filp(i);
				clr(f,0);
				rep(i,n){f[convert(str[i])]++;}
				if(check()){
					temp=1;
					if(ans>q){
						ans=q;
					}
				} 
				Filp(i);
			}
			if(temp){
				printf("%d\n", ans);
			}
			else{
				printf("NOT POSSIBLE\n");
			}	
		}
	}
	return 0;
}














