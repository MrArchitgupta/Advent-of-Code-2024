#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define int long long
#define pb(x) push_back(x)
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
#define vii vector<pair<int, int>>
#define pii pair<int, int>
#define vc vector<char>
#define ss second
#define ff first

#define MOD 1000000007
#define INF 1e18

void solve() {
    vector<vector<int>> data; 
    string line;

    while (getline(cin, line)) {
        if(line.empty()) break;
       
        vector<int> currentSet;
        stringstream ss(line);
        int x, y;
        ss.ignore(12, '+'); 
        ss >> x;
        ss.ignore(5, '+'); 
        ss >> y;
        currentSet.push_back(x);
        currentSet.push_back(y);

        getline(cin, line);
        ss = stringstream(line);
        ss.ignore(12, '+'); 
        ss >> x;
        ss.ignore(5, '+');
        ss >> y;
        currentSet.push_back(x);
        currentSet.push_back(y);

        getline(cin, line);
        ss = stringstream(line);
        ss.ignore(8, '=');
        ss >> x;
        ss.ignore(5, '=');
        ss >> y;
        currentSet.push_back(x);
        currentSet.push_back(y);
        getline(cin, line);
        data.push_back(currentSet);
    }
    
    int ans = 0;
    for (int k = 0; k < data.size(); k++) {
        int numerator_i = (data[k][5] * data[k][2] - data[k][4] * data[k][3]);
        int denominator_i = (-data[k][0] * data[k][3] + data[k][1] * data[k][2]);
    
        int numerator_j = (data[k][4] * data[k][1] - data[k][5] * data[k][0]);
        int denominator_j = (-data[k][0] * data[k][3] + data[k][1] * data[k][2]);
        if (numerator_i % denominator_i == 0 && numerator_j % denominator_j == 0) {
            int i = numerator_i / denominator_i;
            int j = numerator_j / denominator_j;
                ans += 3 * i + j;
        }
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    while (t--) {
        solve();
    }
    
    return 0;
}
