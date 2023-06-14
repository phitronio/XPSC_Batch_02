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
    ll n;
    cin >> n;
    ll a[n], b[n];
    ll mxA = 0, mxB = 0, c1 = 0, c2 = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for (ll i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            mxA = max(mxA, c1);
            c1 = 0;
        }
        else
            c1++;
    }
    mxA = max(mxA, c1);
    for (ll i = 0; i < n; i++)
    {
        if (b[i] == 0)
        {
            mxB = max(mxB, c2);
            c2 = 0;
        }
        else
            c2++;
    }
    mxB = max(mxB, c2);
    if (mxA > mxB)
    {
        cout << "Om" << endl;
    }
    else if (mxB > mxA)
        cout << "Addy" << endl;
    else
        cout << "Draw" << endl;
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
