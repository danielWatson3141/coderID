#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int isPossible(int n, int l, vector<string> flow, vector<string> required)
{
    sort(flow.begin(), flow.end());
    sort(required.begin(), required.end());

    //for(int i=0; i<n; ++i) cout<<flow[i]<<endl;
    //for(int i=0; i<n; ++i) cout<<required[i]<<endl;
    //cout<<endl;

    if(flow == required) return 0;

    if(l == -1) return -1;

    

    int s = -1;

    int flowZeros = 0, flowOnes = 0, requiredZeros = 0, requiredOnes = 0;
    for(int i=0; i<n; ++i)
        if(flow[i][l] == '0') ++flowZeros;
        else ++flowOnes;
    for(int i=0; i<n; ++i)
        if(required[i][l] == '0') ++requiredZeros;
        else ++requiredOnes;

    bool both = flowZeros == flowOnes && flowZeros == requiredZeros && flowOnes == requiredOnes;
    if(both || flowZeros == requiredZeros && flowOnes == requiredOnes)
    {
        int t = isPossible(n, l-1, flow, required);
        if(t != -1 && (s == -1 || t < s)) s = t;
    }
    if(both || flowZeros == requiredOnes && flowOnes == requiredZeros)
    {
        vector<string> flow1 = flow;
        for(int i=0; i<n; ++i)
            if(flow1[i][l] == '0') flow1[i][l] = '1';
            else flow1[i][l] = '0';
        //for(int i=0; i<n; ++i) cout<<flow[i]<<endl;
        //for(int i=0; i<n; ++i) cout<<flow1[i]<<endl;
    //cout</<endl;
        int t = isPossible(n, l-1, flow1, required);
        //cout<<t<<endl;
        if(t != -1 && (s == -1 || t + 1 < s)) s = t + 1;
    }

    return s;
}

int main()
{
    int numberOfCases;
    cin>>numberOfCases;
    for(int t=1; t<=numberOfCases; ++t)
    {
        int n, l;
        cin>>n>>l;
        vector<string> flow(n);
        vector<string> required(n);
        for(int i=0; i<n; ++i)
            cin>>flow[i];
        for(int i=0; i<n; ++i)
            cin>>required[i];
        cout<<"Case #"<<t<<": ";
        int s = isPossible(n, l-1, flow, required);
        if(s==-1) cout<<"NOT POSSIBLE"<<endl;
        else cout<<s<<endl;
    }
    return 0;
}
