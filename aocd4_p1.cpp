#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    string s;
    vector<string> a;
    while (getline(cin, s)) {
       a.push_back(s);
    }
    int n=a.size();
    int m=a[0].size();
    int cnt=0;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
           
            if(i<n-3 && j<m-3){
                if(a[i][j]=='X' && a[i+1][j+1]=='M' && a[i+2][j+2]=='A' && a[i+3][j+3]=='S') cnt++;

            }
            if(i>2 && j>2){
                 if(a[i][j]=='X' && a[i-1][j-1]=='M' && a[i-2][j-2]=='A' && a[i-3][j-3]=='S') cnt++;

            }
            if(i<n-3 && j>2){
                 if(a[i][j]=='X' && a[i+1][j-1]=='M' && a[i+2][j-2]=='A' && a[i+3][j-3]=='S') cnt++;

            }
            if(i>2 && j<n-3){
                 if(a[i][j]=='X' && a[i-1][j+1]=='M' && a[i-2][j+2]=='A' && a[i-3][j+3]=='S') cnt++;

            }
        }
    }
    cout<<cnt<<endl;


}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
