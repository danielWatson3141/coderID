#include<set>
#include<climits>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<iostream>
#include <sstream>
#include <fstream>
using namespace std;

#define LOOP(i,s,n) for(int i=(s);i<(n);i++)
#define loop(i,n) for(int i=0;i<(n);i++)
#define MAX(mVal, oVal) (mVal) = max((mVal),(oVal))
#define MIN(mVal, oVal) (mVal) = min((mVal),(oVal))
#define All(c) (c).begin(),(c).end()
#define ZERO(arr) memset(arr,0,sizeof(arr))
#define FILL(arr,val) memset(arr,val,sizeof(arr))
bool dp[150];

#define FILE_NAME_SMALL "A-small-attempt1"
//#define FILE_NAME_LARGE "large"
#define FILE_NAME_SAMPLE "sample"

class codeJam
{
public:
	string calculateOuput(int N, int L, vector<string> init, vector<string> tar)
	{
		
		if(init == tar) return "0";

		loop(mask,1<<L) 
		{
			int ans = 0;
			vector<string> temp = init;
			loop(j,L) if(mask&(1<<j)) 
			{
				ans++;
				loop(i,N)
				{
					temp[i][j] -= '0';
					temp[i][j] ^= 1;
					temp[i][j] += '0';
				}
			}

			int count = 0;
			ZERO(dp);
			loop(i,N) loop(j,N)
			{
				if(!dp[j] && temp[i] == tar[j]){ count++; dp[j]=true; }
			}

			if(count==N) return to_string(ans);
		}

		return "NOT POSSIBLE"; 
	}

	void processInput(string file)
	{
		ifstream fin;
		ofstream fout;
		int Z;

		fin.open(file + ".in" );
		fout.open(file + ".out");	
		fin >> Z;

		loop(k,Z)
		{
			string str;
			int N, L;
			vector<string> init, tar;
			fin>>N>>L;
			loop(i,N)
			{
				fin >> str;
				init.push_back(str);
			}

			loop(i,N)
			{
				fin >> str;
				tar.push_back(str);
			}
			string ans = calculateOuput(N, L, init, tar);
			fout << "Case #" << k+1 << ": " << ans << endl;
		}

		fin.close();
		fout.close();
	}
};

class unitTesting
{
	ifstream fSampleIn;
	ifstream fSampleOut;
	ifstream fSampleOutForVerify;	

public:
	void run_test(string sampleFileName) 
	{ 
		const int GET_LINE_LENGHT = 100;

		fSampleIn.open(sampleFileName + ".in");
		fSampleOut.open(sampleFileName +  ".out");
		fSampleOutForVerify.open("sampleForVerify.out");

		int X;
		fSampleIn >> X;
		loop(i,X)
		{
			char resultFromProgram[GET_LINE_LENGHT+1], sampleForVerifyOutput[GET_LINE_LENGHT+1];
			fSampleOut.getline(resultFromProgram,GET_LINE_LENGHT);
			fSampleOutForVerify.getline(sampleForVerifyOutput,GET_LINE_LENGHT);
			if(strcmp(resultFromProgram,sampleForVerifyOutput) == 0) cout << "Case " << i << ": Passed" << endl;
			else
			{
				cout << "Case " << i << ": Failed" << endl;
				cout << "\tExpected: " << sampleForVerifyOutput << endl; 
				cout << "\tReceived: " << resultFromProgram << endl << endl; 
			}
		}

		fSampleIn.close();
		fSampleOut.close();
		fSampleOutForVerify.close();
	}
};

int main()
{
	codeJam codeJamObj;

	#ifdef FILE_NAME_SMALL
		cout << "Small Input: ";
		codeJamObj.processInput(FILE_NAME_SMALL);
		cout << "Complete!" << endl;
	#endif

	#ifdef FILE_NAME_LARGE
		cout << "Large Input: ";
		codeJamObj.processInput(FILE_NAME_LARGE);
		cout << "Complete!" << endl;
	#endif

	//Test Code
	#ifdef FILE_NAME_SAMPLE
		cout << endl << "Unit Testing... " << endl;
		codeJamObj.processInput(FILE_NAME_SAMPLE);
		unitTesting testProgramOutput;
		testProgramOutput.run_test(FILE_NAME_SAMPLE);
	#else
		#ifndef FILE_NAME_SMALL
			#ifndef FILE_NAME_LARGE  
				cout << endl << "Unit Testing... " << endl;
				codeJamObj.processInput("sample");
				unitTesting testProgramOutput;
				testProgramOutput.run_test("sample");
			#endif
		#endif
	#endif
	getchar();
	return 0;
}