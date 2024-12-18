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

int fun( vector<string> a, int i, int j, int m , int n){
    if(a[i][j]=='9'){
         return 1;
    }
    if(i<0 && j<0 && i>=m && j>=n){
        return 0;
    }
    int a1=0;
    if( i+1<m && a[i+1][j]==a[i][j]+1){
        a1+=fun(a,i+1,j, m ,n);
    }
    if(i-1>=0 && a[i-1][j]==a[i][j]+1){
        a1+=fun(a,i-1,j, m ,n);
    }
    if(j+1>=0 && j+1<n && a[i][j+1]==a[i][j]+1){
        a1+=fun(a,i,j+1, m ,n);
    }
    if(j-1>=0 && j-1<n && a[i][j-1]==a[i][j]+1){
        a1+=fun(a,i,j-1, m ,n);
    }
    return a1;
}

void solve() {
    string line;
    vector<string> a;
    while (getline(cin, line) && !line.empty()) {
        a.push_back(line);
    }
    int m=a.size();
    int n=a[0].size();
    int ans=0;
    for(int i=0 ; i<m ; i++){
        for(int j=0 ; j<n ; j++){
            if(a[i][j]=='0') ans+=fun(a,i,j,m,n);
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
