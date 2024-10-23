#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
typedef tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
typedef tree<long long,null_type,less_equal<long long>,rb_tree_tag,tree_order_statistics_node_update> multi_indexed_set;
 
 
const int N=2e3+2;
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
 
 
 
 
ll  ara[N],ara1[N],ara2[N];
 
//vector<set<pair<ll,ll>>> v1(N);
vector<ll>v_in[N],v_out[N],v2[N];
vector<ll> set_bits[2000000];
ll dp[2000000][21];
 
void total_Hamiltonian_path()
{
    ll i,j,k,l,m,n,o,p,q,r,t,a,b,h,c,d,e,f,x,X,S,y,z,ans,ans1;
    cin>>n>>m;
    lp(i,1,m)
    {
        cin>>a>>b;
        v_in[a].pb(b);
        v_out[b].pb(a);
    }
    ara[1]=1;
    lp(i,2,20)
    {
        ara[i]=ara[i-1]*2;
    }
 
    x=pow(2,n)-1;
    ll tem=x;
 
    lp(i,1,x)
    {
        a=__builtin_popcount(i);
        v2[a].pb(i);   // in i there are a set bit 
        lp(j,1,n)
        {
            if(ara[j]&i)
            {
                set_bits[i].pb(j);
            }
        }
    }
 
    
    dp[1][1]=1;
    for(S=2;S<=tem;S++)
    {
        if((S&1)==0) continue;
        if((S&ara[n])&&(S!=tem))continue;   // this is the reason for tle,dont include S where nth bit is set but S is not full subset
 
        for(auto j:set_bits[S])
        {
            i=j;
            for(auto x:v_out[i])
            {
                if(ara[x]&S)   // x is a member of S
                {
                    dp[S][i]=(dp[S][i]+dp[S^ara[i]][x])%M;   // main dp  
                }
            }
        }
    }
    x=pow(2,n)-1;
    cout<<dp[x][n];
}
 
void solve()
{
    ll i,j,k,l,m,n,o,p,q,r,t,a,b,h,c,d,e,f,x,y,z,ans,ans1;
    total_Hamiltonian_path();
 
}
 
 
// Let $dp[S][i]$ be the number of routes that visit all the cities in the subset
// $S$ and end at city $i$. The transitions will then be:
 
 
// dp[S][i]= sum of all dp[S\{i}][x]  where x is adjacent of i and,x is a member of set S
// s\{i} means subset S without i
 
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