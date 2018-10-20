#include <iostream>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

int a[1005], b[1005];
int cnt[1005];
void work(int n) 
{
    for (int k = 0; k < n; k++) a[k] = k;
    for (int k = 0; k < n; k++)
	{
        int p = rand()%n;
        swap(a[k], a[p]);
    }
    for (int k = 0; k < n; k++) cnt[k] += (a[k] == b[k]);
}

int main () 
{
    freopen("1.txt", "r", stdin);
	//freopen("2.txt", "w", stdout);
	FILE *fout = fopen("2.txt", "w");
	int cas, T;
	int TM = 10005;
	
	srand(time(0));
	
	for (cas=scanf("%d", &T); cas<=T; cas++)
	{
		int n;
        scanf ("%d", &n);
        for (int i = 0; i < n; i++) scanf ("%d", &b[i]);
        
        for (int i = 0; i < n; i++) cnt[i] = 0;
        for (int i = 0; i < TM; i++) work(n);
        
        double ans = 0, tmp = 1.0 / TM;
        for (int i = 0; i < n; i++)
		{
			//cout <<b[i] << "  " << 1.0 * cnt[i] / TM << endl;
			ans += tmp * cnt[i];
		}
        cout << ans <<endl;
        fprintf(fout, "Case #%d: %s\n", cas, ans > 1+ 5e-3  ? "BAD" : "GOOD");
		printf("Case #%d: %s\n", cas, ans > 1+ 5e-3  ? "BAD" : "GOOD");
    }

    return 0;
}
