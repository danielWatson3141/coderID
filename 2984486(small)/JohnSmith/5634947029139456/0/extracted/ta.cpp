//
// 2014 round 1a problem A
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

int bits( unsigned int m )
{
     if (m==0) return 0;
     return 1+bits(m&(m-1));
}

int solve( vector<string> r, vector<string> s )
{
     int e=100;

     unsigned int n = r.size();
     unsigned int kk = r.at(0).size();
     //cerr << "kk = " << kk << endl;

     sort(s.begin(), s.end());

     for (unsigned int m=0; m<1u<<kk; m++)
     {
	  vector<string> g;
	  for (unsigned int i=0; i<n; i++)
	  {
	       string gg;
	       for (unsigned int k=0; k<kk; k++)
	       {
		    //cerr << "i = " <<i << "  ";
		    //cerr << "k = " << k << " ";
		    //cerr << "kk = " << kk << endl;

		    if (r.at(i).at(k) == '0')
		    {
			 if (m&(1<<k))
			 {
			      gg += '1';
			 }
			 else
			 {
			      gg += '0';
			 }
		    }
		    else
		    {
			 if (m&(1<<k))
			 {
			      gg += '0';
			 }
			 else
			 {
			      gg += '1';
			 }
		    }
	       }
	       g.push_back(gg);
	  }

	  sort(g.begin(), g.end());

	  if (s==g && bits(m)<e)
	  {
	       e = bits(m);
	  }
     }
     if (e==100) e=-1;

     return e;
}


int main( int argc, char ** argv )
{
     unsigned int n;
     unsigned int i;

     cin >> n;

     for (i=1; i<=n; i++) {

	  unsigned int N;
	  unsigned int L;
	  cin >> N;
	  cin >> L;

	  vector<string> r(N);
	  vector<string> s(N);

	  for (auto &x : r) cin >> x;
	  for (auto &x : s) cin >> x;

	  if (0)
	  {
	       for (auto x : r) cerr << x << " ";
	       cerr << endl;

	       for (auto x : s) cerr << x << " ";
	       cerr << endl;
	       cerr << endl;
	  }

	  int e = solve(r, s);
	  
	  cout << "Case #" << i << ": ";
	  if (e>=0)
	       cout << e;
	  else
	       cout << "NOT POSSIBLE";
	  cout << endl;
     }

     return 0;
}

