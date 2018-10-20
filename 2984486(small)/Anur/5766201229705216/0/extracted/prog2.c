#include<stdio.h>
#include<limits.h>

int mat[1001][1001];
int n,t;
int visit[1001];

int find(int ind,int *count)
{
    visit[ind] = 1;

    int i,cnt=0,ttt,temp,ttt1,ttt2;
    int total_ele=0;

    int min1=INT_MAX ,min2 = INT_MAX;

    for(i=0;i<n;i++)
    {
        if(mat[ind][i] == t && visit[i] != 1)
        {
            cnt++;
            temp = find(i,&ttt);
            total_ele += ttt;
            if(temp < min1)
            {
                min2=min1;
                ttt2 = ttt1;
                min1 = temp;
                ttt1 = ttt;
            }
            else if(temp < min2)
            {
               min2 = temp;
               ttt2 = ttt;
            }
        }

    }
    total_ele;
    *count = total_ele+1;
    if(cnt == 0)
       return 0;
    else if(cnt == 1)
       return total_ele;
    else
       return min1+min2+(total_ele-ttt1-ttt2);

}
int main()
{
    int test_case,i,j,a,b,count;
    scanf("%d",&test_case);
    t=1;

    for(i=0;i<1001;i++)
      for(j=0;j<1001;j++)
         mat[i][j] = 0;

    while(t <= test_case)
    {
        scanf("%d",&n);
        for(i=1;i<n;i++)
        {
            scanf("%d %d",&a,&b);
            mat[a-1][b-1] = t;
            mat[b-1][a-1] = t;
        }

        int min=INT_MAX,iii;

        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
               visit[j] = 0;
            int temp = find(i,&count);
            if(min >= temp)
            {
                min = temp;
                iii=i;
            }
        }
        printf("Case #%d: %d\n",t,min);

        t++;
    }
    return 0;
}
