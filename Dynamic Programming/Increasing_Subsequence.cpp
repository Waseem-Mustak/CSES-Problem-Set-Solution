#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
typedef tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
typedef tree<long long,null_type,less_equal<long long>,rb_tree_tag,tree_order_statistics_node_update> multi_indexed_set;
 
 
const int N=4e6+1;
const int M=1e9+7;
long long NN=316,MM,S,K,test_case;
 
 
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
 
 
 
 
 
ll  ara[N],ara1[N],ara_1[N],ara_0[N];
// vector<ll>v[N];
//vector<ll>v(N),inv(N);
//ll arr[1001][1001];
string s1;
// int ara[1001],arr[1001][100001],ara1[1001];
 
 
void solve()
{
    ll i,j,k,l,m,n,o,p,q,r,t,a,b,h,c,d,e,f,x,y,z,ans,ans1;
    cin>>n;
    lp(i,1,n)cin>>ara[i];
    set<ll>stt;
    lp(i,1,n)
    {
        auto tem=stt.lower_bound(ara[i]);
        if(tem!=stt.end())stt.erase(tem);
        stt.insert(ara[i]); 
    }
    cout<<stt.size()<<el;  
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