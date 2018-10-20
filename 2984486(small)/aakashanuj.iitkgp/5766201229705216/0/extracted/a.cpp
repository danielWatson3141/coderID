#include <bits/stdc++.h>
#define MAX 1100
#define INF 10000000
using namespace std;
#define SIZE 3
int n;
vector <int> myvec1,myvec2;
vector < vector <int> > s;
vector <bool> dp;
vector <int> down;
int storage[MAX][SIZE];
 
int final_func (int index, int x)
{
        if (x == SIZE) return INF;
        if (index == myvec1.size()) {
        if (x == SIZE-2) 
                return INF;
        else
                return 0;
        }
        
int result = storage[index][x];
if (result != -1) return result;

result = final_func (index+1, x) + myvec2[index];
result = min (result, myvec1[index]+final_func(index+1, x+1));
return result;
}
 
int f (int x, int p)
{
        vector <int> temp_myvec1;
        vector <int> temp_myvec2;
        long long sum=0;
        int i,j,k,l;
        int len=s[x].size();
        for(int i=0;i< len;i++)  
        {
                int flag=0;
                int xx = s[x][i];
                if (xx == p) 
                        flag=1;
        if(flag==0)
        {
                int xxx = f (xx, x);
                temp_myvec1.push_back (xxx);
                temp_myvec2.push_back (down[xx]);
        } 
        }
        myvec1=temp_myvec1;
        myvec2=temp_myvec2;
        int len1=temp_myvec1.size();
        if (len1 == 0)   return 0;
        if(len1==1)      return myvec2[0];
        
        memset (storage, -1, sizeof(storage));
        
        return final_func (0, 0);
}
 
 int ff (int x, int p)
{
        down[x] = 1;
        long long sum=0;
        int len=s[x].size();
        int i;
        for (i=0;i<len;i++) 
        {
                int flag=0;
                int xx = s[x][i];
                if (xx == p) 
                {
                flag=1;
                }
                if(flag==0)
                {
                        ff (xx, x);
                        down[x] += down[xx];
                }

        }
}

int main()
{

int T;
cin>>T;
int t;
long long N;
int ii = 1;
for(t=1;t<=T;t++)
{
cin >> N;
s.clear(); s.resize (N);
int sum = N;

for (int i = 0; i < N-1; i++) 
{
        int left,right;
        cin >> left >> right;
        left--;
        right--;
        s[left].push_back(right);
        s[right].push_back(left);
}
 
for (int j = 0; j < N; j++) 
{
        int k;
        for(k=0;k<1000000;k++)
        {
                long long temp;
                temp=sum;
        }
        dp.resize (N);down.resize (N);
        for (int ii = 0; ii < dp.size(); ii++) {
        dp[ii] = false;
        down[ii] = 0;
        }
        
        ff(j,j);
        int ret=f(j,j);
        sum = min (sum, ret);
}
  printf("Case #%d: %d\n",t,sum);
}
return 0;
}
