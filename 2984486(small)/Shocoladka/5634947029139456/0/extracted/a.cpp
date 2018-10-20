#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

string sw[200];
string pr[200];

multiset<string> st;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for(int t = 0; t < T; t++)
    {
        cout << "Case #" << t + 1 << ": ";
        int n, l;
        cin >> n >> l;
        for(int i = 0; i < n; i++)
            cin >> sw[i];
        for(int i = 0; i < n; i++)
            cin >> pr[i];
        int mnans = 200;

        for(int i = 0; i < (1 << l); i++)
        {
            st.clear();
            int ans = 0;
            for(int j = 0; j < l; j++)
                if((i >> j) % 2 == 1)
                    ans++;

            string newsw[200];
            for(int j = 0; j < n; j++)
                for(int k = 0; k < l; k++)
                    if((sw[j][k] == '1' && (i >> k) % 2 == 0) ||
                            (sw[j][k] == '0' && (i >> k) % 2 == 1))
                        newsw[j] += '1';
                    else
                        newsw[j] += '0';
            for(int j = 0; j < n; j++)
            {
                st.insert(pr[j]);
            }

            for(int j = 0; j < n; j++)
            {
                st.erase(newsw[j]);
            }

            if(st.size() == 0)
                mnans = min(mnans, ans);
        }

        if(mnans == 200)
            cout << "NOT POSSIBLE" << endl;
        else
            cout << mnans << endl;
    }
}
