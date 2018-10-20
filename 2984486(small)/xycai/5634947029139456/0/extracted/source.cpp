#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
//    freopen("in.txt","r",stdin);
    char str[105];
    gets(str);
    int len = strlen(str);
    int flag = 0;
    for (int i=1;str[i];i++)
    {
        if(str[i] == str[i-1] && str[i-1] == '_')
        {
            puts("Error!");
            return 0;
        }
    }
    if(!(str[0]>='a' && str[0]<='z')) puts("Error!");
    else
    {
        if(str[len-1]=='_') puts("Error!");
        else{
            for(int i=0;str[i];i++)
            {
                if(str[i] == '_')
                {
                    if(flag == 0) flag = 1;
                    if(flag == 2) flag = -1;
                }
                if(str[i] >= 'A' && str[i] <= 'Z')
                {
                    if(flag == 0) flag = 2;
                    if(flag == 1) flag = -1;
                }
            }
            if(flag == -1) puts("Error!");
            if(flag == 0)
            {
                puts(str);
            }
            if(flag == 2)
            {
                for (int i=0;str[i];i++)
                {
                    if(str[i] >= 'A' && str[i] <= 'Z')
                    {
                        printf("_%c",str[i]+32);
                    }
                    else printf("%c",str[i]);
                }
                printf("\n");
            }
            bool is_ = false;
            if(flag == 1)
            {
                for (int i=0;str[i];i++)
                {
                    if(str[i] != '_')
                    {
                        if(is_)
                        {
                            printf("%c",str[i]-32);
                            is_ = false;
                        }
                        else if(str[i]!='_')
                        {
                            printf("%c",str[i]);
                        }
                    }
                    else
                    {
                        is_ = true;
                    }
                }
                printf("NOT POSSIBLE\n");
            }
        }
    }
    return 0;
}
