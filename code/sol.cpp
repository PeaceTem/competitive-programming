#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define int long long

void solve(){
    int p, q; cin >> p >> q;

    int sides = p + 2 * q;

    // I need to find 2 numbers that n + m + 2nm = p + 2q sides

    int inc = 3;
    int start = 4;
    int x;
    int n = 1, m;
    int k;
    for(; start <= sides; start += 3, inc += 2, n++){
        x = (sides - start) % inc;
        if(x != 0) continue;

        m = (1 + (sides - start) / inc);

        if(n + m + 2 * n * m != sides) continue;

        cout << n << " " << m << endl;
        return;
    }


    cout << -1 << endl;
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