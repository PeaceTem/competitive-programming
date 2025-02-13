#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    bool done = false;
    while(!done){
    size_t pos; string numStr = to_string(n);
    while ((pos = numStr.find("33")) != std::string::npos) {
        numStr.erase(pos, 2); // Erase two characters starting at `pos`
        n = numStr.empty() ? 0 : std::stoi(numStr);
    }
    if(n > 33){
        n -= 33;
    } else if(n == 0) {
        done = true;
        cout << "YES" << endl;
    } else if(n < 33) {
        done = true;
        cout << "NO" << endl;
    }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}