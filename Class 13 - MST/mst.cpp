// link - https://cses.fi/problemset/task/1675/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e5 + 5;
ll par[N];
ll parentLevel[N];
void dsu_set(ll n)
{
    for (ll i = 0; i <= n; i++)
    {
        par[i] = -1;
        parentLevel[i] = 0;
    }
}
ll dsu_find(ll n)
{
    if (par[n] == -1)
        return n;
    ll leader = dsu_find(par[n]);
    par[n] = leader;
    return leader;
}
void dsu_union_by_rank(ll a, ll b)
{
    ll leaderA = dsu_find(a);
    ll leaderB = dsu_find(b);
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
class Edge
{
public:
    ll u, v, w;
    Edge(ll u, ll v, ll w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

int main()
{
    ll n, e;
    cin >> n >> e;
    dsu_set(n);
    vector<Edge> edgeList;
    while (e--)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        Edge ed(u, v, w);
        edgeList.push_back(ed);
    }
    sort(edgeList.begin(), edgeList.end(), cmp);
    ll ans = 0;
    ll cnt = 0;
    for (Edge ed : edgeList)
    {
        ll u = ed.u;
        ll v = ed.v;
        ll w = ed.w;
        ll leaderU = dsu_find(u);
        ll leaderV = dsu_find(v);
        if (leaderU != leaderV)
        {
            dsu_union_by_rank(u, v);
            cnt++;
            ans += w;
        }
    }
    if (cnt == n - 1)
        cout << ans << endl;
    else
        cout << "IMPOSSIBLE" << endl;
    return 0;
}