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
 
 
 
 
 
ll  ara[N],multiple_of_9[N],multiple_of_10[N];
// vector<ll>v[N];
// vector<pair<ll,ll>>dp(N);
// int ara[1001],arr[1001][100001],ara1[1001];
// vector<pair<pair<ll,ll>,ll>>v1;
ll fun(ll n)
{
    ll x=0;
    ll m=n;
    while(m)
    {
        x++;
        m/=10;
    }
    // cout<<x<<el;
    ll ans=0;
    ll ans1=0;
 
    lp(i,0,x-1)ans+=multiple_of_9[i];
    ll d=0;
 
    lp(i,1,x)
    {
        if(i==x)ans1+=((((n/multiple_of_10[i-1])%10)-1)*multiple_of_9[i-1]);
        else
        {
            if(((n/multiple_of_10[i-1])%10)<((n/multiple_of_10[i])%10))ans1+=((((n/multiple_of_10[i-1])%10))*multiple_of_9[i-1]);
            else if(((n/multiple_of_10[i-1])%10)==((n/multiple_of_10[i])%10))d=1,ans1=0,ans1+=((((n/multiple_of_10[i-1])%10))*multiple_of_9[i-1]);
            else if(((n/multiple_of_10[i-1])%10)>((n/multiple_of_10[i])%10))ans1+=((((n/multiple_of_10[i-1])%10)-1)*multiple_of_9[i-1]);
        }
    }
    if(d==0)ans1++;
    return ans1+ans;
}
 
// example:
// fun(54452)
// total digit 5
// so we can already make ans=1+9+9*9+9*9*9+9*9*9*9  (0 digit,1 digit .....)
 
// ans1 part
// now from right to left
// 2<5
// so can add more 2*1   (can include 0 and 1)
// 5>4 so can add (5-1)*9    (-1 because i just can include 0,1,2,3,, total 4 element)
// 4=4 so all previously counted(ans1) value will be zero 
// now can add more (4*9*9)
// 4<5 can add more (4*9*9*9)
// for last digit
// can add (5-1)*9*9*9*9
 
// as we already found at least one position where 4=4 was,,so no need to add extra 1 in the ans1
 
 
 
void solve()
{
    ll i,j,k,l,m,n,o,p,q,r,t,a,b,h,c,d,e,f,x,y,z,ans,ans1;
    cin>>a>>b;
    multiple_of_9[0]=multiple_of_10[0]=1;
    lp(i,1,19)
    {
        multiple_of_9[i]=multiple_of_9[i-1]*9;
        multiple_of_10[i]=multiple_of_10[i-1]*10;
    }
    cout<<fun(b)-fun(a-1)<<el;
 
 
    
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