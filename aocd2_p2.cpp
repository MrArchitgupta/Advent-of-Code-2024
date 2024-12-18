#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    string s;
    int sum = 0; 
    while (getline(cin, s)) {
        for (size_t i = 0; i < s.size(); ++i) {
            if (i + 4 <= s.size() && s.substr(i, 4) == "mul(") {
                i += 4; 
                string x, y;

                int f1=1;
                while (i < s.size()) {
                    char ch = s[i];
                    if (isdigit(ch)) {
                        if (f1) {
                            x += ch;
                        } else {
                            y += ch;
                        }
                    } else if (ch == ',') {
                        f1= 0;
                    } else if (ch == ')') {
                        break;  
                    } else {
                        x = y = "";
                        break;
                    }
                    ++i;
                }  
                 if (!x.empty() && !y.empty()) {
                    sum += stoll(x) * stoll(y);
                }
                
            }
        }
    }

    cout << sum << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
