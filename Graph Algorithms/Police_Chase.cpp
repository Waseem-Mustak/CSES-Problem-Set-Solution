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
 
 
ll  ara[N],ara1[N],ara2[N],father[N];
 
vector<ll>v[N];
// vector<vector<ll>> v1;
ll weight[501][501];
vector<ll>who_are_responsible_2;
void bfs1(ll n)
{
    queue<ll>q;
    q.push(n);
    ara[n]=1;
    while(!q.empty())
    {
        ll a=q.front();
        who_are_responsible_2.push_back(a);
        for(auto va:v[a])
        {
            if((ara[va]==0)&&(weight[a][va]>0))
            {
                q.push(va);
                ara[va]=1;
                father[va]=a;
            }
        }
        q.pop();
    }
}
 
void bfs(ll n)
{
    queue<ll>q;
    q.push(n);
    ara[n]=1;
    while(!q.empty())
    {
        ll a=q.front();
        for(auto va:v[a])
        {
            if((ara[va]==0)&&(weight[a][va]>0))
            {
                q.push(va);
                ara[va]=1;
                father[va]=a;
            }
        }
        q.pop();
    }
}
long long max_flow(ll n)
{
    long long a,b,ans;
    ans=0;
    while(1)
    {
        for(int i=1;i<=n;i++)ara[i]=0;
        bfs(1);
 
 
        if(ara[n]==0)break;
 
        vector<long long> path;
        long long tem_n=n;
        while(father[tem_n]!=0)
        {
            path.pb(father[tem_n]);
            tem_n=father[tem_n];
        }
        revv(path);
        path.pb(n);
        long long tem_size=path.size();
        long long tem_min=INT_MAX;
 
        for(int i=1;i<tem_size;i++)
        {
            a=path[i-1];
            b=path[i];
            tem_min=min(tem_min,weight[a][b]);
 
        }
        for(int i=1;i<tem_size;i++)
        {
            a=path[i-1];
            b=path[i];
            weight[a][b]-=tem_min;
            weight[b][a]+=tem_min;
        }
        ans+=tem_min;
    }
    return ans;
}
 
void solve()
{
    ll i,j,k,l,m,n,o,p,q,r,t,a,b,c,d,x,y,z,ans,ans1;
    cin>>n>>m;
    lp(i,1,m)
    {
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
        weight[a][b]+=1;
        weight[b][a]+=1;
    }
    max_flow(n);
    lp(i,1,n)ara[i]=0;
    bfs1(1);
    for(auto va:who_are_responsible_2)
    {
        ara1[va]=1;
    }
    vector<pair<ll,ll>>v2;
    for(auto va:who_are_responsible_2)
    {
        for(auto va1:v[va])
        {
            if(ara1[va1]==0)
            {
                v2.pb({va,va1});
            }
        }
    }
    cout<<v2.size()<<el;
    for(auto va:v2)
    {
        cout<<va.f<<" "<<va.s<<el;
    }
 
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