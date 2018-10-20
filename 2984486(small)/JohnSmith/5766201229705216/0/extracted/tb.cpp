//
// 2014 round 1a problem B
//
// John Smith
//
// Usually built with g++ 4.4.5 on Linux
//
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <queue>
#include <map>

using namespace std;

typedef pair<unsigned int,unsigned int> pii;

vector<vector<unsigned int> > g;

unsigned int nodes_in_tree( unsigned int r, unsigned int f );

unsigned int nodes_to_delete( unsigned int r, unsigned int f )
{
     unsigned int s=0;
     for (auto k : g.at(r))
     {
	  if (k != f) s++;
     }
     if (s==0) return 0;
     
     vector<pii> nt;

     for (auto k : g.at(r))
     {
	  if (k != f)
	  {
	       nt.push_back(make_pair(nodes_to_delete(k,r),
				      nodes_in_tree(k,r)));
	  }
     }
     if (nt.size() ==1) {
	  //cerr << "nodes_to_delet (" << r+1 << "," << f+1 << ") = " << nt.at(0).second << endl;
	  return nt.at(0).second;
     }

     sort(nt.begin(), nt.end());

     //cerr<< "UU ";
     //for (auto x : nt) cerr << x.first << "," << x.second << " "; cerr << endl;

     s=0;
     for (unsigned int i=0; i<nt.size()-2; i++)
     {
	  s += nt.at(i).second;
     }
     s += nt.at(nt.size()-2).first;
     s += nt.at(nt.size()-1).first;

     unsigned int ss=0;
     for (unsigned int i=0; i<nt.size(); i++)
     {
	  ss += nt.at(i).second;
     }
     unsigned int j0, j1;
     unsigned int sss_min = 1000000;
     for (j0=0; j0<nt.size(); j0++)
     {
	  for (j1=j0+1; j1<nt.size(); j1++)
	  {
	       unsigned int sss=ss;
	       sss -= nt.at(j0).second;
	       sss -= nt.at(j1).second;
	       sss += nt.at(j0).first;
	       sss += nt.at(j1).first;
	  
	       if(0 && sss < s) {
		    cerr << "Wrong choice" << endl;
		    cerr<< "s = " << s << endl;
		    cerr<< "sss = " << sss << endl;
	       }
	       if (sss < sss_min) sss_min = sss;
	  }
     }

     //cerr << "nodes_to_delete(" << r+1 << "," << f+1 << ") = " << s << endl;
     return sss_min;
}

unsigned int nodes_in_tree( unsigned int r, unsigned int f )
{
     unsigned int s=1;
     for (auto k : g.at(r))
     {
	  if (k != f)
	  {
	       s += nodes_in_tree(k,r);
	  }
     }
     //cerr << "nodes_in_tree(" << r+1 << "," << f+1 << ") = " << s << endl;
     return s;
}
	       
unsigned int counter( unsigned int r )
{
     return nodes_to_delete(r,1000000);
}

unsigned int solve()
{
     vector<unsigned int> v;
     for (unsigned int j=0; j<g.size(); j++)
     {
	  unsigned int a = counter(j);
	  //cerr << "G" << j+1 << " - " << a << endl;
	  v.push_back(a);
     }
     return *min_element(v.begin(), v.end());
}

int main( int argc, char ** argv )
{
     unsigned int t;
     unsigned int i;

     cin >> t;

     for (i=1; i<=t; i++) {

	  unsigned int n;
	  cin >> n;
	  
	  g.resize(n);
	  for (auto &r : g) r.resize(0);

	  for (unsigned int i=0; i<n-1; i++)
	  {
	       unsigned int x1, x2;
	       cin >> x1 >> x2;
	       x1--;
	       x2--;
	       g.at(x1).push_back(x2);
	       g.at(x2).push_back(x1);
	  }

	  unsigned int r = solve();

	  cout << "Case #" << i << ": ";
	  cout << r;
	  //cout << " " << n;
	  cout << endl;
     }
     
     return 0;
}

