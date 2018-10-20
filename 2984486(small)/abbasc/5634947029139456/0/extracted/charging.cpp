#include <stdio.h>
#include <iostream>

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("asmall.out","w",stdout);
    int x,T;
    scanf("%d", &T);
    for(x = 1; x <= T; x++)
    {
        int n,l,i,j,k,minCount;
        char tmp[41];
        int outlet[151],device[151];
        scanf("%d %d",&n, &l);
        minCount = l+1;
        for(i = 0; i < n; i++)
        {
            scanf("%s", tmp);
            outlet[i] = 0;
            for(j = 0; j < l; j++)
            {
                if(tmp[j] == '1')
                    outlet[i] |= 1<<(l-j-1);
            }

        }
        for(i = 0; i < n; i++)
        {
            scanf("%s", tmp);
            device[i] = 0;
            for(j = 0; j < l; j++)
            {
                if(tmp[j] == '1')
                    device[i] |= 1<<(l-j-1);
            }
            //printf("%d\n",device[i]);

        }
        int total = 1<<(l);
        int found;
        for(i = 0; i < total; i++)
        {
            for(j = 0; j < n; j++)
            {
                found = 0;
                int temp = device[j]^i;
                for(k = 0; k < n; k++)
                {
                    if(outlet[k] == temp)
                    {
                        //printf("outlet = %d\ntemp = %d\n,i = %d\n",outlet[k],temp,i);
                        found = 1;
                        break;
                    }
                }
                if(found == 0)
                    break;
            }
            if(found == 1)
            {
                int temp  = i;
                int count = 0;
                while(temp > 0)
                {
                    count++;
                    temp -= temp & -temp;
                }
                //printf("count = %d\n",count);
                if(count < minCount)
                    minCount = count;
            }
        }
        printf("Case #%d: ",x);
        if(minCount > l)
            printf("NOT POSSIBLE\n");
        else
            printf("%d\n",minCount);
    }
    return 0;
}
