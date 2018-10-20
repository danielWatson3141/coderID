#include <algorithm>
#include <fstream>

using namespace std;

int n, l;
int t;
int now;
char from[155][45];
char to[155][45];
bool visit[155];
bool flip[155][45];
int ans;

void Check()
{
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < l; j++)
        {
            if(flip[i][j] != flip[i][0])
            {
                return;
            }
        }
    }
    int count = 0;
    for(int i = 0; i < l; i++)
    {
        if(flip[0][i])
            count++;
    }
    ans = min(ans, count);
}
void Do(int ind)
{
    if(ind == n)
    {
        Check();
        return;
    }
    for(int i = 0; i < n; i++)
    {
        if(!visit[i])
        {
            visit[i] = true;
            for(int j = 0; j < l; j++)
            {
                if(from[ind][j] != to[i][j])
                {
                    flip[ind][j] = true;
                }
            }
            Do(ind + 1);
            visit[i] = false;
            for(int j = 0; j < l; j++)
                flip[ind][j] = false;
        }
    }
}

int main()
{
    ifstream in("in.txt");
    ofstream out("out.txt");
    in >> t;
    now = 0;
    while(now < t)
    {
        ans = 100;
        for(int i = 0; i < n; i++)
            visit[i] = false;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < l; j++)
                flip[i][j] = false;
        }
        in >> n >> l;
        for(int i = 0; i < n; i++)
            in >> from[i];
        for(int i =0; i < n; i++)
            in >> to[i];
        Do(0);
        if(ans == 100)
        {
            out << "Case #" << now + 1 << ": NOT POSSIBLE" << endl;
        }
        else
        {
            out << "Case #" << now + 1 << ": " << ans << endl;
        }
        now++;
    }
}
