#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long  i,j,k,l,n;
    cin>>n;
    long long array[n];
    for(i=0;i<n;i++)
    {
        cin>>array[i];
    }
    k=0;
    l=array[0];
    for(i=0;i<n;i++)
    {
        if(array[i]<l)
        {
            k=k+(l-array[i]);
        }
        else
        {
            l=array[i];
        }
//cout<<k<<"\n";
    }
    cout<<k<<"\n";
}