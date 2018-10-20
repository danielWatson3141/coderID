//
//  main.cpp
//  C
//
//  Created by Zhou Sun on 4/25/14.
//  Copyright (c) 2014 Zhou Sun. All rights reserved.
//

#include <iostream>
using namespace std;
int a[10000];
int b[10000];
int main(int argc, const char * argv[])
{
    freopen ("c.in.txt","r",stdin);
    freopen ("c.out.txt","w",stdout);

    
    /*for (int i=0; i<100; i++) {
        a[i]=i;b[i]=i;
    }
    for (int i=0; i<100; i++) {
        int b=arc4random()%100;
        cout<<b<<' '<<100<<endl;
        swap(a[i], a[b]);
        
    }*/
    int n,ts;
    cin>>ts;
    for (int tt=1;tt<=ts; tt++) {
        cin>>n; 
    for (int i=0; i<n; i++) {
        cin>>a[i];
        b[i]=i;
    }
    int s1=0;
    for (int i=0; i<n; i++) {
        int k=0;
        for (int j=0; j<n; j++) {
            if (b[j]==a[i]) {
                k=j;
            }
        }
        //cout<<k-i<<' '<<100-i<<endl;
        swap(b[k], b[i]);
        s1+=2*(k-i) -(n-i);
    }
        cout<<"Case "<<tt<<": ";
        if (s1<0) {
            cout<<"BAD\n";
        }
        else{
            cout<<"GOOD\n";
        }
    }
    
    // insert code here...
    /*
    for (int i=0; i<100; i++) {
        a[i]=i;
    }
    for (int i=0; i<100; i++) {
        int b=arc4random()%(100-i);
        cout<<b<<' '<<100-i<<endl;
        swap(a[i], a[i+b]);
        
    }
    int s1=0;
    int s2=0;
    for (int i=0; i<100; i++) {
        if(i<50) {
            s1+=a[i];
        }
        else{
            s2+=a[i];
        }
        cout<<a[i]<<' ';
    }
    cout<<endl;
    cout<<s1<<' '<<s2<<endl;*/
    return 0;
}

