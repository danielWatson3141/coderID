#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int qq = 1; qq <= t; ++qq)
    {
        int n;
        cin >> n;
        bool good = true;
        for (int i = 0; i < n; ++i)
        {
            int t;
            cin >> t;
            if (t == i) good = false;
        }

        if (good)
            cout << "Case #" << qq << ": GOOD" << endl;
        else
            cout << "Case #" << qq << ": BAD" << endl;
    }
    return 0;
}
