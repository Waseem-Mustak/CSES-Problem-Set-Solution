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
 
bool myComparison_tem(const pair<pair<ll,ll>,ll> &a,const pair<pair<ll,ll>,ll> &b)    // for vector sorting  1st element small to learge (if same then second element large to small)
{
    return a.f.s<b.f.s;
}
 
ll lcm(ll a,ll b)
{
    return (a*b)/(__gcd(a,b));
}
ll gcd(ll a,ll b) 
{
    return __gcd(a,b);
}
 
 
 
 
 
ll  ara[N],bit_count[N];
vector<ll>v[N];
vector<pair<ll,ll>>dp(N);
// int ara[1001],arr[1001][100001],ara1[1001];
// vector<pair<pair<ll,ll>,ll>>v1;
void bit_count_(ll n)
{
    lp(i,1,n)
    {
        ll a=__builtin_popcountll(i);
        bit_count[i]=a;
        v[a].pb(i);
    }
}
 
void solve()
{
    ll i,j,k,l,m,n,o,p,q,r,t,a,b,h,c,d,e,f,x,y,z,ans,ans1;
    cin>>n>>o;
    lp(i,1,n)cin>>ara[i];
    m=pow(2,n);
 
    bit_count_(m-1);
    // pri(bit_count,m-1);
    lp(i,1,n)
    {
        for(auto va:v[i])
        {
            k=va;
            ll pos=1;
            ll tem_x=1;
            pair<ll,ll> tem={1000000000000000,1000000000000000};
            while(k)
            {
 
                if(k&1)
                {
                    ll g=va^tem_x;
                    // cout<<g<<el;
                    if(dp[g].s+ara[pos]>o)
                    {
                        tem=min(tem,{dp[g].f+1,ara[pos]});
                    }
                    else
                    {
                        tem=min(tem,{dp[g].f,dp[g].s+ara[pos]});
                    }
                    // if(va==3)cout<<tem.f<<" bb "<<tem.s<<el;
                }
 
                pos++;
                k/=2;
                tem_x*=2;
 
            }
            dp[va]=tem;
        }
    }
    // lp(i,1,m-1)cout<<dp[i].f<<" "<<dp[i].s<<el;
    cout<<dp[m-1].f+1<<el;
    
}
 
 
// dp[3] means
// 3-> 110
// so we will take 1st and 2nd person
// dp[3].f means how many(minimum) ride i need to take 1st and 2nd
// dp[3].s means the weight of my last ride(its important to check if i able or not to take extra person)
 
 
// how to calculate dp[3]?
// so here two option,,
// i already know dp[1] and dp[2] as (1,2) have less bit count than 3
// so for dp[3]
// check from dp[3^1=2] or dp[3^2=1] and do as like everythin in while loop of my code
 
 
 
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