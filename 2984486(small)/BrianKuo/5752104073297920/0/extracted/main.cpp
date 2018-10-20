#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
    ifstream fin("C-small-attempt4.in");
    ofstream fout("C-small-attempt4.out");
    int n;
    fin>>n;
    long long err[n];
    long long err2[n];
    int ans[n];
    for(int t=0;t<n;t++){
        err[t]=0;
        ans[t]=0;
        int N;
        fin>>N;
        int x;
        for(int i=0;i<N;i++){
            fin>>x;
            err[t]+=(x-i-1)*(x-i-1)*(x-i-1)*(x-i-1);
            //cout<<err[t]<<endl;
        }
        err2[t]=err[t];
    }
    sort(err2,err2+n);
    int mid=(n%2==1?err2[n/2]:(err2[n/2]+err2[n/2-1])/2);
    for(int t=1;t<=n;t++){
        cout<<err[t]<<endl;
        char ansstr[500];
        if(err[t-1]<err2[n/2])
            sprintf(ansstr,"Case #%d: BAD\n",t);
        else
            sprintf(ansstr,"Case #%d: GOOD\n",t);
        fout<<ansstr<<endl;
    }
    return 0;
}
