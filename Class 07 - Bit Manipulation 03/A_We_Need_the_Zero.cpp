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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int x = 0; x < (1 << 8); x++)
    {
        vector<int> v = a;
        for (int i = 0; i < n; i++)
        {
            v[i] = v[i] ^ x;
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = ans ^ v[i];
        }
        if (ans == 0)
        {
            cout << x << endl;
            return;
        }
    }
    cout << -1 << endl;
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
