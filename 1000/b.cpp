#include <bits/stdc++.h>

using i64 = long long;
using namespace std;

void solve(){
    // generate an indices vector from 1 to n    
    long long n,l,r; cin>>n>>l>>r; vector<long long> a(n);

    for(long long i=0; i<n;i++) cin>>a[i];
    vector<long long> b = a;
    sort(a.begin()+l-1, a.end()); sort(b.begin(), b.begin()+r, greater<long long>());

    cout << min(accumulate(a.begin() + l - 1, a.begin() + r, 0), accumulate(b.begin() + l - 1, b.begin() + r, 0)) << '\n';
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

iwr -useb https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim |`ni "$(@($env:XDG_DATA_HOME, $env:LOCALAPPDATA)[$null -eq $env:XDG_DATA_HOME])/nvim-data/site/autoload/plug.vim" -Force