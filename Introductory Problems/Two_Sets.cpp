#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,n1,j,k,l;
    cin>>n;
    n1=n;
    if(n%4==0)
    {
        cout<<"YES"<<endl<<n/2<<endl;
        for(i=0;;i++)
        {
            if(n<=0)break;
            cout<<n<<" ";
            cout<<n-3<<" ";
            n=n-4;
        }
        cout<<endl;
        cout<<n1/2<<endl;
        for(i=0;;i++)
        {
            if(n1<=0)break;
            cout<<n1-1<<" ";
            cout<<n1-2<<" ";
            n1=n1-4;
        }
        cout<<endl;
    }
    else if((n-3)%4==0)
    {
        cout<<"YES"<<endl<<((n-1)/2)<<endl;
        for(i=0;;i++)
        {
            if(n<=0)break;
            cout<<n<<" ";
            if((n-3)!=0)cout<<n-3<<" ";
            n=n-4;
        }
        cout<<endl;
        cout<<((n1+2)/2)<<endl;
        for(i=0;;i++)
        {
            if(n1<=0)break;
            cout<<n1-1<<" "<<n1-2<<" ";
            n1=n1-4;
        }
        cout<<endl;
 
    }
    else cout<<"NO"<<endl;
}