#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
char elec[200][200],charge[200][200],mapping[200][200];
int main()
{
    int t,n,l,i,j,k,m,res,temp,p;
    int perm[20];
    vector<int> arr[200][200],var;
    vector<int>::iterator it,it1;
    bool marked1[200],marked2[200];
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d%d",&n,&l);
        for(j=0;j<n;j++)
        {
            scanf("%s",elec[j]);
            perm[j]=j;
        }
        for(j=0;j<n;j++)
        {
            scanf("%s",charge[j]);
        }
        res=200;
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                arr[j][k].clear();
                for(m=0;m<l;m++)
                {
                    if(elec[j][m]!=charge[k][m])
                    {
                       arr[j][k].push_back(m);
                    }
                }
            }
        }
        do
        {
            temp=0;
            temp=arr[0][perm[0]].size();
            //printf("%d ",perm[0]);
            for(j=1;j<n;j++)
            {
                //printf("%d ",perm[j]);
                if(temp!=arr[j][perm[j]].size())
                {
                    temp=-1;
                    break;
                }
            }
            //printf("\n");
            if(temp==-1)
                continue;
            var.clear();
            for(it=arr[0][perm[0]].begin();it!=arr[0][perm[0]].end();it++)
            {
                var.push_back(*it);
              //  printf("%d ",*it);
            }
            //printf("\n");
            for(j=1;j<n;j++)
            {
                it=arr[j][perm[j]].begin();
                it1=var.begin();
                while(it1!=var.end())
                {
                    if(*it!=*it1)
                    {
                        temp=-1;
                        break;
                    }
                    it1++;
                    it++;
                }
                if(temp==-1)
                    break;
            }
            if(temp!=-1)
                res=min(res,temp);
        }while(next_permutation(&perm[0],&perm[n]));
        printf("Case #%d: ",i);
        if(res==200)
            printf("NOT POSSIBLE\n");
        else
            printf("%d\n",res);
    }
    return 0;
}
