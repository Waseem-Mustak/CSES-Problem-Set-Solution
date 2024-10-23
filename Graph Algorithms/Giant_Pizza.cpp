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
 
 
ll  ara[N],ara1[N],ara2[N],ara3[N],ara4[N],position_of_node[N],vis[N];
 
//vector<set<pair<ll,ll>>> v1(N);
vector<ll>eadge[N],eadge_neg[N];
 
void add_eadge(char c1,ll a,char c2,ll b)
{
    a=2*a^(c1=='-');
    b=2*b^(c2=='-');
    ll neg_a=a^1;
    ll neg_b=b^1;
    eadge[neg_b].push_back(a);
    eadge[neg_a].push_back(b);
 
    eadge_neg[a].push_back(neg_b);
    eadge_neg[b].push_back(neg_a);
 
}
 
vec topo_sort;
void topo_dfs(ll n)
{
    vis[n]=1;
    // cout<<n<<el;
    for(auto va:eadge[n])
    {
        if(vis[va]==0)
        {
            topo_dfs(va);
        }
    }
    topo_sort.push_back(n);
}
void dfs1(ll n, ll tomo)
{
    vis[n]=1;
    position_of_node[n]=tomo;
    for(auto va:eadge_neg[n])
    {
        if(vis[va]==0)
        {
            dfs1(va,tomo);
        }
    }
}
 
void solve()
{
    ll i,j,k,l,m,n,o,p,q,e,r,ini,t,a,b,c,d,x,y,z,ans,ans1;
    cin>>n>>m;
    lp(i,0,2*m+2)
    {
        position_of_node[i]=0;
        vis[i]=0;
        eadge[i].clear();
        eadge_neg[i].clear();
    }
    topo_sort.clear();
    lp(i,1,n)
    {
        char c1,c2;
        // scanf(" %c%lld %c%lld", &c1, &a, &c2, &b);   // for lightoj
        scanf(" %c %lld %c %lld", &c1, &a, &c2, &b);   
 
        // string s1,s2;        // lightoj te evabe input kaj korena
        // cin>>s1>>s2;
        // c1=s1[0];
        // a=s1[1]-'0';
        // c2=s2[0];
        // b=s2[1]-'0';
        // // cin>>c1>>a>>c2>>b;
        // a=a;
        // b=b;
        // // cout<<type(a)<<el;
        // c1=c1;
        // c2=c2;
        add_eadge(c1,a,c2,b);
    }
    lp(i,2,2*m+1)
    {
        if(vis[i]==0)
        {
            topo_dfs(i);
        }
    }
    revv(topo_sort);
    lp(i,0,2*m+1)vis[i]=0;
    ll tomo=0;
    lp(i,0,2*m-1)
    {
        if(vis[topo_sort[i]]==0)
        {
            tomo++;
            dfs1(topo_sort[i],tomo);
        }
    }
    vector<char>solution;
    vec solution_2;
    ll taken_council_member=0;
    for(i=1;i<=m;i++)
    {
        if(position_of_node[2*i]==position_of_node[2*i+1])
        {
            cout<<"IMPOSSIBLE"<<el;
            return;
        }
        if(position_of_node[2*i]<position_of_node[2*i+1])
        {
            solution.push_back('-');
        }
        else 
        {
            solution.push_back('+');
            taken_council_member++;
            solution_2.push_back(i);
        }
    }
    // coutl<<"Yes"<<el;
    // cout<<taken_council_member<<" ";
    priv(solution);
}
 
int main()
{
    // fast;     //fast dile lightoj te kaj korena  (scanf dia input nite hoy(fast dile scanf kaj korena)) //https://lightoj.com/problem/forming-the-council  ekhane)
    ll t=1;
    // cin>>t;
    test_case=1;
    while(t--)
    {
 
        solve();
        test_case++;
    }
}