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
const int mod=1e9+7;
int hashing(string s,int base)
{
    int val=1;
    int ans=0;
    for(char c:s)
    {
        int ascii = c-'a'+1;
        ans+=((ascii%mod)*(val%mod))%mod;
        ans=ans%mod;
        // mod formula
        // (a*b)%mod = ((a%mod) * (b%mod))%mod;
        val=((val%mod)*(base%mod))%mod;
    }
    return ans;
}
int main()
{
    fast;
    int n; cin>>n;
    // hashing("hello",3);
    set<pair<int,int>> st;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        st.insert({hashing(s,2),hashing(s,3)});
    }
    int q; cin>>q;
    while(q--)
    {
        string s; cin>>s;
        if(st.count({hashing(s,2),hashing(s,3)})>0) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}