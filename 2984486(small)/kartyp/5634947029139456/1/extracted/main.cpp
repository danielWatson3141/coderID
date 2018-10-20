/* 
 * File:   main.cpp
 * Author: Parnami
 * Created on April 12, 2014, 4:43 AM
 * Description : Google Code Jam 2014 First Round A. Question 1
 */

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <utility>
#include <cmath>
#include <set>
#include <sstream>
#include <fstream>
#include <bitset>

using namespace std;

inline int fastRead()
{
    int input;
    char c=0;
    while (c<33) c=getchar();
    input=0;
    while (c>33)
    {
          input=input*10+c-'0';
          c=getchar();
    }
    return input;
}

vector < map <string, int > > myVec,anoVec,anoVec2;
int n,l,flag,minner;

int flip(bitset <40> myBit,bitset <40> myBitCopy, int pos,vector <string> vecyou)
{   
    int i,j,one=1,two=1;
    anoVec2.clear();
    map <string, int > :: iterator it;
    vector <string> vecy,vecy2;
    vecy = vecyou;
    for(i=0;i<40;i++)
    {
        if(myBit.test(i))
        {
           for(j=0;j<vecy.size();j++)
           {
               if(vecy[j][l-i-1]=='0')
               {    
                   vecy[j][l-i-1]='1';
               }
               else
               {
                   vecy[j][l-i-1]='0';
               }
           }
        }
    }
    /*
    cout<<"vecy : ";
    for(i=0;i<vecy.size();i++)
    {
        cout<<vecy[i]<<" ";
    }
    cout<<endl;
    */
    anoVec2.resize(l+1);
    for(j=0;j<vecy.size();j++)
    {
        if(anoVec2[pos].find(vecy[j].substr(l-pos))!=anoVec2[pos].end())
                 anoVec2[pos][vecy[j].substr(l-pos)]=anoVec2[pos][vecy[j].substr(l-pos)]+1;
        else
                 anoVec2[pos][vecy[j].substr(l-pos)]=1;
    }
    for(it=anoVec2[pos].begin();it!=anoVec2[pos].end();it++)
    {
        //cout<<"For "<<it->first<<" anoVec2 = "<<it->second<<" and myVec = "<<myVec[pos][it->first]<<endl;
        if((it->second)!=myVec[pos][it->first])
        {
            one = 0;
            break;
        }
    }
    
    anoVec2.clear();
    vecy2 = vecyou;
    for(i=0;i<40;i++)
    {
        if(myBitCopy.test(i))
        {
           for(j=0;j<vecy2.size();j++)
           {
               if(vecy2[j][l-i-1]=='0')
               {    
                   vecy2[j][l-i-1]='1';
               }
               else
               {
                   vecy2[j][l-i-1]='0';
               }
           }
        }
    }
    /*
    cout<<"vecy2 : ";
    for(i=0;i<vecy2.size();i++)
    {
        cout<<vecy2[i]<<" ";
    }
    cout<<endl;
    */
    anoVec2.resize(l+1);
    for(j=0;j<vecy2.size();j++)
    {
        if(anoVec2[pos].find(vecy2[j].substr(l-pos))!=anoVec2[pos].end())
                 anoVec2[pos][vecy2[j].substr(l-pos)]=anoVec2[pos][vecy2[j].substr(l-pos)]+1;
        else
                 anoVec2[pos][vecy2[j].substr(l-pos)]=1;
    }
    for(it=anoVec2[pos].begin();it!=anoVec2[pos].end();it++)
    {
        //cout<<"For "<<it->first<<" anoVec2 = "<<it->second<<" and myVec = "<<myVec[pos][it->first]<<endl;
        if((it->second)!=myVec[pos][it->first])
        {
            two = 0;
            break;
        }
    }
    
    if(pos==l)
    {
         if(one==0 && two==0)
         {
             return -1;
         }
         else if(one==1 && two==0)
         {
             cout<<"Winner Bitset :"<<myBit<<endl;
             minner = min(minner,(int)(myBit.count()));
             return 0;
         }
         else if(one==0 && two==1)
         {
             cout<<"Winner Bitset :"<<myBitCopy<<endl;
             minner = min(minner,(int)(myBitCopy.count()));
             return 1;
         }
         else if(one==1 && two==1)
         {
             cout<<"Winner Bitsets :"<<myBitCopy<<" and : "<<myBit<<endl;
             minner = min(minner,(int)(myBit.count()));
             minner = min(minner,(int)(myBitCopy.count()));
             return 0;
         }
    }
    else
    {
         if(one==0 && two==0)
         {
             return -1;
         }
         else if(one==1 && two==0)
         {
             bitset<40> myBitter;
             myBitter = myBit;
             myBit.set(pos);
             return flip(myBitter,myBit,pos+1,vecyou);
         }
         else if(one==0 && two==1)
         {
             bitset<40> myBitter;
             myBitter = myBitCopy;
             myBitCopy.set(pos);
             return (flip(myBitter,myBitCopy,pos+1,vecyou)+1);
         }
         else if(one==1 && two==1)
         {
             int ans1,ans2;
             bitset<40> myBitter;
             myBitter = myBit;
             myBit.set(pos);
             ans1 = flip(myBitter,myBit,pos+1,vecyou);
             myBitter = myBitCopy;
             myBitCopy.set(pos);
             ans2 =  flip(myBitter,myBitCopy,pos+1,vecyou);
             if(ans1==-1)
             {
                 if(ans2==-1)
                 {
                        return -1;
                 }
                 else
                 {
                     return (ans2+1);
                 }
             }
             else if(ans2==-1)
             {
                 return ans1;
             }
             else
                 return min(ans1,ans2+1);
         }
    }
    
}

