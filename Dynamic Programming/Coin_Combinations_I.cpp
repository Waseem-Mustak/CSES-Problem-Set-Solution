#include <bits/stdc++.h>
using namespace std;
const int N=2e6+10;
const int M=1e9+7;
long long NN=0,MM;
vector<int>v[N],vv;
//vector<pair<int,int>>vv;
long long ara[N],ara1[N],ara2[N],ara3[N],ara4[N];
 
long long sp,lp;
 
int main()
{
	long long n,i,j,p,k,m,l,t,a,d,k1,b,index,c,gf,ans=0,div=1,use,from;
	cin>>n>>k;
	for(i=0;i<n;i++)cin>>ara[i];
	ara1[0]=1;
	for(i=1;i<=k;i++)
	{
		ans=0;
		for(j=0;j<n;j++)
		{
			t=i-ara[j];
			
			if(t>=0)
			{
				ans=(ans+ara1[t])%M;
			}
 
		}
		ara1[i]=ans;
	}
	cout<<ara1[k];
	//for(i=0;i<=k;i++)cout<<ara1[i]<<" ";
}