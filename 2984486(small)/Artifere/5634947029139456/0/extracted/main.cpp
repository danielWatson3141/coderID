#include <iostream>
#include <set>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;

string goal[150], curState[150];
int nbDev, length;
int best;
int affect[11];


void rec(int id, int nbUsed)
{
    if (id >= length)
    {
        string curObtained[150];
        for (int i = 0; i < nbDev; i++)
        {
            string a = curState[i];
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
            curObtained[i] = a;
        }

        sort(curObtained, curObtained+nbDev);

        bool ok = true;

        for (int i = 0; i < nbDev; i++)
        {
            if (curObtained[i] != goal[i])
            {
                ok = false;
                break;
            }
        }
        if (ok)
            best = min(best, nbUsed);
        return;
    }


    affect[id] = 0;
    rec(id+1, nbUsed);

    affect[id] = 1;
    rec(id+1, nbUsed+1);



}



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
        best = 100;
        rec(0, 0);


        cout << "Case #" << t << ": ";
        if (best == 100)
            cout << "NOT POSSIBLE\n";
        else
            cout << best << '\n';



    }
    return 0;
}
