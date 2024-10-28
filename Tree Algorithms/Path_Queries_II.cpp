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
#define pb push_back
#define el "\n"
 
 
ll node,q,tim=0;
ll values[N],shuffledValues[N],startTime[N],chainNum[N],subtreeSiz[N];
vector<ll>graph[N];
 
// for lca
ll depth[N],Parr[200003][20];
ll segTreeVal[N];
 
void dfs(ll u,ll p,ll d){
    Parr[u][0]=p;
    depth[u]=d;ll ans=0;
    for(auto v:graph[u]){
        if(v!=p){
            dfs(v,u,d+1);
            ans+=subtreeSiz[v];
    }}
    subtreeSiz[u]=ans+1;
}
 
void dfsHLD(ll u,ll p,ll top_node_of_chain){
    tim++;
    startTime[u]=tim;
    shuffledValues[tim]=values[u];
    chainNum[u]=top_node_of_chain;
    ll bigger_subtree=0,tem=0;
    for(auto v:graph[u]){
        if(v!=p){
            if(subtreeSiz[v]>tem){
                tem=subtreeSiz[v];
                bigger_subtree=v;
    }}}
    if(bigger_subtree)dfsHLD(bigger_subtree,u,top_node_of_chain); //same chain
    for(auto v:graph[u]){
        if(v!=p){
            if(v!=bigger_subtree){
                dfsHLD(v,u,v);    //new chain
}}}}
// segment tree iteratively
void update(ll index,ll value){
    index+=node;
    segTreeVal[index]=value;
    index/=2;
    while(index){
        segTreeVal[index]=max(segTreeVal
            [2*index],segTreeVal[2*index+1]);
        index/=2;
}}
 
ll query(ll index_1,ll index_2){
    ll ans=0;
    index_1+=node;
    index_2+=node+1;
    while(index_1<index_2){
        if(index_1 & 1){
            ans=max(ans,segTreeVal[index_1++]);}
        if(index_2 & 1){
            ans=max(ans,segTreeVal[--index_2]);}
        index_1/=2;
        index_2/=2;
    }
    return ans;
}
 
ll maxOfpathAtoB(ll a,ll b){
    ll ans=0;
    while(chainNum[a]!=chainNum[b]){
        if(depth[chainNum[a]]<depth[chainNum[b]]){
            swap(a,b);
        }
        ans=max(ans,query(startTime[chainNum[a]],startTime[a]));
        a=Parr[chainNum[a]][0];
    }
    if(depth[a]>depth[b])swap(a,b);
    ans=max(ans,query(startTime[a],startTime[b]));
    return ans;
}
 
void solve()
{
    cin>>node>>q;
    for(int i=1;i<=node;i++)cin>>values[i];
    for(int i=1;i<=node-1;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    dfs(1,0,0);
    tim=0;
    dfsHLD(1,0,1);// node,parent,chainNum
 
    for(int i=1;i<=node;i++)
    {
        update(i,shuffledValues[i]);
    }
    while(q--)
    {
        ll a,b,x;
        cin>>a;
        if(a==1)
        {
            cin>>a>>x;
            update(startTime[a],x);
        }
        else
        {
            cin>>a>>b;
            // a=1;
 
            cout<<maxOfpathAtoB(a,b)<<el;
        }
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