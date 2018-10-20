#include <fstream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
int N,L;
string fl[160], devices[160];
int check(string a, string b, int step)
{
  for (int i=0;i<=step; i++)
  {
    if (a[i]!=b[i]) return false;
  }
  return true;
}

int changeSol(string* flows, int step)
{
  sort(flows,flows+N);
  string newflow[160];
  for (int i=0;i<N;i++){
    newflow[i]=flows[i];
    if (newflow[i][step]=='1')newflow[i][step]='0'; else newflow[i][step]='1';
  }
  sort(newflow,newflow+N);
  bool wch=true,ch=true;
  for (int i=0;i<N;i++)
  {
    if (!check(flows[i],devices[i],step)) wch=false;
    if (!check(newflow[i],devices[i],step)) ch=false;
  }
  if (step==L-1)
  {
    if (wch) return 0;
    if (ch) return 1;
    return 170;
  }
  int reswch=170, resch=170;
  if (wch) reswch =changeSol(flows,step+1);
  if (ch) resch =changeSol(newflow,step+1)+1;
  return min(reswch, resch);
    
}

int main()
{
  ifstream f("input.txt");
  ofstream w("output.txt");
  int T;
  f>>T;
 
  for (int ti=1;ti<=T;ti++)
  {
    f>>N>>L;
    for (int i=0;i<N;i++)
      f>>fl[i];
    for (int i=0;i<N;i++)
      f>>devices[i];
    sort(devices,devices+N);
    int res = changeSol(fl,0);
    if (res>=170)
    w<<"Case #"<<ti<<": "<<"NOT POSSIBLE"<<endl;
    else
      w<<"Case #"<<ti<<": "<<res<<endl;
    
  }
  return 0;
}