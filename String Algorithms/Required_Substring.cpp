#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
typedef tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
typedef tree<long long,null_type,less_equal<long long>,rb_tree_tag,tree_order_statistics_node_update> multi_indexed_set;
 
 
const int N=2e3+4;
const long long M=1e9+7;
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
#define pi 2*acos(0.0)
#define Mems(dp,n) memset(dp,n,sizeof(dp))
mt19937_64 rnd(time(0));

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
 
 













ll len[N][N],dp[N][N];

ll power(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1){
            ans=(ans*a)%M;
        }
        a=(a*a)%M;
        b/=2;
    }
    return ans;
}

void solve()
{
    ll i,j,k,l,m,n,o,p,q,r,t,a,b,h,c,d,e,f,x,y,z,ans,ans1;
    cin>>n;
    string s;
    cin>>s;
    m=s.size();
    lp(i,0,m-1){
        lp(j,0,25){
            string pre=s.substr(0,i);
            pre+=j+'A';
            lp(k,0,pre.size()-1){
                if(pre.substr(k)==s.substr(0,pre.size()-k)){
                    len[i][j]=pre.size()-k;
                    break;
                }
            }
        }
    }
    dp[0][0]=1;
    lp(i,1,n){
        lp(j,0,m-1){
            lp(k,0,25){
                dp[i][len[j][k]]+=dp[i-1][j];
                dp[i][len[j][k]]%=M;
            }
        }
    }


    ans=power(26,n);
    lp(i,0,m-1){
        ans=(ans-dp[n][i])%M;
    }
    ans+=M;
    ans%=M;
    cout<<ans<<endl;

}

int main()
{
    fast;
    ll t=1;
    // cin>>t;
    test_case=1;
    // calcFact();
    while(t--)
    {
        solve();
        test_case++;
    }
} 