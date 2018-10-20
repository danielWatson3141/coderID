#include <vector>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

ifstream ein;
FILE * aus;
int TestCase;

int dsum(string a)
{
	int r =0;
	for (int l=0;l<a.length();l++)
	{
		if (a[l]=='1')
			r++;
	}
	return r;
}

string sxor(string a,string b)
{
	string c;
	c = "";
	for (int l=0;l<a.length();l++)
	{
		if (a[l]==b[l])
			c += "0";
		else
			c+="1";
	}
	return c;
}

void start()
{
	int result;
	// read test case
	int N,L;
	ein >> N >> L;
	vector<string> a(N);
	vector<string> b(N);
	vector<string> c(N);

	for (int n=1;n<=N;n++)
		ein >> a[n-1];
	for (int n=1;n<=N;n++)
		ein >> b[n-1];
	sort(b.begin(),b.end());

	result = 100;
	for (int n=0;n<N;n++)
	{
		string ch = sxor(a[0],b[n]);
		for (int k=0;k<N;k++)
			c[k] = sxor(a[k],ch);
		sort(c.begin(),c.end());
		if (c==b)
		{
			if (dsum(ch)<result)
				result = dsum(ch);
		}
	}

	// output result
    if (result == 100)
		fprintf(aus, "Case #%d: NOT POSSIBLE\n", TestCase);
	else
		fprintf(aus, "Case #%d: %d\n", TestCase, result);
}

void main()
{
	int NumTestCases;	
	ein.open("A-large.in");
	//ein.open("a-practice-small0.in");
	//ein.open("a-large.in");
	aus = fopen("out-a.txt","w");
	
	ein >> NumTestCases;
	for (TestCase = 1; TestCase <= NumTestCases; TestCase++)
		start();

	fclose(aus);
	ein.close();
}
