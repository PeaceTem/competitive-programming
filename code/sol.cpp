#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define int long long

void solve(){
    int n;

    vector<pair<int, int>> vp(n);

    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;

        vp.push_back({x, y});
    }
}


int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1; 
    cin >> t;
    while(t-->0){
        solve();
    }
    return 0;
}