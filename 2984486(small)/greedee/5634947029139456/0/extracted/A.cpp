#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue> 
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
#include <cctype> 
#include <string> 
#include <cstring> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 

using namespace std; 


#define PI acos(-1)
#define CLEAR(A) memset(A,0,sizeof(A))
#define SETMAX(A) memset(A,0x7f,sizeof(A))
#define SETM1(A) memset(A,-1,sizeof(A))
#define SQ(A) (A)*(A)


int num1s(int n) {
    int ret = 0;
    while(n) {
        n = n&(n-1);
        ret++;
    }
    return ret;
}

int main()
{
    cout << setprecision(12) ;
    int T;
    cin >> T;
    for(int caseno=0;caseno<T;caseno++) {
        int N, L;
        cin >> N >> L;
        vector<int> vi, req;
        string s;
        for(int i=0;i<N;i++) {
            cin >> s;
            int temp = 0;
            for(int j=0;j<s.size();j++) if(s[j] == '1') temp += 1<<j;
            vi.push_back(temp);
        }
        for(int i=0;i<N;i++) {
            cin >> s;
            int temp = 0;
            for(int j=0;j<s.size();j++) if(s[j] == '1') temp += 1<<j;
            req.push_back(temp);
        }
        sort(req.begin(), req.end());
        int mini = 1000;
        for(int i=0;i<(1<<L);i++) {
            bool ok = true;
            vector<int> temp;
            for(int j=0;j<N;j++) {
                temp.push_back(vi[j] ^ i);
            }
            sort(temp.begin(), temp.end());
            if(req == temp) mini = min(mini, num1s(i));
        }
        if(mini == 1000) {
            cout << "Case #" << caseno+1 << ": " << "NOT POSSIBLE" << endl;
        } else {
            cout << "Case #" << caseno+1 << ": " << mini << endl;
        }
    }
    return 0;
}
