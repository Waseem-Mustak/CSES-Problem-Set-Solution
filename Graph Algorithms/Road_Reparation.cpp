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
 
 
ll  ara[N],ara1[N],ara2[N],ara3[N],siz[N],rnk[N],parent[N];
 
//vector<set<pair<ll,ll>>> v1(N);
vector<ll>v[N];
 
void make(ll n) // create node
{
    parent[n]=n;
    rnk[n]=1;
    siz[n]=1;
}
 
ll find(ll n)      // return the supreme parent of n
{
    if(parent[n]==n)return n;
    else return parent[n]=find(parent[n]);
}
 
 
void Union(ll a,ll b)     // add node a and b in one set
{
    a=find(a);
    b=find(b);
    if(a!=b)   // union by rank
    {
      if(rnk[a]<rnk[b])
      {
          swap(a,b);
      }
      parent[b]=a;
      if(rnk[a]==rnk[b])
      {
          rnk[a]++;
      }
    }
 
    // if(a!=b)   // union by size
    // {
    //     if(siz[a]<siz[b])
    //     {
    //         swap(a,b);
    //     }
    //     parent[b]=a;
    //     siz[a]+=siz[b];
    // }
}
 
 
int main()  //https://cses.fi/problemset/task/1675
{
    fast;
    ll i,j,k,l,m,n,o,p,q,e,r,ini,t,a,b,c,d,x,y,z,ans,ans1;
    t=1;
    // cin>>t;
    r=1;
    while(t--)
    {
        cin>>n>>m;
        vector<pair<ll,pair<ll,ll>>>v1;
        lp(i,1,n)make(i);
        lp(i,1,m)
        {
            cin>>a>>b>>c;
            v1.pb({c,{a,b}});
        }
        srtv(v1);
        ll total_cost=0;
        ll total_eadge_of_tree=0;
        for(auto va:v1)
        {
            ll cost=va.f;
            ll u=va.s.f;
            ll v=va.s.s;
            if(find(u)==find(v))continue;
            Union(u,v);
            total_eadge_of_tree++;
            total_cost+=cost;
        }
        if(total_eadge_of_tree!=(n-1))cout<<"IMPOSSIBLE"<<el;
        else cout<<total_cost<<el;
    }
} 


// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// int const N=200002;
 
// int  ara[N],ara1[N],present_in_stack[N],visited[N];
// vector<pair<int,int>>eadges[N];
// int NN;
// void Prim_Jarnik_algorithm()
// {
//     priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> queuee;
//     int total_cost=0;
//     int total_node=0;
//     // cout<<""
//     for(auto next_node:eadges[1])
//     {
//         queuee.push({next_node.second,{1,next_node.first}});
//     }
//     visited[1]=1;
//     // queuee.push({0,0});
//     while(!queuee.empty())
//     {
//         auto present_node=queuee.top();
//         int u=present_node.second.first;
//         int v=present_node.second.second;
//         int cost=present_node.first;
//         queuee.pop();
//         if(visited[v]==0)
//         {
//             total_cost+=cost;
//             // cout<<u<<" "<<v<<endl;
//             total_node++;
//             for(auto next_node:eadges[v])
//             {
//                 if(visited[next_node.first]==0)
//                 {
//                     queuee.push({next_node.second,{v,next_node.first}});
//                 }
//             }
//         }
//         visited[v]=1;
//     }
//     if(total_node!=NN-1)cout<<"IMPOSSIBLE"<<endl;
//     else cout<<total_cost<<endl;
// }
 
// signed main()
// {
//     // FILE *file1=freopen("input.txt","r",stdin);
//     // FILE *file2=freopen("output.txt","w",stdout);
//     int n,m;
//     cin>>n>>m;
//     NN=n;
//     for(int i=1;i<=m;i++)
//     {
//         int u,v,cost;
//         cin>>u>>v>>cost;
//         eadges[u].push_back({v,cost});
//         eadges[v].push_back({u,cost});
//     }
//     Prim_Jarnik_algorithm();
 
// }