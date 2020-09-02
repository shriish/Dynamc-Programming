#include<iostream>
using namespace std;






bool eqs(int a[],int s,int n)
{
	
int t[n+1][s+1];
int i,j;
for(i=0;i<=n;i++)
{
	t[i][0]=true;
	}	
	
for(i=1;i<=s;i++)
{
	t[0][i]=false;
	}	
	
for(i=1;i<=n;i++)
{
for(j=1;j<=s;j++)
{

if(a[i-1]<=j)

t[i][j]=t[i-1][j-a[i-1]] || t[i-1][j];

else if(a[i-1]>j)
{
	t[i][j] = t[i-1][j];
}
}
}
return t[n][s];
}
int main()
{
	
int n,s=0;	
cout<<"enter the size of the array\n";
cin>>n;
int a[n];
int k;
cout<<"enter the elements of the array\n";
for(k=0;k<n;k++)
cin>>a[k];
int i;
for(k=0;k<n;k++)
{
	s=s+a[k];
}	
cout<<s<<"\n";
if(s%2!=0)
cout<<"equal sum partiotion not possible\n";
else if(s%2==0)
{
	
	if(eqs(a,s/2,n)==true)
	{
		cout<<"subsets are present\n";
	}
	
	else
	cout<<"not present\n";
	
	}	
	
	
}
