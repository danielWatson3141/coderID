#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
const int maxn = 1500;
pair <int,int> fixed[maxn];
int gaga[maxn];
int main(){
  int tt=1;
  scanf("%d",&tt);
  for(int pp=0;pp<tt;pp++){
    int n;
    scanf("%d",&n);
    
    int r = 0;
    int lista[maxn];
    for (int i=0;i<n;i++){
      scanf("%d",&lista[i]);
      if(i>0 && lista[i]==lista[i-1]+1){
	r++;
      }
    }
    //    printf("%d\n",r);
    fixed[pp]=make_pair(r,pp);
  }

  sort(fixed,fixed+tt);
  for(int i=0;i<60;i++){
    gaga[fixed[i].second]=1;
  }
  //  printf("%d\n" ,tt);
  for(int i=0;i<tt;i++){
   
    if (gaga[i]==1)
      printf("Case #%d: GOOD\n",i+1);
    else
      printf("Case #%d: BAD\n",i+1);
  }
  return 0;
}
