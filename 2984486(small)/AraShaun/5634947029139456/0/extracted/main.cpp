#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <bitset>

using namespace std;

struct node
{
    int id;
    vector<pair<int, int> > adj;
};

int main()
{
    FILE *in, *output;
    in = fopen("charge.txt", "r");
    output = fopen("out.txt", "w");
    int t;
    fscanf(in, "%d", &t);
    for(int q = 0; q < t; q++)
    {
        int n, l;
        fscanf(in, "%d %d", &n, &l);
        node out[n];
        node dev[n];
        for(int i = 0; i < n; i++)
        {
            char temp[42];
            fscanf(in, "%s", &temp);
            string xstu = temp;
            bitset<42> temp2(xstu);
            out[i].id = temp2.to_ulong();
        }
        for(int i = 0; i < n; i++)
        {
            char temp[42];
            fscanf(in, "%s", &temp);
            string xstu = temp;
            bitset<42> temp2(xstu);
            dev[i].id = temp2.to_ulong();
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int diff = out[i].id^dev[j].id;
                pair<int, int> temp;
                temp.first = i;
                temp.second = diff;
                dev[j].adj.push_back(temp);
                temp.first = j;
                out[i].adj.push_back(temp);
            }
        }
        vector<int> ans;
        for(int i = 0; i < n; i++)
        {
            bool test[n];
            for(int j = 0; j < n; j++)
            {
                test[j] = false;
            }
            int c = out[0].adj[i].second;
            for(int j = 0; j < n; j++)
            {
                for(int k = 0; k < n; k++)
                {
                    if(dev[j].adj[k].second == c)
                    {
                        if(test[dev[j].adj[k].first]) {k = n; j = n;}
                        else
                        {
                            test[dev[j].adj[k].first] = true;
                        }
                    }
                }
            }
            bool good = true;
            for(int j = 0; j < n; j++)
            {
                if(test[j] == false) {good = false;}
            }
            if(good) ans.push_back(c);
        }
        fprintf(output, "Case #%d: ", q+1);
        if(ans.size() > 0)
        {
            int lowest = 99999999;
            for(int i = 0; i < ans.size(); i++)
            {
                bitset<42> temp3(ans[i]);
                if(temp3.count() < lowest)
                {
                    lowest = temp3.count();
                }
            }
            fprintf(output, "%d\n", lowest);
        }
        else {fprintf(output, "NOT POSSIBLE\n");}
    }
    return 0;
}
