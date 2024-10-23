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
 
ll lcm(ll a,ll b)
{
    return (a*b)/(__gcd(a,b));
}
ll gcd(ll a,ll b) 
{
    return __gcd(a,b);
}
 
 
ll  ara[N],new_graph_weight[N],ara2[N],high_distance[N],visited[N],res_arr[N],vis[N];
 
//vector<set<pair<ll,ll>>> v1(N);
vector<ll>v[N],v_rev[N],vec_SCC[N],vec_new_constructed[N];
 
 
stack<ll> SCC;
void dfs(ll n)
{
    vis[n]=1;
    for(auto va:v[n])
    {
        if(vis[va]==0)
        {
            dfs(va);
        }
    }
    SCC.push(n);
}
 
void dfs1(ll n,ll b)
{
    vis[n]=1;
    vec_SCC[b].pb(n);
    for(auto va:v_rev[n])
    {
        if(vis[va]==0)
        {
            dfs1(va,b);
        }
    }
}
 
 
 
 
vector<ll> topo_vec_of_new_graph;
 
 
void topological_dfs(ll n)
{
    visited[n]=1;
    for(auto va:vec_new_constructed[n])
    {
        if(visited[va]==0)
        {
            topological_dfs(va);
        }
    }
    topo_vec_of_new_graph.pb(n);     // just pushing to stack when a node is completely visited
}
 
 
void Stronly_Connected_Component()
{
    ll i,j,k,l,m,n,o,p,q,e,r,ini,t,a,b,c,d,x,y,z,ans,ans1;
    cin>>n>>m;
    lp(i,1,n)cin>>ara[i];
    lp(i,1,m)
    {
        cin>>a>>b;
        v[a].pb(b);
        v_rev[b].pb(a);
    }
    lp(i,1,n)
    {
        if(vis[i]==0)
        {
            dfs(i);
        }
    }
    lp(i,1,n)vis[i]=0;
    b=0;
    while(!SCC.empty())
    {
        a=SCC.top();
        SCC.pop();
        if(vis[a]==0)
        {
            b++;
            dfs1(a,b);
        }
    }
 
    
    lp(i,1,b)
    {
        a=0;
        for(auto va:vec_SCC[i])
        {
            res_arr[va]=i;
            a+=ara[va];
        }
        // cout<<a<<el;
        new_graph_weight[i]=a;
    }
 
    // cout<<b<<el;
    ll total_node_of_new_graph=b;
 
 
    // pri(res_arr,n);
 
    lp(i,1,n)
    {
        for(auto va:v[i])
        {
            a=res_arr[i];
            b=res_arr[va];
            // cout<<a<<" "<<b<<el;
            if(a!=b)vec_new_constructed[a].pb(b);            
        }
    }
    lp(i,1,total_node_of_new_graph)
    {
        if(visited[i]==0)topological_dfs(i);
    }
    // priv(topo_vec_of_new_graph);
    // pri(new_graph_weight,total_node_of_new_graph);
 
    revv(topo_vec_of_new_graph);
    for(auto x:topo_vec_of_new_graph)high_distance[x]=new_graph_weight[x];
    for(auto x:topo_vec_of_new_graph)
    {
        for(auto y:vec_new_constructed[x])
        {
            if(high_distance[x]+new_graph_weight[y]>high_distance[y])
            {
                high_distance[y]=high_distance[x]+new_graph_weight[y];
            }
        }
    }
 
    // pri(high_distance,total_node_of_new_graph);
    ans=0;
    lp(i,1,total_node_of_new_graph)ans=max(ans,high_distance[i]);
    cout<<ans<<el;
 
 
    // cout<<total_node_of_new_graph<<el;
    // pri(res_arr,n);
 
}
 
 
// First, we split the graph into SCCs. We then treat each component as a node. So then, 
// If the coin collector enters a component, he can collect all the coins in it.
 
// Since the resulting graph is a DAG, we can use DP to find the maximum coins that can be collected.
 
void solve()
{
    ll i,j,k,l,m,n,o,p,q,e,r,ini,t,a,b,c,d,x,y,z,ans,ans1;
    Stronly_Connected_Component();
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