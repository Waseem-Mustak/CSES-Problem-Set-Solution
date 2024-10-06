#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
typedef tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
typedef tree<long long,null_type,less_equal<long long>,rb_tree_tag,tree_order_statistics_node_update> multi_indexed_set;
 
 
const int N=1e6+5;
const int M=1e9+7;
long long NN=0,MM,S,K;
 
 
#define ll long long
#define lp(i,a,b) for(ll i=a;i<=b;i++)
#define rlp(i,a,b) for(ll i=a;i>=b;i--)
#define vi vector<int>
#define pb push_back
#define rpb pop_back
#define f first
#define s second
#define el "\n"
#define pri(ara,n) for(ll i=1;i<=n;i++)cout<<ara[i]<<" ";cout<<el;
 
 
 
 
 
 
 
ll  ara[N],ara1[N],ara2[N],ara3[N],ara4[N];//,ara3[N],ara4[N];
vector<pair<ll,ll>>v[N];
//vector<ll>v(N),inv(N);
ll arr[1001][1001];
 
void dfs(ll i,ll j,ll n,ll m)
{
	if(i<1||j<1||i>n||j>m)return;
	if(arr[i][j]==1)return;
	arr[i][j]=1;
	dfs(i+1,j,n,m);
	dfs(i,j+1,n,m);
	dfs(i-1,j,n,m);
	dfs(i,j-1,n,m);
}
 
int main()
{
    fast;
    ll i,j,k,l,m,n,o,p,q,r,s,t,a,b,c,d,x,y,z,ans,ans1;
    cin>>n>>m;
    //arr[n+1][m+1];
    lp(i,1,n)
    {
    	string s1;
    	cin>>s1;
    	lp(j,1,m)
    	{
    		if(s1[j-1]=='#')arr[i][j]=1;
    		else arr[i][j]=0;
    	}
    }
    ans=0;
    lp(i,1,n)
    {
    	lp(j,1,m)
    	{
    		
    		if(arr[i][j]==0)
    		{
    			dfs(i,j,n,m);
    			ans++;
    		}
 
    	}
    }
    cout<<ans<<el;
}