#include<bits/stdc++.h>
using namespace std;
long long a1[200],a2[200];
typedef struct node
{
    long long val;
    int ind;
}node;
void change1(char arr[][50], int n, int l)
{

    for(int i=0;i<n;i++)
    {
        long long temp = 0;
        for(int j=0;j<l;j++)
        {
            if(arr[i][j] == '1')
            {
                temp = temp | ((long long)1 << (l-1-j));
            }
        }
        a1[i] = temp;
        //cout<<"temp: "<<temp<<endl;
    }
}

void change2(char arr[][50], int n, int l)
{

    for(int i=0;i<n;i++)
    {
        long long temp = 0;
        //cout<<"a2: "<<arr[i]<<endl;
        for(int j=0;j<l;j++)
        {
            if(arr[i][j] == '1')
            {
                temp = temp | ((long long)1 << (l-1-j));
            }
        }
        a2[i] = temp;
        //cout<<"temp: "<<temp<<endl;
    }
}

int noofbits(long long temp)
{
    int c = 0;
    //cout<<"sd: "<<temp<<endl;
    for(long long i=0;i<60;i++)
    {
        if((temp & ((long long)1<<i)))
        {
            //cout<<"i; "<<i<<endl;
            c++;
        }
    }
    return c;
}

int main()
{
    int t;
    ifstream cin("in1.txt");
    ofstream cout("out111.txt");
    int k = 0;
    cin>>t;
    while(t--)
    {
        k++;
        int n,l;
        cin>>n>>l;
        //printf("%d %d\n",n,l);
        char arr1[200][50];
        char arr2[200][50];
        for(int i=0;i<n;i++)
        {
            cin>>arr1[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>arr2[i];
        }
        change1(arr1,n,l);
        change2(arr2,n,l);
        long long dp[300][300];
        int flag[200];
        for(int i=0;i<n;i++)
        {
            flag[i] = 0;
        }
        for(int i=0;i<n;i++)
        {
           // cout<<"a1: "<<a1[i]<<" a2: "<<a2[i]<<endl;
            for(int j=0;j<n;j++)
            {
                dp[i][j] = a1[i] ^ a2[j];
               // cout<<dp[i][j]<<endl;
            }
        }
        int ans = 100;
        for(int i=0;i<n;i++)
        {
            long long temp = dp[0][i];
            //cout<<"temp: "<<temp<<endl;
            flag[i] = 1;
            int flg = 0;
            for(int j=1;j<n;j++)
            {
                int k;
                for(k=0;k<n;k++)
                {
                    if(dp[j][k] == temp && flag[k] == 0)
                    {
                        flag[k] = 1;
                        break;
                    }
                }
                if(k == n)
                {
                    flg = 1;
                    break;
                }
            }
            if(flg == 0)
            {
                int no = noofbits(temp);
                //cout<<"tempin : "<<no<<" temp "<<temp<<endl;
                if(no <= ans)
                {
                    ans = no;
                }
            }
            for(int i=0;i<n;i++)
            flag[i] = 0;
        }
        if(ans == 100)
        cout<<"Case #"<<k<<": "<<"NOT POSSIBLE"<<endl;
        else
        cout<<"Case #"<<k<<": "<<ans<<endl;
    }
    return 0;
}
