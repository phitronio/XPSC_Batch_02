#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int k; cin>>k;
    int mx=INT_MIN;
    // n=1000
    // k = 1
    for(int i=0;i<=n-k;i++)
    {
        int s=0;
        for(int j=i;j<i+k;j++)
        {
            s+=a[j];
        }
        mx=max(mx,s);

    }
    cout<<mx<<endl;
    return 0;
}