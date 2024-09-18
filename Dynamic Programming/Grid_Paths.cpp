#include <bits/stdc++.h>
using namespace std;
const int N=2e6+10;
const int M=1e9+7;
long long NN=0,MM;
vector<int>v[N],vv;
//vector<pair<int,int>>vv;
//long long ara[N],ara1[N],ara2[N],ara3[N],ara4[N];
 
long long sp,lp;
 
int main()
{
	long long n,i,j,p,k,m,l,t,a,d,k1,b,index,c,gf,ans=0,div=1,use,from;
	cin>>n;
	int ara[n+2][n+2];
	char ara1[n+2][n+2];
	for(i=0;i<n+2;i++)
	{
		for(j=0;j<n+2;j++)
		{
			ara[i][j]=0;
		}
	}
	char cg;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cin>>ara1[i][j];
			
		}
	}
	if(ara1[n][n]!='*')ara[n][n]=1;
	//cout<<ara[n][n];
	for(i=n;i>0;i--)
	{
		for(j=n;j>0;j--)
		{
			if(ara1[i][j]!='*')
			{
				if(i==n&&j==n)continue;
				
				
					ara[i][j]=(ara[i+1][j]+ara[i][j+1])%M;
					//cout<<ara[i][j]<<" ";
				
			}
		}
	}
	cout<<ara[1][1];
}