#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define int long long

const int SQ = 500;
void solve(){
    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;

    for(int i = 0; i < n; i++){
        for(int j = 1; j < 500; j++){
            int k = a[i] * j;
            if(k + i >= n) break;
            if(a[k + i] == j) ans++;
        }
    }

    for(int i = 0; i < n; i++){
        if(a[i] >= 500){
            for(int j = 1; j < 500; j++){
                int k = a[i] * j;
                if(i - k < 0) break;
                if(a[i - k] == j) ans++;
            }
        }
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