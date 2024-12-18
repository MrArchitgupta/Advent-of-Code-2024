#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    string s;
    vector<string> a;
    int r, c;
    int j = 0;
    while (getline(cin, s))
    {

        a.push_back(s);
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '^')
            {
                c = i;
                r = j;
            }
        }
        j++;
    }
    char o = 'n';
    int m = a.size();
    int n = a[0].size();
    // cout<<m<<n<<endl;
    while (1)
    {
        a[r][c] = 'X';
        //  cout<<o<<endl;
        if (o == 'n')
        {
            if (r > 0 && a[r - 1][c] == '#')
            {
                c++;
                o = 'e';
            }
            else if (r > 0)
            {
                r--;
            }
            else
            {
                break;
            }
        }
        else if (o == 'e')
        {

            if (c < m - 1 && a[r][c + 1] == '#')
            {
                r++;
                o = 's';
            }
            else if (c < m - 1)
            {
                c++;
            }
            else
            {
                break;
            }
        }
        else if (o == 's')
        {
            if (r < n - 1 && a[r + 1][c] == '#')
            {
                c--;
                o = 'w';
            }
            else if (r < n - 1)
            {
                r++;
            }
            else
            {
                break;
            }
        }
        else if (o == 'w')
        {
            if (c > 0 && a[r][c - 1] == '#')
            {
                r--;
                o = 'n';
            }
            else if (c > 0)
            {
                c--;
            }
            else
            {
                break;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 'X')
                cnt++;
            cout << a[i][j];
        }
        cout << endl;
    }
    cout << cnt << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
