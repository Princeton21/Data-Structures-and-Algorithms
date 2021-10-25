#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <chrono>
#include <random>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>

using namespace std;
#define int long long

// solution to div2 751 B in cpp

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<vector<int>> arr;
    arr.push_back(v);
    vector<int> v2 = v;
    while (1)
    {
        map<int, int> mp;
        for (auto i : v)
            mp[i]++;
        for (int i = 0; i < n; i++)
        {
            v2[i] = mp[v[i]];
        }
        // for (auto i : v2)
        // {
        //     cout << i << " ";
        // }
        // cout << endl;
        arr.push_back(v2);
        if (v == v2)
        {
            break;
        }
        v = v2;
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {

        int x, y;
        cin >> x >> y;
        int sz = arr.size() - 1;
        y = min(y, sz);
        cout << arr[y][x - 1] << " ";
    }
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}