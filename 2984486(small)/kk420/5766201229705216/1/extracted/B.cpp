#include <algorithm>
#include <limits>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

const int MaxInt=numeric_limits<int>::max();
typedef vector<int> VI;
typedef vector<string> VS;
#define For(i,a,n) for (int i=a; i<n; ++i)
#define Fori(n) For(i,0,n)

struct W
{
  VI sad;
  int kosz[1001], lw[1001];
} w[1001];

int lwez(int kt, int bez)
{
  int &wyn=w[kt].lw[bez];
  if (wyn==-1)
  {
    wyn=1;
    Fori(w[kt].sad.size())
    {
      int sad=w[kt].sad[i];
      if (sad!=bez)
        wyn+=lwez(sad, kt);
    }
  } 
  return wyn;  
}

int koszt(int kt, int bez)
{
  W &ww=w[kt];
  int &wyn=ww.kosz[bez];
  if (wyn!=-1)
    return wyn;
  int ld=lwez(kt, bez)-1;
  wyn=ld;
  Fori(ww.sad.size())
    if (ww.sad[i]!=bez)
      for (int j=i+1; j<ww.sad.size(); ++j)
        if (ww.sad[j]!=bez)
          wyn=min(wyn, koszt(ww.sad[i], kt)+koszt(ww.sad[j], kt)+ld-lwez(ww.sad[i], kt)-lwez(ww.sad[j], kt));
  return wyn;
}

int main()
{
  int NNN;
  cin>>NNN;
  for (int ca=1; ca<=NNN; ++ca)
  {
    int n;
    cin>>n;
    Fori(1001)
    {
      w[i].sad.clear();
      memset(w[i].kosz, -1, sizeof(w[i].kosz));
      memset(w[i].lw, -1, sizeof(w[i].lw));
    }
    Fori(n-1)
    {
      int a, b;
      cin>>a>>b;
      --a;
      --b;
      w[a].sad.push_back(b);
      w[b].sad.push_back(a);
    }
    int wyn=n;
    Fori(n)
      wyn=min(wyn, koszt(i, 1000));
    cout<<"Case #"<<ca<<": "<<wyn<<endl;
  }


  return 0;
}
