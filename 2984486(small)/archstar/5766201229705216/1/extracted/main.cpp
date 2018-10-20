#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct cn
{
	int n, c;
};

bool operator<(const cn &lhs, const cn &rhs){
	return lhs.c < rhs.c; 
}

int count(vector<vector<int> >& nodes, int i, int p)
{
	int c = 1;
	for(int k = 0; k < nodes[i].size(); k++)
		if(nodes[i][k] != p)
			c += count(nodes, nodes[i][k], i);
	return c;
}

int numToRem(vector<vector<int> >& nodes, int i, int p)
{
	int parent = 3;
	if(p == -1)
		parent--;
	if(nodes[i].size() < parent)
	{
		int c = 0;
		for(int k = 0; k < nodes[i].size(); k++)
			if(nodes[i][k] != p)
				c += count(nodes, nodes[i][k], i);
		return c;
	}
	else if(nodes[i].size() == parent)
	{
		int c = 0;
		for(int k = 0; k < nodes[i].size(); k++)
			if(nodes[i][k] != p)
				c += numToRem(nodes, nodes[i][k], i);
		return c;
	}
	else
	{
		vector<cn> cns;
		for(int k = 0; k < nodes[i].size(); k++) {
			if(nodes[i][k] != p) {
				cn c;
				c.n = numToRem(nodes, nodes[i][k], i);
				c.c = count(nodes, nodes[i][k], i);
				cns.push_back(c);
			}
		}
		sort(cns.begin(), cns.end());
		int p = 0;
		for(int k = 0; k < cns.size(); k++)
		{
			if(cns.size() - k <= 2)
				p += cns[k].n;
			else
				p += cns[k].c;
		}
		return p;
	}
}

int main()
{
	ifstream ifs("C:\\Users\\Arch\\Documents\\Visual Studio 2010\\Projects\\FacebookChallenge\\a.in");
	ofstream ofs("C:\\Users\\Arch\\Documents\\Visual Studio 2010\\Projects\\FacebookChallenge\\a.out");

	int t;
	ifs >> t;
	for(int g = 0; g < t; g++)
	{
		int n;
		ifs >> n;
		vector<vector<int> > nodes;
		for(int i = 0; i < n; i++)
			nodes.push_back(vector<int>());
		for(int i = 0; i < n - 1; i++)
		{
			int x, y;
			ifs >> x >> y;
			nodes[x - 1].push_back(y - 1);
			nodes[y - 1].push_back(x - 1);
		}
		int best = n - 1;
		for(int r = 0; r < n; r++)
		{
			int b = numToRem(nodes, r, -1);
			if(b < best)
				best = b;
		}
		ofs << "Case #" << (g + 1) << ": " << best << endl;
	}

	return 0;
}


/*
//TODO: HANDLE EMPTY
//TODO: FIX FIRST CHAR

char OP = '*';
char VAL = 'x';

int getXCount(string rpn)
{
	int c = 0;
	for(int i = 0; i < rpn.length(); i++)
		if(rpn[i] == VAL)
			c++;
	return c;
}

int getSCount(string rpn)
{
	int c = 0;
	for(int i = 0; i < rpn.length(); i++)
		if(rpn[i] == OP)
			c++;
	return c;
}

int bestRpn(string rpn)
{
	while(rpn.length() > 0 && (rpn[0] != 'x' && rpn[0] != '*'))
		rpn = rpn.substr(1);
	int xcount = getXCount(rpn);
	int scount = getSCount(rpn);
	if(xcount > scount)
	{
		int moves = 0;
		int d = xcount - scount;
		int best = 10000;
		if(d % 2 == 1)
		{
			d--;
			rpn = rpn + '*';
			moves++;
		}
		if(d == 0)
			best = bestRpn(rpn) + moves;
		for(int k = 0; k < d / 2; k++)
		{
			string newRpn(rpn);
			int toChange = d / 2 - k;
			int index = newRpn.length() - 1;
			while(toChange > 0)
			{
				if(newRpn[index] == 'x')
				{
					newRpn[index] = '*';
					toChange--;
				}
				index--;
			}
			newRpn += string('*', k * 2);
			best = min(best, bestRpn(newRpn) + 2 * k + (d / 2 - k) + moves);
		}
		return best;
	}
	else if(scount > xcount)
	{
		int moves = 0;
		int d = scount - xcount;
		int best = 10000;
		if(d % 2 == 1)
		{
			d--;
			rpn = 'x' + rpn;
			moves++;
		}
		if(d == 0)
			best = bestRpn(rpn) + moves;
		for(int k = 0; k < d / 2; k++)
		{
			string newRpn(rpn);
			int toChange = d / 2 - k;
			int index = 0;
			while(toChange > 0)
			{
				if(newRpn[index] == '*')
				{
					newRpn[index] = 'x';
					toChange--;
				}
				index++;
			}
			newRpn = string('x', k * 2) + newRpn;
			best = min(best, bestRpn(newRpn) + 2 * k + (d / 2 - k) + moves);
		}
		return best;
	}
	else
	{
		int xs = 0;
		int soBad = 0;
		int worstBuffer = 0;
		for(int j = 0; j < rpn.length(); j++)
		{
			if(rpn[j] == 'x')
			{
				int buffer = scount - soBad - xcount + xs;
				if(buffer < worstBuffer)
					worstBuffer = buffer;
				xs++;
			}
			else
			{
				soBad++;
			}
		}
		return max(0, worstBuffer * -2);
	}
}

int bestRpn2(string rpn)
{
	if(rpn[0] == OP)
	{
		int best = bestRpn('x' + rpn) + 1;
		if(rpn.length() > 1)
		{
			best = min(best, bestRpn2(rpn.substr(1)) + 1);
			best = min(best, bestRpn('x' + rpn.substr(1)) + 1);
		}
		return best;
	}
	return bestRpn(rpn.substr(1));
}

void runTest()
{
	string rpn;
	cin >> rpn;
	cout << bestRpn2(rpn) << endl;
}

int main()
{
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		runTest();
	}
	return 0;
}*/