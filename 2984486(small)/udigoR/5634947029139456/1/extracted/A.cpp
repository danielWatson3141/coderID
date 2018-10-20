#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool mycmp (string s1, string s2) 
{ 
    __int64 x1=0, x2 = 0, k = 1;
    for(int i=0; i<s1.size(); i++)
    {        
        if(s1[i] == '0' && s2[i] == '1')
            return true;
        if(s1[i] == '1' && s2[i] == '0')
            return false;
    }
        

    return false;

}

int solve(vector<string> dev, vector<string> outl, int pos, int sum)
{
    for(int i=0; i<outl.size(); i++)
    {
        for(int j=0; j<pos; j++)
            if(outl[i][j] != dev[i][j])
                return -1;
    }
    
    if(outl[0].length() == pos)
        return sum;


    int x1=0, y1=0;
    int x2=0, y2=0;
    for(int i=0; i<dev.size(); i++)
    {
        if(dev[i][pos]=='0')
            x1++;

        if(outl[i][pos]=='0')
            x2++;
    }

    y1 = dev.size() - x1;
    y2 = dev.size() - x2;

    if(x1 == x2 || x1 == y2)
    {
        int s;

        if(x1 != y1)
        {            
            if(x1 == x2)
                s = solve(dev, outl, pos + 1, sum); //No switch
            else
            {
                for(int i=0; i<outl.size(); i++)
                    if(outl[i][pos] == '0')
                        outl[i][pos]='1';
                    else
                        outl[i][pos]='0';

                std::sort(outl.begin(), outl.end(), mycmp);

                s = solve(dev, outl, pos + 1, sum+1);
            }
        }
        else
        {
            s = solve(dev, outl, pos + 1, sum);

            if(s == -1)
            {
                for(int i=0; i<outl.size(); i++)
                    if(outl[i][pos] == '0')
                        outl[i][pos]='1';
                    else
                        outl[i][pos]='0';

                std::sort(outl.begin(), outl.end(), mycmp);

                s = solve(dev, outl, pos + 1, sum + 1);
            }
        }

        return s;
    }
    else
    {
        return -1;
    }
}



void main()
{
	int T = 0;

	ifstream in("A-large.in");
	ofstream out("A-large.out");

	in >> T;

	for(int i=0; i<T; ++i)
	{
		int N, L;

        in >> N >> L;
        vector<string> dev(N), outl(N);		

        
		for(int i =0; i<N; i++)
            in >> outl[i];

        for(int i =0; i<N; i++)
            in >> dev[i];

        
        std::sort(dev.begin(), dev.end(), mycmp);
        std::sort(outl.begin(), outl.end(), mycmp);

        int s = solve(dev, outl, 0, 0);

        if(s == -1)
		    out << "Case #" << i+1 << ": NOT POSSIBLE";
        else
            out << "Case #" << i+1 << ": " << s;


		out << endl;
	}
}
