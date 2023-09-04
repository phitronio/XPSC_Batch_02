#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int par[N];
int parentLevel[N];
int parentSize[N];
void dsu_set(int n)
{
    for (int i = 0; i <= n; i++)
    {
        par[i] = -1;
        parentLevel[i] = 0;
        parentSize[i] = 1;
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
void dsu_union_by_size(int a, int b)
{
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if (leaderA != leaderB)
    {
        if (parentSize[leaderA] > parentSize[leaderB])
        {
            par[leaderB] = leaderA;
            parentSize[leaderA] += parentSize[leaderB];
        }
        else
        {
            par[leaderA] = leaderB;
            parentSize[leaderB] += parentSize[leaderA];
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    dsu_set(n);
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        dsu_union_by_size(a, b);
    }
    cout << dsu_find(5) << endl;
    cout << parentSize[6] << endl;
    return 0;
}