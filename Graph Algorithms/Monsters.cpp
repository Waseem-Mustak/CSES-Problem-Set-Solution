#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
typedef tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
typedef tree<long long,null_type,less_equal<long long>,rb_tree_tag,tree_order_statistics_node_update> multi_indexed_set;
 
 
const int N=1e6+5;
const int M=1e9+7;
long long NN=0,MM,S,K=0;
 
 
#define ll long long
#define lp(i,a,b) for(ll i=a;i<=b;i++)
#define rlp(i,a,b) for(ll i=a;i>=b;i--)
#define vi vector<int>
#define pb push_back
#define rpb pop_back
#define f first
#define s second
#define el "\n"
#define pri(ara,n) for(ll i=1;i<=n;i++)cout<<ara[i]<<" ";cout<<el;
 
 
 
 
 
 
 
ll  ara[N],ara1[N],ara2[N],ara3[N],ara4[N];//,ara3[N],ara4[N];
vector<ll>v[N];
//vector<ll>v(N),inv(N);
ll arr[1001][1001],arr1[1001][1001],arr2[1001][1001],arr3[1001][1001],arr5[1001][1001];
char arr4[1001][1001];
pair<ll,ll>p1,p2;
queue<pair<ll,ll>>q1,q2;
//ll K=0;
 
void bfs(ll n,ll m)
{
    while(!q1.empty())
    {
        auto va=q1.front();
        ll a=va.f,b=va.s;
        if(arr[a][b+1]!=1&&arr1[a][b+1]!=1&&arr2[a][b+1]==0&&(a>0)&&(b+1>0)&&(a<=n)&&(b+1<=m))
        {
            q1.push({a,b+1});
            arr1[a][b+1]=1;
            arr2[a][b+1]=arr2[a][b]+1;
        }
        if(arr[a+1][b]!=1&&arr1[a+1][b]!=1&&arr2[a+1][b]==0&&(a+1>0)&&(b>0)&&(a+1<=n)&&(b<=m))
        {
            q1.push({a+1,b});
            arr1[a+1][b]=1;
            arr2[a+1][b]=arr2[a][b]+1;
        }
        if(arr[a][b-1]!=1&&arr1[a][b-1]!=1&&arr2[a][b-1]==0&&(a>0)&&(b-1>0)&&(a<=n)&&(b-1<=m))
        {
            q1.push({a,b-1});
            arr1[a][b-1]=1;
            arr2[a][b-1]=arr2[a][b]+1;
        }
        if(arr[a-1][b]!=1&&arr1[a-1][b]!=1&&arr2[a-1][b]==0&&(a-1>0)&&(b>0)&&(a-1<=n)&&(b<=m))
        {
            q1.push({a-1,b});
            arr1[a-1][b]=1;
            arr2[a-1][b]=arr2[a][b]+1;
        }
        q1.pop();
    }
}
 
