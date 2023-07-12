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
    string s;
    cin >> s;
    if (n % 3 == 1)
    {
        yes;
        return;
    }

    for (char c = 'a'; c <= 'z'; c++)
    {
        int l = INT_MAX, r = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == c)
            {
                if (i % 3 == 0)
                {
                    l = min(l, i);
                }
                if ((n - 1 - i) % 3 == 0)
                {
                    r = max(r, i);
                }
            }
        }
        if (l < r)
        {
            // cout << c << endl;
            yes;
            return;
        }
    }
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
