#include <stdio.h>
#include <cstring>
struct elec
{
    char txt [60];
};

int devices_num,length;
elec devices[200];
elec plugs[200];
elec help[200];

int fn(int bit);
void flip(int bit);
bool compare(int bit);
void merge_sort(int start,int last,elec array[]);
void merge(int start,int end,elec array[]);
void intializer();

int setbit(int mask,int bit,int value);
int getbit(int mask,int bit);
int min(int x,int y);

const int inf=9999999;


int main()
{
    freopen("A-small-attempt0(1).in","r",stdin);
    freopen("c.out","w",stdout);
    int cases;
    scanf("%d",&cases);
    int p=1;
    while(cases--)
    {
        scanf("%d %d",&devices_num,&length);

        intializer();
        for(int i=0; i<devices_num; i++)
            scanf("%s",devices[i].txt);

        for(int i=0; i<devices_num; i++)
            scanf("%s",plugs[i].txt);

        merge_sort(0,devices_num-1,devices);
        merge_sort(0,devices_num-1,plugs);

        //for(int i=0; i<devices_num; i++)
        //    printf("%s\n",devices[i].txt);

        printf("Case #%d: ",p);
        int ans=fn(0);
        if(ans==inf)
        printf("NOT POSSIBLE");
        else
            printf("%d",ans);
        printf("\n");

        p++;
    }

    return 0;
}


void intializer()
{
    for(int i=0; i<devices_num; i++)
    {
        devices[i].txt[0]='\0';
        plugs[i].txt[0]='\0';
    }
}


int fn(int bit)
{
    //printf("%d stage\n",bit);

    if(bit==length)
        return 0;

    int ans1,ans2;
    merge_sort(0,devices_num-1,plugs);
    // for(int i=0; i<devices_num; i++)
    //    printf("%s\n",plugs[i].txt);
    if(compare(bit))
    {
        ans1=0;
        ans1+=fn(bit+1);

    }

    else
        ans1=inf;


    flip(bit);
    merge_sort(0,devices_num-1,plugs);
    // for(int i=0; i<devices_num; i++)
    //    printf("%s\n",plugs[i].txt);

    if(compare(bit))
    {
        ans2=1;
        ans2+=fn(bit+1);
    }

    else
        ans2=inf;

    flip(bit);
    return min(ans1,ans2);
}

void flip(int bit)
{
    char current;
    for(int i=0; i<devices_num; i++)
    {

        current=plugs[i].txt[bit];
        if(current=='1')
            plugs[i].txt[bit]='0';
        else
            plugs[i].txt[bit]='1';
    }

}

bool compare(int bit)
{
    for(int i=0; i<devices_num; i++)
        if(devices[i].txt[bit]!=plugs[i].txt[bit])
            return false;
    return true;
}

void merge_sort(int start,int last,elec array[])
{
    if(last<=start)
        return;

    int middle=(last-start)/2;
    middle=start+middle;
    merge_sort(start,middle,array);
    merge_sort(middle+1,last,array);
    merge(start,last,array);
    return;
}

void merge(int start,int end,elec array[])
{
    int middle=(end-start)/2;
    middle=middle+start;
    int p1=start;
    int p2=middle+1;
    int main_p=start;

    for(int i=start; i<=middle; i++)
        help[i]=array[i];

    while(main_p<=end)
    {
        if(p1>middle)
        {
            array[main_p]=array[p2];
            p2++;
            main_p++;
            continue;
        }

        if(p2>end)
        {
            array[main_p]=help[p1];
            p1++;
            main_p++;
            continue;
        }

        if((strcmp(help[p1].txt,array[p2].txt))<0)
        {
            array[main_p]=help[p1];
            p1++;
        }
        else
        {
            array[main_p]=array[p2];
            p2++;
        }
        main_p++;
    }
    return ;
}


int setbit(int mask,int bit,int value)
{
    if(value==1)
        return(mask|(1<<bit));
    else
        return (mask&~(1<<bit));
}

int getbit(int mask,int bit)
{
    mask=(mask>>bit)&1;
    return (mask==1);
}


int min(int x,int y)
{
    if(x<y)
        return x;
    else
        return y;
}
