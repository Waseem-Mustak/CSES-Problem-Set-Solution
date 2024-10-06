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
 
 
 
ll  ara[N],ara1[N],ara2[N],ara3[N],ara4[N],ara5[N],fac[N];
 
 //vector<set<pair<ll,ll>>> v1( N);
vector<ll>v[N];
ll arr[1002][1002],arr1[1002][1002];
char  arr2[1002][1002],arr3[1002][1002];
ll ai,aj,bi,bj;
void bfs(ll i,ll j,ll n,ll m)
{
    queue<pair<ll,ll>>q;
    q.push({i,j});
    arr[i][j]=1;
    while(!q.empty())
    {
        auto va=q.front();
        i=va.f;
        j=va.s;
        if((i+1<=n)&&(arr[i+1][j]==0))
        {
            q.push({i+1,j});
            arr[i+1][j]=1;
            arr1[i+1][j]=arr1[i][j]+1;
            arr2[i+1][j]='D';
 
        }
        if((i-1>=1)&&(arr[i-1][j]==0))
        {
            q.push({i-1,j});
            arr[i-1][j]=1;
            arr1[i-1][j]=arr1[i][j]+1;
            arr2[i-1][j]='U';
 
        }
        if((j+1<=m)&&(arr[i][j+1]==0))
        {
            q.push({i,j+1});
            arr[i][j+1]=1;
            arr1[i][j+1]=arr1[i][j]+1;
            arr2[i][j+1]='R';
 
        }
        if((j-1>=1)&&(arr[i][j-1]==0))
        {
            q.push({i,j-1});
            arr[i][j-1]=1;
            arr1[i][j-1]=arr1[i][j]+1;
            arr2[i][j-1]='L';
 
        }
        q.pop();
    }
}
 
int main()
{
    fast;
    ll i,j,k,l,m,n,o,p,q,e,r,ini,t,a,b,c,d,x,y,z,ans,ans1;
    // long long ans;
    t=1;
    //cin>>t;
    r=1;
 
    
    // pri(ara,10);
    while(t--)
    {
        cin>>n>>m;
        lp(i,1,n)
        {
            string s1;
            cin>>s1;
            lp(j,1,m)
            {
                if(s1[j-1]=='#')arr[i][j]=1;
                else if(s1[j-1]=='.')arr[i][j]=0;
                else
                {
                    if(s1[j-1]=='A')
                    {
                        ai=i;
                        aj=j;
                    }
                    else
                    {
                        bi=i;
                        bj=j;
                    }
                }
            }
        }
        // cout<<bi;
        bfs(ai,aj,n,m);
        // lp(i,1,n)
        // {
        //     lp(j,1,m)
        //     {
        //         cout<<arr1[i][j]<<" ";
 
        //     }cout<<el;
        // }
        if(arr1[bi][bj]==0)cout<<"NO"<<el;
        else
        {
            string s1;
            cout<<"YES"<<el;
            cout<<arr1[bi][bj]<<el;
            while(bi!=ai||bj!=aj)
            {
                s1.pb(arr2[bi][bj]);
                if(arr2[bi][bj]=='R')
                {
                    bj--;
                }
                else if(arr2[bi][bj]=='L')
                {
                    bj++;
                }
                else if(arr2[bi][bj]=='U')
                {
                    bi++;
                }
                else if(arr2[bi][bj]=='D')
                {
                    bi--;
                }
            }
            reverse(s1.begin(), s1.end());
            cout<<s1<<el;
        }
    }
}