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
bool cmp1(const ll &a,const ll &b)    // for vector sorting  1st element small to learge (if same then second element large to small)
{
    return a>b;
    // if(a.f.f==b.f.f)return a.f.s>b.f.s;
    // else return a.f.f<b.f.f;
}
 
ll lcm(ll a,ll b)
{
    return (a*b)/(__gcd(a,b));
}
ll gcd(ll a,ll b) 
{
    return __gcd(a,b);
}
 
 
ll  ara[N],ara1[N],ara2[N],bit_cnt[N];
 
vector<ll>v[N];
void pre_compute()
{
    lp(i,1,60)
    {
        bit_cnt[i]=bit_cnt[i-1]*2+(1ll<<(i-1));
    }
}
 
void solve()
{
    ll i,j,k,l,m,n,o,p,q,r,t,a,b,c,d,x,y,z,ans,ans1;
    cin>>n;
    ans=0;
    ll pos=0;
    ll tem=0;
    while(n)
    {
        if(n&1)
        {
            ans+=(bit_cnt[pos]+tem+1);
            tem|=(1ll<<pos);
        }
        pos++;
        n/=2;
    }
    cout<<ans<<el;
}
 
int main()          
{
    fast;
    ll t=1;
    // cin>>t;
    pre_compute();
    test_case=1;
    while(t--)
    {
        solve();
        test_case++;
    }
} 