#include <iostream>
#include <set>
#include <string>
#include <cstdio>
#include <vector>

using namespace std;


vector<int> neighb[1001];
int nbNode;

int dyn[2][1001];


int rep(int node, int pere, int total)
{
    if (dyn[total][node] != -1)
        return dyn[total][node];
    int tmp = 0;
    if (total)
    {
        for (auto x : neighb[node])
            if (x != pere)
                tmp += rep(x, node, 1);
        tmp++;
    }

    else if (neighb[node].size() == 2)
    {
        for (auto x : neighb[node])
        {
            if (x != pere)
            {
        //    cout << x << "vs" << pere<< endl;
                tmp += rep(x, node, 1);
            }
        }
    }

    else if (neighb[node].size() > 3)
    {
        vector<int> totalTrue, totalFalse;
        for (auto x : neighb[node])
        {
            if (x != pere)
            {
        //    cout << x << "vs" << pere<< endl;
                totalTrue.push_back(rep(x, node, 1));
                totalFalse.push_back(rep(x, node, 0));
            }
        }
        int max1 = 0, max2 = 0;
        int idMax1, idMax2;

        for (int i = 0; i < totalTrue.size(); i++)
        {
            if (totalTrue[i]-totalFalse[i] >= max2)
            {
                if (totalTrue[i]-totalFalse[i] >= max1)
                {
                    max2 = max1;
                    idMax2 = idMax1;
                    idMax1 = i;
                    max1 = totalTrue[i]-totalFalse[i];
                }

                else
                {
                    idMax2 = i;
                    max2 = totalTrue[i]-totalFalse[i];
                }
            }
        }

        for (int i = 0; i < totalTrue.size(); i++)
        {
            if (i != idMax1 && i != idMax2)
                tmp += totalTrue[i];
            else
                tmp += totalFalse[i];
        }
    }


    else
    {
        for (auto x : neighb[node])
        {
            if (x != pere)
            {
        //    cout << x << "vs" << pere<< endl;
                tmp += rep(x, node, 0);
            }
        }
    }

    dyn[total][node] = tmp;

    return tmp;
}


int repFirst(int node)
{
    int tmp = 0;

    if (neighb[node].size() == 1)
    {
        for (auto x : neighb[node])
        {
                tmp += rep(x, node, 1);
        }
    }

    else if (neighb[node].size() > 2)
    {
        vector<int> totalTrue, totalFalse;
        for (auto x : neighb[node])
        {

        //    cout << x << "vs" << pere<< endl;
                totalTrue.push_back(rep(x, node, 1));
                totalFalse.push_back(rep(x, node, 0));

        }
        int max1 = 0, max2 = 0;
        int idMax1, idMax2;

        for (int i = 0; i < totalTrue.size(); i++)
        {
            if (totalTrue[i]-totalFalse[i] >= max2)
            {
                if (totalTrue[i]-totalFalse[i] >= max1)
                {
                    max2 = max1;
                    idMax2 = idMax1;
                    idMax1 = i;
                    max1 = totalTrue[i]-totalFalse[i];
                }

                else
                {
                    idMax2 = i;
                    max2 = totalTrue[i]-totalFalse[i];
                }
            }
        }

        for (int i = 0; i < totalTrue.size(); i++)
        {
            if (i != idMax1 && i != idMax2)
                tmp += totalTrue[i];
            else
                tmp += totalFalse[i];
        }
    }


    else
    {
        for (auto x : neighb[node])
        {
                tmp += rep(x, node, 0);

        }
    }


    return tmp;
}




int main()
{
    freopen("t.in", "r", stdin);
    freopen("t.out", "w", stdout);
    int nbDev, length;
    int nbT;
    cin >> nbT;
    for (int t = 1; t <= nbT; t++)
    {
        cin >> nbNode;
        for (int i = 1; i <= nbNode; i++)
            neighb[i].clear();
        for (int i = 0; i < nbNode-1; i++)
        {
            int a,b;
            cin >> a >> b;
            neighb[a].push_back(b);
            neighb[b].push_back(a);
            //cout << a << "vs" << b << endl;
        }

        int minRep = 1002;
        for (int root = 1; root <= nbNode; root++)
        {
            for (int a = 1; a <= nbNode; a++)
            {
                dyn[0][a] = -1;
                dyn[1][a] = -1;
            }
    //        cout << root << " : " << neighb[root].size()<<endl;
            int cur = repFirst(root);

            minRep = min(minRep, cur);
        }



        cout << "Case #" << t << ": " << minRep << '\n';




    }
    return 0;
}
