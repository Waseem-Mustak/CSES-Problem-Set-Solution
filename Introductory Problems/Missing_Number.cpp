#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,k,l;
    cin>>n;
    int arr[n-1];
    for(i=0;i<(n-1);i++)
    {
        cin>>arr[i];
    }
    int arr1[n];
    for(i=0;i<n;i++)
    {
       arr1[i]=0;
    }
    for(i=0;i<n-1;i++)
    {
        arr1[arr[i]-1]=arr[i];
    }
    for(i=0;i<n;i++)
    {
        if(arr1[i]==0)
        {
            cout<<i+1<<"\n";
        }
    }
 
}