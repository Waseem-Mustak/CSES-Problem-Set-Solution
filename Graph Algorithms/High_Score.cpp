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
 
 
 
ll  ara[N],ara1[N],ara2[N],ara3[N],ara4[N],Distance[N],father[N];
 
 //vector<set<pair<ll,ll>>> v1( N);
// vector<ll>v[N];
 
 
int main()
{
    fast;
    ll i,j,k,l,m,n,o,p,q,e,r,ini,t,a,R,b,c,d,x,y,z,ans,ans1;
    t=1;
    //cin>>t;
    r=1;
    
    while(t--)
    {
        cin>>n>>m;
        vector<pair<pair<ll,ll>,ll>>v1;
 
        lp(i,1,m)
        {
            cin>>a>>b>>c;
            v1.pb({{a,b},-c});
        }
 
        lp(i,2,n)Distance[i]=1e18;
        lp(i,1,n-1)
        {
            lp(j,0,m-1)
            {
                a=v1[j].f.f;
                b=v1[j].f.s;
                c=v1[j].s;
                if(Distance[a]==1e18)continue;
                if(Distance[a]+c < Distance[b])Distance[b]=Distance[a]+c;
            }
        }
 
        ans=Distance[n];
 
        lp(i,1,n)
        {
            lp(j,0,m-1)
            {
                a=v1[j].f.f;
                b=v1[j].f.s;
                c=v1[j].s;
                if(Distance[a]==1e18)continue;
                if(Distance[a]+c < Distance[b])Distance[b]=-1e18;
            }
        }
 
        if(ans==Distance[n])cout<<-ans<<el;
        else cout<<-1<<el;
    }
}