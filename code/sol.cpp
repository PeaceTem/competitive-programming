#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define int long long

void solve(){
    int n, x; cin >> n >> x;

    // if(x == n && x % 2 == 0){
    //     cout << 0 << endl; return;
    // }

    int start = max(x - 3, 0LL);
    int end = min(n, x + 3);
    // it starts from all even numbers to num +
    vector<int> dp;
    for(int i = start; i + 3 <= end; i++){
        int k = (i) ^ (i + 1) ^ (i + 2) ^ (i + 3);
        
        if(k == 0){
            dp.push_back(i);
        }
    }

    // if((int) dp.size() > 2){
    //     cout << "Something is wrong" << endl; return;
    // }

    // if((int) dp.size() == 0){
    //     cout << 0 << endl;

    // }

    // cout << dp.size() << " " << dp[0] << endl;

    int ans = 0;
    int mod = 998244353;
    for(int i = 0; i < (int) dp.size(); i++){

        int left = (dp[i] / 4) % mod;
        int right = max(0LL, ((n - dp[i] - 3) / 4) % mod);

        int p = ((left + 1) * (right + 1)) % mod;
        ans = (ans + p) % mod;
        // cout << dp[i] << " left: " << left << " right: " << right << ' ' << p << endl;
    }

    cout << ans << endl;
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