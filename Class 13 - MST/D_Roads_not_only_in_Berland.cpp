// link - https://codeforces.com/contest/25/problem/D
#include <bits/stdc++.h>
#define pi pair<int, int>
using namespace std;
const int N = 1e5 + 5;
int par[N];
int parentLevel[N];
void dsu_set(int n)
{
    for (int i = 0; i <= n; i++)
    {
        par[i] = -1;
        parentLevel[i] = 0;
    }
}
int dsu_find(int n)
{
    if (par[n] == -1)
        return n;
    int leader = dsu_find(par[n]);
    par[n] = leader;
    return leader;
}
void dsu_union_by_rank(int a, int b)
{
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if (leaderA != leaderB)
    {
        if (parentLevel[leaderA] > parentLevel[leaderB])
        {
            par[leaderB] = leaderA;
        }
        else if (parentLevel[leaderB] > parentLevel[leaderA])
        {
            par[leaderA] = leaderB;
        }
        else
        {
            par[leaderB] = leaderA;
            parentLevel[leaderA]++;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    dsu_set(n);
    int e = n - 1;
    vector<pi> bad;
    while (e--)
    {
        int u, v;
        cin >> u >> v;
        int leaderU = dsu_find(u);
        int leaderV = dsu_find(v);
        if (leaderU == leaderV)
        {
            bad.push_back({u, v});
        }
        else
        {
            dsu_union_by_rank(u, v);
        }
    }
    // for (pi p : bad)
    // {
    //     cout << p.first << " " << p.second << endl;
    // }
    vector<pi> add;
    for (int i = 2; i <= n; i++)
    {
        if (dsu_find(1) != dsu_find(i))
        {
            add.push_back({1, i});
            dsu_union_by_rank(1, i);
        }
    }
    cout << bad.size() << endl;
    for (int i = 0; i < bad.size(); i++)
    {
        cout << bad[i].first << " " << bad[i].second << " " << add[i].first << " " << add[i].second << endl;
    }
    return 0;
}