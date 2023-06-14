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
ll mod = 1e9 + 7;
bool isVowel(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;
    return false;
}
void solve()
{
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    ll cnt = 0;
    for (char c : s)
    {
        if (isVowel(c))
            cnt++;
    }
    if (cnt % k != 0)
    {
        cout << 0 << endl;
        return;
    }
    ll newCnt = 0;
    ll afterCnt = 0;
    ll ans = 1;
    for (ll i = 0; i < n; i++)
    {
        if (isVowel(s[i]))
        {
            if (newCnt == k)
                newCnt = 0;
            newCnt++;
            if (afterCnt)
                ans = ((ans % mod) * (afterCnt % mod)) % mod;
            afterCnt = 0;
        }
        if (newCnt == k)
        {
            afterCnt++;
        }
    }
    cout << ans << endl;
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
