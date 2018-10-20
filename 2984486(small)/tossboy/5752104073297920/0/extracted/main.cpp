#include <iostream>
using namespace std;

const int N=1000*10;
int n;
int a[N];

int main(int argc, const char * argv[])
{
    int cur=0;
    int ncase; cin>>ncase;
    for(int ca=1; ca<=ncase; ca++){
        cin>>n;
        bool hf=true;
        for(int i=0; i<=n; i++){
            cin>>a[i];
            if(i<=n/2 && a[i]<(n+1)/2)
                hf=false;
        }
        cout<<"Case #"<<ca<<": ";
        if(hf) cout<<"BAD"<<endl;
        else
            cout<<"GOOD"<<endl;
    }
    return 0;
}

