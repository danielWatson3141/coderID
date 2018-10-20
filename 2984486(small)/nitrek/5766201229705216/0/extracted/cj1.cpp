#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int times;
	int *edge;
	int nodes, turn=0;
	int *done;

	cin >> times;
	bool flag2 = true;

	while(times > 0)
	{
		flag2= false;
		turn++;
		int del=0;
		int counted = 0;
		cin >> nodes;
		edge = (int *)malloc(sizeof(int)*(2*nodes-1));
		done = (int *)malloc(sizeof(int)*(2*nodes-1));
		for(int i=0;i<2*(nodes-1);i++)
		{
			cin >> edge[i];
		}
		for(int i=0;i<2*(nodes-1);i++)
		{
			int counter=0;
			bool flag = true;
			for(int j=0;j<2*(nodes-1);j++)
			{
				for(int k=0;k<counted;k++)
				{
					if(edge[i] == done[k])
					{
						flag = false;
					}
				}
				if(edge[i] == edge[j] && flag)
				{
					counter++;
				}
			}
			if(counter>2)
			{
				del++;
			//	cout << edge[i] << " " ;
				done[counted++] = edge[i];
			}
		}

		int temp = nodes-del;
		int power=2;
		while(temp >= power+1)
		{
			power = power * 2;
			if(power + 1 == temp)
			{
					flag2 = true;
			}
		}
		power = power/2;
		if(!flag2 )
		{
			del += temp - power-1;;
		}
		

	//	if((nodes-del) % 2 == 0)
	//	{
	//		del++;
	//	}

		cout << "Case #" << turn << ": "<< del << endl;


		times--;
	}
	return 0;
}