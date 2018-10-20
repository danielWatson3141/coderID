#include<iostream>
#include<vector>
#include<map>
using namespace std;

typedef long long LL;
typedef vector<LL> VL;
typedef pair<VL,VL> PVV;


int T;
int N,L;
char in[50];
LL A[250];
LL B[250];

LL get(){
    cin>>in;
    LL ret = 0;
    for(int i=0;i<L;++i){
        ret*=2;
        ret=ret+in[i]-'0';
    }
    return ret;
}

int determine(PVV pvv){
    if(pvv.first.size()!=pvv.second.size()) return 0;
    int t1 = 0;
    int t2 = 0;
    for(int i=0;i<pvv.first.size();++i){
        if(pvv.first[i]%2){
            ++t1;
        }
        if(pvv.second[i]%2){
            ++t2;
        }
    }
    int ret = 0;
    if(t1==t2){
        ret|=1;
    }
    if(t1+t2==pvv.first.size()){
        ret|=2;
    }
    return ret;
}

vector<PVV> donoti(PVV pvv){
    VL odd1,odd2;
    VL even1,even2;
    for(int i=0;i<pvv.first.size();++i){
        if(pvv.first[i]%2){
            odd1.push_back(pvv.first[i]/2);
        }
        else{
            even1.push_back(pvv.first[i]/2);
        }
        if(pvv.second[i]%2){
            odd2.push_back(pvv.second[i]/2);
        }
        else{
            even2.push_back(pvv.second[i]/2);
        }
    }
    vector<PVV> ret;
    if(odd1.size()==odd2.size()&&odd1.size()>0){
        ret.push_back(make_pair(odd1,odd2));
    }
    if(even1.size()==even2.size()&&even1.size()>0){
        ret.push_back(make_pair(even1,even2));
    }
    return ret;
}

vector<PVV> doiti(PVV pvv){
    VL odd1,odd2;
    VL even1,even2;
    for(int i=0;i<pvv.first.size();++i){
        if(pvv.first[i]%2){
            odd1.push_back(pvv.first[i]/2);
        }
        else{
            even1.push_back(pvv.first[i]/2);
        }
        if(pvv.second[i]%2){
            odd2.push_back(pvv.second[i]/2);
        }
        else{
            even2.push_back(pvv.second[i]/2);
        }
    }
    vector<PVV> ret;
    if(odd1.size()==even2.size()&&odd1.size()>0){
        ret.push_back(make_pair(odd1,even2));
    }
    if(even1.size()==odd2.size()&&even1.size()>0){
        ret.push_back(make_pair(even1,odd2));
    }
    return ret;
}


vector<PVV> donot(vector<PVV> v){
    vector<PVV> ret;
    for(int i=0;i<v.size();++i){
        vector<PVV> cur = donoti(v[i]);
        for(int j=0;j<cur.size();++j){
            ret.push_back(cur[j]);
        }
    }
    return ret;
}

vector<PVV> doit(vector<PVV> v){
    vector<PVV> ret;
    for(int i=0;i<v.size();++i){
        vector<PVV> cur = doiti(v[i]);
        for(int j=0;j<cur.size();++j){
            ret.push_back(cur[j]);
        }
    }
    return ret;
}


int go(vector<PVV> v,int rem){
    if(rem==0) return 0;
    int action = 3;
    for(int i=0;i<v.size();++i){
        action=action&determine(v[i]);
    }
    int ret = 100;
    if(action&1){
        ret<?=go(donot(v),rem-1);
    }
    if(action&2){
        ret<?=(1+go(doit(v),rem-1));
    }
    return ret;
}



int main(){
    int i,j;
    freopen("A-large.in","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>T;
    for(int cas=1;cas<=T;++cas){
        cin>>N>>L;
        for(i=0;i<N;++i) A[i] = get();
        for(i=0;i<N;++i) B[i] = get();
        vector<LL> AL(A,A+N);
        vector<LL> BL(B,B+N);
        PVV current = make_pair(AL,BL);
        vector<PVV> v;
        v.push_back(current);
        int res = go(v,L);
        cout<<"Case #"<<cas<<": ";
        cerr<<"Case #"<<cas<<": ";
        
        if(res>=100){
            cout<<"NOT POSSIBLE\n";
            cerr<<"NOT POSSIBLE\n";
        }
        else{
            cout<<res<<endl;
            cerr<<res<<endl;
        }
        
    }
    return 0;
}
