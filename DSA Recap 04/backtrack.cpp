#include <bits/stdc++.h>
using namespace std;
bool vis[20];
void back(int n, vector<int> v)
{
    for (int x : v)
        cout << x << " ";
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            vis[i] = true;
            v.push_back(i);
            back(n, v); // waiting
            vis[i] = false;
            v.pop_back();
        }
    }
}
int main()
{
    int n;
    cin >> n;
    memset(vis, false, sizeof(vis));
    back(n, {});
    return 0;
}