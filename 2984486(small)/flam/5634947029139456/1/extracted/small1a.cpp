#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;
int totalDevices, totalSwitches;
vector <string> outlets;
vector <string> devices;
bool works;
int minn=-1;
void manipulate(int index)
{
	for (int cd=0; cd<outlets.size(); cd++)
	{
		if (outlets[cd][index]=='0') outlets[cd][index]='1';
		else outlets[cd][index]='0';
	}
}

void setOutlets(int outletIndex)
{
	vector <string> temp=outlets;
	int toSet=0;
	for (int c=0; c<totalSwitches; c++)
	{
		if (devices[0][c]!=outlets[outletIndex][c])
		{
			toSet++;
			for (int cd=0; cd<outlets.size(); cd++)
			{
				if (temp[cd][c]=='0') temp[cd][c]='1';
				else temp[cd][c]='0';
			}
		}
	}

	vector <bool> used(totalDevices,false);
		int numbers=0;
	for (int cc=0; cc<devices.size(); cc++)
		{
			bool found=false;
			for (int dd=0; dd<devices.size(); dd++)
			{
				if (used[dd]) continue;
				if (devices[cc].compare(temp[dd])==0)
				{
					found=true;
					numbers++;
					used[dd]=true;
				}
			}
			if (!found) break;
		}
	if (numbers>=totalDevices)
	{
		if (toSet<minn||minn==-1)minn=toSet;
	}
		return;

}
void testCombinations (int switchesUsed, int target, int lastIndex)
{
	if (switchesUsed>=target)
	{
		// check
		vector <bool> used(totalDevices,false);
		int numbers=0;
		for (int cc=0; cc<devices.size(); cc++)
		{
			bool found=false;
			for (int dd=0; dd<devices.size(); dd++)
			{
				if (used[dd]) continue;
				if (devices[cc].compare(outlets[dd])==0)
				{
					found=true;
					numbers++;
					used[dd]=true;
				}
			}
			if (!found) break;
		}
		if (numbers>=totalDevices)
		{
			works=true;
		
		}
		return;
	}
	for (int cc=lastIndex+1; cc<totalSwitches; cc++)
	{
		manipulate(cc);
		testCombinations(switchesUsed+1, target,cc);
		manipulate(cc);
		if (works) return;
	}

}
int main()
{
	freopen("test.in", "r", stdin);
	freopen("output3.txt", "w", stdout);
	int testCases;
	scanf("%d", &testCases);
	for (int a=0; a<testCases; a++)
	{
		minn=-1;
		works=false;
		scanf("%d %d", &totalDevices, &totalSwitches);
		string input;
		outlets= vector <string> (totalDevices);
		devices = vector <string> (totalDevices);
		for (int b=0; b<totalDevices; b++)
		{
			cin >> outlets[b];
		}
		for (int b=0; b<totalDevices; b++)
		{
			cin >> devices[b];
		}
		int c=0;
		/*
		for (c; c<=totalSwitches; c++)
		{
			testCombinations(0,c,-1);
			if (works) break;
		}*/
		for (int b=0; b<totalDevices; b++)
		{
			setOutlets(b);
		}
		printf("Case #%d: ", a+1);
		if (minn==-1) printf("NOT POSSIBLE\n");
		else printf("%d\n", minn);
	}

}