#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
typedef tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
typedef tree<long long,null_type,less_equal<long long>,rb_tree_tag,tree_order_statistics_node_update> multi_indexed_set;
 
 
const int N=1e6+2;
const int M=1e9+7;
long long NN=316,MM,S,K,test_case;
 
 
#define ll long long
#define lp(i,a,b) for(ll i=a;i<=b;i++)
#define rlp(i,a,b) for(ll i=a;i>=b;i--)
#define vec vector<long long>
#define pb push_back
#define rpb pop_back
#define f first
#define s second
#define el "\n"
#define pri(ara,n) for(ll i=1;i<=n;i++)cout<<ara[i]<<" ";cout<<el;
#define priv(vec) for(auto va:vec)cout<<va<<" ";cout<<"\n";
#define srt(ara,n) sort(ara+1,ara+1+n);
#define srtv(vec) sort(vec.begin(), vec.end());
#define revv(vec) reverse(vec.begin(), vec.end());
#define coutl cout<<"Case "<<r<<": "
#define in(ara,n) cin>>n;lp(i,1,n)cin>>ara[i];
#define all(ara,n,m) lp(i,1,n)ara[i]=m;
#define index(indexed_Set,val) indexed_Set.order_of_key(val)
#define value(indexed_Set,ind) *indexed_Set.find_by_order(ind) 
#define pi 2*acos(0.0)
 
 
bool myComparison(const pair<pair<ll,ll>,ll> &a,const pair<pair<ll,ll>,ll> &b)    // for vector sorting  1st element small to learge (if same then second element large to small)
{
    if(a.f.f==b.f.f)return a.f.s>b.f.s;
    else return a.f.f<b.f.f;
}
bool cmp1(const pair<ll,ll> &a,const pair<ll,ll> &b)    // for vector sorting  1st element small to learge (if same then second element large to small)
{
    // return a>b;
    if(a.f==b.f)return a.s<b.s;
    else return a.f>b.f;
}
 
ll lcm(ll a,ll b)
{
    return (a*b)/(__gcd(a,b));
}
ll gcd(ll a,ll b) 
{
    return __gcd(a,b);
}
 
 
 
 
 
ll  ara[N],parent[N],visited[N],Distance[N];
vector<ll>v[N];
//vector<ll>v(N),inv(N);
//ll arr[1001][1001];
 
 
 
 
 
 
vector<ll> st,topo_vec;
 
 
void topological_dfs(ll n)
{
    visited[n]=1;
    for(auto va:v[n])
    {
        if(visited[va]==0)
        {
            topological_dfs(va);
        }
    }
    topo_vec.pb(n);     // just pushing to stack when a node is completely visited
}
 
 
 
 
void solve()
{
    ll i,j,k,l,m,n,o,p,q,r,t,a,b,h,c,d,e,f,x,y,z,ans,ans1;
    cin>>n>>m;
    lp(i,1,m)
    {
        cin>>a>>b;
        v[a].pb(b);
    }
    topological_dfs(1);   // first find the topo order
    if(visited[n]==0)cout<<"IMPOSSIBLE"<<el;
    else
    {
        // priv(topo_vec);
        revv(topo_vec);
        for(auto x:topo_vec)
        {
            for(auto y:v[x])
            {
                if(Distance[x]+1>Distance[y])
                {
                    Distance[y]=Distance[x]+1;
                    parent[y]=x;
                }
            }
        }
        vec path;
        x=n;
        while(x!=0)
        {
            path.pb(x);
            x=parent[x];
        }
        cout<<path.size()<<el;
        revv(path);
        priv(path);
    }
    
}
 
int main()
{
    fast;
    ll t=1;
    // cin>>t;
    test_case=1;
    while(t--)
    {
        solve();
        test_case++;
    }
}