#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    int a[m + 1];
    int ans = 0;
    for (int i = 0; i <= m; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
    {
        if (__builtin_popcount(a[i] ^ a[m]) <= k)
            ans++;
    }
    cout << ans << endl;
    return 0;
}