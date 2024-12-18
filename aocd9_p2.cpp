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
    vector<pair<int,int>> num_freq;
    set<pair<int,int>> dot_freq;
    for(int i=0 ; i<s.size() ; i++){
        if(i%2==0){
            int v=s[i]-'0';
              int ind=a.size();
            num_freq.push_back({v,ind});
            while(v--){
                a.push_back(cnt);
            }
            cnt++;
        }
        else{
            int v=s[i]-'0';
            int ind=a.size();
             dot_freq.insert({v,ind});
            while(v--){
                a.push_back(-1);
            }
        }
    }

int ans=0;
    for(int i=num_freq.size()-1 ; i>=0 ; i--){
         auto it = dot_freq.lower_bound({num_freq[i].first, 0});
        if(it!=dot_freq.end()){
            int cnt1=num_freq[i].first;
            int idx=it->ss;
             while(cnt1-- ){
                ans+=i*idx;
                idx++;
            }
            dot_freq.erase(it);
            if(it->ff>num_freq[i].first){
                dot_freq.insert({it->ff-num_freq[i].first, it->ss+num_freq[i].first});
            }

        }
        else{
            int cnt1=num_freq[i].first;
            int idx=num_freq[i].second;
            while(cnt1--){
                ans+=i*idx;
                idx++;
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
