#include <iostream>
using namespace std;
int main()
{
    long long n,i; //if i use int it will give error
    cin>>n;
    for(i=0;;i++)
    {
        cout<<n<<" ";
        if(n==1)
        {
            break;
        }
        else
        {
            if(n%2==0) n=n/2;
            else n=(n*3)+1;
        }
    }
}
