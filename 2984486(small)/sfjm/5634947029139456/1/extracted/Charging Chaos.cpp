#include<cstdio>
#include<cstring>

using namespace std ;

char s[200][50];
char s1[200][50];
char a[200][50];

int n , l;
void change(int j)
{
    for ( int i = 0 ; i < n ; i++ )
        s1[i][j]=(1-(s[i][j]-'0'))+'0';
}
bool judge()
{
    int x = 0;
    for ( int i = 0 ; i < n ; i++ )
    {
        for ( int j = 0 ; j < n ; j++ )
        {
            if (!strcmp(s1[i],a[j]))
            {
                x++ ;
                break;
            }
        }
    }
    if (x==n)return true ;
    return false ;
}
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    int _,ca=1;
    int  i, j ;
    int ans ,step;
    scanf("%d",&_);
    while(_--)
    {
        scanf ("%d%d",&n,&l);
        for ( i = 0 ; i < n ; i++)
            scanf ("%s",s[i]);
        for ( i = 0 ; i < n ; i++)
            scanf ("%s",a[i]);
        for ( i = 0 ,ans =-1 ; i < n ; i++ )
        {
            for (int k =0 ; k < n ; k++ )
            {
                for (int d= 0 ; d<=l;d++)
                    s1[k][d]=s[k][d];
            }
            for ( j =0 , step=0; j < l ; j++ )
            {
                if ( s1[0][j]!=a[i][j])
                {
                    step++;
                    change(j);
                }
            }
            if ( judge() )
            {
                if ( step < ans || ans == -1)
                    ans = step ;
            }
        }
        printf("Case #%d: ",ca++);
        if ( ans == -1)
            puts("NOT POSSIBLE");
            else printf("%d\n",ans);
    }
    return  0;
}
