#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define int long long

void solve(){
    string s; cin >> s;

    int l = 0, r = (int) s.size() - 1;

    while(l < r){
        char t = s[l];
        s[l] = s[r];
        s[r] = t;
        l++, r--;
    }

    cout << s << endl;
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