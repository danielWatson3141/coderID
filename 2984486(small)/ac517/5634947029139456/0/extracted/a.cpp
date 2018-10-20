#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <time.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>

using namespace std;

#define FOR(i,a,b)  for(int i = (a);i<(b);++i)
#define REP(i,a)    FOR(i,0,a)
#define S           size()
#define PB          push_back
#define ALL(a)      a.begin(),a.end()
#define MP          make_pair
#define V           vector
#define VI          V < int > 
#define VVI         V < VI >
#define VVVI		V < VVI >
#define VL			V < long long > 
#define VVL			V < VL >
#define VD          V < double >
#define VF          V < float >
#define VS			V < string >

int pos = -1;

void check(VS in, VS out, int i, int cnt)
{

	if(i==in[0].S)
	{
		sort(ALL(in));
		sort(ALL(out));
	
		REP(j,in.S)
		{
			if(in[j]!=out[j]) return;
		}
	
		if(pos==-1) pos=cnt;
		else pos=min(pos,cnt);
		return;
	}


	int in0=0,in1=0,out0=0,out1=0;
	
	REP(j,in.S)
	{
		if(in[j][i]=='0') ++in0; else ++in1;
		if(out[j][i]=='0') ++out0; else ++out1;
	}
	
	if(in0==out0 && in0==in1)
	{
		VS intmp(in);
		VS outtmp(out);
		
		check(intmp,outtmp,i+1,cnt);
		
		REP(j,in.S)
		{
			in[j][i]=(in[j][i]=='0'?'1':'0');
		}
		
		check(in,out,i+1,cnt+1);
	}
	else if(in0==out0)
	{		
		check(in,out,i+1,cnt);
	}
	else if(in1==out0)
	{
		REP(j,in.S)
		{
			in[j][i]=(in[j][i]=='0'?'1':'0');
		}
		check(in,out,i+1,cnt+1);
	}

}

int main(int argc, char** argv)
{
	int n;
	++argv;
	ifstream in(*argv);
	
	in >> n;
	VS res;
	int N,L;
	REP(i,n)
	{
		in >>N>>L;
		VS input,output;
		REP(j,N)
		{
			string s;
			in >> s;
			input.PB(s);
		}
		REP(j,N)
		{
			string s;
			in >> s;
			output.PB(s);
		}
		pos = -1;
		check(input,output,0,0);
		if(pos==-1)
		{
			res.PB("NOT POSSIBLE");
		}
		else
		{
			stringstream spos;
			spos<<pos;
			res.PB(spos.str());
		}
	}
			
				
	
	stringstream ss;
	REP(i,res.S)
	{
		ss << "Case #" << i+1 << ": " << res[i] << endl;
	}
	
	cout << ss.str();




}


