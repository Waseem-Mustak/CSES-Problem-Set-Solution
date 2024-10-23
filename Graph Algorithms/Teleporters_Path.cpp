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
 
 
 
 
ll  ara[N],ara1[N],ara2[N],eadge_out[N],eadge_in[N];
 
//vector<set<pair<ll,ll>>> v1(N);
vector<ll>v[N];
 
vec path;
void dfs(ll n)
{
    while(!v[n].empty())
    {
        auto va=v[n].back();
        v[n].pop_back();
        int child=va;
        dfs(child);
    }
    path.pb(n);
}
 
 
void euler_path_directed()
{
    ll i,j,k,l,m,n,o,p,q,r,t,a,b,h,c,d,e,f,x,y,z,ans,ans1;
    cin>>n>>m;          // source 1, destination n
    lp(i,1,m)
    {
        cin>>a>>b;
        v[a].pb(b);  
        eadge_in[b]++;
        eadge_out[a]++;  
    }
 
    lp(i,2,n-1)
    {
        if(eadge_in[i]!=eadge_out[i])
        {
            cout<<"IMPOSSIBLE"<<el;
            return;
        }
    }
    if((eadge_out[1]- eadge_in[1]!=1)||(eadge_in[n]- eadge_out[n]!=1))
    {
        cout<<"IMPOSSIBLE"<<el;
        return;
    }
    dfs(1);
    if(path.size()!=(m+1))
    {
        cout<<"IMPOSSIBLE"<<el;
        return;
    }
    else 
    {
        revv(path);
        priv(path);
    }
}
 
 
void solve()
{
    ll i,j,k,l,m,n,o,p,q,r,t,a,b,h,c,d,e,f,x,y,z,ans,ans1;
    euler_path_directed();
 
}
 
// The condition of existance for an eulerian path in a directed graph is: At most one 
// node has 
// $out_i - in_i=1$
//  and at most one node has 
// $in_i - out_i=1$
// .
// This property is because an Eulerian path or cycle leaves a node the same number of 
// times it enters the node. In a directed
// geaph the exception are the start node and the end node.
 
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