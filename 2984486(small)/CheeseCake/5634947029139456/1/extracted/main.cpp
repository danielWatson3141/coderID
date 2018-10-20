#include <cstdio>
#include <algorithm>
#include <deque>
#include <vector>
#include <cstdlib>
using namespace std;

vector<int> probleme;
vector<int> probleme2;
int n, l;



int dfs(int index)
{
  if(index == l)
    return 0;
  int reponsefinale = -1;
  vector< vector<int> > prefixes1;
  vector< vector<int> > prefixes2;

  for(int i = 0; i < n; i++)
  {
    prefixes1.push_back( vector<int>(probleme.begin() + i*l, probleme.begin() + i*l + index + 1));
    prefixes2.push_back( vector<int>(probleme2.begin() + i*l, probleme2.begin() + i*l + index + 1));
  }
  sort(prefixes1.begin(), prefixes1.end());
  sort(prefixes2.begin(), prefixes2.end());

  bool reponse = true;
    if(! equal( prefixes1.begin(), prefixes1.end(), prefixes2.begin()))
    {
      reponse = false;
    }
  if(reponse)
  {
    int valeur = dfs(index + 1);
    reponsefinale = valeur;
  }
  prefixes1.resize(0);
  prefixes2.resize(0);
  for(int i = 0; i < n; i++)
  {
    probleme[i*l + index] = 1 - probleme[i*l + index];
  }
  for(int i = 0; i < n; i++)
  {
    prefixes1.push_back( vector<int>(probleme.begin() + i*l, probleme.begin() + i*l + index + 1));
    prefixes2.push_back( vector<int>(probleme2.begin() + i*l, probleme2.begin() + i*l + index + 1));
  }
  sort(prefixes1.begin(), prefixes1.end());
  sort(prefixes2.begin(), prefixes2.end());

  reponse = true;
    if(! equal( prefixes1.begin(), prefixes1.end(), prefixes2.begin()))
    {
      reponse = false;
    }
  if(reponse)
  {
    int valeur = dfs(index + 1);
    if(reponsefinale != -1)
    {
      if(valeur != -1 && valeur + 1< reponsefinale)
	reponsefinale = valeur + 1;
    }
    else if (valeur != -1)
      reponsefinale = valeur + 1;
  }
  for(int i = 0; i < n; i++)
  {
    probleme[i*l + index] = 1 - probleme[i*l + index];
  }
  return reponsefinale;

}


void un_test()
{
  scanf("%d%d", &n, &l);
  probleme.resize(n*l);
  probleme2.resize(n*l);
  vector<int> permutation(l);
  for(int i = 0; i < l; i++)
  {
    permutation[i] = i;
  }
  for(int i = 0; i < l; i++)
  {
    int index = rand() % (l - i);
    swap(permutation[i], permutation[i+index]);
  }

  char temp[50];
  for(int i = 0; i < n; i++)
  {
    scanf("%s", temp);
    for(int j = 0; j < l; j++)
    {
      probleme[i*l + j] = temp[permutation[j]] - '0';
    }
  }
  for(int i = 0; i < n; i++)
  {
    scanf("%s", temp);
    for(int j = 0; j < l; j++)
    {
      probleme2[i*l + j] = temp[permutation[j]] - '0';
    }
  }
  int reponse = dfs(0);
  if(reponse == -1)
  {
    printf("NOT POSSIBLE");
  }
  else
    printf("%d", reponse);
  return;


}

int main()
{

  int t;
  srand(42);
  scanf("%d",&t);
  for(int i = 1; i <= t; i++)
  {

    printf("Case #%d: ",i);
    un_test();
    printf("\n");
  }
  return 0;
}
