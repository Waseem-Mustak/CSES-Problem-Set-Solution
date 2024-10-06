#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
typedef tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
typedef tree<long long,null_type,less_equal<long long>,rb_tree_tag,tree_order_statistics_node_update> multi_indexed_set;
 
 
const int N=1e5+2;
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
 
 
ll  ara[N],ara1[N],ara2[N],ara3[N],ara4[N],ara5[N],vis[N];
 
//vector<set<pair<ll,ll>>> v1(N);
vector<pair<ll,ll>>v[N];
ll Distance[N][12];
 
int main()
{
    fast;
    ll i,j,k,l,m,n,o,p,q,e,r,ini,t,a,b,c,d,x,y,z,ans,ans1;
    t=1;
    //cin>>t;
    r=1;
    while(t--)
    {
        cin>>n>>m>>k;
        lp(i,1,m)
        {
            cin>>a>>b>>c;
            v[a].pb({b,c});
        }
 
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>q;
        lp(i,0,n)
        {
            lp(j,0,k)Distance[i][j]=1e18;
        }
 
 
        Distance[1][0]=0;
        q.push({0,1});
        while(!q.empty())
        {
            auto father=q.top();
            q.pop();
            if(vis[father.s]<k)
            {
                vis[father.s]++;
 
 
            //if(father.f>Distance[father.s][k-1])continue;   //if i use this,then no need to check vistited or not,,here vis[n]<k because a node an be visit at most k times here
                for(auto child:v[father.s])
                {
                    if(father.f+child.s<Distance[child.f][k-1])
                    {
                        Distance[child.f][k-1]=father.f+child.s;
                        q.push({father.f+child.s,child.f});
                        sort(Distance[child.f],Distance[child.f]+k);
                    }
                }
            }
        }
 
 
        lp(i,0,k-1)cout<<Distance[n][i]<<" ";
        r++;
    }
}