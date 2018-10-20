#include<cstdio>
int N = 1000;
int main()
{
    int ti;scanf("%d",&ti);
    for(int ca=1; ca<=ti; ca++)
    {
        int n;scanf("%d",&n);
        int a=0,b=0;
        for(int i = 0; i < n; i ++)
        {
            int tmp;
            scanf("%d",&tmp);

            if(i == n-1)continue;
            if(tmp <= i&& i - tmp <= 450)a ++;
            else b++;
        }
        //printf("%d %d\n",a,b);
        printf("Case #%d: %s\n",ca,a>b?"BAD":"GOOD");
    }
}
