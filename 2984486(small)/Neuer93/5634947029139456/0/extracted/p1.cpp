#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;
int n,m;
string so[160],te[160];
int sc[50],tc[50];
int record[50];

bool judge(){
    for (int i = 0; i < n-1; ++i)
        for (int j = i + 1; j < n; ++j)
            if (so[i] > so[j]){
                string temp = so[i];
                so[i] = so[j];
                so[j] = temp;
            }

    for (int i = 0; i < n; ++i){
        if (so[i] != te[i]){
            return false;
        }
    }
    return true;
}

void reverse(int x){
    for (int i = 0; i < n; ++i)
    {
        if (so[i][x] == '1')
        {
            so[i][x] = '0';
        }else{
            so[i][x] = '1';
        }
    }
}

int dfs(int step,int times){
    if (step == m){
        if (judge()){
            return times;
        }else{
            return -1;
        }
    }
    int temp1 = -1,temp2 = -1;
    
    if (sc[step] == tc[step])
    {
        temp1 = dfs(step + 1,times);
    }

    if (sc[step] == n - tc[step])
    {
        reverse(step);
        temp2 = dfs(step + 1,times + 1);
        reverse(step);
    }

    if (temp2 == -1 && temp1 == -1)
    {
        return -1;
    }else{
        if (temp1 == -1) return temp2;
        if (temp2 == -1) return temp1;
        if (temp1 > temp2) return temp2;
            else return temp1;
    }
}

int main()
{
    int t;
    cin>>t;
    for (int iii = 0; iii < t; ++iii)
    {
        cout<<"Case #"<<iii+1<<": ";
        cin>>n>>m;
        for (int i = 0; i < m; ++i)
        {
            sc[i] = 0;
            tc[i] = 0;
            record[i] = 0;
        }

        for (int i = 0; i < n; ++i){
            cin>>so[i];
            for (int j = 0; j < m; ++j){
                if (so[i][j] == '1'){
                    ++sc[j];
                }
            }
        }

        for (int i = 0; i < n; ++i){
            cin>>te[i];
            for (int j = 0; j < m; ++j){
                if (te[i][j] == '1'){
                    ++tc[j];
                }
            }
        }

        for (int i = 0; i < n-1; ++i)
        for (int j = i + 1; j < n; ++j)
            if (te[i] > te[j]){
                string temp = te[i];
                te[i] = te[j];
                te[j] = temp;
            }

        int ans = -1;
        ans = dfs(0,0);
        if(ans>=0){
            cout<<ans<<endl;
        }else{
            cout<<"NOT POSSIBLE"<<endl;
        }
    }
    return 0;
}
