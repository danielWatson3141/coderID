#include<iostream>
int main()
{
	int T;
	std::cin>>T;
	int n=T;
	while(T--)
	{
		int N;
		std::cin>>N;
// 		std::vector<int> data(N);
		int count=0;
		for(int i=0;i<N;++i)
		{
			int x;
			std::cin>>x;
			if(x>=i-N/500 && x<=i+N/500)
				count++;
		}
		if(count>6)
			std::cout<<"Case #"<<n-T<<": BAD"<<std::endl;
		else 
			std::cout<<"Case #"<<n-T<<": GOOD"<<std::endl;
	}
}