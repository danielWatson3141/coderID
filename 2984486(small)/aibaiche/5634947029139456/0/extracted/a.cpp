#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <map>

#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#define debug
#define lp(i,n) for(int i=0;i<n;i++)
#define lpb(i,n) for(int i=1;i<=n;i++)
#define _max 12
#define inf 0xfffffff
using namespace std;
FILE *fin,*fout = NULL;
int getmax(int a,int b){
  return a>b? a : b;
}
int getmin(int a,int b){
  return a<b?a:b;
}
char out[160][45];
char in[160][45];
int bl[160],ii[160];

int t,l,n,sum;

int cal_out(int i){
  int ss=0;
  lp(j,n){
    if(out[j][i]=='1') ss++;
  }
  return ss;
}
int cal_in(int i){
  int ss=0;
  lp(j,n){
    if(in[j][i]=='1') ss++;
  }
  return ss;
}
void change(int i){
  lp(j,n){
    if(out[j][i]=='1') out[j][i]='0';
    else if(out[j][i]=='0') out[j][i]='1';
  }
}
bool ise(int i,int j){
  lp(k,l){
    if(out[i][k] != in[j][k]){return false;}
  }
  return true;
}
bool valid(){
    int tem = 0;
       
       memset(ii,0,sizeof(ii));
       bool flag=false;
       lp(i,n) {
          if(flag){tem=-1; break;}
          flag = true;
          lp(j,n){
            if(ii[j]==0)
              if(ise(i,j)){ 
                ii[j]=1;flag=false;break;
              }
          }
       }
    if(tem==-1) return false;
    else return true;
}

bool cal(int x){
     if(x==l) return valid();
     
     if(valid()) return true;
     if(bl[x]==0) return cal(x+1);
     
     if(cal(x+1)) return true;
     change(x); 
     sum++;
     if( cal(x+1) ) return true;
     else{change(x); sum--; return false;}
     
}
int main(){

    
    fout= fopen("out.txt","w");
    fin = fopen("A-small-attempt4.in","r");
    //fin = fopen("A-large.in","r");

    fscanf(fin,"%d",&t);
    lpb(kk,t){
       fscanf(fin,"%d%d",&n,&l);
       lp(i,n){ fscanf(fin,"%s",out[i]); }
       lp(i,n){ fscanf(fin,"%s",in[i]); }

       sum = 0;
        memset(bl,0,sizeof(bl));
       lp(i,l){
          int ooo =cal_out(i);
          int iii = cal_in(i);
          if(kk==4){cout<<ooo<<" "<<iii<<endl;}
          if(ooo==iii){
            bl[i]=1;
          }else if(ooo+iii==n){
            change(i);
            sum++;
          }else{
            sum=-1; //if(kk==4)cout<<i<<endl;
            break;
          }   
       }
       if(sum==-1){
        fprintf(fout,"Case #%d: NOT POSSIBLE\n",kk);
        continue;
        }
       //cout<<sum<<endl;
       
       if(kk==4)
       for(int x=0;x<n;x++){
       printf("%s ",out[x]);
       printf("%s\n",in[x]);}
       
       
       if(cal(0))
        fprintf(fout,"Case #%d: %d\n",kk,sum);
       else
         fprintf(fout,"Case #%d: NOT POSSIBLE\n",kk);
         
       //for(int x=0;x<n;x++){
       //fprintf(fout,"%s ",out[x]);
       //fprintf(fout,"%s\n",in[x]);}
    }
    fclose(fin);
    fclose(fout);
    system("pause");
    return 0;
}



