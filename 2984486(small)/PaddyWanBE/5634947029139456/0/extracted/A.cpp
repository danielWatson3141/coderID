#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <cstring>

using namespace std;
typedef unsigned int uint;
typedef unsigned long ulong;

uint aantal;
uint casei;
void flushLine();
void opl();

string l[155];
string cl[155];

int main()
{
    for(uint i = 0; i < 155; i++)
	l[i].reserve(45);
    for(uint i = 0; i < 155; i++)
	cl[i].reserve(45);
    cin >> aantal;
    flushLine();
    for(casei = 1; casei <= aantal; casei++)
	opl();
    return 0;
}

void flushLine()
{
    string str;
    getline(cin, str);
}

void opl()
{
    multiset<string> m;
    uint N;
    uint L;
    cin >> N;
    cin >> L;
    for(uint i = 0; i < N; i++)
    {
	cin >> l[i];
    }
    for(uint i = 0; i < N; i++)
    {
	string s;
	cin >> s;
	m.insert(s);
    }
    sort(l, l+N);
    uint a = 0; 
    bool gevonden = std::equal(l,l+N,m.begin());
    while(!gevonden && a < L)
    {
	a++;
	string s(L, '0');
	for(uint i = 0; i < a; i++)
	    s[i] = '1';
	sort(s.begin(), s.end());
	{  
	    for(uint i = 0; i < N; i++)
	    {
		cl[i] = l[i];
	    }
	    for(uint j = 0; j < L; j++)
	    {
		if(s[j] == '1')
		    for(uint i = 0; i < N; i++)
		    {
			cl[i][j] = (cl[i][j] == '0'? '1':'0');
		    }
	    }
	    sort(cl,cl+N);
	    gevonden = std::equal(cl,cl+N,m.begin());
	}
	while(!gevonden && next_permutation(s.begin(), s.end()))
	{
	    for(uint i = 0; i < N; i++)
	    {
		cl[i] = l[i];
	    }
	    for(uint j = 0; j < L; j++)
	    {
		if(s[j] == '1')
		    for(uint i = 0; i < N; i++)
		    {
			cl[i][j] = (cl[i][j] == '0'? '1':'0');
		    }
	    }
	    sort(cl,cl+N);
	    gevonden = std::equal(cl,cl+N,m.begin());	    
	}
    }
    
    if(gevonden)
	cout << "Case #" << casei << ": " << a << endl;
    else
	cout << "Case #" << casei << ": NOT POSSIBLE" << endl;
}

