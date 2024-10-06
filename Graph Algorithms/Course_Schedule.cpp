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
 
 
 
 
 
ll  ara[N],ara1[N],ara2[N],visited[N],present_in_stack[N];
vector<ll>v[N];
//vector<ll>v(N),inv(N);
//ll arr[1001][1001];
 
stack<ll> st,topo_stack;
bool dfs(ll n,ll p)
{
    visited[n]=1;
    st.push(n);
    present_in_stack[n]=1;
    for(auto va:v[n])
    {
        if(visited[va]==0)
        {
            if(dfs(va,n))
            {
                return true;
            }
        }
        if((visited[va]==1)&&(present_in_stack[va]==1))        
        {
            st.push(va);
            return true;
        }
    }
    st.pop();
    present_in_stack[n]=0;
    return false;
}
void topological_dfs(ll n)
{
    visited[n]=1;
    for(auto va:v[n])
    {
        if(visited[va]==0)
        {
            topological_dfs(va);
        }
    }
    topo_stack.push(n);
}
 
int main()
{
    fast;
    ll i,j,k,l,m,n,o,p,q,r,t,a,b,c,d,x,y,z,ans,ans1;
    cin>>n>>m;
    lp(i,1,m)
    {
        cin>>a>>b;
        v[a].pb(b);
    }
    ans=0;
    lp(i,1,n)
    {
        if(visited[i]==0)
        {
            if(dfs(i,0))
            {
                ans=1;
                break;
            }
        }
    }
    if(ans==1)cout<<"IMPOSSIBLE"<<el;
    else
    {
        lp(i,0,n)visited[i]=0;
        lp(i,1,n)
        {
            if(visited[i]==0)
            {
                topological_dfs(i);
            }
        }
        while(!topo_stack.empty())
        {
            cout<<topo_stack.top()<<" ";
            topo_stack.pop();
        }        
    }  
}