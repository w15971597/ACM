#include <iostream>
#include <string>
using namespace std;

bool isomorphic(string s, string t)
{
    int m1[256] = {0},
        m2[256] = {0},
        n = s.size();
    for (int i = 0; i < n; ++i)
    {
        if (m1[s[i]] != m2[t[i]])
        {
            return false;
        }
        m1[s[i]] = i + 1;
        m2[t[i]] = i + 1;
    }
    // for (int i = 0; i < 256; ++i)
    // {
    //     cout << m1[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < 256; ++i)
    // {
    //     cout << m2[i] << " ";
    // }
    return true;
}

int main()
{
    string a = "eggf",
           b = "addc";
    cout << isomorphic(a, b) << endl;
    // isomorphic(a, b);
    return 0;
}
