#include <bits/stdc++.h>

using i64 = long long;
using namespace std;



void solve() {
    int n, m, k; cin>>n>>m>>k; vector<int> a(m); vector<int> q(k);
    string output = "";
    for (int i = 0; i < m; i++) cin>>a[i];
    for (int i = 0; i < k; i++) cin>>q[i];

    if(n==k){
        output += string(m, '1');
    } else {
        output += string(m, '0');
    }
    
    if((n-k) == 1){
        bool checked = true;
        for(int i=0; i<k; i++){
            
            if(a[i] != q[i]){
                output[i] = '1'; checked = false;
                break;
            }
        else if(i+1 == n && checked) output.back() = '1';

        }
        
    }
    cout << output << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) {
        solve();
    }
}