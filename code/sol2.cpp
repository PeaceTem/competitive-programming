#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define int long long

void solve(){
    int n, m, l;
    cin >> n >> m >> l;
    vector<int> a(n);

    for(int i = 0; i < n; i++) cin >> a[i];

    if(m == 1){
        cout << l - a.back() << endl;
        return;
    }
    int k = 0, t = 0;
    k = (a[0] + 1) / 2;
    t = 0;
    for(int i = 1; i < n; i++){
        int off = a[i] - a[i - 1];

        if(off > k){
            off = k + off;
            k = (off + 1) / 2;
            t = off / 2;
        }
        else {
            t = off;
        }

        if(i == n - 1) k = min(k, t);
        else max(k, t);
    }

    cout << k + (l - a.back()) << endl;
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