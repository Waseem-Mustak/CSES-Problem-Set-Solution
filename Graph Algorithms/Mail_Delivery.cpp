#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
typedef tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
typedef tree<long long,null_type,less_equal<long long>,rb_tree_tag,tree_order_statistics_node_update> multi_indexed_set;
 
 
const int N=2e5+2;
const int M=998244353;
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
// #define el endl
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
 
bool myComparison(const pair<pair<ll,ll>,ll> &a,const pair<pair<ll,ll>,ll> &b)  // for vector sorting  1st element small to learge (if same then second element large to small)
{
    if(a.f.f==b.f.f)return a.f.s>b.f.s;
    else return a.f.f<b.f.f;
}
bool cmp1(const pair<ll,ll> &a,const pair<ll,ll> &b)    // for vector sorting  1st element small to learge (if same then second element large to small)
{
    // return a>b;
    if(a.f==b.f)return a.s>b.s;
    else return a.f<b.f;
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
 
 
 
 
ll  ara[N],ara1[N],ara2[N],ara3[N],eadge_vis[N];
 
//vector<set<pair<ll,ll>>> v1(N);
vector<pair<ll,ll>>v[N];
 
vec path;
void dfs(ll n)
{
    while(!v[n].empty())
    {
        auto va=v[n].back();
        v[n].pop_back();
        int child=va.f;
        int eadge_number=va.s;
        if(eadge_vis[eadge_number])continue;
        eadge_vis[eadge_number]=1;
        dfs(child);
    }
    path.pb(n);
}
 
 
void euler_cycle_undirected()
{
    ll i,j,k,l,m,n,o,p,q,r,t,a,b,h,c,d,e,f,x,y,z,ans,ans1;
    cin>>n>>m;
    lp(i,1,m)
    {
        cin>>a>>b;
        v[a].pb({b,i});      // i because of tracking the eadge number
        v[b].pb({a,i});
        eadge_vis[i]=0;
    }
 
    lp(i,1,n)
    {
        if(v[i].size()%2!=0)
        {
            cout<<"IMPOSSIBLE"<<el;
            return;
        }
    }
    dfs(1);
    if(path.size()!=(m+1))
    {
        cout<<"IMPOSSIBLE"<<el;
        return;
    }
    else 
    {
        priv(path);
    }
}
 
 
void solve()
{
    ll i,j,k,l,m,n,o,p,q,r,t,a,b,h,c,d,e,f,x,y,z,ans,ans1;
    euler_cycle_undirected();
 
}
 
// First let's define what an Eulerian path is.
 
// An Eulerian path is a path that goes through every edge once.
 
// Similarly, an Eulerian cycle is an Eulerian path that starts and ends with the same node.
 
// An important condition is that a graph can have an Eulerian cycle (not path!) if and
// only if every node has an even degree.
 
// Now, to find the Eulerian cycle we run a modified DFS. The DFS goes through only
// unvisited edges and the same edge can be processed multiple times throughout the DFS,
// so we remove it from the graph at the first visit.
 
// The algorithm described is Hierholzer's Algorithm.
 
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