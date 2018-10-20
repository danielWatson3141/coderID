// GoogleJam_Problem1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "StringHelpers.h"
#include "windows.h"

const unsigned int c_MaxD = 1000;


struct Item
{
    unsigned __int64 v[3];

    Item()
    {
        v[0] = 0;
        v[1] = 0;
        v[2] = 0;
    }

    bool operator <(const Item& rhs) const
    {
        return memcmp(v, rhs.v, sizeof(v)) < 0;
    }

    Item& operator &(const Item& rhs)
    {
        v[0] &= rhs.v[0];
        v[1] &= rhs.v[1];
        v[2] &= rhs.v[2];
    }

    Item& operator ^(const Item& rhs)
    {
        v[0] &= rhs.v[0];
        v[1] &= rhs.v[1];
        v[2] &= rhs.v[2];
    }

    Item& operator |(const Item& rhs)
    {
        v[0] &= rhs.v[0];
        v[1] &= rhs.v[1];
        v[2] &= rhs.v[2];
    }
};

//void Print(Item * v, long nb)
//{
//    for(int i = 0; i < nb; ++i)
//    {
//        printf("%d ", v[i].p);
//    }
//    printf("\n");
//}

int v[c_MaxD][c_MaxD];
int d[c_MaxD];
int n = 0;

int SolveP(int s, int p, int * numn)
{
    *numn = 1;
    int f = p < 0 ? -1 : 0; 
    if(d[s] == 1 + f)
    {
        return 1;
    }

    if(d[s] == 2 + f)
    {
        int res = 0;
        for(int i = 0; i < d[s]; ++i)
        {
            if(v[s][i] != p)
            {
                int nc = 0;
                SolveP(v[s][i], s, &nc);
                *numn = nc + 1;
                return 1;
            }
        }
    }

    if(d[s] == 3 + f)
    {
        int res = 0;
        for(int i = 0; i < d[s]; ++i)
        {
            if(v[s][i] != p)
            {
                int nc = 0;
                res += SolveP(v[s][i], s, &nc);
                *numn += nc;
            }
        }

        return res + 1;
    }

    // need to select best 2
    int r1 = 0;
    int nc1 = 0;
    int r2 = 0;
    int nc2 = 0;
    for(int i = 0; i < d[s]; ++i)
    {
        if(v[s][i] != p)
        {
            int nc = 0;
            int res = SolveP(v[s][i], s, &nc);
            *numn += nc;
            if(res > r2)
            {
                if(res > r1)
                {
                    r1 = res;
                    nc1 = nc;
                }
                else
                {
                    r2 = res;
                    nc2 = nc;
                }
            }
        }
    }

    return r1 + r2 + 1;
}

int Solve(int s)
{
    if(d[s] == 0)
    {
        return 1;
    }

    int nc = 0;
    return SolveP(s, -1, &nc);
}

// ----------
// LARGE
//
int SolveLarge()
{
    int best = 0;

    for(int i = 0; i < n; ++i)
    {
        int s = 0;
        int r = Solve(i);
        if(r > best)
        {
            best = r;
        }
    }

    return n - best;    
}


bool Test(Item *v, long nb)
{
    return true;
}

//void Test()
//{
//    {
//        Item v1[10] = { {0, 0.01, 0}, {0, 0.02, 0}, {0, 0.03, 0}, {0, 0.04, 0}, {0, 0.05, 0},
//                        {1, 0.11, 0}, {1, 0.12, 0}, {1, 0.13, 0}, {1, 0.14, 0}, {1, 0.15, 0} };
//
//        Test(v1, sizeof(v1)/sizeof(v1[0])/2);
//    }
//
//
//}

int _tmain(int argc, _TCHAR* argv[])
{
    __int64 start = GetTickCount64();
    if(argc < 3)
    {
        printf("Error. Need in and out files\n");
        return -1;
    }

    FILE * fin = NULL;
    FILE * fout = NULL;

    fin = _fsopen(argv[1], "rt", _SH_DENYNO);
    if(fin == NULL)
    {
        printf("Can't open %s\n", argv[1]);
        return -1;
    }

    fout = _fsopen(argv[2], "w", _SH_DENYNO);
    if(fout == NULL)
    {
        printf("Can't open %s\n", argv[2]);
        return -1;
    }

    char buf[20240];

    char * ps = fgets(buf, sizeof(buf), fin);
    int numTests = atoi(ps);
    
    //Testing
    //Test();

    //char (*v)[c_MaxD] = new char[c_MaxD][c_MaxD];
    //int d[c_MaxD];

    for(int t = 1; t <= numTests; ++t)
    {
        ps = fgets(buf, sizeof(buf), fin);
        n = atoi(ps);

        memset(d, 0, sizeof(d));

        for(int p = 0; p < n - 1; ++p)
        {
            ps = fgets(buf, sizeof(buf), fin);
            char * ps1 = ps;
            ps = strtok(ps, " ");
            long v1 = atoi(ps) - 1;
            ps += strlen(ps) + 1;
            long v2 = atoi(ps) - 1;
            
            v[v1][d[v1]] = v2;
            ++(d[v1]);

            v[v2][d[v2]] = v1;
            ++(d[v2]);
        }

        int res = SolveLarge();
        
        fprintf(fout, "Case #%d: %d\n", t, res);
    }

    fclose(fin);
    fclose(fout);

    __int64 end = GetTickCount64();

    printf("Time = %.3f sec\n", ((double)(end - start))/1000);

	return 0;
}

