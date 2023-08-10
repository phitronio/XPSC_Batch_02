#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int q;
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        auto it1 = lower_bound(a.begin(), a.end(), x);
        auto it2 = upper_bound(a.begin(), a.end(), x);
        int idx1 = it1 - a.begin();
        int idx2 = it2 - a.begin();
        if (idx1 == 0)
            cout << "X ";
        else
            cout << a[idx1 - 1] << " ";

        if (idx2 == n)
            cout << "X" << endl;
        else
            cout << a[idx2] << endl;
    }
    return 0;
}