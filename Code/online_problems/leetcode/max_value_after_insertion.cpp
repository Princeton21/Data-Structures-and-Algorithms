#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>

using namespace std;

string maxValue(string s, int x)
{
    int i = 0, n = s.size();
    string res = "";

    if (s[0] == '-')
    {
        int i = 1;
        while (i < n && s[i] - '0' <= x)
            i++;
        res += s.substr(0, i) + to_string(x) + s.substr(i);
        return res;
    }

    while (i < n && s[i] - '0' >= x)
        i++;

    res += s.substr(0, i) + to_string(x) + s.substr(i);

    return res;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;

    while (t--)
    {
        string s;
        int n;
        cin >> s;
        cin >> n;
        cout << maxValue(s, n) << endl;
    }
}