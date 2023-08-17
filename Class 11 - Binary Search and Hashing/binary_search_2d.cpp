/*
||-----------------------------------||
||        Rahat Khan Pathan          ||
||         Programming Hero          ||
||-----------------------------------||
*/
#include<bits/stdc++.h>
#define ll long long int
#define pub push_back
#define pob pop_back
#define PI 3.14159265359
#define vll vector<ll>
#define All(X) (X).begin(),(X).end()
#define Unique(X) (X).erase(unique(All(X)),(X).end())
#define fast ios_base::sync_with_stdio(0); cin.tie(NULL);
#define pi pair<ll,ll>
#define vpair vector<pair<ll,ll> >
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define minus cout<<-1<<endl
using namespace std;
bool cmp(vector<int> a, vector<int> b)
{
    for(int i=0;i<26;i++)
    {
        if(a[i]==b[i]) continue;
        return a[i]<b[i];
    }
}
int main()
{
    fast;
    int n; cin>>n;
    vector<vector<int>> v(n,vector<int>(26,0));
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for(char c:s)
        {
            v[i][c-'a']++;
        }
    }
    sort(v.begin(),v.end(),cmp);
    
    int q; cin>>q;
    while(q--)
    {
        string s; cin>>s;
        int cnt[26]={0};
        for(char c:s)
        {
            cnt[c-'a']++;
        }
        int lo=0,hi=n-1;
        bool flag=true;
        for(int i=0;i<26;i++)
        {
            int amar_count = cnt[i]; //2
            int l=lo,r=hi;
            int ans=-1;
            while(l<=r)
            {
                int mid=(l+r)>>1;
                if(v[mid][i] == amar_count)
                {
                    ans=mid;
                    r=mid-1;
                }
                else if(v[mid][i] > amar_count)
                {
                    r=mid-1;
                }
                else 
                {
                    l=mid+1;
                }
            }
            // cout<<ans<<endl;
            if(ans==-1)
            {
                flag=false;
                break;

            }
            lo=ans;
            l=lo,r=hi;
            int ans2=-1;
            while(l<=r)
            {
                int mid=(l+r)>>1;
                if(v[mid][i] == amar_count)
                {
                    ans2=mid;
                    l=mid+1;
                }
                else if(v[mid][i] > amar_count)
                {
                    r=mid-1;
                }
                else 
                {
                    l=mid+1;
                }
            }
            // cout<<ans2<<endl;
            hi=ans2;
        }
        if(flag) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}