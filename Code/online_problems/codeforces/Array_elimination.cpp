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

#define int long long
using namespace std;

// solution to div2 751 C in cpp

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);

    for (auto &i : v)
        cin >> i;

    vector<int> bits(32, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 31; j++)
            if ((v[i] & (1 << j)))
                bits[j]++;
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        int ok = 0;
        for (int j = 0; j < 30; j++)
        {
            if (bits[j] % i)
                ok = 1;
        }
        if (!ok)
            ans.push_back(i);
    }
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}