	#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
#include <map>
#include <list>
#include <locale>
#include <deque>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <cassert>
#include <climits>
#include <fstream>
#include <string>
#include<bits/stdc++.h>
    
#define pb push_back
#define mp make_pair
    #define clr(x) x.clear()
    #define sz(x) ((int)(x).size())
    #define F first
    #define S second
    #define rep(i,b) for(i=0;i<b;i++)
    #define rep1(i,b) for(i=1;i<=b;i++)
    #define mod 1000000007
    #define pi(n) printf("%d",n)
    #define pin(n) printf("%d\n",n)
    #define piw(n) printf("%d ",n)
    #define pll(n) printf("%lld",n)
    #define plln(n) printf("%lld\n",n)
    #define pllw(n) printf("%lld ",n)
    #define sll(n) scanf("%lld",&n)
    #define ss(s) scanf("%s",s)
    #define ps(s) printf("%s",s)
    #define psn(s) printf("%s\n",s)
    #define psw(s) printf("%s ",s)
    #define si(n) scanf("%d",&n)
    #define pn printf("\n")
    #define pw printf(" ")
    using namespace std;
	
	
	int scan_d()    {register int ip=getchar_unlocked(),ret=0,flag=1;for(;ip<'0'||ip>'9';ip=getchar_unlocked())if(ip=='-'){flag=-1;ip=getchar_unlocked();break;}for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return flag*ret;}
ld scan_ld()    {register int ip=getchar_unlocked(),flag=1;ld ret=0;for(;ip<'0'||ip>'9';ip=getchar_unlocked())if(ip=='-'){flag=-1;ip=getchar_unlocked();break;}for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return flag*ret;}
lld scan_lld()    {register int ip=getchar_unlocked(),flag=1;lld ret=0;for(;ip<'0'||ip>'9';ip=getchar_unlocked())if(ip=='-'){flag=-1;ip=getchar_unlocked();break;}for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return flag*ret;}
llu scan_llu()    {register int ip=getchar_unlocked();llu ret=0;for(;ip<'0'||ip>'9';ip=getchar_unlocked());for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return ret;}
void scan_str(bool &f)   {register char pr='\0',ip=getchar_unlocked();int flag=0;while(1){ if(ip=='\n') break; if(pr!='\0' && flag!=2){if(ip!=pr) flag++; else flag=0; if(flag==2) f=1;} pr=ip; ip=getchar_unlocked();} return;}  
//end of fast input
 
//fast output
 
//no line break
void print_d(int n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=10;char output_buffer[10];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<10);}
void print_ld(ld n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=11;char output_buffer[11];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<11);}
void print_lld(lld n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=21;char output_buffer[21];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<21);}
void print_llu(llu n)     {int i=21;char output_buffer[21];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<21);}
 
//new line
void println_d(int n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=10;char output_buffer[11];output_buffer[10]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<11);}
void println_ld(ld n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=11;char output_buffer[12];output_buffer[11]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<12);}
void println_lld(lld n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=21;char output_buffer[22];output_buffer[21]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<22);}
void println_llu(llu n)     {int i=21;char output_buffer[22];output_buffer[21]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<22);}
 
//special char
char sp;
void printsp_d(int n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=10;char output_buffer[11];output_buffer[10]=sp;do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<11);}
void printsp_ld(ld n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=11;char output_buffer[12];output_buffer[11]=sp;do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<12);}
void printsp_lld(lld n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=21;char output_buffer[22];output_buffer[21]=sp;do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<22);}
void printsp_llu(llu n)     {int i=21;char output_buffer[22];output_buffer[21]=sp;do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<22);}
 
	


 
int check(vector<int> a,vector<int> b)
{
    int i=a.size(),j=b.size();
    if(i!=j)
        return 0;
    for(i=0;i<j;i++)
        if(a[i]!=b[i])
        return 0;
    return 1;
}
int main()
{
 //   freopen("A-large.in","r",stdin);
   // freopen("op1.txt","w",stdout);
    int t;
    cin>>t;
    int q1=0;
 
    while(t--)
    {
        q1++;
        int n,l,i,j,k;
        cin>>n>>l;
        string init[n],fin[n];
        for(i=0;i<n;i++)
            cin>>init[i];
        for(i=0;i<n;i++)
            cin>>fin[i];
        int mark[n];
        memset(mark,0,sizeof(mark));
        vector<vector<int> > v[n];
        vector<int> v1,pos;
        vector<int>::iterator it;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                v1.clear();
                for(k=0;k<l;k++)
                {
                    if(init[i][k]!=fin[j][k])
                        v1.pb(k);
                }
                v[i].pb(v1);
            }
        }
        int q,w;
        int min=100;
        /*for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                cout<<"i= "<<i<<" j= "<<j<<"\n";
                for(k=0;k<v[i][j].size();k++)
                    cout<<v[i][j][k]<<" ";
                cout<<"\n";
            }
        }
        */
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                memset(mark,0,sizeof(mark));
                //if(v[i][j].size()<min)
                min=v[i][j].size();
                mark[j]=1;
                for(q=0;q<n;q++)
                {
                    if(q==i)
                        continue;
                    for(w=0;w<n;w++)
                    {
                        if(w==j)
                        continue;
                        if(mark[w]==0&&check(v[i][j],v[q][w])){
                            mark[w]=1;
                            break;
                        }
                    }
                }
                for(w=0;w<n;w++){
                    if(mark[w]==0)
                        goto ab;
                    }
                    pos.pb(min);
                    //cout<<i<<" "<<j<<"\n";
              ab: continue;
            }
        }
        if(pos.size()==0)
            printf("Case #%d: NOT POSSIBLE\n",q1);
        else
        {
            sort(pos.begin(),pos.end());
            printf("Case #%d: %d\n",q1,pos[0]);
            //cout<<pos[0]<<"\n";
        }
    }
    return 0;
}
 