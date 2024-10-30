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
 
 
ll  ara[N],ara1[N],ara2[N],ara3[N],ara4[N],ara5[N];
 
 //vector<set<pair<ll,ll>>> v1( N);
vector<ll>v[N],v1[N];
ll tim=1;
void dfs(ll n)
{
    ara[n]=1;
    ara2[n]=tim;
    ara3[tim]=ara1[n];
    tim++;
    ll a=0;
    for(auto va:v[n])
    {
        if(ara[va]==0)
        {
            dfs(va);
            a+=ara4[va];
        }
    }
    ara4[n]=a+1;
 
}
 
 
ll seg_tree(ll n,ll a,ll b)
{
    ll mid=(a+b)/2;
    if(a==b)
    {
        return ara5[n]=ara3[a];
    }
    else return ara5[n]=(seg_tree(2*n,a,mid)+seg_tree((2*n)+1,mid+1,b));
}
void change_value(ll n,ll a,ll b,ll v,ll pos)
{
    ll mid=(a+b)/2;
    if(pos<a||pos>b)return;
    if(a==b)
    {
        ara5[n]-=v;
        return;
    }
    ara5[n]-=v;
    change_value(2*n,a,mid,v,pos);
    change_value(2*n+1,mid+1,b,v,pos);
}
ll print_sum(ll n,ll a,ll b,ll c,ll d)
{
    ll mid=(a+b)/2;
    if(d<a||c>b)return 0;
    if(a==b)return ara5[n];
    if(a>=c&&b<=d)return ara5[n];
    return print_sum(2*n,a,mid,c,d)+print_sum(2*n+1,mid+1,b,c,d);
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
        cin>>n>>q;
        lp(i,1,n)cin>>ara1[i];
        lp(i,2,n)
        {
            cin>>a>>b;
            v[a].pb(b);
            v[b].pb(a);
        }
        dfs(1);
        // pri(ara2,n);
        // pri(ara3,n);
        // pri(ara4,n);
        seg_tree(1,1,n);
        //pri(ara5,15);
        lp(i,1,q)
        {
            cin>>a;
            if(a==1)
            {
                cin>>a>>b;
                c=ara1[a];
                change_value(1,1,n,c-b,ara2[a]);
                ara1[a]=b;
            }
            else
            {
                cin>>a;
                c=ara2[a];
                d=c+ara4[a]-1;
                cout<<print_sum(1,1,n,c,d)<<el;
            }
        }
 
 
 
 
        // dfs(1,0,0);
        // lp(i,1,19)
        // {
        //     lp(j,1,n)
        //     {
        //         arr[j][i]=arr[arr[j][i-1]][i-1];
        //     }
        // }
        // lp(i,1,q)
        // {
        //     cin>>a>>b;
        //     ara3[a]++;
        //     ara3[b]++;
        //     if(ara1[a]>ara1[b])
        //     {
        //         a=kth_upper_element(a,ara1[a]-ara1[b]);
        //     }
        //     else
        //     {
        //         b=kth_upper_element(b,ara1[b]-ara1[a]);
        //     }
        //     x=ara1[a];
        //     y=0;
        //     while(x-y>1)
        //     {
        //         ll mid=(x+y)/2;
        //         p=x-mid;
        //         c=kth_upper_element(a,p);
        //         d=kth_upper_element(b,p);
        //         if(c==d)y=mid;
        //         else
        //         {
        //             a=c;
        //             b=d;
        //             x=mid;
        //         }
        //     }
            
        //     if(a==b)ans=a;
        //     else ans=kth_upper_element(a,x-y);
        //     ara3[ans]--;
        //     ara3[arr[ans][0]]--;
        // }
        // dfs1(1);
        // pri(ara3,n);   // just changed the long long to int and got AC
    }
}