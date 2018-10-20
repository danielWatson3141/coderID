#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <bitset>

using namespace std;

struct Edge{
Edge() {
}
Edge(int x1, int y1){
x = x1;
y = y1;
}

int x,y;
};

bool comp1(Edge e1, Edge e2) {
   if(e1.x < e2.x)
      return true;
   if(e1.x > e2.x)
      return false;
   return e1.y < e2.y;

}

bool addToSet(set<int> &s, int n, vector<vector<int> > &adj) {
   for(int i = 0; i < adj[n].size(); i++) {
      if(s.find(adj[n][i]) != s.end())
         return false;
      if(adj[n][i] == n)
         return false;
   }

   s.insert(n);
   for(int i = 0; i < adj[n].size(); i++) {
      addToSet(s, adj[n][i], adj);
   }

   return true;
}

bool check(set<int> &s, bitset<15> &b, vector<vector<int> > &adj, int n, int prev) {

   //count adj
   int count = 0;
   for(int i = 0; i < adj[n].size(); i++)
      if(adj[n][i]!=prev && b[adj[n][i]])
         count++;
   if(count!=0 && count!=2)
      return false;

   for(int i = 0; i < adj[n].size(); i++) {
      if(adj[n][i] == prev) continue;
      if(b[adj[n][i]] && s.find(adj[n][i]) != s.end())
         return false;
      if(adj[n][i] == n)
         return false;
   }

   s.insert(n);

   bool result = true;
   for(int i = 0; i < adj[n].size(); i++) {
      if(adj[n][i] == prev) continue;
      if(b[adj[n][i]])
         result = result && check(s,b,adj,adj[n][i], n);
   }

   return result;
}

void solve() {
   int N;
   cin >> N;

   vector<Edge> e(N-1);
   for(int i = 0; i < N-1; i++){
      cin >> e[i].x >> e[i].y;
      // index from 0
      e[i].x--; e[i].y--;
   }



   /*vector<int> counts;
   for(int i = 0; i < N; i++)
      counts.push_back(0);
   for(int i = 0; i < e.size(); i++) {
      counts[e[i].x]++;
      counts[e[i].y]++;
   }

   Set<int> curr;
   for(int i = 0; i < N; i++)
      if(counts[i]>0)
         curr.insert(i);*/


   // make adjacency lists
   vector<vector<int> > adj(N);
   for(int i = 0; i < e.size(); i++) {
      adj[e[i].x].push_back(e[i].y);
      adj[e[i].y].push_back(e[i].x);
   }

   // ?? connected components

   int best = 1;
   // for every node, use it as root make a tree
   /*for(int root = 0; root < N; root++) {
      // find largest set of nodes with 
      set s<int>;
      if(!addToSet(s,root,adj))
         continue;

      // make into binary tree



   }*/

   // try every possible subset
   for(int subset = 1; subset < (1 << N); subset++) {
      bitset<15> b(subset);
      for(int i = 0; i < N; i++) {
         if(!b[i])
            continue;
         set<int> s;
         if(check(s,b,adj,i, -1)){
            best = max((int)s.size(),best);
         }
      }
   }

   cout<< N-best;
}

int main() {

int t;
cin >> t;
for (int i = 0; i < t; i++) {
   cout << "Case #" << i+1 << ": "; 
   solve();
   cout << endl;
}


return 0;
}
