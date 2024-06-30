#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n,i,k1,k2,k3,j,k,l;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        k=(i*i);
        k1=(k*(k-1))/2;   //value of nC2
 
 
        k2=(i-2)*(((i-4)*4)+(5*2));  
        k3=(((i-4)*2)+(2*2));
 
        cout<<k1-k2-k3<<endl;
 
    }
}