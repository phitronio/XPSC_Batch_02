#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<vector<int>> subsets;
    for (int i = 0; i < (1 << n); i++)
    {

        vector<int> subset;
        for (int j = 0; j < n; j++)
        {
            if ((i & (1 << j)) != 0)
            {
                subset.push_back(a[j]);
            }
        }
        subsets.push_back(subset);
    }
    for (int i = 0; i < subsets.size(); i++)
    {
        for (auto val : subsets[i])
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}