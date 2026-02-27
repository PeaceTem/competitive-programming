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
    int n; cin >> n;

    vector<vector<int>> a(n);
    vector<int> ht(n);

    for(int i = 0; i < n; i++){
        int m; cin >> m;
        ht[i] = m - 1;
        for(int j = 0; j < m; j++){
            int x; cin >> x;
            a[i].push_back(x);
        }
    }
    
    vector<int> ans;
    unordered_set<int> mk;
    while(true){
        int val = LLONG_MAX, inc = 0, pt = -1;

        for(int j = 0; j < n; j++){
            while(ht[j] != -1){
                if(mk.count(a[j][ht[j]])) ht[j]--;
                else {
                    if(val == a[j][ht[j]]){
                        inc++;
                        // cout << "Picked1: " << val << endl;
                    } else if(val > a[j][ht[j]]) {
                        inc = 1;
                        val = a[j][ht[j]];
                        pt = j;
                        // cout << "Picked0: " << val << endl;
                    }
                    // val = a[j][ht[j]];
                    // the code is pick the least one without duplicate
                    // that's wrong.
                    break;
                }
            }
        }

        if(inc == 0) break;
        if(inc > 1){
            // create a function that goes deep into this one;
            // if this set is not empty then use it and check for all the indices in it;
            // else use the normal condition;
            mk.insert(val);
            ans.push_back(val);
        } else {
            int k = (int) a[pt].size();
            for(k = k - 1; k >= 0; k--){
                if(mk.count(a[pt][k])) continue;
                mk.insert(a[pt][k]);
                ans.push_back(a[pt][k]);
            }
            ht[pt] = -1;
        }
    }

    for(int& u : ans) cout << u << " ";
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

