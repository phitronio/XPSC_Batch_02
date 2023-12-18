#include <bits/stdc++.h>
using namespace std;
int n, m;
void toggle(vector<vector<int>> &v, int c)
{
    for (int i = 1; i <= n; i++)
    {
        v[i][c] = !v[i][c];
    }
}
int finalAns;
void fun(int c, int k, vector<vector<int>> &v)
{

    if (c == m + 1)
    {
        if (k == 0)
        {
            // calculate
            int ans = 0;
            for (int i = 1; i <= n; i++)
            {
                int cnt = 0;
                for (int j = 1; j <= m; j++)
                {
                    if (v[i][j] == 1)
                        cnt++;
                }
                if (cnt == m)
                {
                    ans++;
                }
            }
            finalAns = max(finalAns, ans);
        }
        return;
    }
    // choice 1 - toggle
    if (k > 0)
    {
        vector<vector<int>> cpy = v;
        toggle(cpy, c);
        fun(c, k - 1, cpy);
    }
    // choice 2 - toggle korbo na
    fun(c + 1, k, v);
}
int main()
{
    int k;
    cin >> n >> m >> k;
    vector<vector<int>> v(20, vector<int>(20));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> v[i][j];
        }
    }
    finalAns = INT_MIN;
    fun(1, k, v);
    cout << finalAns << endl;
    return 0;
}