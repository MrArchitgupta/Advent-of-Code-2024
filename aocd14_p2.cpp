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
        // cout<<x<<" "<<y<<" "<<z<<" "<<w<<endl;
        currentSet.push_back(x);
        currentSet.push_back(y);
        currentSet.push_back(z);
        currentSet.push_back(w);
        data.push_back(currentSet);
    }
    
    int a=101,b=103;
       int t=10000;
       while(t--){

            for(int i=0 ; i<data.size() ; i++){
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

    int cnt=0;
   vector<vector<int>> loc(a,vector<int>(b,0));
   for(int i=0 ; i<data.size() ; i++){
    loc[data[i][0]][data[i][1]]++;
   }

   for(int i=0 ; i<a ; i++){
    int cnt1=0;
    for(int j=0 ; j<b ; j++){
       if(loc[i][j]!=0) {cnt1++; cnt=max(cnt,cnt1);}
       else{
        cnt1=0;
       }
    }
    
   }
   if(cnt>20){
    cout<<10000-t<<endl;
   for(int i=0 ; i<a ; i++){
    for(int j=0 ; j<b ; j++){
          if(loc[i][j]==0){
            cout<<'.';
        }
        else{
            cout<<'#';
        }
    }
    cout<<endl;
   }
   }
     
 }
   
 
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
