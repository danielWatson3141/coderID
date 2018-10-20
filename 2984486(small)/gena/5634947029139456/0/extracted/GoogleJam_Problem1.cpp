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


// ----------
// LARGE
//
int SolveLarge(unsigned __int64 *vo, unsigned __int64 *vd, int n, int l)
{
    int s = 0;
    unsigned __int64 vom[150];
    int best = 10000;

    for(int o = 0; o < n; ++o)
    {
        int mod = 0;
        // Find diff of device 0 with outlet o
        unsigned __int64 f = vd[0]^vo[o];

        // modify outlets
        for(int i = 0; i < n; ++i)
        {
            vom[i] = vo[i] ^ f;
        }

        bool all = true;
        // Try all devices
        for(int i = 0; i < n; ++i)
        {
            unsigned __int64 d = vd[i];
            
            int fo = 0;
            for(; fo < n - i; ++fo)
            {
                if(d == vom[fo])
                {
                    break;
                }
            }

            if(fo >= n - i)
            {
                all = false;
                break;
            }
            else
            {
                vom[fo] = vom[n - i - 1];
            }
        }

        if(all)
        {
            int t = 0;
            for(int i = 0; i < l; ++i)
            {
                if(f&(1ull << i))
                {
                    ++t;
                }
            }

            if(t < best)
            {
                best = t;
            }
        }
    }

    if(best <= l)
    {
        return best;
    }
    else
    {
        return -1;
    }
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

    char buf[10240];

    char * ps = fgets(buf, sizeof(buf), fin);
    int numTests = atoi(ps);
    
    //Testing
    //Test();

    unsigned __int64 o[200];
    unsigned __int64 d[200];

    for(int t = 1; t <= numTests; ++t)
    {
        ps = fgets(buf, sizeof(buf), fin);
        ps = strtok(ps, " ");
        long n = atoi(ps);
        ps += strlen(ps) + 1;
        //ps = strtok(ps, " ");
        long l = atoi(ps);

        memset(o, 0, sizeof(o));
        memset(d, 0, sizeof(o));

        for(int p = 0; p < 2; ++p)
        {
            ps = fgets(buf, sizeof(buf), fin);
            char * ps1 = ps;
    
            for(int b = 0; b < n; ++b)
            {
                for(int i = 0; i < l; ++i)
                {
                    if(ps1[i] == '1')
                    {
                        if(p == 0)
                        {
                            o[b] |= (1ull << i);
                        }
                        else
                        {
                            d[b] |= (1ull << i);
                        }
                    }
                }
                ps1 += l+1;
            }
        }

        int res = SolveLarge(o, d, n, l);
        
        if(res >= 0)
        {
            fprintf(fout, "Case #%d: %d\n", t, res);
        }
        else
        {
            fprintf(fout, "Case #%d: NOT POSSIBLE\n", t);
        }
    }

    fclose(fin);
    fclose(fout);

    __int64 end = GetTickCount64();

    printf("Time = %.3f sec\n", ((double)(end - start))/1000);

	return 0;
}

