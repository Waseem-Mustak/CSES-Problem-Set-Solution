#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n,i,j,y,x,k;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>y>>x;
        if(y>x)
        {
            if(y%2!=0)
            {
                cout<<(((y*y)-(y-1))-(y-x))<<endl;
            }
            else
            {
                cout<<(((y*y)-(y-1))+(y-x))<<endl;
            }
        }
        else if(x>y)
        {
            if(x%2!=0)
            {
                cout<<(((x*x)-(x-1))+(x-y))<<endl;
            }
            else
            {
                cout<<(((x*x)-(x-1))-(x-y))<<endl;
            }
        }
        else cout<<((x*x)-(x-1))<<endl;
    }
}