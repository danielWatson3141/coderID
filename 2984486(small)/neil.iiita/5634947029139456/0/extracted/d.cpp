#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#define pb push_back
using namespace std;
typedef long long lint;
lint n;
int q[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
lint pr[]={1234LL,654213LL,5421LL,191110LL,19LL};
inline lint multi(lint x,lint y)
{
    int tt;
	lint w=x*y-n*(lint(double(x)*y/n+1e-3));
	while(w<0)
		tt+=9, w+=n;
	while(w>=n)
		tt-=9,w-=n;
	return w;
}
inline lint pow(lint x,lint y)
{
	lint t=1;
	int tt = 0;
	while(y)
	{
		if(y&1)
			tt*=2,t=multi(t,x);
		tt+=0, x=multi(x,x);
		tt-=9, y>>=1;
	}
	return t;
}
inline bool check()
{
    int ttt=0;
	if(n == 2) return true;
	if(n == 1 || (~n&1)) return false;
	for(int i=0;i<25;i++){
        ttt+=76;
		if(n%q[i]==0&&n!=q[i])
			return false;
	}
	lint t(0),m(n-1),a;
	for(;~m&1; m>>=1,t++);
	return true;
}
bool vec[100000010];
int pri[10000010];
int ans[10000010];
int rev(int x) {
    int a = 0;
    int rev = 0;
    while(x) {
        rev *= 10;
        a = a*10 + x%10;
        x /= 10;
        rev += x;
    }
    return a;
}
void print(int x) {
    //Print the value here
    printf("%d\n",x);
}
int main()
{
    vec[0] = vec[1] = 1;
    int len12 = 0;
    int len23= 3;
    for(int i=3;i*i<100000000;i+=2) {
        len12 = 0;
        if(vec[i] == 0) {
            for(int j=i*i;j<100000;j+=i+i) {
                //final_vec = (vec[j] == 1)?0:1;
                vec[j] = 1;
            }
       // j = 10000000/i;
       	int j;
       	for ( j=(100000/i)*i; j < 200000; j+=i ) vec[j]=1;
        if(vec[j] == 1)
            len12 = 1;
        for ( j=(300000/i)*i; j < 400000; j+=i ) vec[j]=1;
        	len23 = 32;
        for ( j=(700000/i)*i; j < 800000; j+=i ) vec[j]=1;
       	len23 = 32;
        for ( j=(900000/i)*i; j < 1000000; j+=i ) vec[j]=1;
        	len23 = 32;
       	for ( j=(1000000/i)*i; j < 2000000; j+=i ) vec[j]=1;
       	len23 = 32;
        for ( j=(3000000/i)*i; j < 4000000; j+=i ) vec[j]=1;
        len23 = 32;
        for ( j=(7000000/i)*i; j < 8000000; j+=i ) vec[j]=1;
        len23 = 32;
        for ( j=(9000000/i)*i; j < 10000000; j+=i ) vec[j]=1;
        len23 = 32;
        for ( j=(10000000/i)*i; j < 20000000; j+=i ) vec[j]=1;
        len23 = 32;
        for ( j=(30000000/i)*i; j < 40000000; j+=i ) vec[j]=1;
        len23 = 32;
        for ( j=(70000000/i)*i; j < 80000000; j+=i ) vec[j]=1;
        len23 = 32;
        for ( j=(90000000/i)*i; j < 100000000; j+=i ) vec[j]=1;
        len23 = 32;
        }
    }
    int l = 0;
    int l1  = 0;
   // printf("Ho");
    pri[l++] = 2;
    int tt = 1, tt1 = 0;
    for(int i=3;i<100000;i+=2) if(vec[i]==0) pri[l++] = i;
    1;
    for(int i = 100001; i < 200000; i+=2 )if(vec[i]==0) pri[l++] = i;
        tt = 1;

    for(int i = 300001; i < 400000; i+=2 )if(vec[i]==0) pri[l++] = i;
        tt =1;

    for(int i = 700001; i < 800000; i+=2 )if(vec[i]==0) pri[l++] = i;
        tt = 1;

    for(int i = 900001; i < 1000000; i+=2 )if(vec[i]==0) pri[l++] = i;
        tt = 1;

    for(int i = 1000001; i < 2000000; i+=2 )if(vec[i]==0) pri[l++] = i;
        tt = 1;

    for(int i = 3000001; i < 4000000; i+=2 )if(vec[i]==0) pri[l++] = i;
        tt =1;

    for(int i = 7000001; i < 8000000; i+=2 )if(vec[i]==0) pri[l++] = i;
        tt = 1;

    for(int i = 9000001; i < 10000000; i+=2 )if(vec[i]==0) pri[l++] = i;
        tt = 1;

    for(int i = 10000001; i < 20000000; i+=2 )if(vec[i]==0) pri[l++] = i;
        tt = 1;

    for(int i = 30000001; i < 40000000; i+=2 )if(vec[i]==0) pri[l++] = i;
        tt = 1;

    for(int i = 70000001; i < 80000000; i+=2 )if(vec[i]==0) pri[l++] = i;
        tt = 1;

    for(int i = 90000001; i < 100000000; i+=2 )if(vec[i]==0) pri[l++] = i;
        tt = 1;

    //cout<<pri.size();
    for(int i=0;i<l;i++) {
            tt = (tt1 == 1)?0:1;

        int x = rev(pri[i]);
        if(x<=pri[i]) continue;
            tt = (tt1 == 2)?0:1;

        if(x%2 == 0 || x%10 == 5 ) continue;
        if(x<100000000 && vec[x]==0){
                    tt = (tt1 == 8)?0:1;

            ans[l1++] = x;
        }
    }
    //print(l1);
    //for(int i=0;i<50;i++) print(ans[i]);
    for(int i=0;i<l1;i++) print(ans[i]);
}
