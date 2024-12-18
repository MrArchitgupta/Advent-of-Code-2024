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
     ifstream f("input16.txt");
    if (!f.is_open()) {
        cerr << "Error opening the file!";

        return ;
    }
    vector<string> a;
    string line;
    while(getline(f,line)){
        if(line.empty()){
            break;
        }
        a.push_back(line);
    }
    int n=a.size();
    int m=a[0].size();
    // cout<<n<<m;
     int ans=INT_MAX;
    vector<vector<int>> vis(n , vector<int> (m,0));
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
           
            if(a[i][j]=='S'){
                vis[i][j]=1;
                queue<vector<int>> q;
                q.push({i,j,2,0});
                while(!q.empty()){
                    int r=q.front()[0];
                    int c=q.front()[1];
                    int dir=q.front()[2];
                    int score=q.front()[3];
                    if(a[r][c]=='E'){
                        ans=min(ans,score);
                    }
                    q.pop();
                    if(dir==1){
                        if(r-1>=0 && !vis[r-1][c] && (a[r-1][c]=='.' || a[r-1][c]=='E')){
                            vis[r-1][c]=1;
                            q.push({r-1,c,1,score+1});
                        }
                        if(c-1>=0 &&!vis[r][c-1] && (a[r][c-1]=='.' || a[r][c-1]=='E')){
                            vis[r][c-1]=1;
                            q.push({r,c-1,4,score+1001});
                        }
                        if(c+1<m &&!vis[r][c+1] && (a[r][c+1]=='.' || a[r][c+1]=='E')){
                            vis[r][c+1]=1;
                            q.push({r,c+1,2,score+1001});
                        }
                    }
                    else if(dir==2){
                         if(c+1<m &&!vis[r][c+1] && (a[r][c+1]=='.' || a[r][c+1]=='E')){
                            vis[r][c+1]=1;
                            q.push({r,c+1,2,score+1});
                        }
                        if(r-1>=0 && !vis[r-1][c] && (a[r-1][c]=='.' || a[r-1][c]=='E')){
                            vis[r-1][c]=1;
                            q.push({r-1,c,1,score+1001});
                        }
                        if(r+1<n && !vis[r+1][c] && (a[r+1][c]=='.' || a[r+1][c]=='E')){
                            vis[r+1][c]=1;
                            q.push({r+1,c,3,score+1001});
                        }
                        
                       
                    }
                    if(dir==3){
                        if(r+1<n && !vis[r+1][c] && (a[r+1][c]=='.' || a[r+1][c]=='E')){
                            vis[r+1][c]=1;
                            q.push({r+1,c,3,score+1});
                        }
                       if(c-1>=0 && !vis[r][c-1] && (a[r][c-1]=='.' || a[r][c-1]=='E')){
                            vis[r][c-1]=1;
                            q.push({r,c-1,4,score+1001});
                        }
                        
                        
                        if(c+1<m &&!vis[r][c+1] && (a[r][c+1]=='.' || a[r][c+1]=='E')){
                            vis[r][c+1]=1;
                            q.push({r,c+1,2,score+1001});
                        }
                    }
                    if(dir==4){
                       if(c-1>=0 && !vis[r][c-1] && (a[r][c-1]=='.' || a[r][c-1]=='E')){
                            vis[r][c-1]=1;
                            q.push({r,c-1,4,score+1});
                        }
                        if(r+1<n && !vis[r+1][c] && (a[r+1][c]=='.' || a[r+1][c]=='E')){
                            vis[r+1][c]=1;
                            q.push({r+1,c,3,score+1001});
                        }
                        
                        if(r-1>=0 && !vis[r-1][c] && (a[r-1][c]=='.' || a[r-1][c]=='E')){
                            vis[r-1][c]=1;
                            q.push({r-1,c,1,score+1001});
                        }
                    }
                    
                    
                }
            }
        }
    }
    cout<<ans<<endl;
    // cout<<29<<endl;
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


// #include<bits/stdc++.h>
// using namespace std;

// bool marked[150][150];

