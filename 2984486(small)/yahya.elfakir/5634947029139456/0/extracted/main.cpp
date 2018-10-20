#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <bitset>
#include <cstring>
#define oo 1e6
using namespace std;
int N,L;
vector<string> all;
vector<string> devices;
void afficher(vector<string> a){
    for(int i=0;i<a.size();i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
int check(bitset<10> mask){
    vector<string> tocheck;
    for(int i=0;i<all.size();i++){
        tocheck.push_back(all[i]);
    }
    for(int i=0;i<10;i++){
        if(mask[i]){
            for(int j=0;j<tocheck.size();j++){
                    if(tocheck[j][i]=='0')
                tocheck[j][i]='1';
                else
                tocheck[j][i]='0';
            }
        }
    }

    sort(tocheck.begin(),tocheck.end());
    int a=0;
    for(int i=0;i<devices.size();i++){
        if(devices[i]!=tocheck[i])
            return oo;
    }
    return mask.count();
}
int meme[10][1<<10];
int solve(int idx,bitset<10> mask){
    if(idx==L){
        return check(mask);
    }
    int& ret=meme[idx][mask.to_ulong()];
    if(ret!=-1)
        return ret;
    ret=oo;
    int choice1=solve(idx+1,mask);
    bitset<10> nmask=mask;
    nmask[idx]=1;
    int choice2=solve(idx+1,nmask);
    ret=min(ret,min(choice1,choice2));
    return ret;
}
int main()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int t;
    int c=0;
    cin>>t;
    while(t--){
            c++;
            cout<<"Case #"<<c<<": ";
            all.clear();
            devices.clear();
            memset(meme,-1,sizeof(int)*10*(1<<10));
        cin>>N>>L;
        for(int i=0;i<N;i++){
            string x;
            cin>>x;
            all.push_back(x);
        }
        for(int i=0;i<N;i++){
            string x;
            cin>>x;
            devices.push_back(x);
        }
        sort(devices.begin(),devices.end());
        bitset<10> mask;
        mask.reset();
        int res=solve(0,mask);
        if(res>=oo)
            cout<<"NOT POSSIBLE"<<endl;
        else
            cout<<res<<endl;
    }
    return 0;
}
