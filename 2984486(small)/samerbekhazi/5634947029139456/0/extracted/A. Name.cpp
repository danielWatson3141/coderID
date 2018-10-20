#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

string flow[150];
string required[150];

string flowAux[150];
string reqAux[150];

pair<int,bool> dp[42];

int N,L;
pair<int,bool> f(int index, string flip)
{
    if(index==L)
    {
        for(int i=0; i<N; i++)
            flowAux[i]=flow[i];
        for(int i=0; i<N; i++)
            reqAux[i]=required[i];

        for(int k=0; k<flip.length(); k++)
        {
            if(flip[k]=='1')
            {
                for(int i=0; i<N; i++)
                {
                    if(flow[i][k]=='0')
                        flowAux[i][k]='1';
                    else if(flow[i][k]=='1')
                        flowAux[i][k]='0';
                }
            }
        }
        sort(flowAux,flowAux+N);
        sort(reqAux,reqAux+N);

        for(int i=0; i<N; i++)
        {
            if(flowAux[i]!=reqAux[i])
                return make_pair(0,false);
        }
        return make_pair(0,true);
    }

    int count0f=0;
    int count1f=0;
    int count0r=0;
    int count1r=0;
    for(int i=0; i<N; i++)
    {
        if(flow[i][index]=='0')
            count0f++;
        else if(flow[i][index]=='1')
            count1f++;
        if(required[i][index]=='0')
            count0r++;
        else if(required[i][index]=='1')
            count1r++;

    }

    if(count0f == count1f && count0r == count1r && count0f == count0r)
    {
        pair<int,bool> o1 = f(index+1,flip+"0");
        pair<int,bool> o2 = f(index+1,flip+"1");
        if(o1.second && o2.second)
        {
            if(o1.first<1+o2.first)
                return make_pair(o1.first,true);
            else
                return make_pair(1+o2.first,true);
        }
        else if(o1.second)
            return make_pair(o1.first,true);
        else if(o2.second)
            return make_pair(1+o2.first,true);
        else
            return make_pair(0,false);
    }
    if(count0f == count0r && count1f == count1r)
    {
        pair<int,bool> o = f(index+1,flip+"0");
        if(o.second)
            return make_pair(o.first,true);
        else
            return make_pair(0,false);
    }
    else if(count0f == count1r && count1f == count0r)
    {
        pair<int,bool> o = f(index+1,flip+"1");
        if(o.second)
            return make_pair(1+o.first,true);
        else
            return make_pair(0,false);
    }
    else
        return make_pair(0,false);
}

void initialize(int n)
{
    for(int i=0; i<n; i++)
    {
        dp[i]=make_pair(-1,true);
    }
}

int main()
{
    ifstream infile("A-small-attempt0.in");
    ofstream outfile("A-small-attempt0.out");
    int T;
    infile >> T;

    for(int t=0 ;t<T; t++)
    {
        infile >> N >> L;
        for(int i=0; i<N; i++)
            infile >> flow[i];
        for(int i=0; i<N; i++)
            infile >> required[i];

        pair<int,bool> o = f(0,"");
        if(o.second)
            outfile << "Case #" << t+1 << ": " <<o.first << endl;
        else
            outfile << "Case #" << t+1 << ": " <<"NOT POSSIBLE" << endl;
    }
    return 0;
}
