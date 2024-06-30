#include <bits/stdc++.h>
using namespace std;
const int M=1e9+7;
int main()
{
    int n,i,j,k=1;
    cin>>n;
    for(i=0;i<n;i++)
    {
        k=(k*2)%M;
    }
    cout<<k<<endl;
}