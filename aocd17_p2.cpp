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
int fun(vector<int>& program , int ind , int ans){
    if(ind==-1){
        return ans;
    }
    for(int i=0 ; i<8 ; i++){
        int a=ans<<3;
        a+=i;
        int b=a%8;
        b=b^1;
        int c=a>>b;
        b=b^c;
        b=b^4;
        if(b%8==program[ind]){
            int d=fun(program, ind-1, a);
            if(d==-1){
                continue;
            }
            else{
                return d;
            }
        }
    }
    return -1;
}

void solve() {   vector<int> program={2,4,1,1,7,5,4,6,1,4,0,3,5,5,3,0};
   cout<< fun(program, 15, 0);
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
