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
 
 
 
 
 
 
 
ll  ara[N],ara1[N],ara2[N],ara3[N],ara4[N];//,ara3[N],ara4[N];
vector<ll>v[N];
//vector<ll>v(N),inv(N);
//ll arr[1001][1001];
ll lvl=-1,num=-1;
void dfs(ll n,ll l)
{
    ara[n]=1;
    if(l>lvl)
    {
        lvl=l;
        num=n;
    }
    ara1[n]=l;
    for(auto va:v[n])
    {
        if(ara[va]==0)
        {
            dfs(va,l+1);
        }
    }
}
 
void dfs1(ll n,ll l)
{
    ara[n]=1;
    ara1[n]=max(ara1[n],l);
    for(auto va:v[n])
    {
        if(ara[va]==0)
        {
            dfs1(va,l+1);
        }
    }
 
}
 
 
int main()
{
    fast;
    ll i,j,k,l,m,n,o,p,q,r,s,t,a,b,c,d,x,y,ans,ans1;
    cin>>n;
    lp(i,1,n-1)
    {
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    dfs(1,0);
    lp(i,0,n)ara[i]=0;
    lvl=-1;
    dfs(num,0);
    lp(i,0,n)ara[i]=0;
    dfs1(num,0);
    lp(i,1,n)cout<<ara1[i]<<" ";
 
}