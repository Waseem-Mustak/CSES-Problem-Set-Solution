#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
typedef tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
typedef tree<long long,null_type,less_equal<long long>,rb_tree_tag,tree_order_statistics_node_update> multi_indexed_set;
 
 
const int N=2e6+2;
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
// #define el endl
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
 
bool myComparison(const pair<pair<ll,ll>,ll> &a,const pair<pair<ll,ll>,ll> &b)  // for vector sorting  1st element small to learge (if same then second element large to small)
{
    if(a.f.f==b.f.f)return a.f.s>b.f.s;
    else return a.f.f<b.f.f;
}
bool cmp1(const pair<ll,ll> &a,const pair<ll,ll> &b)    // for vector sorting  1st element small to learge (if same then second element large to small)
{
    // return a>b;
    if(a.f==b.f)return a.s>b.s;
    else return a.f<b.f;
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
 
 
 
 
ll  ara[N],ara1[N],ara2[N],dp[N];
vector<ll>v[N];
 
 
 
struct Node{
 
    Node *position[26];  // 0 means a,1 means b .....
    long long cntEndwith=0;
    long long cntPrefix=0;
 
    bool containsKey(char ch){return (position[ch-'a']!=NULL);}
    Node * get(char ch){return position[ch-'a'];}
 
    void put(char ch,Node * node){position[ch-'a']=node;}  
};
 
class Trie{
 
public:
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
        for(char ch='a';ch<='z';ch++)
        {
            if(node->containsKey(ch))
            {
                del(node->get(ch));
            }
        }
        delete(node);
    }
 
    void insert(string &word){
        Node * node=root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->containsKey(word[i]))
            {
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
            // node->increasePrefix();   
            node->cntPrefix++;
        }
        // node->increaseEnd();
        node->cntEndwith++;
    }
 
    long long countWordsEqualTo(string &word){
        Node * node=root;
 
        for(int i=0;i<word.size();i++)
        {
            if(!node->containsKey(word[i]))
            {
                return 0;
            }
            else
            {
                node=node->get(word[i]);
            }
        }
        return node->cntEndwith;
    }
 
    int countWordsStartingWith(string &word){
        Node * node=root;
 
        for(int i=0;i<word.size();i++)
        {
            if(!node->containsKey(word[i]))
            {
                return 0;
            }
            else
            {
                node=node->get(word[i]);
            }
        }
        return node->cntPrefix;
    }
 
    void erase(string &word){
        Node * node=root;
 
        for(int i=0;i<word.size();i++)
        {
            if(!node->containsKey(word[i]))
            {
                return;
            }
            else
            {
                node=node->get(word[i]);
                // node->decreasePrefix();
                node->cntPrefix--;
            }
        }
        // node->decreaseEnd();
        node->cntEndwith--;
    }
    long long modified_insert(string &word){
        long long ans=0;
        Node * node=root;
        for(int i=word.size()-1;i>=0;i--)
        {
            if(!node->containsKey(word[i]))
            {
                // node->put(word[i],new Node());
                return ans;
            }
            node=node->get(word[i]);
            if(node->cntEndwith >0 )
            {
                ans=(ans+dp[i])%M;
            }
            // node->increasePrefix();   
        }
        return ans;
        // node->increaseEnd();
    }
};
 
 
// dp[i] means ,how many ways can i create substring (1 to i) of input
// dp[0]=1
// dp[i]= sum of dp[j] j= 0 to i-1   if(substring j+1 to i exist in array)
 
 
 
void solve()
{
    ll i,j,k,l,m,n,o,p,q,r,t,a,b,h,c,d,e,f,x,y,z,ans,ans1,mid;
    Trie tri;
    string s1,s2,s3;
    cin>>s1;
    cin>>n;
    lp(i,1,n)
    {
        cin>>s2;
        reverse(s2.begin(), s2.end());
        tri.insert(s2);
    }
    n=s1.size();
    dp[0]=1;
    lp(i,1,n)
    {
        s3.pb(s1[i-1]);
        dp[i]=tri.modified_insert(s3);
    }
    cout<<dp[n]<<el;
}
 
 
int main()   //https://cses.fi/problemset/task/1731
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