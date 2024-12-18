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
     int a=59397658,b=0,c=0;
      vector<int> program={2,4,1,1,7,5,4,6,1,4,0,3,5,5,3,0};
   int ip=0;
    while(ip<program.size()){
        int opcode=program[ip];
        int oprand=program[ip+1];
        int lit_oprand=oprand;
        int combo_oprand;
        if(oprand<=3) combo_oprand=oprand;
        if(oprand==4) combo_oprand=a;
        if(oprand==5) combo_oprand=b;
        if(oprand==6) combo_oprand=c;
        if(oprand==7){
            combo_oprand=-1;
        }
        if(opcode==0){
            a=a/pow(2,combo_oprand);
        }
        else if(opcode==1){
            b=b^lit_oprand;
        }
        else if(opcode==2){
            b=combo_oprand%8;
        }
        else if(opcode==3){
            if(a!=0){
                ip=lit_oprand;
                continue;
            }
            
        }
        else if(opcode==4){
           b=b^c;
        }
        else if(opcode==5){
            cout<<combo_oprand%8<<',';
        }
        else if(opcode==6){
            b=a/pow(2,combo_oprand);
        }
        else if(opcode==7){
            c=a/pow(2,combo_oprand);
        }


        ip+=2;
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
