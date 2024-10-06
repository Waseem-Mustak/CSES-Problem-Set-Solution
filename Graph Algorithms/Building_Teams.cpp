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
vector<ll>v[N];
//vector<ll>v(N),inv(N);
//ll arr[1001][1001];
 
void dfs(ll i,ll n)
{
    ara[i]=1;
    ara1[i]=n;
    for(auto va:v[i])
    {
        if(ara[va]==0)
        {
            if(n==1)dfs(va,2);
            else dfs(va,1);
        }
    }
}
 
int main()
{
    fast;
    ll i,j,k,l,m,n,o,p,q,r,s,t,a,b,c,d,x,y,ans,ans1;
    cin>>n>>m;
    vector<pair<ll,ll>>v1;
    lp(i,1,m)
    {
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
        v1.pb({a,b});
    }
    lp(i,1,n)
    {
        if(ara[i]==0)dfs(i,1);
    }
    k=0;
    lp(i,0,m-1)
    {
        auto va=v1[i];
        if(ara1[va.f]==ara1[va.s])
        {
            k=1;
            break;
        }
    }
    //pri(ara1,n);
    if(k==1)cout<<"IMPOSSIBLE"<<el;
    else
    {
        pri(ara1,n);
    } 
 
}