#include <bits/stdc++.h>

using i64 = long long;
using namespace std;


i64 calcLessThanX(vector<i64> b, i64 x){
    i64 res = 0;
    i64 sum = accumulate(b.begin(), b.end(), 0);
    i64 n = b.size(), j=0;

    for(i64 i=n-1; i>=0; i--){
        while(j < n && sum - b[j] - b[i] >= x) j++;
        res += n-j;
    }

    for(i64 i=0; i<n; i++){
        if(sum - b[i] - b[i] < x) res -= 1;
    }

    
    return res / 2;
}


void solve() {
    // generate an indices vector from 1 to n    
    i64 n; i64 l,r; cin>>n>>l>>r; vector<i64> a(n);

    for(i64 i=0; i<n;i++) cin>>a[i];

    sort(a.begin(), a.end());
    // use two pointer
    // if 1st element + nth element <
    
    cout << calcLessThanX(a, r+1) - calcLessThanX(a, l) << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 t = 1;
    std::cin >> t;

    while (t--) {
        solve();
    }

}