#include<cstdio>
#include<cstring>
#include<vector>
#include<cassert>
using namespace std;
const int maxn = 1100;
int n;

int best[maxn][maxn];//make binary
int calc[maxn][maxn];//delete all tree cost
vector<int> grafo[maxn];

int cal(int a, int b){
  if(calc[a][b]!=-1)return calc[a][b];

  int ret = 1;
  for(auto i : grafo[a]){
    if(i==b)continue;
    ret += cal(i,a);
  }
  return calc[a][b]=ret;
}

int go(int a, int b){
  //  printf("%d %d\n",a,b);
  if(best[a][b]!=-1)return best[a][b];
  vector<int> x;
  int ret = 0;
  int m1=0,m2=0;
  for(auto i : grafo[a]){
    if(i==b)continue;
    ret += cal(i,a);
    int z = cal(i,a) - go(i,a);
    //    printf("%d %d %d %d\n" ,i,a,cal(i,a),go(i,a));
    assert(z>=0);
    if(z>m2)m2=z;
    if(m2>m1)swap(m1,m2);

    assert(m1>=m2);
    //    assert(m2==0 || m2>=z);

    x.push_back(z);
  }

  if(x.size()==0)return best[a][b]=0;
  if(x.size()==1)return best[a][b]=ret;
  assert(x.size()>=2);
  
  assert(ret>=(m1+m2));
  return best[a][b] = ret - m1 - m2;
  
}
int main (){
  int tt;
  scanf("%d",&tt);
  for(int pp=1;pp<=tt;pp++){
    scanf("%d",&n);

    for(int i=0;i<=n;i++)
      grafo[i].clear();

    memset(best,-1,sizeof(best));
    memset(calc,-1,sizeof(calc));

    for(int i=0;i<n-1;i++){
      int a,b;
      scanf("%d %d",&a,&b);
      a--,b--;
      grafo[a].push_back(b);
      grafo[b].push_back(a);
    }
    int ret = 0x3f3f3f3f;
    
    for(int i=0;i<n;i++)
      ret = min(go(i,n),ret);
    printf("Case #%d: %d\n",pp,ret);
  }
  return 0;
}
