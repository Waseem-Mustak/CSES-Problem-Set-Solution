#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
typedef tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
typedef tree<long long,null_type,less_equal<long long>,rb_tree_tag,tree_order_statistics_node_update> multi_indexed_set;
 
 
const int N=3e5+2;
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
 
 
 
 
 
ll  ara[N],min_price[N],min_price_road[N],min_flight_in_min_price_road[N],max_flight_in_min_price_road[N];
vector<pair<ll,ll>>v[N];
//vector<ll>v(N),inv(N);
//ll arr[1001][1001];
 
 
int main()  
{
    fast;    
    ll i,j,k,l,m,n,o,p,q,r,t,a,b,c,d,x,y,z,ans,ans1;
    t=1;
    //cin>>t;
    r=1;
    while(t--)
    {
        cin>>n>>m;
        lp(i,1,m)
        {
            cin>>a>>b>>c;
            v[a].pb({b,c});
        }
 
        lp(i,2,n)min_price[i]=1e18;
 
        set<pair<ll,ll>>st;
        
        st.insert({0,1});
        min_price_road[1]=1;
        ll cost,father,child,new_cost;
 
        while(!st.empty())
        {
            auto a=*st.begin();
            st.erase(st.begin());
            cost=a.f;
            father=a.s;
            for(auto va:v[father])
            {
                child=va.f;
                new_cost=va.s;
                if(cost+new_cost==min_price[child])
                {
                    min_price_road[child]=(min_price_road[child]+min_price_road[father])%M;
                    min_flight_in_min_price_road[child]=min(min_flight_in_min_price_road[child],min_flight_in_min_price_road[father]+1);
                    max_flight_in_min_price_road[child]=max(max_flight_in_min_price_road[child],max_flight_in_min_price_road[father]+1);
                }
                if(cost+new_cost<min_price[child])
                {
                    min_price[child]=cost+new_cost;
                    min_price_road[child]=min_price_road[father];
                    min_flight_in_min_price_road[child]=min_flight_in_min_price_road[father]+1;
                    max_flight_in_min_price_road[child]=max_flight_in_min_price_road[father]+1;
                    st.insert({cost+new_cost,child});
                }
            }
        }
 
        cout<<min_price[n]<<" "<<min_price_road[n]<<" "<<min_flight_in_min_price_road[n]<<" "<<max_flight_in_min_price_road[n]<<el;
 
        r++;
    }
}