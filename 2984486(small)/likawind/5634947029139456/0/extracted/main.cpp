//
//  main.cpp
//  A
//
//  Created by Zhou Sun on 4/25/14.
//  Copyright (c) 2014 Zhou Sun. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;
int f[1000];
int main(int argc, const char * argv[])
{
    freopen ("a.in.txt","r",stdin);
    freopen ("a.out.txt","w",stdout);
    int ts,n,x,y,l;
    cin>>ts;
    for (int tt=1; tt<=ts;tt++) {
        cin>>n>>l;
        string s1[100];
        string s2[100];
        for (int i=0; i<n; i++) {
            cin>>s1[i];
        } 
        vector<string> ss2;
        for (int i=0; i<n; i++) {
            cin>>s2[i];
            ss2.push_back(s2[i]);
        }
        sort(ss2.begin(), ss2.end());
        int mi=1000;
        for (int i=0; i<n; i++) {
            memset(f, 0, sizeof(f));
            int ff=0;
            //cout<<s2[i]<<"saeaf"<<  endl;
            for (int j=0; j<l; j++) {
                if (s1[0][j]!=s2[i][j]){
                    f[j]=1;
                    ff++;
                }

            }
            vector<string> ss;
            for (int i=0; i<n;i++) {
                string s=s1[i];
                for (int j=0; j<l; j++) {
                    if (f[j]) {
                        if (s[j]=='0') {
                            s[j]='1';
                        }
                        else
                            s[j]='0';
                    }
                }
                //cout<<s<<endl;
                ss.push_back(s);
                
            }
            bool flag=1;
            sort(ss.begin(), ss.end());
            for (int j=0; j<n;j++) {
                if (ss[j]!=ss2[j]) {
                    flag=0;
                    
                }
            }
            if (flag) {
                if (mi>ff) {
                    mi=ff;
                }
            }
            
        }
        cout<<"Case #"<<tt<<": ";
        if (mi==1000) {
            cout<<"NOT POSSIBLE\n";
        }else cout<<mi<<endl;
    }
    return 0;
}

