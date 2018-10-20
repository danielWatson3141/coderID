#include <iostream>
using namespace std;
int t[2000];
int main()
{
	int ilez;
	cin>>ilez;
	int suma1=0,suma2=0;
	for(int aa=0; aa<ilez; aa++)
	{
		int ile;
		cin>>ile;
		suma1=suma2=0;
		for(int n=0; n<ile; n++)
		{
			cin>>t[n];
		}
		for(int n=0; n<ile/2; n++)
		{
			suma1+=t[n];
			suma2+=t[n+ile/2];
		}
//		cout<<suma1<<" "<<suma2<<endl;
		cout<<"Case #"<<aa+1<<": ";
		if(suma1>suma2) cout<<"BAD"<<endl;
		else cout<<"GOOD"<<endl;
	}
}
