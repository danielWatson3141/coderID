#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define mod 1000000007

char elec[200][200];
char outlets[200][200];

int n, m;
int ans;

vector<int> dict;
vector<int> device;


int check(int s, int t)
{
    dict.clear();
    int cans=0;
    for (int i=0; i<m; i++)
        cans+=(elec[s][i]!=outlets[t][i]);
    for (int i=1; i<=n; i++)
    {
        int temp=0;
        for (int j=0; j<m; j++)
            if (elec[s][j]==outlets[t][j])
                temp=((2*temp)%mod+elec[i][j]-'0')%mod;
            else
                temp=((2*temp)%mod+1-(elec[i][j]-'0'))%mod;
        dict.push_back(temp);
    }
    sort(dict.begin(), dict.end());
    if (dict==device)
        if (cans<ans)
            ans=cans;
    return ans;
}



int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int CAS1;
    scanf("%d", &CAS1);
    for (int CAS=1; CAS<=CAS1; CAS++)
    {
        scanf("%d%d", &n, &m);
        for (int i=1; i<=n; i++)
            scanf("%s", elec[i]);
        for (int i=1; i<=n; i++)
            scanf("%s", outlets[i]);
        device.clear();
        for (int i=1; i<=n; i++)
        {
            int temp = 0;
            for (int j=0; j<m; j++)
                temp=(temp*2%mod+outlets[i][j]-'0')%mod;
            device.push_back(temp);
        }
        sort(device.begin(), device.end());
        ans=m+1;
        for (int i=1; i<=n; i++)
            check(1, i);
        printf("Case #%d: ", CAS);
        if (ans<=m)
            printf("%d\n", ans);
        else
            printf("NOT POSSIBLE\n");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
