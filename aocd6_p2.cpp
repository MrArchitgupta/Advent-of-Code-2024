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
    int r1 = r;
    int c1 = c;
    vector<vector<int>> vis(m, vector<int>(n, 0));

    while (1)
    {
        if (r >= 0 && r < m && c >= 0 && c < n)
            vis[r][c] = 1;
        else
            break;
        
        if (o == 'n')
        {
            if (r > 0 && a[r - 1][c] == '#')
            {
                if (a[r][c + 1] == '.')
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

            if (c < n - 1 && a[r][c + 1] == '#')
            {
                if (a[r + 1][c] == '.')
                    r++;
                o = 's';
            }
            else if (c < n - 1)
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
            if (r < m - 1 && a[r + 1][c] == '#')
            {
                if (a[r][c - 1] == '.')
                    c--;
                o = 'w';
            }
            else if (r < m - 1)
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
                if (a[r - 1][c] == '.')
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
    int ans1 = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (vis[i][j])
                ans1++;
        }
    }
    cout << "part1 :" << ans1 << endl;

    // part 2
    int ans2 = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (vis[i][j])
            {
                if (a[i][j] == '#' || a[i][j] == '^')
                    continue;

                a[i][j] = '#';
                map<tuple<int, int, char>, int> m1;
                o = 'n';
                r = r1;
                c = c1;

                while (1)
                {

                    m1[{r, c, o}]++;
                    if (r < 0 || r > m - 1 && c < 0 && c > n - 1)
                        break;
                    if (o == 'n')
                    {
                        if (r > 0 && a[r - 1][c] == '#')
                        {
                            if (a[r][c + 1] == '.')
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

                        if (c < n - 1 && a[r][c + 1] == '#')
                        {
                            if (a[r + 1][c] == '.')
                                r++;
                            o = 's';
                        }
                        else if (c < n - 1)
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
                        if (r < m - 1 && a[r + 1][c] == '#')
                        {
                            if (a[r][c - 1] == '.')
                                c--;
                            o = 'w';
                        }
                        else if (r < m - 1)
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
                            if (a[r - 1][c] == '.')
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
                    if (m1.find({r, c, o}) != m1.end())
                    {
                        ans2++;
                        break;
                    }
                }
                a[i][j] = '.';
            }
        }
    }

    cout << "part2 :" << ans2 << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
