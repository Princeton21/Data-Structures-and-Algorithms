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
// solution to div2 751 A part
void solve()
{
    string s;
    cin >> s;
    char c = 'z';
    for (auto ch : s)
    {
        c = min(c, ch);
    }

    int idx = s.find(c);
    string p = "";
    p += c;
    string r = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (i != idx)
        {
            r += s[i];
        }
    }
    cout << p << " " << r << endl;
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