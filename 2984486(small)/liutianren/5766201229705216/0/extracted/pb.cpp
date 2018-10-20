#include <iostream>
#include <map>
//#include <iomanip>
using std::cin;
using std::cout;
using std::endl;

struct NS
{
public:
	bool assigned;
	int removed;
	int remained;
//public:
//	NS() : assigned(false){};
//	NS(bool b) : assigned(b){};
};

inline void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int removeNeed(std::map<int, NS>  * table, int N, int root, int child)
{
	NS& ret = table[root][child];
	if(ret.assigned == true){
		//cout<<"T"<<endl;
		return ret.removed;
	}
	//cout<<"flag"<<endl;
	//return 0;

	std::map<int, NS>& cmap = table[child];

	if(cmap.size() == 1)
	{
		ret.assigned = true;
		ret.removed = 0;
		ret.remained = 1;
	}
	else if(cmap.size() == 2)
	{
		auto it = cmap.begin();
		if((*it).first == root)
			++it;
		if((*it).second.assigned == false)
		{
			removeNeed(table, N, child, (*it).first);
		}
		ret.assigned = true;
		ret.removed = (*it).second.removed + (*it).second.remained;
		ret.remained = 1;
	}
	else if(cmap.size() >= 3)
	{
		int remainda = 0;
		int remaindb = 0;
		int removed = 0;
		for (auto it = cmap.begin(); it != cmap.cend(); ++it)
		{
			if((*it).first == root)
				continue;
			if((*it).second.assigned == false)
				removeNeed(table, N, child, (*it).first);
			removed += (*it).second.removed;
			int tr = (*it).second.remained;
			if(tr > remainda)
				swap(tr,remainda);
			if(tr > remaindb)
				swap(tr,remaindb);
			removed += tr;
		}
		ret.assigned = true;
		ret.removed = removed;
		ret.remained = 1 + remainda + remaindb;
	}
	return ret.removed;
}

int removeNeed(std::map<int, NS>  * table, int N, int root)
{
	std::map<int, NS>& cmap = table[root];

	if(cmap.size() == 0)
	{
		return 0;
	}
	else if(cmap.size() == 1)
	{
		return N-1;
	}
	else if(cmap.size() >= 2)
	{
		int remainda = 0;
		int remaindb = 0;
		int removed = 0;
		for (auto it = cmap.begin(); it != cmap.cend(); ++it)
		{
			if((*it).second.assigned == false)
				removeNeed(table, N, root, (*it).first);
			removed += (*it).second.removed;
			int tr = (*it).second.remained;
			if(tr > remainda)
				swap(tr,remainda);
			if(tr > remaindb)
				swap(tr,remaindb);
			removed += tr;
		}
		return removed;
	}
}

void game()
{
	unsigned int N;
	cin >>N;

	std::map<int, NS> *table = new std::map<int, NS>[N];

	for(int i=1; i<N; i++)
	{
		int a,b;
		cin >>a>>b;
		table[a-1][b-1].assigned = false;
		table[b-1][a-1].assigned = false;
		//table[a-1].at(b-1).assigned = false;
		//table[b-1].at(a-1).assigned = false;
	}
	
	int minRemove = N;
	for(int i=0; i<N; i++)
	{
		std::map<int, NS> &rmap = table[i];
		int removed = removeNeed(table, N, i);
		if(removed < minRemove)
			minRemove = removed;
		//cout<<i<<' '<<rmap.size()<<' '<<removed<<endl;
	}
	cout<< minRemove <<endl;
	delete[] table;
}

int main()
{
	int caseNum;
	cin >> caseNum;
	for(int t=1; t<=caseNum; t++)
	{
		cout<<"Case #"<<t<<": ";
		game();
	}
}
