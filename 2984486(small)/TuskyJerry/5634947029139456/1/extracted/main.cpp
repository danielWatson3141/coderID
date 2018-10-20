#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
//#include <ctime>
#include <map>

using namespace std;

struct pack
{
    long long design;
    long long num;
    bool used;
};

pack packs[400];

long long outs[400];
long long dvs[400];
int numOut[400];
int numDev[400];

int n, length, tot,dNum,outNum;


void init(){
    for (int i=0;i<400;i++)
    {
        outs[i]=0;
        dvs[i]=0;
        packs[i].design=0;
        packs[i].num=0;
        packs[i].used=false;
        numOut[i]=0;
        numDev[i]=0;
    }
    n=0;
    length=0;
    tot=0;
    dNum=0;
    outNum=0;
}

void add_plan(long long design)
{
    bool found = false;
    for (int i=0;i<tot;i++)
        if (design == packs[i].design)
    {
        found = true;
    }
    if (!found)
    {
        packs[tot].design=design;
        packs[tot].num=1;
        packs[tot].used=true;
        tot++;
    }
}

void update_plan(long long design)
{
    for (int i=0;i<tot;i++)
        if (design == packs[i].design)
    {
        if (!packs[i].used)
        {
            packs[i].used=true;
            packs[i].num++;
        }
        break;
    }
}

void clear_used(){
    for (int i=0;i<tot;i++)
        packs[i].used=false;
}

int sumOnes(long long design)
{
    int ret = 0;
    while (design != 0)
    {
        ret+=(design & 1);
        design=design>>1;
    }
    return ret;
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
	ios :: sync_with_stdio(false);
    int cases;
    cin>>cases;
    for (int testk = 1; testk <= cases; testk++)
    {
       init();
       cin>>n;
       cin>>length;
       cout<<"Case #"<<testk<<": ";
       char c;
       long long tmp;
       for (int i=0;i<n;i++)
       {
           tmp=0;
           for (int j=0;j<length;j++)
           {

               cin>>c;
               if (c == '1')
                  tmp=(tmp<<1)+1;
               else
                  tmp=(tmp<<1)+0;
           }
           bool found =false;
           for (int k=0;k<outNum;k++)
                if (tmp == outs[k])
                {
                    found=true;
                    numOut[k]++;
                }
           if (!found)
           {
               outs[outNum]=tmp;
               numOut[outNum]=1;
               outNum++;
           }
       }
       for (int i=0;i<n;i++)
       {
           tmp=0;
           for (int j=0;j<length;j++)
           {

               cin>>c;
               if (c == '1')
                  tmp=(tmp<<1)+1;
               else
                  tmp=(tmp<<1)+0;
           }
           bool found =false;
           for (int k=0;k<dNum;k++)
                if (tmp == dvs[k])
                 {
                     found=true;
                     numDev[k]++;
                 }
           if (!found)
           {
               dvs[dNum]=tmp;
               numDev[dNum]=1;
               dNum++;
           }
       }
       if (dNum != outNum)
       {
           cout<<"NOT POSSIBLE"<<endl;
           continue;
       }
       else
            n=dNum;

       for (int i=0;i<n;i++)
       if (numDev[0] == numOut[i])
       {
           tmp = dvs[0] ^ outs[i];
           add_plan(tmp);
       }
       for (int i=1;i<n;i++)
       {
           clear_used();
           for (int j=0;j<n;j++)
           if (numDev[i] == numOut[j])
           {
               tmp = dvs[i] ^ outs[j];
               update_plan(tmp);
           }
       }
       bool haveAns = false;
       int ans = length+1;
       long long ansDesign =0;
       for (int i=0;i<tot;i++)
       {
           if (packs[i].num == n)
           {
               int tmpOnes = sumOnes(packs[i].design);
               haveAns = true;
               if (tmpOnes < ans)
               {
                   ans = tmpOnes;
                   ansDesign=packs[i].design;
               }
           }
       }
       if (haveAns)
       {
           cout<<ans<<endl;
       } else
       {
           cout<<"NOT POSSIBLE"<<endl;
       }
    }
    return 0;
}
