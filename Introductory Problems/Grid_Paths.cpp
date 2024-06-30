#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
typedef tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
typedef tree<long long,null_type,less_equal<long long>,rb_tree_tag,tree_order_statistics_node_update> multi_indexed_set;
 
 
const int N=3e6+2;
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
 
 
ll vis[1001][1001];
 
 
 
 
ll  ara[N],ara1[N],ara2[N],ara3[N];
 
vector<ll>v[N];
string s1;
ll mans=0;
ll is_visited(ll i,ll j)
{
    if(i==0||j==0||i==8||j==8)return 1;
    else return vis[i][j];
}
void dfs(ll i,ll j,ll n)
{   
    if(i==7&&j==1&&n==48)
    {
        mans++;
        return;
    }
    if(i==7&&j==1&&n!=48)
    {
        return;
    }
    if(n>=48)return;
    vis[i][j]=1;
 
    if(s1[n]=='L')
    {
        if(is_visited(i,j-1)==0)dfs(i,j-1,n+1);
    }
    else if(s1[n]=='R')
    {
        if(is_visited(i,j+1)==0)dfs(i,j+1,n+1);
    }
    else if(s1[n]=='U')
    {
        if(is_visited(i-1,j)==0)dfs(i-1,j,n+1);
    }
    else if(s1[n]=='D')
    {
        if(is_visited(i+1,j)==0)dfs(i+1,j,n+1);
    }
    else
    {
        // egula na dile tle ashe,,
        // here we return because,
        // if we are in any squre where it exist,thats divide the whole grid,so if we decide
        //     to run dfs still,it will go any one side of grid,so at least one square of another side will be unvisited,
        // so 48 move will not be completed
        // 1 1 1 1 1 0
        // 0 0 0 0 1 0
        // 0 0 0 0 0 0
        // 0 0 0 0 0 0
        // 0 0 0 0 0 0
        // 0 0 0 0 0 0
        // 0 0 0 0 0 0
        // if we are in 2,7 position,if we go up,then it will never visit down part
        //     if we go down,it will never visit 1,7 position
 
        if(is_visited(i,j+1)==0&&is_visited(i,j-1)==0&&is_visited(i+1,j)==1&&is_visited(i-1,j)==1)
        {
            vis[i][j]=0;
            return;
        }
        if(is_visited(i,j+1)==1&&is_visited(i,j-1)==1&&is_visited(i+1,j)==0&&is_visited(i-1,j)==0)
        {
            vis[i][j]=0;
            return;
        }
        if(is_visited(i,j-1)==0)dfs(i,j-1,n+1);
        if(is_visited(i,j+1)==0)dfs(i,j+1,n+1);
        if(is_visited(i-1,j)==0)dfs(i-1,j,n+1);
        if(is_visited(i+1,j)==0)dfs(i+1,j,n+1);
    }
 
 
 
    vis[i][j]=0;
}
 
void solve()
{
    ll i,j,k,l,m,n,o,p,q,r,t,a,b,h,c,d,e,f,x,y,z,ans,ans1;
    cin>>s1;
    dfs(1,1,0);
    cout<<mans<<el;
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