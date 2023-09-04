#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    int dif = a ^ b;
    int cnt = 0;
    while (dif)
    {
        if (dif & 1)
            cnt++;
        dif = dif >> 1;
    }
    cout << cnt << endl;
    return 0;
}