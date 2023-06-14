/*
||-----------------------------------||
||        Rahat Khan Pathan          ||
||         Programming Hero          ||
||-----------------------------------||
*/
#include <bits/stdc++.h>
#define ll long long int
#define pub push_back
#define pob pop_back
#define PI 3.14159265359
#define vll vector<ll>
#define All(X) (X).begin(), (X).end()
#define Unique(X) (X).erase(unique(All(X)), (X).end())
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);
#define pi pair<ll, ll>
#define vpair vector<pair<ll, ll>>
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define cyes cout << "Yes" << endl
#define cno cout << "No" << endl
#define minus cout << -1 << endl
#define MAX 100000
using namespace std;
ll cs = 1;
void solve()
{
    ll n, b;
    cin >> n >> b;
    vll v;
    while (n--)
    {
        ll a;
        cin >> a;

        ll vl = a & b;
        if (vl == b)
        {
            v.pub(a);
        }
    }
    if (v.size() == 0)
    {
        no;
        return;
    }
    ll ans = v[0]; //
    for (int i = 1; i < v.size(); i++)
    {
        ans = ans & v[i];
    }
    if (ans == b)
        yes;
    else
        no;
}
int main()
{
    fast;
    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
