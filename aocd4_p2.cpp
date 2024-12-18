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
           if(i>0 && j>0 && i<n-1 && j<m-1){
            if(a[i][j]=='A'){
                if(a[i-1][j-1]=='M' && a[i-1][j+1]=='M' && a[i+1][j-1]=='S' && a[i+1][j+1]=='S') cnt++;
                if(a[i-1][j-1]=='S' && a[i-1][j+1]=='S' && a[i+1][j-1]=='M' && a[i+1][j+1]=='M') cnt++;
                if(a[i-1][j-1]=='M' && a[i-1][j+1]=='S' && a[i+1][j-1]=='M' && a[i+1][j+1]=='S') cnt++;
                if(a[i-1][j-1]=='S' && a[i-1][j+1]=='M' && a[i+1][j-1]=='S' && a[i+1][j+1]=='M') cnt++;
            }
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
