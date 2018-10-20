#include <fstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <utility>
#include <vector>
using namespace std;
vector<int> a[1000];
 
int N;
int deletecount (int head, int from)
{
  int result=0;
  for (int i=0;i<a[head].size();i++)
  {
    if(a[head][i]!=from)result+=1+deletecount(a[head][i],head);
  }
  return result;
}

bool myfunction (pair<int,int> i,pair<int,int> j) { return (i.first<j.first); }
int makeSubTree(int head, int from)
{
 vector<int> del;
 vector<int> cr;
 vector<int> vrt;
 int count=a[head].size();
 if (from!=-1) count--;
 if (count==0) return 0;
 if (count==1) return deletecount(head,from);
 for (int i=0;i<a[head].size();i++){
   if (a[head][i]!=from){
     pair<int,int> it;
     it.first=deletecount(a[head][i],head);
     it.second=a[head][i];
      del.push_back(deletecount(a[head][i],head)+1);
      cr.push_back(makeSubTree(a[head][i],head));
      vrt.push_back(a[head][i]);
   }
 }
 if (count==2) return cr[0]+cr[1];
 int result=1024;
 for (int i=0;i<del.size();i++)
   for (int j=i+1;j<del.size();j++)
   {
     int res=0;
     res=cr[i]+cr[j];
     for (int k=0;k<del.size();k++)
       if (k!=i&&k!=j)res+=del[k];
     result=min(result,res);
   }
 return result;
}

int main()
{
  ifstream f("input.txt");
  ofstream w("output.txt");
  int T;
  f>>T;
 
  for (int ti=1;ti<=T;ti++)
  {
    f>>N;
    for (int i=0;i<N;i++)
      a[i].clear();
    for (int i=0;i<N-1;i++)
    {
      int st, fs;
      f>>st>>fs;
      a[st-1].push_back(fs-1);
      a[fs-1].push_back(st-1);
    }
    int res = 1024;
    for (int i=0;i<N;i++)
    res=min(res,makeSubTree(i,-1));
    w<<"Case #"<<ti<<": "<<res<<endl;
  }
  return 0;
}