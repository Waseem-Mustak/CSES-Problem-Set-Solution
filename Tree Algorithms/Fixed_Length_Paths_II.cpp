#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
typedef tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
typedef tree<long long,null_type,less_equal<long long>,rb_tree_tag,tree_order_statistics_node_update> multi_indexed_set;
 
 
const int N=2e5+2;
const int M=1e9+7;
long long NN=316,MM,S,K;
long long test_case; 
 
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
#define coutl cout<<"Case "<<test_case<<": "
#define in(ara,n) cin>>n;lp(i,1,n)cin>>ara[i];
#define all(ara,n,m) lp(i,1,n)ara[i]=m;
#define index(indexed_Set,val) indexed_Set.order_of_key(val)
#define value(indexed_Set,ind) *indexed_Set.find_by_order(ind) 
#define pi 2*acos(0.0)
#define Mems(dp,n) memset(dp,n,sizeof(dp))
 
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
 
 
 
 
vector<ll> graph[N];
ll subtree_size[N];
ll max_depth;
long long ans;
bool processed[N];
ll n,k1,k2;
 
 
 
 
 
 
 
struct BIT                 // starttttttttttttttttt
{
    vector<vector<ll>>bit;  // 0/1 indexing,change in three place
    int size;
    BIT(int n) {bit.resize(2,vector<ll>(n+2,0));size=n;}
 
    void update(int indx,ll val,int flag=0){  // update a value just in bit array not in main array
        while(indx<=size){
            bit[flag][indx]+=val;
            // indx+=(indx & -indx); //for 1 indexing
            indx=(indx|(indx+1));  //for 0 indexing
        }
    }
 
    ll sum(int indx,int flag=0){   // returning sum from ara[0]/ara[1] to ara[indx]
        ll ans=0;
        // while(indx>0){   // for 1 indexing
        while(indx>=0){   //for 0 indexing
            ans+=bit[flag][indx];
            // indx-=(indx & -indx); // for 1 indexing
            indx=(indx & (indx+1))-1;  //for 0 indexing
        }
        return ans;
    }
 
    ll query(int l,int r)
    {
        return sum(r,0)-sum(l-1,0);
    }
    //this part is for range update
    void updateRange(int l,int r,long long val){
        update(0,l,val);       update(0,r+1,-val);   
        update(1,l,val*(l-1)); update(1,r+1,-val*r);
    }
    long long sumRange(int indx){    // from ara[0]/ara[1] to ara[indx]
        return sum(0,indx)*indx- sum(1,indx);
    }
    long long queryRange(int l,int r){
        return sumRange(r)- sumRange(l-1);
    }
};
 
BIT bit(N);
 
 
ll dfs_subtree_size(ll u,ll p=-1)
{
    subtree_size[u]=1;
    for(auto v:graph[u])
    {
        if((processed[v]==false)&&(v!=p))
        {
            subtree_size[u]+=dfs_subtree_size(v,u);
        }
    }
    return subtree_size[u];
}
 
ll dfs_find_centroid(ll u,ll tree_size,ll p=-1)
{
    for(auto v:graph[u])
    {
        if((processed[v]==false)&&(v!=p))
        {
            if(subtree_size[v]*2>tree_size)
            {
                return dfs_find_centroid(v,tree_size,u);
            }
        }
    }
    return u;
}
 
void get_cnt(ll node,ll parent,bool filling,ll depth=1)
{
    if(depth>k2)return;
    max_depth=max(max_depth,depth);
    if(filling==true)bit.update(depth,1);
    else ans+=(bit.query(max((ll)0,k1-depth),k2-depth));
    for(auto va:graph[node])
    {
        if(va!=parent && processed[va]==false)
        {
            get_cnt(va,node,filling,depth+1);
        }
    }
}
 
void dfs_centroid_decompos(ll node=1,ll par=-1)
{
    ll centroid=dfs_find_centroid(node,dfs_subtree_size(node));
    processed[centroid]=true;
    max_depth=0;
    for(auto va:graph[centroid])
    {
        if(va!=par && processed[va]==false)
        {
            get_cnt(va,centroid,false);
            get_cnt(va,centroid,true);
        }
    }
    for(int i=1;i<=max_depth;i++)
    {
        bit.update(i,-bit.query(i,i));
    }
    for(auto va:graph[centroid])
    {
        if(va!=par && processed[va]==false)dfs_centroid_decompos(va);
    }
}
 
void solve()
{
    
    cin>>n>>k1>>k2;
    ans=0;
    lp(i,1,n-1)
    {
        ll a,b;
        cin>>a>>b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    bit.update(0,1);
    dfs_centroid_decompos(1,-1);
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