#include <iostream>
#include<string>
#include<vector>
#include<climits>
#include<cstdio>
using namespace std;

int check(vector<string>a, vector<string>b){
    for(unsigned int i=0;i<a.size();i++){
        int f=0;
        for(unsigned int j=0;j<b.size();j++){
            if(a[i]==b[j]){
                b[j]="";
                f=1;
            }
        }
        if(f==0)
            return 0;
    }
    return 1;
}

vector<string> change(vector<string>v,int k){
    vector<string>r;
    for(unsigned int i=0;i<v.size();i++){
        string s=v[i];
        if(s[k]=='0')
            s[k]='1';
        else
            s[k]='0';
        r.push_back(s);
    }

    return r;
}
void search(vector<string> now, vector<string>target,int k,int L,int N,int turn_n,int &min){
    if(k==L){
        if(check(now,target))
            min=min>turn_n?turn_n:min;
    }else{
        int n_1=0,n_2=0;
        for(int i=0;i<N;i++){
            if(now[i][k]=='0')
                n_1++;
            if(target[i][k]=='0')
                n_2++;
        }
        if(n_1!=n_2 && n_1!=N-n_2)
            return;
        if(n_1==n_2&& n_1==N-n_2){
            search(now,target,k+1,L,N,turn_n,min);
            vector<string>v_t=change(now,k);
            search(v_t,target,k+1,L,N,turn_n+1,min);
        }else if(n_1==n_2)
            search(now,target,k+1,L,N,turn_n,min);
        else{
            vector<string>v_t=change(now,k);
            search(v_t,target,k+1,L,N,turn_n+1,min);
        }
    }
}

int main()
{
    FILE*fout=fopen("out.txt","w");
        FILE*fin=fopen("in.txt","r");

    int testcase_n;
    fscanf(fin,"%d",&testcase_n);
    for(int i=0;i<testcase_n;i++){
        //cout<<i<<endl;
        int N,L;
        fscanf(fin,"%d%d",&N,&L);
        vector<string>now,target;
        for(int j=0;j<N;j++){
            char str[100];
            fscanf(fin,"%s",str);
            string t(str);
            now.push_back(t);
        }
        for(int j=0;j<N;j++){
            char str[100];
            fscanf(fin,"%s",str);
            string t(str);
            //cout<<t;
            target.push_back(t);
        }
//        for(int j=0;j<N;j++)
//            cout<<now[j]<<endl;
        int min=INT_MAX;
        search(now,target,0,L,N,0,min);
        fprintf(fout,"Case #%d: ",i+1);
        if(min==INT_MAX)
            fprintf(fout,"NOT POSSIBLE\n");
        else
            fprintf(fout,"%d\n",min);
    }
        fclose(fin);
    fclose(fout);
    return 0;
}
