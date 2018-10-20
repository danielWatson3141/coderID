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

VS g, u;
int n, l;

int ile(int poz, int zmian)
{
  if (poz==l)
  {
    sort(g.begin(), g.end());
    if (g==u)
      return zmian;
    return 100;
  }
  int wyn=ile(poz+1, zmian);
  Fori(g.size())
    g[i][poz]=g[i][poz]=='0' ? '1' : '0';
  wyn=min(wyn, ile(poz+1, zmian+1));
  Fori(g.size())
    g[i][poz]=g[i][poz]=='0' ? '1' : '0';
  return wyn;
}

int main()
{
  int NNN;
  cin>>NNN;
  for (int ca=1; ca<=NNN; ++ca)
  {
    cin>>n>>l;
    g.clear();
    u.clear();
    Fori(n)
    {
      string s;
      cin>>s;
      g.push_back(s);
    }
    Fori(n)
    {
      string s;
      cin>>s;
      u.push_back(s);
    }
    sort(u.begin(), u.end());
    int wyn=ile(0, 0);
    cout<<"Case #"<<ca<<": ";
    if (wyn>=100) cout<<"NOT POSSIBLE\n";
    else cout<<wyn<<endl;
  }


  return 0;
}
