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
    ifstream f("input18.txt");
    if (!f.is_open()) {
        cerr << "Error opening the file!";
        return ;
    }
    int n=71;
    vector<vector<char>> a(n, vector<char>(n,'.'));
    vector<pair<int,int>> cor;
    string line;
    int b=1;
    while(getline(f,line)){
        if(line.empty()){
            break;
        }
        // if(b>1024){
        //     break;
        // }
         stringstream ss(line); // Use stringstream to parse the string
        string num1, num2;

        // Split the string based on the comma delimiter
        getline(ss, num1, ',');
        getline(ss, num2, ',');

        // Convert strings to integers
        int col = stoi(num1);
        int row = stoi(num2);
        // int row=line[2]-'0';
        // int col=line[0]-'0';
        
        if(b<=1024) if(row>=0 && row<n && col>=0 && col<n) a[row][col]='#';
        b++;
        cor.push_back({row,col});


        // cout<<line[2]<<" "<<line[0]<<endl;
    }
    // for(int i=0; i<n ; i++){
    //     for(int j=0 ; j<n ; j++){
    //         cout<<a[i][j];
    //     }
    //     cout<<endl;
    // }

    int j=1024;
    while(1){
        a[cor[j].first][cor[j].second]='#';
     
        int f=0;
    queue<vector<int>> q;
    q.push({0,0,0});
    int drow[]={-1,0,1,0};
    int dcol[]={0,-1,0,1};
    vector<vector<bool>> vis(n, vector<bool>(n,false));
    vis[0][0]=true;
    int temp=0;
   
    while(!q.empty()){
        int r=q.front()[0];
        int c=q.front()[1];
        int dist=q.front()[2];
        q.pop(); 
       
        if(r==n-1 && c==n-1){
            f=1;
            break;
        }
        for(int k=0 ; k<4 ; k++){
            int dr=r+drow[k];
            int dc=c+dcol[k];
            if(dr>=0 && dr<n && dc>=0 && dc<n && !vis[dr][dc] && a[dr][dc]=='.'){
                vis[dr][dc]=true;
                q.push({dr,dc,dist+1});
            }
        }
    }

    if(f==0){
        cout<<j<<endl;
        cout<<cor[j].second<<" "<<cor[j].first<<endl;
        break;
    }
       j++;
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

