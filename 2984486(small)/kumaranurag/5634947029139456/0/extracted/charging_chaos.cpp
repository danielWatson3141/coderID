#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
using namespace std;


int main() 
{

        freopen ("input.txt","r",stdin);
        freopen ("output.txt","w",stdout);


        int t;
        scanf("%d",&t);

        int testcases=0;
        while(t--)
        {
            int N,L;
            scanf("%d%d",&N,&L);

            set<int>original;original.clear();
            set<int>required;required.clear();


            char s[100];
            for(int i=0;i<N;i++)
            {
                scanf("%s",s);
                int num=0;
                for(int j=0;j<strlen(s);j++)
                {
                    if(j>=1)
                    num=(num<<1)+(s[j]-'0');
                    else
                    num=num+(s[j]-'0');
                }

                original.insert(num);
            }
            

            for(int i=0;i<N;i++)
            {
                scanf("%s",s);
                int num=0;
                for(int j=0;j<strlen(s);j++)
                {
                    if(j>=1)
                    num=(num<<1)+(s[j]-'0');
                    else
                    num=num+(s[j]-'0');
                }

                required.insert(num);
            }


            int ans=999999999;

            int flag=0;
            for(int i=0;i<(1<<13);i++)
            {
                set<int>tmp;tmp.clear();

                for(set<int>::iterator it=original.begin();it !=original.end();it++)
                {
                    tmp.insert((*it) ^ i);

                }

                if(tmp.size()==required.size())
                {
                    set<int>::iterator it1=tmp.begin();
                    set<int>::iterator it2=required.begin();

                    int flag2=1;
                    for(;it1!=tmp.end();it1++,it2++)
                    {
                        if(*it1==*it2) continue;
                        else
                        {
                            flag2=0;
                            break;
                        }
                    }

                    
                    if(flag2==1)
                    {
                        //count no of ones in i

                        int count = 0;
                        int n=i;
                        while(n)
                        {
                            count += n & 1;
                            n >>= 1;
                        }

                        if(count<ans)
                            ans=count;
                        flag=1;
                    }
                }

            }

                       

            printf("Case #%d: ",++testcases);

            if(flag==0)
            {
                printf("NOT POSSIBLE\n");
            }
            else
            {
                printf("%d\n",ans);
            }

        }

		return 0;
}


