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
 
 
ll lcm(ll a,ll b)
{
    return (a*b)/(__gcd(a,b));
}
ll gcd(ll a,ll b) 
{
    return __gcd(a,b);
}
 
 
ll  ara[N],ara1[N],ara2[N],ara3[N],ara4[N],ara5[N],vis[N];
 
 //vector<set<pair<ll,ll>>> v1( N);
vector<ll>v[N],v1[N];
ll tim=1;
void dfs(ll n)
{
    vis[n]=1;
    ara1[n]=tim;
    ara3[tim]=ara[n];
    tim++;
    ll a=0;
    for(auto va:v[n])
    {
        if(vis[va]==0)
        {
            dfs(va);
            a+=ara4[va];
        }
    }
    ara2[n]=tim;
    ara3[tim]=(-1*ara[n]);
    tim++;
    ara4[n]=a+1;
}
ll seg_tree(ll a,ll b,ll n)
{
    ll mid=(a+b)/2;
    if(a==b)
    {
        return ara5[n]=ara3[a];
    }
    return ara5[n]=(seg_tree(a,mid,2*n)+seg_tree(mid+1,b,2*n+1));
}
ll change_value(ll a,ll b,ll n,ll c,ll d)
{
    ll mid=(a+b)/2;
    if(c<a||c>b)return ara5[n];
    if(a==b)
    {
        return ara5[n]=d;
    }
    return ara5[n]=change_value(a,mid,2*n,c,d)+change_value(mid+1,b,2*n+1,c,d);
}
ll print_value(ll a,ll b,ll n,ll d)
{
    ll mid=(a+b)/2;
    if(a>=1&&b<=d)return ara5[n];
    if(a>d)return 0;
    return print_value(a,mid,2*n,d)+print_value(mid+1,b,2*n+1,d);
}
int main()
{
    fast;
    ll i,j,k,l,m,n,o,p,q,e,r,ini,t,a,b,c,d,x,y,z,ans,ans1;
    t=1;
   // cin>>t;
    r=1;
    while(t--)
    {
        cin>>n>>q;
        lp(i,1,n)cin>>ara[i];
        lp(i,2,n)
        {
            cin>>a>>b;
            v[a].pb(b);
            v[b].pb(a);
        }
        dfs(1);
        seg_tree(1,2*n,1);
        lp(i,1,q)
        {
            cin>>a;
            if(a==1)
            {
                cin>>a>>b;
                change_value(1,2*n,1,ara1[a],b);
                change_value(1,2*n,1,ara2[a],-b);
            }
            else
            {
                cin>>a;
                cout<<print_value(1,2*n,1,ara1[a])<<el;
            }
        }
    }
}