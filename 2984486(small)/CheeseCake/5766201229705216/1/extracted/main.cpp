#include <vector>
#include <algorithm>
#include <deque>
#include <cstdio>
#include <utility>
using namespace std;

vector< vector<int> > voisins;

vector<int> parents;

typedef pair<int,int> pii;

pii tester_racine(int noeud, int parent )
{
  int tailletab = voisins[noeud].size() - 1 + (parent == -1); 
  vector<int> tarbreenfant(tailletab);
  vector<int> coutenfant = tarbreenfant;
  int index = 0;
  int sommetaille = 0;
  for(int i = 0; i < voisins[noeud].size(); i++)
  {
    if(voisins[noeud][i] == parent)
      continue;
    pii reponse = tester_racine(voisins[noeud][i], noeud);
    sommetaille += reponse.first;
    tarbreenfant[index] = reponse.first;
    coutenfant[index] = reponse.second;
    index++;
  }
  if( index == 0)
  {
    return make_pair(1,0);
  }
  if(index == 1)
  {
    return make_pair( 1 + sommetaille, sommetaille);
  }


  vector<int> scoreenfants(index);
  for(int i = 0; i < index; i++)
  {
    scoreenfants[i] = coutenfant[i] - tarbreenfant[i];
  }
  sort(scoreenfants.begin(), scoreenfants.end());
  return make_pair(1 + sommetaille, scoreenfants[0] + scoreenfants[1] + sommetaille);
}

void cas()
{
  int n;
  scanf("%d",&n);
  voisins.resize(0);
  voisins.resize(n);
  for(int i = 0; i < n-1; i++)
  {
    int a,b;
    scanf("%d%d", &a, &b);
    a--;b--;
    voisins[a].push_back(b);
    voisins[b].push_back(a);
  }
  int mini = n;
  for(int i = 0; i < n; i++)
  {
    mini = min(tester_racine(i,-1).second, mini);
  }
  printf("%d", mini);
  return;
}
int main()
{
  int tests;
  scanf("%d", &tests);
  for(int t = 1; t <= tests; t++)
  {
    printf("Case #%d: ", t);
    cas();
    printf("\n");
  }
  return 0;
}