int main(int argc, char** argv) 
{
    string fileName = "in.txt",temp;
    ifstream input_data("A-large.in");
    ofstream outputFile("outter2.txt");
    int i,j,t,k,answer;
    //input_data.open;
    input_data>>t;
    for(i=0;i<t;i++)
    {
        cout<<i<<endl;
        minner = 50;
        vector <string> vecyou;
        input_data>>n>>l;
        myVec.clear();
        myVec.resize(l+1);
        anoVec.clear();
        anoVec.resize(l+1);
        flag=0;
        for(j=0;j<n;j++)
        {
                input_data>>temp;
                cout<<temp<<endl;
                for(k=1;k<=l;k++)
                {
                    //cout<<"k = "<<k<<"  "<<temp.substr(l-k)<<endl;
                    if(myVec[k].find(temp.substr(l-k))!=myVec[k].end())
                    {
                        myVec[k][temp.substr(l-k)]=myVec[k][temp.substr(l-k)]+1;
                    }
                    else
                    {
                        myVec[k][temp.substr(l-k)]=1;
                    }
                }
        }
        for(j=0;j<n;j++)
        {
                input_data>>temp;
                //cout<<temp<<endl;
                vecyou.push_back(temp);
                for(k=1;k<=l;k++)
                {
                    if(anoVec[k].find(temp.substr(l-k))!=anoVec[k].end())
                        anoVec[k][temp.substr(l-k)]=anoVec[k][temp.substr(l-k)]+1;
                    else
                        anoVec[k][temp.substr(l-k)]=1;
                }
        }
        bitset <40> myBit,myBitCopy;
        myBitCopy.set(0);
        answer = flip(myBit,myBitCopy,1,vecyou);
        if(minner==50)
        {
            cout<<"Impossible"<<endl;
        }
        else
            cout<<"answer : "<<minner<<endl;
        outputFile<<"Case #"<<i+1<<": ";
        if(minner==50)
            outputFile<<"NOT POSSIBLE"<<endl;
        else
            outputFile<<minner<<endl;
    }
}

