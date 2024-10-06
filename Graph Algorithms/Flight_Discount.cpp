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
 
 
ll lcm(ll a,ll b)
{
    return (a*b)/(__gcd(a,b));
}
ll gcd(ll a,ll b) 
{
    return __gcd(a,b);
}
 
 
 
ll  ara[N],ara1[N],ara2[N],vis_0[N],vis_1[N],Distance_0[N],Distance_1[N];
 
 //vector<set<pair<ll,ll>>> v1( N);
vector<pair<ll,ll>>v[N];

 
int main()
{
    fast;
    ll i,j,k,l,m,n,o,p,q,e,r,ini,t,a,R,b,c,d,x,y,z,ans,ans1;
    t=1;
    //cin>>t;
    r=1;
    
    while(t--)
    {
        cin>>n>>m;
        set<pair<pair<ll,ll>,ll>>st; // 0 means without halve,1 means with halve
 
        st.insert({{0,1},0});
        st.insert({{0,1},1});
 
        lp(i,1,m)
        {
            cin>>a>>b>>c;
            v[a].pb({b,c});
        }
 
        lp(i,2,n)
        {
            Distance_0[i]=1e18;
            Distance_1[i]=1e18;
        }
 
        while(!st.empty())
        {
            auto va=(*st.begin());
            st.erase(st.begin());
 
            a=va.f.f;
            b=va.f.s;
            c=va.s;
 
            if(c==0)      // offer of halving still exist
            {
                if(vis_0[b]==0)   // not visited
                {
                    vis_0[b]=1;
                    for(auto child:v[b])
                    {
                        x=child.f;
                        y=child.s;
 
                        if(a+y<Distance_0[x])
                        {
                            st.insert({{a+y,x},0});
                            Distance_0[x]=a+y;
                        }
                        else st.insert({{a+y,x},0});
 
                        if(a+(y/2)<Distance_1[x])
                        {
                            st.insert({{a+(y/2),x},1});
                            Distance_1[x]=a+(y/2);
                        }
                    }
                }
            }
            else
            {
                if(vis_1[b]==0)   // not visited
                {
                    vis_1[b]=1;
                    for(auto child:v[b])
                    {
                        x=child.f;
                        y=child.s;
 
                        if(a+y<Distance_1[x])
                        {
                            st.insert({{a+y,x},1});
                            Distance_1[x]=a+y;
                        }
                    }
                }
            }
        }
 
        cout<<min(Distance_1[n],Distance_0[n])<<el;
    }
}