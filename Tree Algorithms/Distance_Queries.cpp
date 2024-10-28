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
 
 
#define ll int
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
 
 
ll  ara[N],ara1[N],ara2[N],ara3[N],ara4[N],ara5[N];
 
 //vector<set<pair<ll,ll>>> v1( N);
vector<ll>v[N],v1[N];
ll arr[200003][20];
 
//ll arr[1001][1001];
void dfs(ll n,ll d,ll p)
{
    ara[n]=1;
    ara1[n]=d; // depth of node
    arr[n][0]=p; // storing parent node of every node
    for(auto va:v[n])
    {
        if(ara[va]==0)
        {
            dfs(va,d+1,n);
        }
    }
}
 
ll kth_upper_element(ll a,ll k)  // will return the kth upper node of node a
{
    ll c=0;
    while(k)
    {
        if(k&1)
        {
            a=arr[a][c];
        }
        c++;
        k/=2;
    }
    return a;
}
 
ll lca(ll a,ll b)
{
    ll tem_a=a;
    ll tem_b=b;
    if(ara1[a]>ara1[b])  // balancing both node in same level
    {
        a=kth_upper_element(a,ara1[a]-ara1[b]);
    }
    else
    {
        b=kth_upper_element(b,ara1[b]-ara1[a]);
    }
 
 
    ll x=ara1[a];
    ll y=0;
    ll c,d,p;
    while(x-y>1)  // finding LCA by binary search
    {
        ll mid=(x+y)/2;
        p=x-mid;
        c=kth_upper_element(a,p);
        d=kth_upper_element(b,p);
        if(c==d)y=mid;
        else
        {
            a=c;
            b=d;
            x=mid;
        }
    }
    ll LCA;
    if(a==b)LCA=a;
    else LCA=kth_upper_element(a,x-y);
    return LCA;
}
 
ll shortest_path_distance(ll a,ll b)
{
    ll LCA=lca(a,b);
    return ara1[a]+ara1[b]-(2*ara1[LCA]);
}
 
int main()
{
    fast;
    ll i,j,k,l,m,n,o,p,q,e,r,ini,t,a,b,c,d,x,y,z,ans,ans1;
    t=1;
   // cin>>t;
    r=1;
    while(t--)
    {
        cin>>n>>q;
        lp(i,2,n) // input of treeeee
        {
            cin>>a>>b;
            v[a].pb(b);
            v[b].pb(a);
        }
        dfs(1,0,0);
 
        lp(i,1,19)  // storing 1st,2nd,4th,8th,16th upper node of every node
        {            // 0 index 1st upper(parent) ,1 index means 2nd upper
            lp(j,1,n)
            {
                arr[j][i]=arr[arr[j][i-1]][i-1];
            }
        }
 
 
        lp(i,1,q)
        {
            cin>>a>>b;
            // ll LCA=lca(a,b);  // LCA done
            // cout<<shortest_path_distance(a,b)<<el;
            ll tem_a=a;
            ll tem_b=b;
            if(ara1[a]>ara1[b])  // balancing both node in same level
            {
                a=kth_upper_element(a,ara1[a]-ara1[b]);
            }
            else
            {
                b=kth_upper_element(b,ara1[b]-ara1[a]);
            }
 
 
            ll x=ara1[a];
            ll y=0;
            ll c,d,p;
            while(x-y>1)  // finding LCA by binary search
            {
                ll mid=(x+y)/2;
                p=x-mid;
                c=kth_upper_element(a,p);
                d=kth_upper_element(b,p);
                if(c==d)y=mid;
                else
                {
                    a=c;
                    b=d;
                    x=mid;
                }
            }
            ll LCA;
            if(a==b)LCA=a;
            else LCA=kth_upper_element(a,x-y);
 
 
            cout<<ara1[tem_a]+ara1[tem_b]-(2*ara1[LCA])<<el; 
        }
    }
}