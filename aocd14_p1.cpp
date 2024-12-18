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
     ifstream f("input14.txt");
     
    if (!f.is_open()) {
        cerr << "Error opening the file!";

        return ;
    }
    vector<vector<int>> data; 
    string line;

    while (getline(f, line)) {
        // if(line.empty()) break;
        vector<int> currentSet;
        int x, y, z, w;
        char skip; 

        stringstream ss(line);
        ss >> skip >> skip >> x >> skip >> y >> skip  >> skip >> z >> skip >> w;
        currentSet.push_back(x);
        currentSet.push_back(y);
        currentSet.push_back(z);
        currentSet.push_back(w);
        data.push_back(currentSet);
    }
    
    int a=101,b=103;
       int t=100;
       while(t--){
            for(int i=0 ; i<data.size() ; i++){
                // cout<<a;
                data[i][0]+=data[i][2];
                if(data[i][0]>=a){
                    data[i][0]=data[i][0]%(a-1);
                    data[i][0]--;
                }
                else if(data[i][0]<0){
                    data[i][0]+=a;
                }
                data[i][1]+=data[i][3];
                if(data[i][1]>=b){
                    data[i][1]=data[i][1]%(b-1);
                    data[i][1]--;
                }
                else if(data[i][1]<0){
                    data[i][1]+=b;
                }
        }
   }

    int q1=0,q2=0,q3=0,q4=0;
   vector<vector<int>> loc(a,vector<int>(b,0));
   for(int i=0 ; i<data.size() ; i++){
    loc[data[i][0]][data[i][1]]++;
   }

   for(int i=0 ; i<a ; i++){
    for(int j=0 ; j<b ; j++){
        if(i<a/2 && j<b/2){
            q1+=loc[i][j];
        }
        if(i<a/2 && j>b/2){
            q2+=loc[i][j];
        }
        if(i>a/2 && j<b/2){
            q3+=loc[i][j];
        }
        if(i>a/2 && j>b/2){
            q4+=loc[i][j];
        }
    }
   }
   cout<<q1*q2*q3*q4<<endl;
     
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
