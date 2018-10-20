#include<math.h>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
struct Edge;
struct Node
{
	int id;
	Edge* head;
	bool visited;
	Node* parent;
	int familySize;
	int cost;
};
struct Edge
{
	Node* dest;
	Edge *next;
};
const int N=1100;
Node node[N];
Edge edge[2*N];
int nEdge;
void addEdge(int s,int t)
{
	edge[nEdge].dest=&node[t];
	edge[nEdge].next=node[s].head;
	node[s].head=&edge[nEdge];
	nEdge++;
}
void search(Node *current)
{
	if (current->visited)
	{
		return ;
	}
	current->visited=true;
	current->familySize=1;
	Edge *i,*j;
	int best=0;
	for (i=current->head;i;i=i->next)
	{
		Node *child=i->dest;
		if (child==current->parent)
		{
			continue;
		}
		child->parent=current;
		search(child);
		current->familySize+=child->familySize;
		best+=child->familySize;
	}
	for (i=current->head;i;i=i->next)
	{
		if (i->dest==current->parent)
		{
			continue;
		}
		for (j=i->next;j;j=j->next)
		{
			if (j->dest==current->parent)
			{
				continue;
			}
			int x=current->familySize-1-i->dest->familySize-j->dest->familySize+i->dest->cost+j->dest->cost;
			if (x<best)
			{
				best=x;
			}
		}
	}
	current->cost=best;
}
int main()
{
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	int t;
	scanf("%d",&t);
	int ti;
	for (ti=1;ti<=t;ti++)
	{
		int n;
		scanf("%d",&n);
		int i;
		for (i=0;i<n;i++)
		{
			node[i].id=i;
			node[i].head=0;
		}
		nEdge=0;
		for (i=0;i<n-1;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			a--;
			b--;
			addEdge(a,b);
			addEdge(b,a);
		}
		int ans=2147483647;
		int root;
		for (root=0;root<n;root++)
		{
			for (i=0;i<n;i++)
			{
				node[i].visited=false;
				node[i].parent=0;
				node[i].familySize=0;
				node[i].cost=0;
			}
			search(&node[root]);
			if (node[root].cost<ans)
			{
				ans=node[root].cost;
			}
		}
		printf("Case #%d: %d\n",ti,ans);
	}
	return 0;
}
