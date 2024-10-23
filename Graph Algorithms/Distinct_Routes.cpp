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
 
vector<ll>v[N],tem_graph[N];
// vector<vector<ll>> v1;
ll weight[501][501],check_graph[501][501],check_graph_2[501][501];
 
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
                // cout<<"L"<<el;
                q.push(va);
                ara[va]=1;
                father[va]=a;
            }
        }
        q.pop();
    }
}
long long max_flow(ll n,ll print_path)
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
        
        if(print_path==1)
        {
            cout<<path.size()<<el;
            priv(path);
        }
        long long tem_size=path.size();
        long long tem_min=INT_MAX;
 
        for(int i=1;i<tem_size;i++)
        {
            a=path[i-1];
            b=path[i];
 
            tem_min=min(tem_min,weight[a][b]);
 
            //new
            if(check_graph[a][b]==0)
            {
                check_graph_2[b][a]=-1;
                check_graph_2[a][b]=-1;
                // weight[b][a]=0;
            }
            else
            {
                if(check_graph_2[a][b]!=-1)check_graph_2[a][b]=1;
            }
 
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
        check_graph[a][b]=1;
        c=1;
        v[a].pb(b);
        v[b].pb(a);
        weight[a][b]+=c;
    }
    
    cout<<max_flow(n,0)<<el;
 
    // reinitialize
    lp(i,0,n)
    {   
        v[i].clear();
        lp(j,0,n)
        {
            weight[i][j]=0;
        }
    }
 
    //rebuild graph
    lp(i,1,n)
    {
        lp(j,1,n)
        {
            if(check_graph_2[i][j]==1)
            {
                v[i].pb(j);
                weight[i][j]=1;
                // cout<<i<<" "<<j<<" "<<weight[i][j]<<el;
            }
        }
    }
    max_flow(n,1);
}
 
// basic part
// from first max flow from my given graph G_a
// i got some path(which are sometimes invalid path),,
// from every path i will got some eadges
 
// i will construct another graph only by usuing these eadges 
// which is G_b
 
// ***
// but but,,when constructing new graph
// if a eadge a->b comes,,,,if a->b is not present in G_a 
// but i got it for adding in G_b ,i will never add it,,even i 
// will never add b->a too
 
 
// now,in new graph G_b ,again i will run max_flow,it will give all path too
 
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