// class Loc {
// public:
//     int x, y, dir; // 0-North, 1-East, 2-South, 3-West
//     bool operator<(const Loc &other) const {
//         if (x < other.x) {
//             return true;
//         } else if (x > other.x) {
//             return false;
//         }
//         if (y < other.y) {
//             return true;
//         } else if (y > other.y) {
//             return false;
//         }
//         return dir < other.dir;
//     }
// };

// bool inside(int i, int j, int n, vector<vector<char>> &v) {
//     return (i >= 0 && i < n && j >= 0 && j < n && v[i][j] != '#');
// }

// void dijkstra(int n, map<Loc, vector<pair<Loc, int>>> &adj, Loc s, map<Loc, int> &d, map<Loc, vector<Loc>> &p) {
//     d[s] = 0;
//     p[s] = {{-1, -1, -1}};
//     using pil = pair<int, Loc>;
//     priority_queue<pil, vector<pil>, greater<pil>> q;
//     q.push({0, s});

//     while (!q.empty()) {
//         Loc v = q.top().second;
//         int d_v = q.top().first;
//         q.pop();

//         if (d_v != d[v])
//             continue;

//         for (auto edge : adj[v]) {
//             Loc to = edge.first;
//             int len = edge.second;

//             if (d.find(to) == d.end()) d[to] = 1e9 + 10;
//             if (p.find(to) == p.end()) p[to] = {{-1, -1, -1}};

//             if (d[v] + len < d[to]) {
//                 p[to].clear();
//                 d[to] = d[v] + len;
//                 p[to] = {v};
//                 q.push({d[to], to});
//             } else if (d[v] + len == d[to]) {
//                 p[to].push_back(v);
//             }
//         }
//     }
// }

// void mark(Loc src, map<Loc, vector<Loc>> &p) {
//     if (src.x == -1 && src.y == -1) return;
//     marked[src.x][src.y] = true;
//     for (auto par : p[src]) {
//         mark(par, p);
//     }
// }

// int main() {
//     int n = 141, ans = 0;
//     Loc start, target;
//     vector<vector<char>> v(n, vector<char>(n));

//     // Input the maze
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             cin >> v[i][j];
//             if (v[i][j] == 'S') {
//                 start.x = i;
//                 start.y = j;
//                 start.dir = 1;
//             } else if (v[i][j] == 'E') {
//                 target.x = i;
//                 target.y = j;
//                 target.dir = -1;
//             }
//         }
//     }

//     map<Loc, vector<pair<Loc, int>>> adj;

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             for (int k = 0; k < 4; k++) {
//                 if (!inside(i, j, n, v)) continue;
//                 adj[{i, j, k}].push_back({{i, j, (k + 1) % 4}, 1000});
//                 adj[{i, j, k}].push_back({{i, j, (k + 3) % 4}, 1000});
//                 if (k == 0 && inside(i - 1, j, n, v)) {
//                     adj[{i, j, k}].push_back({{i - 1, j, k}, 1});
//                 }
//                 if (k == 1 && inside(i, j + 1, n, v)) {
//                     adj[{i, j, k}].push_back({{i, j + 1, k}, 1});
//                 }
//                 if (k == 2 && inside(i + 1, j, n, v)) {
//                     adj[{i, j, k}].push_back({{i + 1, j, k}, 1});
//                 }
//                 if (k == 3 && inside(i, j - 1, n, v)) {
//                     adj[{i, j, k}].push_back({{i, j - 1, k}, 1});
//                 }
//             }
//         }
//     }

//     map<Loc, int> d;
//     map<Loc, vector<Loc>> p;
//     dijkstra(n, adj, start, d, p);

//     memset(marked, false, sizeof(marked));
//     int target_cost = min({d[{target.x, target.y, 0}], d[{target.x, target.y, 1}], d[{target.x, target.y, 2}], d[{target.x, target.y, 3}]});

//     for (int k = 0; k < 4; k++) {
//         Loc tmp = {target.x, target.y, k};
//         if (d[tmp] == target_cost) mark(tmp, p);
//     }

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             if (marked[i][j]) ans++;
//         }
//     }

//     cout << ans << endl;
//     return 0;
// }
