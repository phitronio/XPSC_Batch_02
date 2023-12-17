#include <bits/stdc++.h>
using namespace std;
int n;
int si, sj;
int di, dj;
vector<pair<int, int>> a(15);
bool vis[15];
int mn;
void back(int n, vector<int> &v)
{
    if (v.size() == n)
    {
        int sum = 0;
        int lasti = si;
        int lastj = sj;
        for (int x : v)
        {
            // |x1-x2| + |y1-y2|
            int tmp = abs(lasti - a[x].first) + abs(lastj - a[x].second);
            sum += tmp;
            lasti = a[x].first;
            lastj = a[x].second;
        }
        sum += abs(lasti - di) + abs(lastj - dj);
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
int cs = 1;
int main()
{
    int t = 10;
    while (t--)
    {
        cin >> n;
        cin >> si >> sj;
        cin >> di >> dj;
        for (int i = 1; i <= n; i++)
            cin >> a[i].first >> a[i].second;
        memset(vis, false, sizeof(vis));
        vector<int> v;
        mn = INT_MAX;
        back(n, v);
        cout << "# " << cs++ << " " << mn << endl;
    }
    return 0;
}