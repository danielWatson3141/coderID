#include<iostream>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<memory.h>
#include<vector>
#include<algorithm>
using namespace std;

int Merge(int * arr, int beg, int mid, int end, int * tmp_arr)
{
    memcpy(tmp_arr+beg,arr+beg,sizeof(int)*(end-beg+1));
    int i = beg;
    int j = mid + 1;
    int k = beg;
    int inversion = 0;  // 合并过程中的逆序数
    while(i <= mid && j <= end)
    {
        if(tmp_arr[i] <= tmp_arr[j])
        {
            arr[k++] = tmp_arr[i++];
        }else
        {
            arr[k++] = tmp_arr[j++];
            inversion += (mid - i + 1);
        }
    }
    while(i <= mid)
    {
        arr[k++] = tmp_arr[i++];
    }
    while(j <= end)
    {
        arr[k++] = tmp_arr[j++];
    }
    return inversion;
}
 
int MergeInversion(int * arr, int beg, int end, int * tmp_arr)
{
    int inversions = 0;    // 记录倒序数
    if(beg < end)
    {
        int mid = (beg + end) >> 1;
        inversions += MergeInversion(arr, beg, mid, tmp_arr);
        inversions += MergeInversion(arr, mid+1, end, tmp_arr);
        inversions += Merge(arr, beg, mid, end, tmp_arr);
    }
    return inversions;
}


int arrcopy[1010],a[1010],n1,i1,num,i,n,b[130],c[130],bound;
//double ,bound2;

int main()
{
	cin>>n1;
	
	for(i1=1;i1<=n1;i1++)
	{
		cin>>n;
		for(i=0;i<n;i++)
			cin>>a[i];
			int num = 0;
for(int i = 0; i < n; ++i)
{
    for(int j = i+1; j < n; ++j)
    {
        if(a[i] > a[j])
        {
            num++;
        }
    }
}
//cout<<num<<" "<<n*(n-1)/2/2<<endl;
b[i1]=fabs(num-n*(n-1)/2/2);
	c[i1]=b[i1];		
			
	}
	sort(b+1,b+1+n1);
	bound=b[(1+n1)/2];
		for(i1=1;i1<=n1;i1++)
		{
		cout<<"Case #"<<i1<<": ";
	//	cout<<c[i1];
		if(c[i1]<=bound)
			cout<<"GOOD"<<endl;
		else cout<<"BAD"<<endl;
	}
	//	num= MergeInversion(a,0,n,arrcopy);

	//cout<<num<<endl;
	//	cout<<num<<endl;
	//	bound1=n*(n-1)/2*0.49;
	//	bound2=n*(n-1)/2*0.51;
	//	cout<<bound1<<" "<<bound2<<endl;
	
	//	if(num>=bound1&&num<=bound2)
	
}
