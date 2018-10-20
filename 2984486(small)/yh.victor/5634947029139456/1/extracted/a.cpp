#include<cstdio>
#include<vector>
#include<string>
#include<iostream>
#include<map>
using namespace std;

char tmp[110];
typedef long long ll;
int n,l;
ll gain(char *str)
{
    ll ret=0;
    for(int i=0; str[i]; i ++)
    {
        ret <<= 1;
        ret += str[i]=='1';
    }
    //cout << ret << endl;
    return ret;
}

vector<int> predo(vector<ll>&input,int w)
{
    vector<int> a(l,0);
    for(int i = 0; i < n; i ++)
    {
        if(i == w)continue;
        ll val = input[i];
        for(int j = 0; j < l; j ++)
        {
            a[j] += val&1;
            val >>= 1;
        }
    }
    //for(int i = 0; i < l; i ++)printf("%d ",a[i]);printf("\n");
    return a;
}

ll predo(vector<ll>&input,vector<ll>&output,int w1,int w2)
{
    vector<int>a = predo(input,w1);
    vector<int>b = predo(output,w2);
    ll ret=0;
    for(int i = l -1 ; i >= 0; i --)
    {
        ret <<= 1;
        if(a[i]!=b[i])ret+=1;
    }
    return ret;
}
int check(vector<ll>&input,vector<ll>&output,ll use)
{
    //cout << use <<" ";
    map<ll,int>dict;
    for(int i = 0; i < n; i ++)
    {
        //cout << (input[i]^use) << " ";
        dict[input[i]^use]++;
    }
    for(int i = 0; i < n; i ++)
    {
        //cout << output[i] << " ";
        if(dict[output[i]] <= 0)return 0;
        dict[output[i]]--;
    }
    return 1;
}

int count(ll val)
{
    int ret = 0;
    while(val > 0)
    {
        if(val&1)ret ++;
        val >>= 1;
    }
    return ret;
}
int main()
{
    int ti;scanf("%d",&ti);
    for(int ca=1; ca<=ti; ca++)
    {
        scanf("%d%d",&n,&l);
        vector<ll>input,output;
        for(int i = 0; i < n; i ++)
        {
            scanf("%s",tmp);
            input.push_back(gain(tmp));
        }
        for(int i = 0; i < n; i ++)
        {
            scanf("%s",tmp);
            output.push_back(gain(tmp));
        }
        printf("Case #%d: ",ca);
        if(n%2)
        {
            ll ans = predo(input,output,-1,-1);
            if(check(input,output,ans))
            {
                printf("%d\n",count(ans));
            }
            else
            {
                printf("NOT POSSIBLE\n");
            }
        }
        else
        {
            int ret = 100;
            for(int j = 0; j < n; j ++)
            {
                ll ans=predo(input,output,0,j);
                //cout << ans << " ";
                if(check(input,output,ans))
                {
                    ret = min(ret,count(ans));
                }
            }
            if(ret == 100)
            {
                printf("NOT POSSIBLE\n");
            }
            else
            {
                printf("%d\n",ret);
            }
        }
    }
}
/*
2 8
00010010 01011101
10011101 11010010
*/
