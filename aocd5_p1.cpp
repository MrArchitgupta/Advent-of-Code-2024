#include <bits/stdc++.h>
using namespace std;
using namespace std;


bool fun(const vector<int>& b, const map<int, vector<int>>& m ) {
    map<int, int> pos;
    for (int i = 0; i < b.size(); i++) {
        pos[b[i]] = i;
    }
    for (const auto& rule : m) {
        int page = rule.first;
         auto dep = rule.second;
        if (pos.find(page) == pos.end()) continue;
        for (int v : dep) {
            if (pos.find(v) == pos.end()) continue;
            if (pos[page] > pos[v]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    map<int, vector<int>> m;
    vector<vector<int>> a;      
    string line;
     while (getline(cin, line) && !line.empty()) {
        stringstream ss(line);
        int x, y;
        char c;
        ss >> x >> c >> y;
        m[x].push_back(y);
    }
   

  while (getline(std::cin, line) && !line.empty()) {
        stringstream ss(line);
        vector<int> u;
        int page;
        while (ss >> page) {
            if (ss.peek() == ',' || ss.peek() == ' ') {
                ss.ignore();
            }
            u.push_back(page);
        }
        a.push_back(u);
    }


    int sum = 0;
    for (auto& b : a) {
        if (fun(b, m)) {
            int mid = b[b.size() / 2]; 
            sum+= mid;
        }
    }
    cout<<sum<<endl;
    return 0;
}
