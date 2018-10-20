#include <cstdio>
#include <cstdlib>
#include <ctime>

int p[1000][300000];
int pref[1000];


bool bad(){
  for(int i=0;i<300000;i++){
  for(int k=0;k<1000;k++)
  p[k][i] = k;
  for(int k=0;k<1000;k++){
    int w = rand()%1000;
    int x=p[k][i];p[k][i]=p[w][i];p[w][i]=x;
    }
  return true;
  }
}


int main(){
  srand (time(NULL));
  int a,b;
  bad();
  scanf("%d",&a);
  for(int c=1;c<=120;c++){
    scanf("%d",&b);
    for(int j=0;j<1000;j++)
      scanf("%d",&pref[j]);

  bool ans;
  for(int a=0;a<300000;a++){
    ans=true;
    for(int k=0;k<1000;k++){if(p[k][a]!=pref[k]){ans=false;break;}}
    if(ans)break;
  }
  printf("Case #%d: %s\n",c,ans?"TRUE":"FALSE");
    
  }
  
  
}
