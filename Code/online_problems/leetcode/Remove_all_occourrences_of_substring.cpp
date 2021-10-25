#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>

using namespace std;

string removeOccurrences(string s, string part)
{

    string res = "";
    int last = 0;
    while (1)
    {
        auto idx = s.find(part);

        if (idx == string::npos)
            break;
        int len = idx - last;
        s = s.substr(0, idx) + s.substr(idx + part.size());
    }

    return s;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;

    while (t--)
    {
        string s, p;
        cin >> s;
        cin >> p;
        cout << removeOccurrences(s, p) << endl;
    }
}