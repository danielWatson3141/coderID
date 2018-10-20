#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<sstream>

#define forn(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()

using namespace std;

string calc(int n)
{
    vector<int> vec(n);
    forn(i,n)
        cin >> vec[i];

}

int main()
{
    freopen("C-small.in","r",stdin);
    freopen("C.out","w",stdout);
    int casos;
    cin >> casos;
    vector<pair<int,int> > vec;
    forn(i,casos)
        vec.push_back(make_pair(0,i));
    int N;
    for(int casito = 0; casito < casos; casito++)
    {
        cin >> N;
        vector<int> vec2(N);
        forn(i,N)
            cin >> vec2[i];
        forn(i,N)
        {
            if(vec2[i]>=i)
                vec[casito].first += vec2[i]-i;
            else
                vec[casito].first += N+vec2[i]-i;
        }
    }
    sort(all(vec));
    for(int casito = 1; casito <= casos; casito++)
    {
        cout << "Case #" <<casito <<": ";
        int pos = 0;
        forn(i,casos)
        if(vec[i].second == casito-1)
            pos = i;
        if(pos<casos/2)
            cout << "BAD" << endl;
        else
            cout << "GOOD" << endl;
    }
}
