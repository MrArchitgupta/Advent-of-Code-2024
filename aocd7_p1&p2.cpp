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

int concat(int a, int b) 
{ 
  
    string s1 = to_string(a); 
    string s2 = to_string(b); 
    string s = s1 + s2; 
    int c = stoll(s); 
    return c; 
} 

bool fun2(vector<int> &a, int sum, int cal , int i){
    if(i==a.size()){
         if(cal==sum){
         return true;
        }
        return false;
    }
   
    return fun2(a,sum,cal+a[i],i+1)||fun2(a,sum,cal*a[i],i+1)||fun2(a,sum,concat(cal,a[i]), i+1);
}
bool fun1(vector<int> &a, int sum, int cal , int i){
    if(i==a.size()){
         if(cal==sum){
         return true;
        }
        return false;
    }
   
    return fun1(a,sum,cal+a[i],i+1)||fun1(a,sum,cal*a[i],i+1);
}

void solve() {
   string line;
   vector<vector<int>> a;
   vector<int> b;
     while (getline(cin, line) && !line.empty()) {
        stringstream ss(line);
        int x;
        char c;

        ss >> x >> c ;
        b.push_back(x);
         vector<int> d;
        int v;
        while (ss >> v) { 
            d.push_back(v);
        }
        a.push_back(d);
        
    }
    int m=a.size();
    int n=a[0].size();
    int ans1=0,ans2=0;
    for(int i=0 ; i<m ; i++){
        
        if(fun1(a[i],b[i],a[i][0],1)){
            ans1+=b[i];
        }
        if(fun2(a[i],b[i],a[i][0],1)){
            ans2+=b[i];
        }
        
    }
    cout<<"part1: "<<ans1<<endl;
    cout<<"part2: "<<ans2<<endl;
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
