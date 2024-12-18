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
    vector<string> a;
    while (getline(cin, s))
    {
        a.push_back(s);
    }
    int n=a.size();
    int m=a[0].size();
    int drow[]={-1,0,1,0};
    int dcol[]={0,1,0,-1};
    vector<vector<bool>> vis(n, vector<bool>(m,false));
    int ans=0;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            int area=0;
            int peri=0;
            if(!vis[i][j]){
                vis[i][j]=true;
                queue<pair<int,int>> q;
                q.push({i,j});
                while(!q.empty()){
                    int r=q.front().first;
                    int c=q.front().second;
                    q.pop();
                    area++;
                    for(int k=0 ; k<4 ; k++){
                        int row=r+drow[k];
                        int col=c+dcol[k];
                        if(row>=0 && row<n && col>=0 && col<m){
                            if(a[row][col]==a[i][j]){
                                if(!vis[row][col]){
                                vis[row][col]=true;
                                q.push({row,col});
                                }
                            }
                            else{
                                peri++;
                            }
                        }
                        else peri++;
                        
                    }
                }
                //  cout<<area<<" "<<peri<<endl;
                ans+=peri*area;
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
