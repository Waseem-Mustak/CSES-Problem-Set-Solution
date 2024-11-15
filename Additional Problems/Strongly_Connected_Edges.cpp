#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
typedef tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
typedef tree<long long,null_type,less_equal<long long>,rb_tree_tag,tree_order_statistics_node_update> multi_indexed_set;
 
 
const int N=1e6+2;
const int M=1e9+7;
long long NN=316,MM,S,K;
long long test_case; 
 
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
#define coutl cout<<"Case "<<test_case<<": "
#define in(ara,n) cin>>n;lp(i,1,n)cin>>ara[i];
#define all(ara,n,m) lp(i,1,n)ara[i]=m;
#define index(indexed_Set,val) indexed_Set.order_of_key(val)
#define value(indexed_Set,ind) *indexed_Set.find_by_order(ind) 
#define pi 2*acos(0.0)
#define Mems(dp,n) memset(dp,n,sizeof(dp))
mt19937 rnd(time(0));
bool myComparison(const pair<pair<ll,ll>,ll> &a,const pair<pair<ll,ll>,ll> &b)  // for vector sorting  1st element small to learge (if same then second element large to small)
{
    if(a.f.f==b.f.f)return a.f.s>b.f.s;
    else return a.f.f<b.f.f;
}
bool cmp1(const pair<ll,ll> &a,const pair<ll,ll> &b)   // for vector sorting  1st element small to learge (if same then second element large to small)
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
 
 
//ll arr[1001][1001];
 
 
 
 
ll  ara[N],ara1[N],visited[N],vis[N];
 
vector<ll>graph[N];
 
 
ll starting_pos[N],low[N];
 
ll tim=0;
 
vector<pair<ll,ll>>IS_BRIDGE; 
ll hasBridge=0;
ll cntNode=0;
void find_bridge(ll node,ll parent)
{
     cntNode++;
    visited[node]=1;
    tim++;
    low[node]=starting_pos[node]=tim;
    for(auto child:graph[node])
    {
        if(child==parent)continue;
        if(visited[child]==0)
        {
            find_bridge(child,node);
            low[node]=min(low[node],low[child]);
 
            if(low[child]>starting_pos[node])   //part of bridge
            {
                // IS_BRIDGE.pb({node,child});
               hasBridge++;
            }
            else                   // mearge them with one parent by DSU
            { 
                // Union(node,child);
            }
        }
        else
        {
            low[node]=min(low[node],starting_pos[child]);
        }
    }
}
 
 
ll isInSameStack[N];
void dfsTree(ll n,ll p)
{
     vis[n]=1;
     isInSameStack[n]=1;
     for(auto va:graph[n])
     {
          if(vis[va]==0)
          {
               cout<<n<<" "<<va<<el;
               dfsTree(va,n);
          }
          else
          {
               if(va!=p&&isInSameStack[va]==1)
               {
                    cout<<n<<" "<<va<<el;
               }
          }
     }
     isInSameStack[n]=0;
}
 
 
void solve()
{
     ll i,j,k,l,m,n,o,p,q,r,t,a,b,h,c,d,e,f,x,y,z,ans,ans1;
     cin>>n>>m;
     lp(i,1,m)
     {
          cin>>a>>b;
          graph[a].pb(b);
          graph[b].pb(a);
     }
     find_bridge(1,0);
     if(hasBridge || (cntNode!=n))
     {
          cout<<"IMPOSSIBLE"<<endl;
          return;
     }
 
     dfsTree(1,0);
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