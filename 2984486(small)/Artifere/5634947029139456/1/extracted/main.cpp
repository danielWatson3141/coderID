#include <iostream>
#include <set>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;

string goal[150], curState[150];
int nbDev, length;
int best;
int affect[50];



int main()
{
    freopen("t.in", "r", stdin);
    freopen("t.out", "w", stdout);

    int nbT;
    cin >> nbT;
    for (int t = 1; t <= nbT; t++)
    {
        cin >> nbDev >> length;
        for (int i = 0; i < nbDev; i++)
            cin >> curState[i];
        for (int i = 0; i < nbDev; i++)
            cin >> goal[i];

        sort(goal, goal+nbDev);

        for (int i = 0; i< length; i++)
            affect[i] = 0;
        best = 10000;



        for (int i = 0; i < nbDev; i++)
        {
            int cur =  0;
            for (int j = 0; j< length; j++)
            {
                if (goal[i][j] != curState[0][j])
                {
                    affect[j] = 1;
                    cur++;
                }
                else
                    affect[j] = 0;
            }



            string curObtained[150];
            for (int k = 0; k < nbDev; k++)
            {
                string a = curState[k];
                for (int j =0; j < length; j++)
                {
                    if (affect[j])
                    {
                        if (a[j] == '0')
                            a[j] = '1';
                        else
                            a[j] = '0';
                    }
                }
                curObtained[k] = a;
            }

            sort(curObtained, curObtained+nbDev);

            bool ok = true;

            for (int k = 0; k < nbDev; k++)
            {
                if (curObtained[k] != goal[k])
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
                best = min(best, cur);
        }






        cout << "Case #" << t << ": ";
        if (best == 10000)
            cout << "NOT POSSIBLE\n";
        else
            cout << best << '\n';



    }
    return 0;
}
