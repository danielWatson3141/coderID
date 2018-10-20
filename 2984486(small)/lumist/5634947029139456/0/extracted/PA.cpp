#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <stack>
#include <math.h>
#include <limits.h>
#define MAX(a,b) (a>b)?a:b
#define MIN(a,b) (a<b)?a:b
#define ABS(a) (a<0)?-a:a
#define EPS 0.000000001
using namespace std;


ifstream fin("in.in");
ofstream fout("out.out");

int T;
int N,L;
int first=-1;
int ans=INT_MAX;
__int64 power[41];
string out[150];
int OUT[150];
string need[150];
int NEED[150];

int Olen[41];
int Nlen[41];
int op[41];

bool ispossible(){
  int i,j,k,l,o;
  for(i=0;i<L;i++){
    k=0;
    l=0;
    for(j=0;j<N;j++)
      if(out[j][i]=='1')
        k++;
    Olen[i]=k;
    for(j=0;j<N;j++)
      if(need[j][i]=='1')
        l++;
    Nlen[i]=l;
    if(k!=l && k+l!=N)
      return false;
  }
  return true;
}

void opre(int cow){
  int i,j,k,l;
  if(cow==L){
    return;
  }
  if(N%2==0){
    if(Nlen[cow]!=Olen[cow])
      op[cow]=1;
    else{
      if(Nlen[cow]==N/2)
        op[cow]=2;
      else
        op[cow]=0;
    }
  }
  else{
    if(Nlen[cow]!=Olen[cow])
      op[cow]=1;
    else
      op[cow]=0;
  }
  opre(cow+1);
}

struct status{
  __int64 p[150];
}A,B;

__int64 quickmod(int k){
  __int64 a=1;
  int j=k;
  if(power[k]!=0)
    return (a=power[k]);
  while(k--){
    a*=2;
    power[j-k]=a;
  }
  return a;
}

int comp(const void*a,const void*b){
  return *((__int64*)a)-*((__int64*)b);
}

void convertO(){
  int i,j;
  __int64 AB=0;
  for(i=0;i<N;i++){
    AB=0;
    for(j=0;j<L;j++)
      AB+=(need[i][j]-48)*quickmod(L-j-1);
    A.p[i]=AB;
  }
  qsort(A.p,N,sizeof(A.p[0]),comp);
}

void convertN(){
  int i,j;
  __int64 AB=0;
  for(i=0;i<N;i++){
    AB=0;
    for(j=0;j<L;j++){
      if(op[j]==1)
        AB+=(49-out[i][j])*quickmod(L-j-1);
      else
        AB+=(out[i][j]-48)*quickmod(L-j-1);
    }
      
    B.p[i]=AB;
  }
  qsort(B.p,N,sizeof(B.p[0]),comp);
}

void DFS(int layer){
  int i,j;
  if(layer==L){
    convertO();
    convertN();
    for(i=0;i<N;i++){
      if(A.p[i]!=B.p[i])
        return;
    }
    int ANS=0;
    for(i=0;i<L;i++){
      if(op[i]==1)
        ANS++;
    }
    if(ANS<ans)
      ans=ANS;
    return;
  }
  
  if(op[layer]==2){
    if(first<0)
      first=layer;
    op[layer]=0;
    DFS(layer+1);
    op[layer]=1;
    DFS(layer+1);
    if(first<layer)
      op[layer]=2;
  }
  else
    DFS(layer+1);
}

int getans(){
  opre(0);
  DFS(0);
  return ans;
}

int main(){
  int i,j;
  fin>>T;
  for(i=1;i<=T;i++){
    fin>>N>>L;
    first=-1;
    ans=INT_MAX;
    for(j=0;j<N;j++)
      fin>>out[j];
    for(j=0;j<N;j++)
      fin>>need[j];
    
    fout<<"Case #"<<i<<": ";
    if(!ispossible())
      fout<<"NOT POSSIBLE"<<endl;
    else{
      getans();
      if(ans==INT_MAX)
        fout<<"NOT POSSIBLE"<<endl;
      else
        fout<<ans<<endl;
    }
      
  }
}

/*
8 10
1001101100 0110001100 0101000011 1010011110 0110101001 0010001110 0000111100 1000100011
0010100001 0010000100 1100001110 0001101110 0100010001 1110110011 1101000001 0110100011
1
2 7
1001101 0101100
0000100 1100101
1000101 0100100
1001101 0101100
*/