void bfs1(ll n,ll m)
{
    while(!q2.empty())
    {
        auto va=q2.front();
        ll a=va.f,b=va.s;
        if(a==1||b==1||a==n||b==m)
        {
            p2.f=a;
            p2.s=b;
            K=1;
            break;
        }
        if((a<=n)&&(b+1<=m)&&(a>0)&&(b+1>0))
        {
            if((arr3[a][b]+1<arr2[a][b+1])&&arr5[a][b+1]==0)
            {
 
                q2.push({a,b+1});
                arr5[a][b+1]=1;
                arr3[a][b+1]=arr3[a][b]+1;
                arr4[a][b+1]='R';
                if(a==1||b+1==1||a==n||b+1==m)
                {
                    p2.f=a;
                    p2.s=b+1;
                    K=1;
                    break;
                }
            }
        }
        if((a<=n)&&(b-1<=m)&&(a>0)&&(b-1>0))
        {
            if((arr3[a][b]+1<arr2[a][b-1])&&arr5[a][b-1]==0)
            {
 
                q2.push({a,b-1});
                arr5[a][b-1]=1;
                arr3[a][b-1]=arr3[a][b]+1;
                arr4[a][b-1]='L';
                if(a==1||b-1==1||a==n||b-1==m)
                {
                    p2.f=a;
                    p2.s=b-1;
                    K=1;
                    break;
                }
            }
        }
        if((a+1<=n)&&(b<=m)&&(a+1>0)&&(b>0))
        {
            if((arr3[a][b]+1<arr2[a+1][b])&&arr5[a+1][b]==0)
            {
 
                q2.push({a+1,b});
                arr5[a+1][b]=1;
                arr3[a+1][b]=arr3[a][b]+1;
                arr4[a+1][b]='D';
                if(a+1==1||b==1||a+1==n||b==m)
                {
                    p2.f=a+1;
                    p2.s=b;
                    K=1;
                    break;
                }
            }
        }
        if((a-1<=n)&&(b<=m)&&(a-1>0)&&(b>0))
        {
            if((arr3[a][b]+1<arr2[a-1][b])&&arr5[a-1][b]==0)
            {
 
                q2.push({a-1,b});
                arr5[a-1][b]=1;
                arr3[a-1][b]=arr3[a][b]+1;
                arr4[a-1][b]='U';
                if(a-1==1||b==1||a-1==n||b==m)
                {
                    p2.f=a-1;
                    p2.s=b;
                    K=1;
                    break;
                }
            }
        }
        q2.pop();
    }
}
int main()
{
    fast;
    ll i,j,k,l,m,n,o,p,q,r,s,t,a,b,c,d,x,y,ans,ans1;
    cin>>n>>m;
    arr[n+1][m+1];
    p2.f=-1;
    p2.s=-1;
    lp(i,1,n)
    {
        string s1;
        cin>>s1;
        lp(j,1,m)
        {
            if(s1[j-1]=='#')arr[i][j]=1;
            else if(s1[j-1]=='M')
            {
                q1.push({i,j});
                arr1[i][j]=1;
                arr[i][j]=2;
            }
            else if(s1[j-1]=='A')
            {
                q2.push({i,j});
                arr[i][j]=3;
                arr5[i][j]=1;
            }
            else if(s1[j-1]=='.')arr[i][j]=4;
        }
    }
    lp(i,1,n)
    {
        lp(j,1,m)arr4[i][j]='.';
    }
    bfs(n,m);
    // lp(i,1,n)
    // {
    //     lp(j,1,m)cout<<arr2[i][j]<<" ";
    //     cout<<el;
    // }
    // cout<<q2.front().s<<el;
    lp(i,1,n)
    {
        lp(j,1,m)
        {
            if(arr[i][j]==1||arr[i][j]==2)arr2[i][j]=0;
            else if(arr2[i][j]==0)arr2[i][j]=100000000000000000;
        }
    }
    bfs1(n,m);
    // lp(i,1,n)
    // {
    //     lp(j,1,m)cout<<arr4[i][j]<<" ";
    //     cout<<el;
    // }
    // cout<<p2.f<<" "<<p2.s<<el;
 
    if(K==0)cout<<"NO"<<el;
    else
    {
        cout<<"YES"<<el;
        vector<char>v3;
        while(arr4[p2.f][p2.s]!='.')
        {
            v3.pb(arr4[p2.f][p2.s]);
            if(arr4[p2.f][p2.s]=='R')
            {
                p2.s--;
            }
            else if(arr4[p2.f][p2.s]=='D')
            {
                p2.f--;
            }
            else if(arr4[p2.f][p2.s]=='L')
            {
                p2.s++;
            }
            else if(arr4[p2.f][p2.s]=='U')
            {
                p2.f++;
            }
        }
        cout<<v3.size()<<el;
        reverse(v3.begin(), v3.end());
        for(auto va:v3)cout<<va;
    }
 
}