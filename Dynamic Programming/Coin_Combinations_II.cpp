#include <bits/stdc++.h>
using namespace std;
const int N=2e6+10;
const int M=1e9+7;
long long NN=0,MM;
vector<int>v[N],vv;
//vector<pair<int,int>>vv;
//long long ara[N],ara1[N],ara2[N],ara3[N],ara4[N];
// int ara[1001][1001],ara1[1001][1001];
// char arr[1001][1001],arr1[1001][1001];
 
 
 
long long sp,lp;
 
int main()
{
 
	int n,i,j,p,k,m,l,t,a,d,b,c,ans=0;
	cin>>n>>m;
	int ara[n+1];
	for(i=1;i<=n;i++)cin>>ara[i];
	int arr[n+1][m+1];
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			if(j==0)arr[i][j]=1;
			else arr[i][j]=0;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			arr[i][j]=(arr[i][j]+arr[i-1][j])%M;
			t=j-ara[i];
			if(t>=0)
			{
				arr[i][j]=(arr[i][j]+arr[i][t])%M;
			}
		}
	}
	// for(i=0;i<=n;i++)
	// {
	// 	for(j=0;j<=m;j++)
	// 	{
	// 		cout<<arr[i][j]<<" ";
	// 	}cout<<endl;
	// }
	cout<<arr[n][m];
}