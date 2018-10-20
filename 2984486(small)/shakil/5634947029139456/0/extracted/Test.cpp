#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<cstring>
#include<string>
#include<map>
using namespace std;

/*
void Vec()
{
	vector<int> A;  
	A.push_back(10);
	int n = A.size();
	A.clear();
	if(!A.empty())
	{
		int sum = 0;
		for(vector<int>::iterator it = A.begin();it != A.end();it++)
		{
			sum += *it;
		}

		vector<int>::iterator it = A.begin();
		A.erase(it);
		sort(A.begin(),A.end());
		it = max_element(A.begin(),A.end());
		it = min_element(A.begin(),A.end());
		A.insert(it,10);
		A.pop_back();
		int a = A.front();
		int b = A.back();
	}
}

void Pairs()
{
	pair<int,int> A;
	A.first = 10;
	A.second = 15;
}

void STRING()
{
	string a = "Hello";
	a = a + a;
	string b = a.substr(0,3);
	int t = a.find_first_of('a');
	cout<< a;
}

void SET()
{
	set<int> A;
	A.insert(10);
	A.erase(10);
	int t = A.count(10);
	set<int>::iterator it = A.find(10);
	it = A.upper_bound(10);//>10
	it = A.lower_bound(10);//<=10

	A.clear();
	if(!A.empty())
	{
		int sum = 0;
		for(set<int>::iterator it = A.begin();it != A.end();it++)
		{
			sum += *it;
		}
	}
}

void MAP()
{
	map<int,int> A;
	A[10]=20;
	A.erase(10);
	A.clear();
	A.size();
	map<int,int>::iterator it = A.find(10);

	if(!A.empty())
	{
		int sum = 0;
		for(map<int,int>::iterator it = A.begin();it != A.end();it++)
		{
			sum += it->second;
		}
	}
}

struct fun{
  int  xnode, weight;
  fun() {}
  fun(int t, int w) : xnode(t), weight(w) {}
  bool operator < (const fun &that) const {
    return weight > that.weight;
  }
};

void Priority_Queue()
{
	priority_queue<fun> q;
	q.top().weight;
	q.pop();
	q.push(fun(1,2));
	int i = q.size();
	if(!q.empty())
	{}
}
*/

	char A[200][50];
	char sak[200][50];
	char AA[200][50];
	int n,l;
	int B[200],C[200];

int BackTrack(int x)
{
	if(x==l)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<l;j++)
				AA[i][j]=(((A[i][j]-'0')+B[j])%2+'0');
			AA[i][l]=0;
			C[i]=0;
		}

		for(int i=0;i<n;i++)
		{
			int flag = 0;

			for(int j=0;j<n;j++)
				if(C[j]==0 && strcmp(sak[i],AA[j])==0)
				{
					C[j]=1;
					flag = 1;
					break;
				}

				if(flag == 0)
					return -1;
		}

		return 0;
	}
	else
	{
		B[x] = 0;
		int k = BackTrack(x+1);

		B[x] = 1;
		int p1 = BackTrack(x+1);

		if(k==-1&&p1==-1)
			return -1;
		else if(k==-1)
			return p1+1;
		else if(p1==-1)
			return k;
		else if(k<p1+1)
			return k;
		else
			return p1+1;
	}
}

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	int cas;

	scanf("%d",&cas);

	for(int cas1=1;cas1<=cas;cas1++)
	{
		scanf("%d %d",&n,&l);

		for(int i=0;i<n;i++)
			scanf("%s",A[i]);

		for(int i=0;i<n;i++)
			scanf("%s",sak[i]);

		int t = BackTrack(0);

		if(t == -1)
			printf("Case #%d: NOT POSSIBLE\n",cas1);
		else
			printf("Case #%d: %d\n",cas1,t);

	}

	return 0;    
}
