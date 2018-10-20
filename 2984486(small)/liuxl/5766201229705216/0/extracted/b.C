#include <iostream>
#include <cstdio>
#include <cmath>

#include <string>
#include <vector>
#include <set>
#include <map>

#include <algorithm>

using namespace std;

#define ll long long
#define pb push_back 

#define vT int
#define vit  vector<vT>::iterator 
#define vitr vector<vT>::reverse_iterator 

#define sT int
#define sit  set<sT>::iterator 
#define sitr set<sT>::reverse_iterator 

#define mT1 int
#define mT2 int
#define mit  map<int, vector<int> >::iterator 

int count(map<int, vector<int> >& m, const int i, set<int> s)
{
   const int fnd= s.find(i) != s.end();
   if(! fnd) return 0;
   else      s.erase(i);

   int ret= 1;
   const vector<int> &v= m[i];
   const int len= v.size();
   if(len <= 1 ) return 1;

   vector<int> vtem;
   for(int j=0; j!=len; j++)
   {
      int n= v[j];
      if(s.find(n) != s.end()) vtem.pb(count(m, n, s));
      sort(vtem.begin(), vtem.end());
   // reverse(vtem.begin(), vtem.end());
   }
   const int lll= vtem.size();
   if(lll == 1) return 1;

   ret+= vtem[lll- 1]+ vtem[lll- 2];
   return ret;
}

int main()
{
   int T;
   int N;
   cin >> T;
   map<int, vector<int> > m;
   set<int> s;

   for(int j=0; j!=T; j++)
   {
      cin >> N;
      int num= 0;
      m.clear();
      s.clear();
      int a, b;
      for(int k=0; k!=(N-1); k++)
      {
	 cin >> a >> b;
	 m[a].pb(b);
	 m[b].pb(a);
	 s.insert(a);
	 s.insert(b);
      }

      const int len= m.size();
      for(mit it=m.begin(); it!=m.end(); it++)
      {
	 const int key= it->first;
	 set<int> ss(s.begin(), s.end());
	 int sum= count(m, key, ss);
	 if(sum > num) num= sum;
      // cout << sum << " test " << key << " " << num << endl;
      }
      int minus= len- num;
      cout << "Case #" << (j+ 1)<< ": " << minus;
      cout << endl;
   }

   return 0;
}
