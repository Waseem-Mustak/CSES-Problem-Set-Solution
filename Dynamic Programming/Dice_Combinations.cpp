#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
const int M=1e9+7;
const int M1=1e9+6;
long long ara[N],ara1[N];
 
int main()
{
	long long n,i,j,p,q,r,s,k,l,t,c,a,b,ans,to=1,to1=1,sum=1,mul=1;
	cin>>n;
	ara[0]=1;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=6;j++)
		{
			if(i-j>=0)
			{
				ara[i]=(ara[i]+ara[i-j])%M;
			}
		}
	}
	cout<<ara[n]<<endl;
}