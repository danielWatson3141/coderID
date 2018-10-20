#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    vector<int> p;
    for (int o=0;o<t;o++){
        cout << "Case #" << o+1 << ": ";
        int n;
        cin >> n;
        vector <int> a(n, 0);
        for (int i=0;i<n;i++)
            cin >> a[i];
        int m = 0;
        for (int i=0;i<n;i++)
        for (int j=i+1;j<n;j++)
            if (a[i] > a[j])
                m++;
        p.push_back(m);
        if (m > 238000)
            cout << "GOOD" << endl;
        else
            cout << "BAD" << endl;
    }
    for (int j=200000;j<260000;j++){
        int m=0;
        for (int i=0;i<p.size();i++){
            if (p[i] < j)
                m++;
        }
        if ((m*1.0/p.size()) > 0.15){
            cout << j;
            break;
        }
    }
    return 0;
}
