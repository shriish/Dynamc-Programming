#include<iostream>
using namespace std;

int min(int k,int l)
{
	if(k<l)
	return k;
	else
	return l;
}



int mcs(int a[],int sum,int n)
{
	int i,j;
	int t[n+1][sum+1];
	for(i=0;i<=sum;i++)
	t[0][i] = INT_MAX-1;
	for(i=1;i<=n;i++)
	t[i][0]=0;
	for(j=1;j<=sum;j++)
	{
		
		if(j%a[1]==0)
		{
			t[1][j]=j/a[1];
		}
		else
		{
			
			t[1][j]=INT_MAX-1;
		}
		
		
	}
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=sum;j++)
		{
			
			if(a[i-1]<=j)
			{
				t[i][j]=min(t[i-1][j],t[i][j-a[i-1]]+1);
			}
			
			else if(a[i-1]>j)
			{
				t[i][j]=t[i-1][j];
			}
		}
	}
	
	return t[n][sum];
	
}

int main()
{
	int sum=5,n=3,a[3]={1,2,3};
	int c = mcs(a,sum,n);
	cout<<"minimum no of coins that can form "<<sum<<" is: "<<c<<"\n";
	
	
	
}
