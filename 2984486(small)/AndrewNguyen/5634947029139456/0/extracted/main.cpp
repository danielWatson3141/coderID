//
//  main.cpp
//  Charging Chaos
//

#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main(int argc, const char * argv[])
{
    freopen("A-small-attempt0.in.txt", "r", stdin);
    freopen("A-small-attempt0.out.txt", "w", stdout);
    //freopen("test.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    int ncases;
    scanf("%d", &ncases);
    
    for (int i = 0; i < ncases; ++i)
    {
        int N, L;
        scanf("%d %d", &N, &L);
        vector<string> outlet;
        vector<string> device;
        
        char str[60];
        for (int j = 0; j < N; ++j)
        {
            scanf("%s", str);
            outlet.push_back(string(str));
        }
        for (int j = 0; j < N; ++j)
        {
            scanf("%s", str);
            device.push_back(string(str));
        }
        //
        int mx = 1000;
        for (int j = 0; j < outlet.size(); ++j)
        {
            //vector<string> outlet1(outlet);
            string o = outlet[j];
            for (int k = 0; k < device.size(); ++k)
            {
//                if (0 == j && 1 == k)
//                {
//                    int tmp = 3;
//                }
                string d = device[k];
                vector<int> transform;
                for (int l = 0; l < L; ++l)
                {
                    if (o[l] != d[l])
                        transform.push_back(l);
                }
                if (transform.size() > mx) continue;
                //
                vector<string> outlet1(outlet);
                for (int l = 0; l < outlet1.size(); ++l)
                {
                    for (int m = 0; m < transform.size(); ++m)
                    {
                        int idx = transform[m];
                        if (outlet1[l][idx] == '0')
                            outlet1[l][idx] = '1';
                        else outlet1[l][idx] = '0';
                    }
                }
                //
                bool used[N+10];
                int cnt = 0;
                for (int l = 0; l < N; l++)
                    used[l] = false;
                for (int l = 0; l < N; ++l)
                {
                    for (int m = 0; m < N; ++m)
                    {
                        if (used[m])
                            continue;
                        if (device[l] == outlet1[m])
                        {
                            used[m] = true;
                            cnt++;
                        }
                    }
                }

                if (cnt == N)
                {
                    mx = transform.size();
                }
            }
        }
        
        if (mx == 1000)
        {
            printf("Case #%d: NOT POSSIBLE\n", i+1);
        }
        else
        {
            printf("Case #%d: %d\n", i+1, mx);
        }
    }
    
    fclose(stdin);
    //fclose(stdout);
    return 0;
}

