#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int k; cin>>k;

    int i=0,j=0,mx=INT_MIN,sum=0;
    while(j<n)
    {
        sum+=a[j];
        if(j<k-1)
        {
            j++;
        }
        else 
        {
            mx=max(mx,sum);
            sum-=a[i];
            i++;
            j++;
        }
    }
    cout<<mx<<endl;
    return 0;
}