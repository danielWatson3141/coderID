// Google Jam.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <fstream>

using namespace std;

//string _tostringlower(string s){for(int i = 0; i<s.length(); i++)	{		if( __isascii(s[i])&& isupper(s[i]))			s[i] = char(_tolower(s[i]));	}	return s;}
//string _tostringupper(string s){	for(int i = 0; i<s.length(); i++)	{		if( __isascii(s[i])&& islower(s[i]))			s[i] = char(_toupper(s[i]));	}	return s;}
vector<string> split( const string& s, const string& delim=" ") {    vector<string> res;    string t;    for ( int i = 0 ; i != s.size() ; i++ ) {        if ( delim.find( s[i] ) != string::npos ) {            if ( !t.empty() ) {                res.push_back( t );                t = "";            }        } else {            t += s[i];        }    }    if ( !t.empty() ) {        res.push_back(t);    }    return res;}
vector<string> splitall( const string& s, const string& delim=" ") {    vector<string> res;    string t;    for ( int i = 0 ; i != s.size() ; i++ ) {        if ( delim.find( s[i] ) != string::npos ) {            {                res.push_back( t );                t = "";            }        } else {            t += s[i];        }    }     {        res.push_back(t);    }    return res;}
vector<int> splitInt( const string& s, const string& delim =" " ) {    vector<string> tok = split( s, delim );    vector<int> res;    for ( int i = 0 ; i != tok.size(); i++ )        res.push_back( atoi( tok[i].c_str() ) );    return res;}
vector<double> splitDouble( const string& s, const string& delim =" " ) {    vector<string> tok = split( s, delim );    vector<double> res;    for ( int i = 0 ; i != tok.size(); i++ )        res.push_back( atof( tok[i].c_str() ) );    return res;}
vector<int> splitIntall( const string& s, const string& delim =" " ) {    vector<string> tok = splitall( s, delim );    vector<int> res;    for ( int i = 0 ; i != tok.size(); i++ )        res.push_back( atoi( tok[i].c_str() ) );    return res;}
//bool isPrime (int n){   if (n<=1) return false;   if (n==2) return true;   if (n%2==0) return false;   for (int i=3; (i*i)<=n; i+=2)      if (n%i==0)         return false;   return true;}
//vector<bool> sieve(int n){	vector<bool> prime(n+1, true);	prime[0]=false;	prime[1]=false;    for (int i=2; (i*i)<=n; i++)		if (prime[i])			for (int k=i*i; k<=n; k+=i)				prime[k]=false;   return prime;} 
//int GCD(int a, int b){   if (b==0) return a;   return GCD(b,a%b);}
//int LCM(int a, int b){   return b*a/GCD(a,b);}
//bool _endstring(string s, string s2){	if(s2.length()> s.length()) return false;	s = s.substr( s.length()-s2.length());	if(s == s2) return true;	return false;}
//bool _ispalindrome(string s){	int size = s.length();	int size2 = s.length()/2;	for(int i = 0;i<size2; i++){	if(s[i] != s[size-1-i]) return false;	}	return true;	}
//int sdx[] = {-1, 1, 0, 0};
//int sdy[] = { 0, 0,-1, 1};
//int spx[] = { -1, -1, 1, 1};
//int spy[] = { -1, 1, 1, -1};
//int sax[] = {-1, 1, 0, 0, -1, -1, 1, 1};
//int say[] = { 0, 0,-1, 1, -1, 1, 1, -1};[


int n = 0;
int l = 0;

int solve(int count, vector<string> sw, vector<string> device, int col)
{
	int x = -1;
	int y = -1;
	if(col > l)
	{
		return -1;
	}

	

	sort(sw.begin(), sw.end());
	sort(device.begin(), device.end());
	//check if same
	bool check = true;
	for(int i = 0; i<sw.size(); i++)
	{
		if(sw[i] != device[i])
		{
			check = false;
			break;
		}
	}
	if(check)
	{
		return count;
	}

	//if not check column only
	check = true;
	for(int i = 0; i<sw.size(); i++)
	{
		if(sw[i].substr(0,col+1) != device[i].substr(0,col+1))
		{
			check = false;
			break;
		}
	}
	if(check)
	{
		x = solve(count, sw, device,col+1); 
	}


	//flip
	for(int i =0; i<sw.size(); i++)
	{
		if(sw[i][col] == '0')
		{
			sw[i][col] = '1';
		}
		else
		{
			sw[i][col] = '0';
		}
	}
	count++;

	sort(sw.begin(), sw.end());
	sort(device.begin(), device.end());
	check = true;
	for(int i = 0; i<sw.size(); i++)
	{
		if(sw[i] != device[i])
		{
			check = false;
			break;
		}
	}
	if(check)
	{
		return count;
	}

	check = true;
	for(int i = 0; i<sw.size(); i++)
	{
		if(sw[i].substr(0,col+1) != device[i].substr(0,col+1))
		{
			check = false;
			break;
		}
	}
	if(check)
	{
		y = solve(count, sw, device,col+1); 
	}
	

	if(x == -1)
	{
		return y;
	}
	if(y == -1)
	{
		return x;
	}

	if(x<=y)
	{
		return x;
	}
	else
	{
		return y;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	FILE * pFile;
	//pFile = fopen("out.txt", "w");
	//ifstream in("in.txt");
	pFile = fopen("A-small-attempt1.out", "w");
	ifstream in("A-small-attempt1.in");


	string s;
	getline(in,s);
	int cases = atoi(s.c_str());
		
	for(int i_line = 0; i_line<cases; i_line++)
	{
		fprintf(pFile, "Case #%d: ", i_line+1);

		getline(in,s);

		vector<int> vi = splitInt(s);
		n = vi[0];
		l = vi[1];

		getline(in,s);
		vector<string> sw = split(s);

		getline(in,s);
		vector<string> device = split(s);

		int x = solve(0, sw, device,0);

		if(x == -1)
		{
			fprintf(pFile, "NOT POSSIBLE");
		}
		else
		{
			fprintf(pFile, "%d", x);
		}
		fprintf(pFile, "\n");

		//
	}

	in.close();

	fclose(pFile);
	return 0;
}
