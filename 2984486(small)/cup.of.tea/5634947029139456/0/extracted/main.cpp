#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <iterator>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;




int main()
{
    ios_base::sync_with_stdio(false);
#define cin in
#define cout out
    ifstream in("input.txt");
    ofstream out("output.txt");
    int nb_cas;
    cin>>nb_cas;
    for(int cas=1;cas<=nb_cas;cas++)
    {
        cout<<"Case #"<<cas<<": ";
        int N,L;
        cin>>N>>L;
        vector<string> v1(N),v2(N);
        set<string> s;
        for(int c=0;c<N;c++)
        {
            cin>>v1[c];
            s.insert(v1[c]);
        }

        for(int c=0;c<N;c++)
        {
            cin>>v2[c];
        }
        int mini = 10000000;
        for(int c=0;c<(1<<(L+1));c++)
        {
            int trouves = 0;
            int bla = 0;
            for(int c2=0;c2<N;c2++)
            {
                bla = 0;
                string ori = v2[c2];
                for(int c3=0;c3<L;c3++)
                {
                    if((1<<c3) & c)
                    {
                        bla++;
                        if(ori[c3]=='1') ori[c3]='0';
                        else ori[c3]='1';
                    }
                }
                if(s.find(ori)!=s.end()) trouves++;
            }
            if(trouves == N)
            {
                mini = min(mini,bla);
            }
        }
        if(mini < 10000)
            cout<<mini<<endl;
        else cout<<"NOT POSSIBLE"<<endl;
    }
}
