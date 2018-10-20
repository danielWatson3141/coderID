#include<cstdio>
#include<vector>
#include<map>

using namespace std;

char tablets[151][151];
char outlets[151][151];

//long long is ok

long long tab[151];
long long out[151];


int score(long long int s){
  int r=0;
  while(s){if(!(s%2))s/=2; else{s--;r++;}  }
  return r;
}


int main(){
  int t;
  scanf("%d",&t);
  for(int c=1;c<=t;c++){
    int n,l;
    scanf("%d %d",&n,&l);

    for(int i=0;i<n;i++){
      scanf("%s",&tablets[i]);
      tab[i]=0;
      for(int j=0;j<l;j++){tab[i]+= (tablets[i][j]-48)*(1 << j); }
      }

    for(int i=0;i<n;i++){
      scanf("%s",&outlets[i]);
      out[i]=0;
      for(int j=0;j<l;j++){out[i]+= (outlets[i][j]-48)*(1 << j); }
      }    
      map<long long int,int> res;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
      res[tab[i] ^ out[j]]++;
    }
    
    int minscore=800;

    for(auto& x:res){
      if(x.second == n && score(x.first)<minscore){minscore=score(x.first);}
    }
    if(minscore==800)printf("Case #%d: NOT POSSIBLE\n",c);
    else printf("Case #%d: %d\n",c,minscore);


    
    
    
    
  }
  return 0;
}
