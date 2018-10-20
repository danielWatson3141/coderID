#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define min(a,b) ((a<b)?a:b)

int main()
{
    int T;
    cin >> T;
    for (int c = 1; c <= T; c++) {
        int N, L;
        cin >> N >> L;
        vector<string> O(N), E(N);
        for (int i = 0; i < N; i++)
            cin >> O[i];
        for (int i = 0; i < N; i++)
            cin >> E[i];

        int shortest = 99999;
        for (int j = 0; j < N; j++) {
            vector<int> idxs;
            for (int k = 0; k < L; k++)
                if (O[0][k] != E[j][k])
                    idxs.push_back(k);
            int k;
            vector<string> F(E.begin(), E.end());
            for (k = 0; k < N; k++) {
                string cstr = O[k];
                for (int a = 0; a < idxs.size(); a++)
                    cstr[idxs[a]] = (cstr[idxs[a]] == '0' ? '1' : '0');
                vector<string>::iterator it = find(F.begin(), F.end(), cstr);
                if (it == F.end())
                    break;
                F.erase(it);
            }
            if (k == N)
                shortest = min(shortest, idxs.size());
        }
        cout << "Case #" << c << ": ";
        if (shortest == 99999)
            cout << "NOT POSSIBLE" << endl;
        else
            cout << shortest << endl;
    }
    return 0;
}
