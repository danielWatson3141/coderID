#include <vector>
#include <algorithm>
#include <fstream>
#include <list>


using namespace std;

ifstream ein;
FILE * aus;
int TestCase;

int N;
vector<vector<pair<int,int>>> tree(1000);

void doit(int x,int y)
{
	int nb = 1;
	for (int k=0;k<tree[y].size();k++)
	{		
		if (tree[y][k].first != x) 
		{
			if (tree[y][k].second == 0)
				doit(y,tree[y][k].first);
			nb += tree[y][k].second;
		}
	}
	for (int k=0;k<tree[x].size();k++)
	{
		if (tree[x][k].first == y)
			tree[x][k].second = nb;
	}
}

int dobin(int x,int y)
{
	if (tree[y].size() == 1)
	{
		return 0;
	}
	if ((x>=0) && (tree[y].size() == 2))
	{
		for (int k=0;k<tree[y].size();k++)
		{
			if (tree[y][k].first != x)
				return tree[y][k].second;
		}
	}
	int sm1 = -1;
	int sm2 = -1;

	for (int k=0;k<tree[y].size();k++)
	{
		if (tree[y][k].first != x)
		{
			if (sm1 == -1)
				sm1 = k;
			else
			{
				if (tree[y][k].second > tree[y][sm1].second)
					sm1 = k;
			}
		}
	}
	for (int k=0;k<tree[y].size();k++)
	{
		if ((tree[y][k].first != x) && (k != sm1))
		{
			if (sm2 == -1)
				sm2 = k;
			else
			{
				if (tree[y][k].second > tree[y][sm2].second)
					sm2 = k;
			}
		}
	}
	int bd = 0;
	for (int k=0;k<tree[y].size();k++)
	{
		if ((tree[y][k].first != x) && (k != sm1) && (k!=sm2))
		{
			bd += tree[y][k].second;
		}
	}
	int db1 = dobin(y,tree[y][sm1].first);
	int db2 = dobin(y,tree[y][sm2].first);
	return bd + db1 + db2; 
}


void start()
{
	int result;
	// read test case
	ein >> N;
	for (int n=0;n<N;n++)
		tree[n].clear();
	for (int n=0;n<N-1;n++)
	{
		int x,y;
		ein >> x >> y;
		tree[x-1].push_back(make_pair(y-1,0));
		tree[y-1].push_back(make_pair(x-1,0));
	}
	for (int x=0;x<N;x++)
	{
		for (int k=0;k<tree[x].size();k++)
		{
			if (tree[x][k].second == 0)
				doit(x,tree[x][k].first);
		}
	}
	result = 11111;
	for (int rt=0;rt<N;rt++)
	{
		if (tree[rt].size()>=2)	// possible root
		{
			result = min(result, dobin(-1,rt));
		}
	}
	
	if (N==2)
		result = 1;
	// output result
    fprintf(aus, "Case #%d: %d\n", TestCase, result);
}

void main()
{
	int NumTestCases;	
	ein.open("B-large.in");
	//ein.open("b-practice-small0.in");
	//ein.open("b-large.in");
	aus = fopen("out-b.txt","w");
	
	ein >> NumTestCases;
	for (TestCase = 1; TestCase <= NumTestCases; TestCase++)
		start();

	fclose(aus);
	ein.close();
}
