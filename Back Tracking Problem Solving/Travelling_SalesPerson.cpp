#include <bits/stdc++.h>
using namespace std;
int n;
int a[15][15];
bool vis[15];
int mn;
void back(int n, vector<int> &v)
{
    if (v.size() == n)
    {
        int sum = 0;
        int last = 0;
        for (int x : v)
        {
            sum += a[last][x];
            last = x;
        }
        sum += a[last][0];
        mn = min(mn, sum);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            vis[i] = true;
            v.push_back(i);
            back(n, v);
            vis[i] = false;
            v.pop_back();
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }
        memset(vis, false, sizeof(vis));
        mn = INT_MAX;
        vector<int> v;
        back(n - 1, v);
        cout << mn << endl;
    }
    return 0;
}