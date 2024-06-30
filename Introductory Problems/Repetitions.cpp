#include <bits/stdc++.h>
using namespace std;
//const int N=1e6+5;
//char c[N];
int main()
{
    int i,j,k=0,l,m=0;
    string c;
    cin>>c;
    char c1;
    c1=c[0];
    l=c.length();
    for(i=0;i<l;i++)
    {
        if(c1==c[i])
        {
            k++;
        }
        else
        {
            if(k>m)
            {
                m=k;
            }
            k=1;
            c1=c[i];
        }
    }
    if(k>m)
    {
        m=k;
    }
    cout<<m;
}