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
 
 
 
 
ll  ara[N],ara1[N],ara2[N],ara3[N],dep[N],cnt_dep[N], kuno_ekta_node_N_je_depth_e_ache_sekhane_tar_serial_koto[N];
 
vector<ll>v[N];
ll fans=0;
void dfs(ll n)
{
    ara1[n]=1;
    ll p=0;
    for(auto va:v[n]){
        if(ara1[va]==0)
        {
            dfs(va);
            if(ara2[va]==0)p=1;
        }
    }
    if(p==1)
    {
        fans++;
        ara2[n]=1;
    }
}
 
 
 
int main()
{
    fast;
    ll i,j,k,l,m,n,o,p,q,e,r,ini,t,a,b,c,d,x,y,z,ans,ans1;
    cin>>n;
    lp(i,2,n)
    {
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    dfs(1);
    cout<<fans<<el;
}