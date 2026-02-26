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


void solve(){
    int k, x; cin >> k >> x;

    vector<int> ans;
    int y = (1LL << (k + 1)) - x;
    while(x != y){
        if(x < y){
            ans.push_back(1);
            y -= x;
            x <<= 1;
        } else {
            ans.push_back(2);
            x -= y;
            y <<= 1;
        }
    }
    int p = ans.size();
    cout << p << endl;
    for(int i = p - 1; i >= 0; i--) cout << ans[i] << " ";
    cout << endl;
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

