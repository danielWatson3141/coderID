#include <iostream>
#include<math.h>
#include<fstream>
using namespace std;

int main()
{
    int tt,nn;
    cin>>tt>>nn;
    ofstream outputFile;
    outputFile.open("program3data.txt");
    int a[120][1000];
    for(int t=0;t<tt;t++){
        for(int n=0;n<nn;n++){
        cin>>a[t][n];
        }
    }
    int inv=0;
    for(int t=0;t<tt;t++){
            inv=0;
        for(int m=0;m<nn;m++)
        for(int l=0;l<m;l++){
                if(a[t][m]<a[t][l])
                    inv++;
        }
        if(inv>(pow(nn,2)-nn)/4)
                outputFile<<"Case #"<<t+1<<": GOOD"<<endl;
            else
                outputFile<<"Case #"<<t+1<<": BAD"<<endl;
    }
    return 0;
}
