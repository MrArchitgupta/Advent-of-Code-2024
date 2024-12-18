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
     ifstream f("input15.txt");
    if (!f.is_open()) {
        cerr << "Error opening the file!";

        return ;
    }
    // vector<vector<int>> data; 
    string line;
    vector<string>a;
    vector<string>b;
    int flag=0;
    while (getline(f, line)) {
        if(line.empty()){
            flag=1;
            continue;
        }
        string s="";
        if(flag==0){
            for(int i=0 ; i<line.size() ; i++){
                if(line[i]=='.'){
                    s+="..";
                }
                if(line[i]=='#'){
                    s+="##";
                }
                if(line[i]=='O'){
                    s+="[]";
                }
                if(line[i]=='@'){
                    s+="@.";
                }
            }
            a.push_back(s);
        }
        else{
            b.push_back(line);
        }
    }


    int r,c;
    for(int i=0 ; i<a.size() ; i++){
        for(int j=0 ; j<a[0].size() ; j++){
            if(a[i][j]=='@'){
                a[i][j]='.';
                r=i;
                c=j;
            }
        }
    }
 
  
  
    for(int i=0 ; i<b.size() ; i++){
        for(int j=0 ; j<b[i].size() ; j++){
            //  cout<<r<<" "<<c<<endl;
            // cout<<b[i][j];
            // cout<<j+1<<endl;
            //  for(int i1=0 ; i1<a.size() ; i1++){
            //     for(int j1=0 ; j1<a[0].size() ; j1++){
            //         if(i1==r && j1==c){
            //             cout<<'@';
            //             continue;
            //         }
            //         cout<<a[i1][j1];
            //     }
            //     cout<<endl;
            // }
            // cout<<endl;
            if(b[i][j]=='<'){
                // cout<<1;
                
                if(a[r][c-1]==']'){
                    int k=2;
                    int ind=-1;
                    while(1){
                        if(a[r][c-k]=='.'){
                            ind=c-k;
                            break;
                        }
                        else if(a[r][c-k]=='#'){
                            break;
                        }
                        k++;
                    }
                    if(ind!=-1){
                        // a[r][c-1]='.';
                        
                        for(int l=ind ; l<=c-2 ; l++){
                            a[r][l]=a[r][l+1];
                        }
                        a[r][c-1]='.';
                        c=c-1;
                    }
                }
                else if(a[r][c-1]=='.'){
                    c=c-1;
                }
                
            }
            else if(b[i][j]=='>'){
               
                if(a[r][c+1]=='['){
                    int k=2;
                    int ind=-1;
                    while(c+k<a[0].size()){
                        if(a[r][c+k]=='.'){
                            ind=c+k;
                            break;
                        }
                        else if(a[r][c+k]=='#'){
                            break;
                        }
                        k++;
                    }
                    if(ind!=-1){
                        
                        
                        for(int l=ind ; l>=c+2 ; l-- ){
                            a[r][l]=a[r][l-1];
                        }
                        a[r][c+1]='.';
                        c=c+1;
                    }
                }
                else if(a[r][c+1]=='.'){
                    
                        c=c+1;
                    
                }
            }

            else if(b[i][j]=='^'){
                // cout<<a[r-1][c]<<endl;
              
                if(a[r-1][c]=='[' || a[r-1][c]==']'){
                    vector<pair<int,int>> cor;
                    queue<pair<int,int>> q;
                    vector<vector<int>> vis(a.size() , vector<int>(a[0].size(), 0));
                    q.push({r-1,c});
                    int f=1;
                    while(!q.empty()){
                        int row=q.front().first;
                        int col=q.front().second;
                        q.pop();
                        cor.push_back({row,col});
                        vis[row][col]=1;
                        if(a[row][col]=='[' ){
                            if(!vis[row][col+1]) {q.push({row,col+1}); vis[row][col+1]=1;}
                            if(a[row-1][col]=='#'){
                                f=0;
                                break;
                            }
                            else if(!vis[row-1][col] &&a[row-1][col]=='[' || a[row-1][col]==']'){
                                q.push({row-1,col}); 
                                 vis[row-1][col]=1;
                            }
                        }
                        else{
                            if(!vis[row][col-1]) {q.push({row,col-1});  vis[row][col-1]=1;}
                            if(a[row-1][col]=='#'){
                                f=0;
                                break;
                            }
                            else if(!vis[row-1][col] &&a[row-1][col]=='[' || a[row-1][col]==']'){
                                q.push({row-1,col});
                                 vis[row-1][col]=1;
                            }
                        }

                    }
                    if(f==1){
                        for(int i=cor.size()-1; i>=0 ; i--){
                            int row=cor[i].first;
                            int col=cor[i].second;
                            a[row-1][col]=a[row][col];
                            a[row][col]='.';
                        }
                            r=r-1;
                    }
                    
                    
                }
                else if(a[r-1][c]=='.'){
                   
                        r=r-1;
                    
                }
            }
           else if(b[i][j]=='v'){

                if(a[r+1][c]=='[' || a[r+1][c]==']'){
                    vector<pair<int,int>> cor;
                    queue<pair<int,int>> q;
                    vector<vector<int>> vis(a.size() , vector<int>(a[0].size(), 0));
                    q.push({r+1,c});
                    int f=1;
                    while(!q.empty()){
                        int row=q.front().first;
                        int col=q.front().second;
                        q.pop();
                        cor.push_back({row,col});
                        vis[row][col]=1;
                        if(a[row][col]=='[' ){
                            if(!vis[row][col+1]) {q.push({row,col+1}); vis[row][col+1]=1;}
                            if(a[row+1][col]=='#'){
                                f=0;
                                break;
                            }
                            else if(!vis[row+1][col] &&a[row+1][col]=='[' || a[row+1][col]==']'){
                                vis[row+1][col]=1;
                                q.push({row+1,col});
                            }
                        }
                        else{
                            if(!vis[row][col-1]) q.push({row,col-1});
                            if(a[row+1][col]=='#'){
                                f=0;
                                break;
                            }
                            else if(!vis[row+1][col] &&a[row+1][col]=='[' || a[row+1][col]==']'){
                                 vis[row+1][col]=1;
                                q.push({row+1,col});
                            }
                        }

                    }
                    if(f==1){
                        for(int i=cor.size()-1; i>=0 ; i--){
                            int row=cor[i].first;
                            int col=cor[i].second;
                            a[row+1][col]=a[row][col];
                            a[row][col]='.';
                        }
                          r=r+1;
                    }
                    
               
            }
             else if(a[r+1][c]=='.'){
                        r=r+1;
                }
                
            // cout<<j;
            

        }
    }
    
   
    
   
    }
     int ans=0;
    for(int i=0 ; i<a.size() ; i++){
        for(int j=0 ; j<a[0].size() ; j++){
            if(a[i][j]=='['){
            ans+=100*i+j;
            }
            cout<<a[i][j];
        }
        cout<<endl;
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
