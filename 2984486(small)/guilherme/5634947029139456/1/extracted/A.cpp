#include <cstdio>
#include <algorithm>
#include <set>
#include <cassert>
#include <string>
using namespace std;

char lam[250][250];
char tom[250][250];
int aux[250];
int n,l;

set <string> dict;
inline char troca (char a, int b){
  if (b==0)return a;
  if (b==1 && a=='0')return '1';
  if (b==1 && a=='1')return '0';
  throw "perdi";
}

int main () {
  int tt;
  scanf("%d",&tt);
  for (int pp=1;pp<=tt;pp++){
    scanf("%d %d",&n,&l);
    for(int i=0;i<n;i++)
      scanf(" %s", tom[i]);
    for(int i=0;i<n;i++)
      scanf(" %s", lam[i]);
    
    int ret = 0x3f3f3f3f;
    for(int i=0;i<n;i++) {//match lam[0] with tom[i]
      int at = 0;
     
      for(int j=0;j<l;j++){
	if(lam[0][j]!=tom[i][j]){at++; aux[j]=1;}
	else {aux[j]=0;}
      }
      if(at>=ret)continue;
      dict.clear();
      
      for(int j=0;j<n;j++){
	if(i==j)continue;
	string r = "";
	for(int k=0;k<l;k++){
	  r.push_back(troca(tom[j][k],aux[k]));
	}
	dict.insert(r);
      }

      assert((int)dict.size()==n-1);
      for(int j=1;j<n;j++){
	string r;
	for(int k=0;k<l;k++){
	  r.push_back(lam[j][k]);
	}

	if(dict.find(r)==dict.end()){
	  at = 0x3f3f3f3f;
	  break;
	}
      }

      ret = min(ret, at);

    }
    if(ret < 0x3f3f3f3f)
      printf("Case #%d: %d\n", pp, ret);
    else
      printf("Case #%d: NOT POSSIBLE\n",pp);
  }
  return 0;
}
