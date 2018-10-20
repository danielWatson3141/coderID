#include <iostream>
#include <fstream>
#define MAXN 200
using namespace std;

ifstream fin;
ofstream fout;

struct PLAN
{
    long long design;
    long long num;
    bool used;
};

PLAN plans[MAXN];

long long outlets[MAXN];
long long devices[MAXN];
int numOut[MAXN];
int numDev[MAXN];

int number, length, total_ans,deviceNum,outletNum;


void init(){
    for (int i=0;i<MAXN;i++)
    {
        outlets[i]=0;
        devices[i]=0;
        plans[i].design=0;
        plans[i].num=0;
        plans[i].used=false;
        numOut[i]=0;
        numDev[i]=0;
    }
    number=0;
    length=0;
    total_ans=0;
    deviceNum=0;
    outletNum=0;
}

void add_plan(long long design)
{
    bool found = false;
    for (int i=0;i<total_ans;i++)
        if (design == plans[i].design)
    {
        found = true;
    }
    if (!found)
    {
        plans[total_ans].design=design;
        plans[total_ans].num=1;
        plans[total_ans].used=true;
        total_ans++;
    }
}

void update_plan(long long design)
{
    for (int i=0;i<total_ans;i++)
        if (design == plans[i].design)
    {
        if (!plans[i].used)
        {
            plans[i].used=true;
            plans[i].num++;
        }
        break;
    }
}

void clear_used(){
    for (int i=0;i<total_ans;i++)
        plans[i].used=false;
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
    fin.open("A-large.in",ios::in);
    fout.open("output.txt",ios::trunc);
    int cases;
    fin>>cases;
    for (int caseNum = 1; caseNum <= cases; caseNum++){
       init();
       fin>>number;
       fin>>length;

       //input outlets
       char c;
       long long tmp;
       for (int i=0;i<number;i++)
       {
           tmp=0;
           for (int j=0;j<length;j++)
           {

               fin>>c;
               if (c == '1')
                  tmp=(tmp<<1)+1;
               else
                  tmp=(tmp<<1)+0;
           }
           bool found =false;
           for (int k=0;k<outletNum;k++)
                if (tmp == outlets[k])
                {
                    found=true;
                    numOut[k]++;
                }
           if (!found)
           {
               outlets[outletNum]=tmp;
               numOut[outletNum]=1;
               outletNum++;
           }
       }
       //input devices
       for (int i=0;i<number;i++)
       {
           tmp=0;
           for (int j=0;j<length;j++)
           {

               fin>>c;
               if (c == '1')
                  tmp=(tmp<<1)+1;
               else
                  tmp=(tmp<<1)+0;
           }
           bool found =false;
           for (int k=0;k<deviceNum;k++)
                if (tmp == devices[k])
                 {
                     found=true;
                     numDev[k]++;
                 }
           if (!found)
           {
               devices[deviceNum]=tmp;
               numDev[deviceNum]=1;
               deviceNum++;
           }
       }
       if (deviceNum != outletNum)
       {
           fout<<"Case #"<<caseNum<<": NOT POSSIBLE"<<endl;
           continue;
       }
       else
            number=deviceNum;
       // use the first one to set base
       for (int i=0;i<number;i++)
       if (numDev[0] == numOut[i])
       {
           tmp = devices[0] ^ outlets[i];
           add_plan(tmp);
       }
       for (int i=1;i<number;i++)
       {
           clear_used();
           for (int j=0;j<number;j++)
           if (numDev[i] == numOut[j])
           {
               tmp = devices[i] ^ outlets[j];
               update_plan(tmp);
           }
       }
       bool haveAns = false;
       int ans = length+1;
       long long ansDesign =0;
       for (int i=0;i<total_ans;i++)
       {
           if (plans[i].num == number)
           {
               int tmpOnes = sumOnes(plans[i].design);
               haveAns = true;
               if (tmpOnes < ans)
               {
                   ans = tmpOnes;
                   ansDesign=plans[i].design;
               }
           }
       }
       if (haveAns)
       {
           fout<<"Case #"<<caseNum<<": "<<ans<<endl;
       } else
       {
           fout<<"Case #"<<caseNum<<": NOT POSSIBLE"<<endl;
       }
    }
    return 0;
}
