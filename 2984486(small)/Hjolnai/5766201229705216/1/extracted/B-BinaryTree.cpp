#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <queue>

using namespace std;
vector<bool> seen;
vector<vector<int> > edge_list;	//first: start of edge. value: end of edge.
pair<int, int> costs(int ind)
{
	int costdel=1, costkeep=0;
	vector<int> costsdel, costskeep;
	vector<pair<int, pair<int, int> > > best_keeps;
	for(int i=0; i<edge_list[ind].size(); i++)
	{
		if(!seen[edge_list[ind][i]])
		{
			seen[edge_list[ind][i]]=true;
			pair<int, int> cs=costs(edge_list[ind][i]);
			costsdel.push_back(cs.first);
			costskeep.push_back(cs.second);
			best_keeps.push_back(make_pair(cs.first-cs.second, cs));
			costdel+=cs.first;
		}
	}
	sort(best_keeps.begin(), best_keeps.end());
	if(costskeep.size()>1)	//if it's possible to have two children
		costkeep=costdel-1-best_keeps[best_keeps.size()-1].first-best_keeps[best_keeps.size()-2].first;
	else
		costkeep=costdel-1;
	return make_pair(costdel, costkeep);
}
int main()
{
	//Algorithm is simple: For each node, assume it is the root. How many deletions needed? Just propagate recursively, where the total cost is:
	//All subtrees: How many nodes can they keep? Take the best 2. Subtract this value from the total nodes they have, and you get the cost.
	int T;
	cin>>T;
	for(int t=0; t<T; t++)
	{
		int N;
		cin>>N;
		int cost=N-1;
		edge_list.resize(0);
		edge_list.resize(N);
		for(int i=0; i<N-1; i++)
		{
			int t1, t2;
			cin>>t1>>t2;
			edge_list[t1-1].push_back(t2-1);
			edge_list[t2-1].push_back(t1-1);
		}
		for(int i=0; i<N; i++)	//Starting at node i
		{
			seen.resize(0);
			seen.resize(N, false);
			seen[i]=true;
			cost=min(cost, costs(i).second);
		}
		cout<<"Case #"<<t+1<<": "<<cost<<endl;
	}
	return 0;
}