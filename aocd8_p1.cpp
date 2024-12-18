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
     string s;
    vector<string> a;
    while (getline(cin, s))
    {
        a.push_back(s);
    }
    int n=a.size();
    int m=a[0].size();
    int ans=0;
    set<pair<int,int>> s1;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(a[i][j]!='.'){
                s1.insert({i,j});
            }
        }
    }
    for(auto it=s1.begin() ; it!=s1.end() ; it++){
        auto i=it++;
        auto it2=it;
        it=i;
        
        for( ; it2!=s1.end() ; it2++){
            int i=it->first;
            int j=it->second;
            int k=it2->first;
            int l=it2->second;
            int di=i-k;
            int dj=j-l;
            if(a[i][j]!=a[k][l]){
                continue;
            }
            if( k-di>=0 && k-di<n && l-dj>=0 && l-dj<m ){
                if(a[k-di][l-dj]=='.') ans++;
            }
            if(i+di>=0 && i+di<n && j+dj>=0 && j+dj<m ){
                if(a[i+di][j+dj]=='.') ans++;
            }
        }
    }
    cout<<ans<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t=1;
    // cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}

/**#include <bits/stdc++.h>
using namespace std;

// Parse the input grid and return positions of antennas
map<char, vector<pair<int, int>>> parseGrid(const vector<string>& grid) {
    map<char, vector<pair<int, int>>> antennas;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            char freq = grid[i][j];
            if (freq != '.') {
                antennas[freq].emplace_back(i, j);
            }
        }
    }
    return antennas;
}

// Compute unique antinodes for the grid
int countUniqueAntinodes(const vector<string>& grid) {
    map<char, vector<pair<int, int>>> antennas = parseGrid(grid);
    set<pair<int, int>> antinodeLocations;

    for (const auto& [freq, positions] : antennas) {
        int n = positions.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                auto [x1, y1] = positions[i];
                auto [x2, y2] = positions[j];

                // Antinodes are at 2:1 ratio along the line between (x1, y1) and (x2, y2)
                int dx = x2 - x1;
                int dy = y2 - y1;

                // First antinode (extending from (x1, y1))
                int x3 = x1 - dx;
                int y3 = y1 - dy;

                // Second antinode (extending from (x2, y2))
                int x4 = x2 + dx;
                int y4 = y2 + dy;

                // Validate bounds
                if (x3 >= 0 && x3 < grid.size() && y3 >= 0 && y3 < grid[0].size()) {
                    antinodeLocations.insert({x3, y3});
                }
                if (x4 >= 0 && x4 < grid.size() && y4 >= 0 && y4 < grid[0].size()) {
                    antinodeLocations.insert({x4, y4});
                }
            }
        }
    }

    return antinodeLocations.size();
}

int main() {
    vector<string> grid;
    string line;
    while (getline(cin, line)) {
        grid.push_back(line);
    }

    int result = countUniqueAntinodes(grid);
    cout << result << endl;
    return 0;
}
 */