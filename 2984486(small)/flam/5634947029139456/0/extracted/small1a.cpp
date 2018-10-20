#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;
int totalDevices, totalSwitches;
vector <string> outlets;
vector <string> devices;
bool works;
void manipulate(int index)
{
	for (int cd=0; cd<outlets.size(); cd++)
	{
		if (outlets[cd][index]=='0') outlets[cd][index]='1';
		else outlets[cd][index]='0';
	}
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
	freopen("output.txt", "w", stdout);
	int testCases;
	scanf("%d", &testCases);
	for (int a=0; a<testCases; a++)
	{
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
		for (c; c<=totalSwitches; c++)
		{
			testCombinations(0,c,-1);
			if (works) break;
		}
		printf("Case #%d: ", a+1);
		if (!works) printf("NOT POSSIBLE\n");
		else printf("%d\n", c);
	}

}