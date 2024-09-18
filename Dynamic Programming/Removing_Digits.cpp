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
	cin>>n;
	ara1[0]=0;
	for(i=1;i<=n;i++)
	{
		m=i;
		ans=INT_MAX;
		while(m!=0)
		{
			l=m%10;
			if(l!=0)
			{
				if(ara1[i-l]<ans)ans=ara1[i-l];
			}
			m=m/10;
		}
		ara1[i]=ans+1;
	}
	cout<<ara1[n];
}