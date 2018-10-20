// code_jam.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "InputFileReader.h"
#include <conio.h>
#include <algorithm>
#include <map>
#include <iomanip>
#include <bitset>


using namespace std;

class SecondTask : public InputFileReader
{

public:
   SecondTask(string fileName)
   : InputFileReader(fileName)
   {

   }
   virtual void readTestCase( std::ifstream & file, std::ofstream & fileOut, int z ) 
   {
	   pair<int, int> devicesAndSwitches;
	   readValue(file, devicesAndSwitches);
	   devCount = devicesAndSwitches.first;
	   vector<string> outletsString;
	   readValue(file, outletsString);
	   vector<string> devicesString;
	   readValue(file, devicesString);
	   vector<bitset<40>> outlets;
	   for (int i = 0; i < devicesAndSwitches.first; i++)
	   {
			outlets.push_back(bitset<40>(outletsString[i]));
	   }
	   devices.clear();
	   for (int i = 0; i < devicesAndSwitches.first; i++)
	   {
		   devices.push_back((bitset<40>(devicesString[i])).to_ulong());
	   }
	   sort(devices.begin(), devices.end());
	  
	  int res = check(outlets, devicesAndSwitches.second);
	  if (res < 40)
	  {
		  fileOut << "Case #" << z+1 << ": " << res  << endl;
	  } 
	  else
	  {
		  fileOut << "Case #" << z+1 << ": " << "NOT POSSIBLE"  << endl;	  
	  }
	  

   }

   int check(vector<bitset<40>> outlets, int count)
   {
	   vector<unsigned long> outl;
	   for (int i = 0; i < devCount; i++)
	   {
	      outl.push_back(outlets[i].to_ulong());
	   }
		sort(outl.begin(), outl.end());
		if (outl == devices)
		{
			return 0;
		}
		
		{
			if (count == 0)
			{
				return 40;
			}
			vector<bitset<40>> outletsM = outlets;
			for (int i = 0; i < devCount; i++)
			{
				outletsM[i].flip(count-1);
			}
			return min (check(outlets, count-1), 1+check(outletsM,count-1));
		}
   }
   vector<unsigned long> devices;
   int devCount;
};


int _tmain(int argc, _TCHAR* argv[])
{
	SecondTask fr("c:\\jam.in");
	fr.readFile();
    getch();
	return 0;
}

