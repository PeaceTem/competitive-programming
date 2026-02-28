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
    int n, x, y; cin >> n >> x >> y;

    vector<int> p(n);
    for(int i = 0; i < n; i++) cin >> p[i];
    int mn = 1e10;
    int chosen = -1;
    for(int i = x; i < y; i++){
        if(p[i] < mn) mn = p[i], chosen = i;
    }
    // cout << chosen << " : " << p[chosen] << endl;

    vector<int> kk;
    for(int i = 0; i < (y - x); i++){
        if(chosen == y) chosen = x;
        kk.push_back(p[chosen]);
        chosen++;
    }

    vector<int> k;
    for(int i = 0; i < n; i++){
        if(i >= x && i < y) continue;
        k.push_back(p[i]);
    }

    int f = 0, s = 0;
    int a = k.size(), b = kk.size();
    for(int i = 0; i < 3e10; i++){

        if(f < a && s < b){
            if(k[f] < kk[s]){
                cout << k[f] << " "; 
                f++;
                continue;
            } else if(s < b) {
                for(int j = 0; j < b; j++) cout << kk[j] << " ";
                s = b;
            }
        } else if(f < a) cout << k[f] << " ", f++;
        else if(s < b){
            for(int j = 0; j < b; j++) cout << kk[j] << " ";
            s = b;
        }

        if(f == a && s == b) break;
    }
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

