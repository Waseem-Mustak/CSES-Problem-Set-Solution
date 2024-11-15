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
 
bool myComparison(const pair<pair<ll,ll>,ll> &a,const pair<pair<ll,ll>,ll> &b)  // for vector sorting  1st element small to learge (if same then second element large to small)
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
 
 
//ll arr[1001][1001];
 
 
 
 
ll  ara[N],ara1[N],ara2[N],ara3[N];
 
vector<ll>v[N];
vector<long long> lps_array_of_kmp_algo(string s)  //It is pi array also
{
    long long n=s.size();
    vector<long long> array(n);
    array[0]=0;
    long long j=0;
    for(int i=1;i<n;i++)
    {
        while((j>0)&&(s[i]!=s[j]))
        {
            j=array[j-1];
        }
        if(s[i]==s[j])j++;
        array[i]=j;
    }
    return array;
}
//solution
// Define an array $\pi_S$ on some string $S$ such that $\pi_S[i]$ stores 
// the length of the longest nontrivial prefix of the entire 
// string that is equivalent to a suffix ending at position 
// $i$. Formally,
 
// $$\pi_S[i] = \max\{k \: | \: 1 \leq k < i \text{ and } S[0:k - 1] \equiv S[i - (k - 1): i]\}$$
 
 
 
 
 
 
 
vector<ll> z_function(string s)
{
    ll n=s.size();
    vector<ll> z_tem(n);
    for(ll i=1,l=0,r=0;i<n;i++)
    {
        if(i<=r)
        {
            z_tem[i]=min(z_tem[i-l],r-i+1);
        }
        while(i+z_tem[i]<n && s[z_tem[i]]==s[i+z_tem[i]])
        {
            z_tem[i]++;
        }
        if(i+z_tem[i]-1>r)
        {
            l=i;
            r=i+z_tem[i]-1;
        }
    }
    return z_tem;
}
 
 
// we now define an array 
// $z_S$
//  such that 
// $z_S[i]$
//  is the length of the longest prefix beginning at index 
// $i$
//  that is equivalent to a prefix of the entire string. Formally,
 
 
void solve()
{
    ll i,j,k,l,m,n,o,p,q,r,t,a,b,h,c,d,e,f,x,y,z,ans,ans1;
    string s1;
    cin>>s1;
    priv(z_function(s1));
    priv(lps_array_of_kmp_algo(s1));
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