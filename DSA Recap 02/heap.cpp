#include <bits/stdc++.h>
using namespace std;
class MaxHeap
{
public:
    vector<int> v;
    int top()
    {
        // O(1)
        return v[0];
    }
    bool empty()
    {
        // O(1)
        return v.size() == 0;
    }
    void heapify(int idx)
    {
        int leftParent = idx * 2;
        int rightParent = leftParent + 1;
        int sz = v.size();
        if (leftParent <= sz && rightParent <= sz)
        {
            if (v[leftParent - 1] >= v[idx - 1] && v[leftParent - 1] >= v[rightParent - 1])
            {
                swap(v[idx - 1], v[leftParent - 1]);
                heapify(leftParent);
            }
            else if (v[rightParent - 1] >= v[idx - 1] && v[rightParent - 1] >= v[leftParent - 1])
            {
                swap(v[idx - 1], v[rightParent - 1]);
                heapify(rightParent);
            }
            else
                return;
        }
        else if (leftParent <= sz)
        {
            if (v[leftParent - 1] >= v[idx - 1] && v[leftParent - 1] >= v[rightParent - 1])
            {
                swap(v[idx - 1], v[leftParent - 1]);
                heapify(leftParent);
            }
            else
                return;
        }
        else
        {
            return;
        }
    }
    void pop()
    {
        v[0] = v.back();
        v.pop_back();
        heapify(1); // O(logN)
    }
    void push(int val)
    {
        // O(logN)
        v.push_back(val);
        int idx = v.size();
        while (idx > 1)
        {
            int parIdx = idx / 2;
            if (v[parIdx - 1] < v[idx - 1])
            {
                swap(v[parIdx - 1], v[idx - 1]);
                idx = parIdx;
            }
            else
                break;
        }
    }
};
int main()
{
    MaxHeap pq;
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        pq.push(x);
    }
    for (int x : pq.v)
        cout << x << " ";
    cout << endl;
    pq.pop();
    for (int x : pq.v)
        cout << x << " ";
    cout << endl;

    return 0;
}