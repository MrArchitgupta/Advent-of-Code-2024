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
        if(flag==0){
            a.push_back(line);
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
            
            if(b[i][j]=='<'){
                // cout<<1;
                
                if(a[r][c-1]=='O'){
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
                        a[r][c-1]='.';
                        
                        for(int l=c-2 ; l>=ind ; l-- ){
                            a[r][l]='O';
                        }
                        c=c-1;
                    }
                }
                else if(a[r][c-1]=='.'){
                    c=c-1;
                }
                
            }
            else if(b[i][j]=='>'){
               
                if(a[r][c+1]=='O'){
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
                        a[r][c+1]='.';
                        
                        for(int l=c+2 ; l<=ind ; l++ ){
                            a[r][l]='O';
                        }
                        c=c+1;
                    }
                }
                else if(a[r][c+1]=='.'){
                    
                        c=c+1;
                    
                }
            }
            else if(b[i][j]=='^'){
                // cout<<a[r-1][c]<<endl;
              
                if(a[r-1][c]=='O'){
                    int k=2;
                    int ind=-1;
                    while(r-k>=0){
                        if(a[r-k][c]=='.'){
                            ind=r-k;
                            break;
                        }
                        else if(a[r-k][c]=='#'){
                            break;
                        }
                        k++;
                    }
                    if(ind!=-1){
                        a[r-1][c]='.';
                        
                        for(int l=r-2 ; l>=ind ; l-- ){
                            a[l][c]='O';
                        }
                        r=r-1;
                    }
                }
                
                else if(a[r-1][c]=='.'){
                   
                        r=r-1;
                    
                }
            }
           else if(b[i][j]=='v'){
                if(a[r+1][c]=='O'){
                    int k=2;
                    int ind=-1;
                    while(1){
                        if(a[r+k][c]=='.'){
                            ind=r+k;
                            break;
                        }
                        else if(a[r+k][c]=='#'){
                            break;
                        }
                        k++;
                    }
                    if(ind!=-1){
                        a[r+1][c]='.';
                        
                        for(int l=r+2 ; l<=ind ; l++ ){
                            a[l][c]='O';
                        }
                        r=r+1;
                    }
                }
                else if(a[r+1][c]=='.'){
                        r=r+1;
                }
            }

            //  for(int i1=0 ; i1<a.size() ; i1++){
            //     for(int j1=0 ; j1<a[0].size() ; j1++){
            //         if(i1==r && j1==c){{
            //             cout<<'@';
            //             continue;
            //         }}
            //         cout<<a[i1][j1];
            //     }
            //     cout<<endl;
            // }

        }
    }
    
    int ans=0;
    for(int i=0 ; i<a.size() ; i++){
        for(int j=0 ; j<a[0].size() ; j++){
            if(a[i][j]=='O'){
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
