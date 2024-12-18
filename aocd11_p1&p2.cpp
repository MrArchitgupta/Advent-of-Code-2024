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

map<pair<int,int>,int> m;
int countd(int number) {
    int count = 0;
    while (number != 0) {
        number /= 10; 
        count++;
    }
    return count;
}

int fun(int num, int n ){
    if(n==0){
        return 1;
    }
    if(m.find({num,n})!=m.end()){
        return m[{num,n}];
    }
     int cnt=countd(num);
            if(num==0){
               return m[{num,n}]=fun(1,n-1);
            }
            else if(cnt%2==0){
            
                 string numStr = to_string(num); 
                    int len = numStr.length();

                    string f = numStr.substr(0, len / 2);       
                    string s = numStr.substr(len / 2, len / 2); 
                
                    int first = stoll(f);
                    int second = stoll(s);
                    return m[{num,n}]=fun(first, n-1)+fun(second, n-1);
            }
            else{
                return m[{num,n}]=fun(num*2024, n-1 );
            }
}


void solve() {
    vector<int> a; 
    int num;
    while (cin >> num ) { 
        a.push_back(num); 
    }
    int ans=0;
    for(int i=0 ; i<a.size() ; i++){
       ans+= fun(a[i],75);
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
