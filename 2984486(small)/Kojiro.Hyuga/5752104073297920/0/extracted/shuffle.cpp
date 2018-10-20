#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int n=1000;

double as=0;
double bs=0;

int b[1100][1100];

void pg()
{
  int a[n];
  for (int k=0;k<n;k++)
  a[k]=k;
  for (int k=0;k<n;k++)
  {
    int range=n-1-k+1;
    int p=rand()%range+k;
    swap(a[k],a[p]);
  }
  /*for (int k=0;k<n;k++)
  cout<<a[k]<<' ';
  cout<<endl;*/
  
  
  int z=as;
  for (int k=0;k<n;k++)
  {
    int x=a[k];
    if (x<k)
    as+=n-x+k+1;
    else
    as+=k-x+1;
  }
  //cout<<as-z<<endl;
}

void ba()
{
  int a[n];
  for (int k=0;k<n;k++)
  a[k]=k;
  for (int k=0;k<n;k++)
  {
    //int range=n-1-k+1;
    int p=rand()%n;
    swap(a[k],a[p]);
  }
  for (int k=0;k<n;k++)
  cout<<a[k]<<' ';
  cout<<endl;
  
  //for (int k=0;k<n;k++)
  //b[a[k]][k]++;
  
  for (int k=0;k<n;k++)
  {
    int x=a[k];
    if (x<k)
    bs+=n-x+k+1;
    else
    bs+=k-x+1;
  }
  
}

int score()
{
  int r[n];
  for (int i=0;i<n;i++)
  cin>>r[i];
  
  int ss=0;
  for (int k=0;k<n;k++)
  {
    int x=r[k];
    if (x<k)
    ss+=n-x+k+1;
    else
    ss+=k-x+1;
  }
  //if (ss<486000) cout<<"diu"<<' ';
  //cout<<ss<<endl;
  return ss;
}

int main()
{
  srand(time(0));
  for (int i=0;i<n;i++)
  for (int j=0;j<n;j++)
  b[i][j]=0;
  //for (int i=0;i<100;i++)
  //pg();
  
  as=0;
  bs=0;
  
  //for (int i=0;i<10000;i++)
  //pg();
  //for (int i=0;i<10000;i++)
  //ba();
  cin>>as;
  for (int i=0;i<120;i++)
  {
    cout<<"Case #"<<i+1<<": ";cin>>as;
    if (score()<487000)
    cout<<"BAD\n";
    else cout<<"GOOD\n";
  }
  
  
  /*for (int i=0;i<n;i++) {
    cout<<i<<"***";
  for (int j=0;j<n;j++)
  
    cout<<b[i][j]<<' ';
    cout<<endl;
  }*/
  
  //cout<<as/10000.0<<endl;
  //cout<<bs/10000.0;
  
  return 0;
}
