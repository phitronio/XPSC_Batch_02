#include <bits/stdc++.h>
using namespace std;
int a[20][20];
bool bame(int i)
{
    return (i == 1 || i == 3 || i == 6 || i == 7);
}
bool dane(int i)
{
    return (i == 1 || i == 3 || i == 4 || i == 5);
}
bool upore(int i)
{
    return (i == 1 || i == 2 || i == 4 || i == 7);
}
bool niche(int i)
{
    return (i == 1 || i == 2 || i == 5 || i == 6);
}
bool vis[20][20];
int n, m;
bool valid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}
int bfs(int si, int sj, int l)
{
    queue<pair<int, pair<int, int>>> q;
    q.push({si, {sj, 1}});
    vis[si][sj] = true;
    int ans = 0;
    while (!q.empty())
    {
        pair<int, pair<int, int>> p = q.front();
        q.pop();
        int ci = p.first;
        int cj = p.second.first;
        int cl = p.second.second;
        if (a[ci][cj] == 0 || cl > l)
            continue;

        ans++;
        if (bame(a[ci][cj]) && valid(ci, cj - 1) && dane(a[ci][cj - 1]) && !vis[ci][cj - 1])
        {
            q.push({ci, {cj - 1, cl + 1}});
            vis[ci][cj - 1] = true;
        }
        if (dane(a[ci][cj]) && valid(ci, cj + 1) && bame(a[ci][cj + 1]) && !vis[ci][cj + 1])
        {
            q.push({ci, {cj + 1, cl + 1}});
            vis[ci][cj + 1] = true;
        }
        if (upore(a[ci][cj]) && valid(ci - 1, cj) && niche(a[ci - 1][cj]) && !vis[ci - 1][cj])
        {
            q.push({ci - 1, {cj, cl + 1}});
            vis[ci - 1][cj] = true;
        }
        if (niche(a[ci][cj]) && valid(ci + 1, cj) && upore(a[ci + 1][cj]) && !vis[ci + 1][cj])
        {
            q.push({ci + 1, {cj, cl + 1}});
            vis[ci + 1][cj] = true;
        }
    }
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int si, sj, l;
        cin >> n >> m >> si >> sj >> l;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }
        memset(vis, false, sizeof(vis));
        cout << bfs(si, sj, l) << endl;
    }

    return 0;
}