#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define F first
#define S second
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define ld long double
#define eps 1e-9
#define int long long

bool check(int mid, vector<int> c, vector<bool> d){
    for(int i = 61; i >= 1; i--){
        if(d[i]){
            c[i - 1] += 2 * max(0LL, c[i] - mid);
        } else c[i - 1] += 2 * c[i];
    }

    if(c[0] > 0 && !d[0]) return false;
    if(c[0] <= mid) return true;
    return false;
}

void solve(){
    int s, m; cin >> s >> m;

    vector<int> c(62, 0);
    vector<bool> d(62, false);

    for(int i = 61; i >= 0; i--){
        if((1LL << i) & s) c[i] = 1;

        if((1LL << i) & m) d[i] = true;
    }

    int l = 0, r = s + 1;

    while(l + 1 < r){
        int mid = l + (r - l) / 2;

        if(check(mid, c, d)) r = mid;
        else l = mid;
    }
    if(r > s) cout << -1 << endl;
    else cout << r << endl;
}


int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    int t = 1; 
    cin >> t;
    while(t-->0){
        solve();
    }
    return 0;
}

