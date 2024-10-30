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
 
 
//ll arr[1001][1001];
 
 
 
 
ll  ara[N],ara1[N],ara2[N],ara3[N];
 
vector<ll>v[N];
 
 
struct sort_all_cyclic_shift_of_a_string   //https://cp-algorithms.com/string/suffix-array.html
{
    string str;
    int size;
    vector<int> powerOfTwo;
    vector<int> P,C;   // p[i] means string started from P[i]th(o index) position is the ith lexografically longest substring
                             // C[i] means string started from ith position is the C[i]th lexographically logest string of all distrinc substring
                             // example
                             // for string aaba
                             // for substring of len 1
                             // P={0,1,3,2}
                             // C={0,0,1,0}
                             // we will do some operation for len log(n)+1 time
                             // finally we will find P[i],C[i] for all 0<=i<n of substring len>=n
    sort_all_cyclic_shift_of_a_string(string s)
    {
        str=s;
        size=s.size();
        P.resize(size);
        C.resize(size);
        build();
    }
 
    void build()
    {
        int tem_num=1;   // precompute  // can be done outside of struct
        for(int i=0;i<31;i++)
        {
            powerOfTwo.push_back(tem_num);
            tem_num*=2;
        }
 
        // constructing P[i]
        vector<int>tem_vec[258];
        for(int i=0;i<size;i++)
        {
            tem_vec[str[i]].push_back(i);
        }
        int pos=0;
        for(int i=0;i<258;i++)
        {
            for(auto val:tem_vec[i])
            {
                P[pos]=val;
                pos++;
            }
        }
        // P done for 1 len substring
 
 
        // now find C from vector P
        C[P[0]]=0;
        int classes=0;
        char cur,prev;
        pair<int,int> curp,prevp;
        for (int i=1;i<size;i++)
        {
            cur=str[P[i]];   // first time directly comparing char of str
            prev=str[P[i-1]];
            if(cur!=prev)
            {
                classes++;
            }
            C[P[i]]=classes;
        }
        // C done for 1 len substring
        
        vector<int>temP(size),temC(size),cnt(size);
        for(int i=0;powerOfTwo[i]<size;i++)
        {
            for(int j=0;j<size;j++)
            {
                cnt[j]=0;  // 
                temP[j]=P[j]-powerOfTwo[i];     // redix sort// making it sorted based part 2nd part of substring
                if(temP[j]<0)temP[j]+=size;
 
            }
 
            for(int j=0;j<size;j++)
            {
                cnt[C[temP[j]]]++;  
            }
                
            for(int j=1;j<=classes;j++)
            {
                cnt[j]+=cnt[j-1];
            }
                
            for(int j=size-1;j>=0;j--)
            {
                P[cnt[C[temP[j]]]-1]=temP[j];
                cnt[C[temP[j]]]--;
            }
           // P done for len 2^i string
                
            temC[P[0]]=0;
            classes=0;
            for(int j=1;j<size;j++)
            {
                curp={C[P[j]],C[(P[j]+powerOfTwo[i])%size]};
                prevp={C[P[j-1]],C[(P[j-1]+powerOfTwo[i])%size]};
                if(curp!=prevp)
                {
                    classes++;
                }
                temC[P[j]]=classes;
            }
            C=temC;
        }
    }
 
    vector<int> getP(){return P;}
    vector<int> getC(){return C;}
};
 
struct suffixArray
{
    vector<int> SA;
    string s;
    int n;
    suffixArray(string st)
    {
        s=st;
        n=st.size();
        st+="#";
        sort_all_cyclic_shift_of_a_string min_cyclick_shift(st);
        vector<int>tem=min_cyclick_shift.getP();
        for(int i=1;i<=n;i++)
        {
            SA.push_back(tem[i]);
        }
    }
 
    vector<int> getSuffixArray()
    {
        return SA;
    }
 
 
 
    bool isSubstringPresentOrNot(string ss)
    {
        int m=ss.size();
        int a=0;
        int b=n-1;
 
 
        while(b-a>1)
        {
            int mid=(a+b)/2;
            // string tem;
            int x=0;
            bool flag=true;
            for(int i=SA[mid];i<n;i++)
            {
                if(x<m)
                {
                    if(s[i]<ss[x])
                    {
                        a=mid;
                        flag=false;
                        break;
                    }
                    else if(s[i]>ss[x])
                    {
                        b=mid;
                        flag=false;
                        break;
                    }
                    // tem.push_back(s[i]);
                    x++;
                }
                else break;
            }
            if(flag)
            {
                if(x<m)a=mid;
                else b=mid;
            }
            // cout<<tem<<el;
            // if(tem<ss)
            // {
            //     a=mid;
            // }
            // else b=mid;
        }
        // string tem;
        int x=0;
        bool flag=true;
        for(int i=SA[a];i<n;i++)
        {
            if(x<m)
            {
                if(s[i]!=ss[x])flag=false;
                // tem.push_back(s[i]);
                x++;
            }
            else break;
        }
        if(x<m)flag=false;
        if(flag)return true;
 
        // tem.clear();
        x=0;
        flag=true;
        for(int i=SA[b];i<n;i++)
        {
            if(x<m)
            {
                if(s[i]!=ss[x])flag=false;
                // tem.push_back(s[i]);
                x++;
            }
            else break;
        }
        if(x<m)flag=false;
        if(flag)return true;
        //if(tem==ss)return true;
 
        return false;
 
    }
 
