#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        int a[n];
        int mx = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            mx = max(mx, a[i]);
        }
        // sort(a, a + n);
        int l = mx, r = INT_MAX;
        int ans;
        while (l <= r)
        {
            int cap = l + (r - l) / 2;
            int cnt = 1;
            int s = 0;
            for (int i = 0; i < n; i++)
            {
                if (s + a[i] <= cap)
                {
                    s += a[i];
                }
                else
                {
                    cnt++;
                    s = a[i];
                }
            }
            // cout << cap << " " << cnt << endl;
            if (cnt <= m)
            {
                ans = cap;
                r = cap - 1;
            }
            else
            {
                l = cap + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}