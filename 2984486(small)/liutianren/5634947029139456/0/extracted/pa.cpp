#include <iostream>
#include <map>
//#include <iomanip>
using std::cin;
using std::cout;
using std::endl;

typedef unsigned long long int64;

int64 readOne(int L)
{
	char buffer[50];
	cin >> buffer;
	long ret = 0;
	for(int i=0; i<L; i++)
	{
		ret = 2*ret + (buffer[i] == '1');
	}
	return ret;
}

int haming(int64 v)
{
	int weight = 0;
	while(v!=0)
	{
		if((v & 1) != 0)
			weight ++;
		v = v/2;
	}
	return weight;
}

void game()
{
	unsigned int N,L;
	cin >> N >> L;

	int64 *src = new int64[N];
	int64 *dst = new int64[N];

	for(int i=0; i<N; i++)
		src[i] = readOne(L);
	for(int i=0; i<N; i++)
		dst[i] = readOne(L);

	std::map<int64,int> log;

	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			log[src[i] ^ dst[j]] ++;
		}
	}

	delete[] src;
	delete[] dst;

	int minWeight = 1000;
	
	for(auto it = log.cbegin(); it != log.cend(); ++it)
	{
		if((*it).second == N)
		{
			int w = haming((*it).first);
			if(w < minWeight)
				minWeight = w;
		}
	}
	if(minWeight <= L)
		cout<< minWeight <<endl;
	else
		cout<< "NOT POSSIBLE"<<endl;
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
