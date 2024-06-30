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
 
 
//ll arr[1001][1001];
 
 
 
 
ll  ara[N],ara1[N],ara2[N],ara3[N];
 
vector<ll>v[N];
ll bin(ll a,ll b)
{
    ll ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=(ans*a)%M;
        }
        b/=2;
        a=(a*a)%M;
    }
    return ans;
}
 
 
string s1;
char arr[100];
set<string>answers;
 
ll input_[9][9],check_[9][9];
 
void mak(ll pos,ll n)
{
    if(pos==0)
    {
        string ss;
        lp(i,1,n)ss.pb(arr[i]);
        answers.insert(ss);
        return;
    }
    lp(i,1,n)
    {
        if(ara[i]==0)
        {
            ara[i]=1;
            arr[i]=s1[pos-1];
            mak(pos-1,n);
            ara[i]=0;
        }
    }
}
 
void solve()
{
    ll i,j,k,l,m,n,o,p,q,r,t,a,b,h,c,d,e,f,x,y,z,ans,ans1;
    s1="12345678";
    n=s1.size();
    mak(n,n);
    ans=0;
    lp(i,1,8)
    {
        string s2;
        cin>>s2;
        lp(j,0,7)
        {
            if(s2[j]=='*')input_[i][j+1]=1;
        }
    }
 
    a=0;
    for(auto va:answers)
    {
        a++;
        p=0;
        lp(i,1,8)
        {
            j=va[i-1]-'1'+1;
            if(input_[i][j])p=1;
        }
        if(p==0)
        {
            lp(i,1,8)
            {
                j=va[i-1]-'1'+1;
                lp(k,i+1,8)
                {
                    j++;
                    l=va[k-1]-'1'+1;
                    if(j==l)p=1;
                }
                j=va[i-1]-'1'+1;
                lp(k,i+1,8)
                {
                    j--;
                    l=va[k-1]-'1'+1;
                    if(j==l)p=1;
                }
            }
            if(p==0)
            {
                ans++;
            }
        }
    }
    cout<<ans<<el;
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