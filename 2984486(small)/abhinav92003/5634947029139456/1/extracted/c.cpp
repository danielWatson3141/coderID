#include<bits/stdc++.h>
using namespace std;
char init[150][41],req[150][41];
void sort(int n)
{
    char temp[41];
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(strcmp(init[i],init[j])>0)
            {
                strcpy(temp,init[i]);
                strcpy(init[i],init[j]);
                strcpy(init[j],temp);
            }
        }
    }
}

int main()
{
	ios::sync_with_stdio(false);
    int t=1,T;
    cin>>T;
    while(t<=T)
    {

        string sreq[150];
        int n,i,l,j,k,flag=1;
        cin>>n>>l;
        for(i=0;i<n;i++)
        {
            cin>>init[i];
        }
        for(i=0;i<n;i++)
        {
            cin>>req[i];
            sreq[i].assign(req[i]);
        }

        int flip[150]={0},count=0;
        map<string,int> flips;
        map<string,int>::iterator it;
        char temp[81];
        string stemp;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                for(k=0;k<l;k++)
                {
                    if(init[i][k]==req[j][k])
                        temp[k]=0+'0';
                    else
                        temp[k]=1+'0';
                }
                temp[k]='\0';
                stemp.assign(temp);
               // cout<<stemp<<endl;;
                it=flips.find(stemp);
                if(it==flips.end())
                {
                    flips.insert(pair<string,int>(stemp,1));
                }
                else
                {
                    it->second+=(1);
                }

            }
        }

        it=flips.begin();
        count=1000000;
        int tcount=0;
        sort(sreq,sreq+n);
        while(it!=flips.end())
        {
           // cout<<it->first<<" "<<it->second<<endl;
            if(it->second>=n)
            {
              ///  cout<<"here";
                string after[150];
                for(i=0;i<n;i++)
                {
                    char temp[51];
                 //   cout<<"using "<<(*it).first<<" "<<init[i]<<" to ";
                    for(j=0;j<l;j++)
                    {
                         init[i][j]-='0';
                        if((*it).first[j]=='1')
                        {

                            temp[j]=1-init[i][j];

                        }
                        else
                            temp[j]=init[i][j];
                        init[i][j]+='0';
                        temp[j]+='0';
                    }
                    temp[j]='\0';
                //    cout<<temp<<"-";
                    string stemp;
                    stemp.assign(temp);
                    after[i]=stemp;
                }
              //  cout<<endl;
                sort(after,after+n);
                int flag=1;
                for(i=0;i<n;i++)
                {
                  //  cout<<sreq[i]<<" and "<<after[i]<<endl;
                    if(sreq[i].compare(after[i])!=0)
                    {
                        flag=0;
                        break;
                    }
                }
                if(flag==1)
                {
                    tcount=0;
                    for(i=0;i<l;i++)
                    {
                        tcount+=((*it).first[i]-'0');
                    }
                    if(tcount<count)
                    {
                        count=tcount;
                    }
                }
            }
            it++;
        }


        cout<<"Case #"<<t<<": ";
        if(count!=1000000)
        {

            cout<<count;
        }
        else
        {
            cout<<"NOT POSSIBLE";
        }
        cout<<endl;

        t++;
    }
	return 0;
}
