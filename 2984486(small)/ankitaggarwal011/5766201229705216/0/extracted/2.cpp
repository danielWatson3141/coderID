#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int nod, cases=0;

	int uses;
	int *ed;
	
	int *dr;

	cin >> uses;
	bool flagged = true;

	while(uses > 0)
	{
		
		cases++;
		int delete=0;
		int count1 = 0;
		

		flagged= false;
		cin >> nod;
		ed = (int *)malloc(sizeof(int)*(2*nod-1));
		dr = (int *)malloc(sizeof(int)*(2*nod-1));
		for(int i=0;i<2*(nod-1);i++)
		{
			cin >> ed[i];
		}
		for(int i=0;i<2*(nod-1);i++)
		{
			int count=0;
			bool flag = true;
			for(int j=0;j<2*(nod-1);j++)
			{
				for(int k=0;k<count1;k++)
				{
					if(ed[i] == dr[k])
					{
						flag = false;
					}
				}
				if(ed[i] == ed[j] && flag)
				{
					count++;
				}
			}
			if(count>2)
			{
				delete++;
			//	cout << ed[i] << " " ;
				dr[count1++] = ed[i];
			}
		}

		int temp = nod-delete;
		int power=2;
		while(temp >= power+1)
		{
			power = power * 2;
			if(power + 1 == temp)
			{
					flagged = true;
			}
		}
		power = power/2;
		if(!flagged )
		{
			delete += temp - power-1;;
		}
		

	//	if((nod-delete) % 2 == 0)
	//	{
	//		delete++;
	//	}

		cout << "Case #" << cases << ": "<< delete << endl;


		uses--;
	}
	return 0;
}