    int leftmostPosition(string ss)
    {
        int m=ss.size();
        int a=0;
        int b=n-1;
 
        
        while(b-a>1)
        {
            int mid=(a+b)/2;
            int x=0;
            bool flag=true;
            for(int i=SA[mid];i<n;i++)
            {
                if(x<m)
                {
                    if(s[i]<ss[x])
                    {
                        a=mid;
                        flag=false;
                        break;
                    }
                    else if(s[i]>ss[x])
                    {
                        b=mid;
                        flag=false;
                        break;
                    }
                    x++;
                }
                else break;
            }
            if(flag)
            {
                if(x<m)a=mid;
                else b=mid;
            }
        }
        int x=0;
        bool flag=true;
        for(int i=SA[a];i<n;i++)
        {
            if(x<m)
            {
                if(s[i]!=ss[x])flag=false;
                x++;
            }
            else break;
        }
        if(x<m)flag=false;
        if(flag)return a;
 
        x=0;
        flag=true;
        for(int i=SA[b];i<n;i++)
        {
            if(x<m)
            {
                if(s[i]!=ss[x])flag=false;
                x++;
            }
            else break;
        }
        if(x<m)flag=false;
        if(flag)return b;
        return -1;
    }
 
 
    int rightmostPosition(string ss)
    {
        int m=ss.size();
        int a=leftmostPosition(ss);
        if(a==-1)return a;
        int b=n-1;
 
        while(b-a>1)
        {
            int mid=(a+b)/2;
            int x=0;
            bool flag=true;
            for(int i=SA[mid];i<n;i++)
            {
                if(x<m)
                {
                    if(s[i]<ss[x])
                    {
                        a=mid;
                        flag=false;
                        break;
                    }
                    else if(s[i]>ss[x])
                    {
                        b=mid;
                        flag=false;
                        break;
                    }
                    // tem.push_back(s[i]);
                    x++;
                }
                else break;
            }
            if(flag)
            {
                if(x<m)b=mid;
                else a=mid;
            }
            // cout<<tem<<el;
            // if(tem<ss)
            // {
            //     a=mid;
            // }
            // else b=mid;
        }
        // string tem;
        int x=0;
        bool flag=true;
        for(int i=SA[b];i<n;i++)
        {
            if(x<m)
            {
                if(s[i]!=ss[x])flag=false;
                // tem.push_back(s[i]);
                x++;
            }
            else break;
        }
        if(x<m)flag=false;
        if(flag)return b;
 
        // tem.clear();
        x=0;
        flag=true;
        for(int i=SA[a];i<n;i++)
        {
            if(x<m)
            {
                if(s[i]!=ss[x])flag=false;
                // tem.push_back(s[i]);
                x++;
            }
            else break;
        }
        if(x<m)flag=false;
        if(flag)return a;
        //if(tem==ss)return true;
 
        return -1;
 
    }
};
 
void solve()
{
    ll i,j,k,l,m,n,o,p,q,r,t,a,b,h,c,d,e,f,x,y,z,ans,ans1;
    string s1,s2;
    cin>>s1;
    suffixArray sa(s1);
    vector<int>tem=sa.getSuffixArray();
 
    cin>>q;
    while(q--)
    {
        cin>>s2;
        if(sa.rightmostPosition(s2)!=-1)
        {
            cout<<"YES"<<el;
        }
        else cout<<"NO"<<el;
 
        // cout<<sa.leftmostPosition(s2)<<el;
 
    }
    // priv(sa.getSuffixArray());
 
    // s1+="#";
    // sort_all_cyclic_shift_of_a_string min_cyclick_shift(s1);
    // priv(min_cyclick_shift.getP());
    // // priv(min_cyclick_shift.getC());
    // int pos=min_cyclick_shift.getP()[0];
    // for(int i=pos;i<s1.size();i++)cout<<s1[i];
    // for(int i=0;i<pos;i++)cout<<s1[i];
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