#include <bits/stdc++.h>
using namespace std;
class WarmHole
{
public:
    int si, sj, di, dj, c;
};
int n;
int si, sj, di, dj;
vector<WarmHole> a(10);
bool vis[15];
int mn;
void back(int n, vector<int> &v)
{
    int sum = 0;
    int lasti = si, lastj = sj;
    for (int x : v)
    {
        int tmp = abs(lasti - a[x].si) + abs(lastj - a[x].sj) + a[x].c;
        lasti = a[x].di;
        lastj = a[x].dj;
        sum += tmp;
    }
    sum += abs(lasti - di) + abs(lastj - dj);
    // ulta
    int sum2 = 0;
    int lasti2 = si, lastj2 = sj;
    for (int x : v)
    {
        int tmp = abs(lasti2 - a[x].di) + abs(lastj2 - a[x].dj) + a[x].c;
        lasti2 = a[x].si;
        lastj2 = a[x].sj;
        sum2 += tmp;
    }
    sum2 += abs(lasti2 - di) + abs(lastj2 - dj);
    if (min(sum, sum2) > mn)
    {
        return;
    }
    mn = min({mn, sum, sum2});

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
        cin >> si >> sj >> di >> dj;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i].si >> a[i].sj >> a[i].di >> a[i].dj >> a[i].c;
        }
        memset(vis, false, sizeof(vis));
        mn = INT_MAX;
        vector<int> v;
        back(n, v);
        cout << mn << endl;
    }
    return 0;
}