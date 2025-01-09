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
#define pi 2*acos(0.0)
#define Mems(dp,n) memset(dp,n,sizeof(dp))
mt19937 rnd(time(0));
bool myComparison(const pair<pair<ll,ll>,ll> &a,const pair<pair<ll,ll>,ll> &b)  // for vector sorting  1st element small to learge (if same then second element large to small)
{
    if(a.f.f==b.f.f)return a.f.s>b.f.s;
    else return a.f.f<b.f.f;
}
bool cmp1(const pair<ll,ll> &a,const pair<ll,ll> &b)   // for vector sorting  1st element small to learge (if same then second element large to small)
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
 
 
//ll arr[1001][1001];
 
 
 
 
ll  ara[N],ara1[N],ara2[N],vis[N];
 
vector<ll>graph[N];
 
 
struct Node{
 
    Node *position[2];  // 0 means 0,1 means 1 .....
 
    bool containsKey(int bit)
    {
        return (position[bit]!=NULL);
    }
 
    Node * get(int bit)
    {
        return position[bit];
    }
 
    void put(int bit,Node * node)
    {
        position[bit]=node;
    }
};
 
class Trie{
 
private:
    Node *root;
public:
 
    Trie(){
        root= new Node();
    }
 
    ~Trie(){
        del(root);
    }
    void del(Node *node)
    {
        for(int i=0;i<2;i++)
        {
            if(node->containsKey(i))
            {
                del(node->get(i));
            }
        }
        delete(node);
    }
 
    void insert(int num){
        Node * node=root;
        for(int i=31;i>=0;i--)
        {
            int bit=((num>>i)&1);
            if(!node->containsKey(bit))
            {
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }
 
    long long getMaxXor(int num){
        Node * node=root;
        int maxNum=0;
        for(int i=31;i>=0;i--)
        {
            int bit=((num>>i)&1);
            if(node->containsKey(1-bit))
            {
                maxNum=(maxNum|(1<<i));
                node=node->get(1-bit);
            }
            else{
                node=node->get(bit);
            }
        }
        return maxNum;
    }
    int getMinXor(int num){
        Node * node=root;
        int minNum=0;
        for(int i=31;i>=0;i--)
        {
            int bit=((num>>i)&1);
            if(!node->containsKey(bit)) // ei bit na thake
            {
                minNum=(minNum|(1<<i));
                node=node->get(1-bit);
            }
            else{
                node=node->get(bit);
            }
        }
        return minNum;
    }
};
 
 
void solve()
{
     ll i,j,k,l,m,n,o,p,q,r,t,a,b,h,c,d,e,f,x,y,z,ans,ans1;
     cin>>n;
     lp(i,1,n)
     {
        cin>>ara[i];
     }
     Trie tri;
     tri.insert(0);
     lp(i,1,n)
     {
        ara1[i]=ara1[i-1]^ara[i];
        tri.insert(ara1[i]);
     }
     ans=0;
     lp(i,1,n)
     {
        ans=max(ans,tri.getMaxXor(ara1[i]));
     }
     cout<<ans<<el;
 
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