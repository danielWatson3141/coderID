//name Yufei Wang

#include <iostream>
#include <fstream>
#include <stdlib.h> 
#include <iomanip>
#include <math.h>
#include <algorithm>
using namespace std;
int binaryToBase10(int n);
bool comparearr(int *a, int* b, int N);
int countSetBits(unsigned long long int n);
int main (int arg, char* argv[])
{
	
	int numofrun = 0;
	int currentrun = 1;
	int N = 0;
	int L = 0;
	int temp = 0;
	int numbit = 0;
	int success;
	unsigned long long int mask;
	int answer = 0;
///////////////////get the code from file/////////
	string filename;
	ifstream infile;
	ofstream outfile;
	infile.open(argv[1], ios::in);
	outfile.open("result.txt", ios::out);
	if(!infile)
	 {
	  cout <<" cannot open file" ;
	  exit(0);
	  }

	if(!outfile)
	{
	  cout <<" cannot open file" ;
	  exit(0);
	 }

infile >> numofrun; ///number of tests

	 while( currentrun<= numofrun)
{
	infile >> N;
	
	infile >> L;

	int initial[N];
	int final[N];
	int middle[N];
	success = 0;
	for (int i = 0; i < N; ++i)
	{
		infile >> temp;
		initial[i] = binaryToBase10(temp);
	}
		for (int i = 0; i < N; ++i)
	{
		infile >> temp;
		final[i] = binaryToBase10(temp);
	}
//////////getting data finished/////////


	sort(final,final+N); 
	numbit = pow(2.0,L);
			for (mask = 0; mask <numbit; ++mask)
	{
		for (int i = 0; i < N; ++i)
		{
			middle[i] = initial[i] ^ mask;
		}


		sort(middle,middle+N); 
		if(comparearr(middle,final,N))
		{
			success = 1;
			break;
		}
	}

if (success)
{
	answer = countSetBits(mask);
	outfile<<"Case #"<<currentrun<<": "<<answer<<endl;
}
else
{
	outfile<<"Case #"<<currentrun<<": NOT POSSIBLE"<<endl;
}
	
	currentrun++;
}////eof

   infile.close();
   outfile.close();
return 0;
}


int binaryToBase10(int n) {

    int output = 0;

    for(int i=0; n > 0; i++) {

        if(n % 10 == 1) {
            output += pow(2, i);
        }
        n /= 10;
    }

    return output;
}

bool comparearr(int *a, int* b, int N)
{
	for (int i = 0; i < N; ++i)
	{
		if(a[i]!=b[i])
		{
			return false;
		}
	}
	return true;
}

int countSetBits(unsigned long long int n)
{
  unsigned int count = 0;
  while(n)
  {
    count += n & 1;
    n >>= 1;
  }
  return count;
}