#include<iostream>
#include<vector>
#include<math.h>
#include<map>
#include<algorithm>
std::vector<bool> bits(int n,int max)
{
	std::vector<bool> result;
	for(int i=0;i<max;++i)
		result.push_back(n&1<<i);
	return result;
}
bool possible(std::vector<std::string> a,std::vector<std::string> b)
{
	for(int i=0;i<a.size();++i)
		if(a[i]!=b[i])
			return false;
	return true;
}
int main()
{
	int T;
	std::cin>>T;
	int n=T;
	while(T--)
	{
		int N,L;
		std::cin>>N>>L;
		std::vector<std::string> initial(N);
		for(int i=0;i<N;++i)
			std::cin>>initial[i];
		std::vector<std::string> required(N);
		for(int i=0;i<N;++i)
			std::cin>>required[i];
		std::sort(required.begin(),required.end());
		int least=L+1;
		for(int i=0;i<pow(2,L)-0.5;++i)
		{
			auto b=bits(i,L);
			int count=0;
			for(int i=0;i<L;++i)
				if(b[i])
					count++;
			
			auto copy=initial;
			for(int i=0;i<N;++i)
			{
				for(int j=0;j<L;++j)
				{
					if(b[j]==true)
					{
// 						std::cout<<"f "<<i<<j<<std::endl;
						if(copy[i][j]=='0')
							copy[i][j]='1';
						else if(copy[i][j]=='1')
							copy[i][j]='0';
					}
				}
			}
			std::sort(copy.begin(),copy.end());
			
// 			for(int i=0;i<b.size();++i)
// 				std::cout<<b[i];
// 			std::cout<<std::endl;
// 			for(auto x:copy)
// 				std::cout<<x<<' ';
// 			std::cout<<std::endl;
// 			for(auto x:required)
// 				std::cout<<x<<' ';
// 			std::cout<<std::endl;
// 			std::cout<<std::endl;
			if(possible(copy,required))
				if(count<least)
					least=count;
		}
		
		if(least<=L)
			std::cout<<"Case #"<<n-T<<": "<<least<<std::endl;
		else
			std::cout<<"Case #"<<n-T<<": NOT POSSIBLE"<<std::endl;
		
	}
}