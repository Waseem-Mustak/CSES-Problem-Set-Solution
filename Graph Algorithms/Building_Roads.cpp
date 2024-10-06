#include <bits/stdc++.h>
using namespace std;
const int N=2e6+10;
const int M=1e9+7;
long long NN=0,MM;
vector<int>v[N],vv;
//vector<pair<int,int>>vv;
long long ara[N],ara1[N],ara2[N],ara3[N],ara4[N];
 
void dfs(int ver)
{
	ara[ver]=1;
	for(auto va:v[ver])
	{
		if(ara[va]==0)
		{
			dfs(va);
		}
	}
}
 
long long sp,lp;
 
int main()
{
	int n,i,j,p,k,m,l,t,a,d,k1,b,index,c,gf,ans=0,div=1,use,from;
	cin>>n>>m;
	for(i=0;i<m;i++)
	{
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(i=1;i<=n;i++)
	{
		if(ara[i]==0)
		{
			vv.push_back(i);
			dfs(i);
		}
	}
	b=vv.size();
	cout<<b-1<<endl;
	for(i=0;i<b-1;i++)
	{
		cout<<vv[i]<<" "<<vv[i+1]<<endl;
	}
}