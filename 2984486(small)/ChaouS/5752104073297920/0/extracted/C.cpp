#include <bits/stdc++.h>
#define N 1111
using namespace std;

map<vector<int> ,int> m;
int n;
void solve(int pos,vector<int> x){
    if(pos == n) m[x]++;
    else{
        for(int i = 0; i < n; ++i)
        {   swap(x[i],x[pos]);
            solve(pos+1,x);
            swap(x[i],x[pos]);
        }
    }
}
map<vector<int> , int>::iterator it;
vector< pair< int,vector<int> > > valores;

int a[N];
int main(){
    freopen("in.c","r",stdin);
    freopen("salida.cpp","w",stdout);
    /*
    n = 5;
    vector<int> x;
        for(int i = 0; i < n; ++i)
            x.push_back(i);
    solve(0,x);

    for(it = m.begin(); it != m.end(); ++it){
      //  x = it->first;
        //for(int i = 0; i < n; ++i)
         //   cout << x[i] <<" ";
       // cout <<"f = "<<it->second<<endl;
    valores.push_back(pair< int,vector<int> > (it->second,it->first));
    }

    sort(valores.rbegin(),valores.rend());

    for(int i = 0; i < min((int)valores.size(),20); ++i)
    {   cout << "f = "<<valores[i].first<<"  ";
        x = valores[i].second;
         for(int i = 0; i < n; ++i)
            cout << x[i] <<" ";
        cout << endl;
    }*/


    int tc , nc = 1;
    cin >> tc;
    while(tc--){
        cin >> n;
        for(int i = 0; i < n; ++i)
            cin >> a[i];

        double prob = 0;

        if(a[0] == 1 && a[1] == 2) prob += 0.5;

            set<int> s;
            for(int i = 0; i < 10; ++i)
                s.insert(a[i]);

            int dif = abs(*s.begin() - *s.rbegin());
            if( dif <= 20 ) prob += 0.5;

            for(int i = 10; i < 100; ++i)
                s.insert(a[i]);

            dif = abs(*s.begin() - *s.rbegin());
            if( dif <= 200 ) prob += 0.4;

            for(int i = 100; i < 500; ++i)
                s.insert(a[i]);

            dif = abs(*s.begin() - *s.rbegin());
            if( dif <= 600 ) prob += 0.3;

            for(int i = 500; i < 700; ++i)
            s.insert(a[i]);

            dif = abs(*s.begin() - *s.rbegin());
            if( dif <= 900 ) prob += 0.2;


            for(int i = 0; i  + 1< n; ++i)
            {   dif = abs(a[i] - a[i+1]);
                if(dif <= 1) prob += 0.030; else
                if(dif <= 5) prob += 0.020; else
                if(dif <= 10) prob += 0.006; else
                if(dif <= 50) prob += 0.0006; else
                if(dif <= 100) prob += 0.00005;
            }

        int c = 0;
        for(int i = 0; i < n; ++i)
            if(a[i+1] < a[i]){ c = i; break; }

        if(c >= 500) prob += 0.3;
        else
            if(c >= 100) prob += 0.2;
            else
                if(c >= 50) prob +=0.1;


        printf("Case #%d: ",nc++);
        if(prob >= 0.4) puts("BAD");
        else puts("GOOD");
    }



    return 0;
}

