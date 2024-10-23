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
ll global_ans_number_of_connected_component,global_ans_max_size_from_all_connected_components;
 
void make(ll n) // create node
{
    parent[n]=n;
    rnk[n]=1;
    siz[n]=1;
}
 
ll find(ll n)       // return the supreme parent of n
{
    if(parent[n]==n)return n;
    else return parent[n]=find(parent[n]);
}
 
 
void Union(ll a,ll b)      // add node a and b in one set
{
    a=find(a);
    b=find(b);
    // if(a!=b)   // union by rank
    // {
    //     if(rnk[a]<rnk[b])
    //     {
    //         swap(a,b);
    //     }
    //     parent[b]=a;
    //     if(rnk[a]==rnk[b])
    //     {
    //         rnk[a]++;
    //     }
    // }
 
    if(a!=b)   // union by size
    {
        if(siz[a]<siz[b])
        {
            swap(a,b);
        }
        parent[b]=a;
        siz[a]+=siz[b];
        
        global_ans_number_of_connected_component--;
        global_ans_max_size_from_all_connected_components=max(siz[a],global_ans_max_size_from_all_connected_components);
    }
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
        cin>>n>>m;
        global_ans_number_of_connected_component=n;
        global_ans_max_size_from_all_connected_components=1;
        lp(i,1,n)
        {
            make(i);
        }
        lp(i,1,m)
        {
            cin>>a>>b;
            Union(a,b);
            cout<<global_ans_number_of_connected_component<<" "<<global_ans_max_size_from_all_connected_components<<el;
        }
    }
} 