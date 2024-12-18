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
    cin>>s;
    vector<int>a;
    int cnt=0;
    for(int i=0 ; i<s.size() ; i++){
        if(i%2==0){
            int v=s[i]-'0';
            while(v--){
                a.push_back(cnt);
            }
            cnt++;
        }
        else{
            int v=s[i]-'0';
            while(v--){
                a.push_back(-1);
            }
        }
    }
    vector<int> num;
    for(int i=a.size()-1 ; i>=0 ;i--){
        if(a[i]!=-1){
            num.push_back(a[i]);
        }
    }
    int j=0;
    int ans=0;
    cnt=0;
    for(int i=0 ; i<num.size() ; i++){
        if(a[i]!=-1){
            ans+=i*a[i];
        }
        else{
            ans+=i*num[j];
            j++;
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
