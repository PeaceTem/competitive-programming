#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define int long long


void solve(){
    int n, k; cin >> n >> k;

    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    // unordered_set<int> st;
    // vector<bool> freq(n + 1);

    // for(int i = 0; i < n; i++){
    //     if(b[i] != -1){
    //         if(freq[b[i]]){
    //             cout << "NO" << endl; return;
    //         }
    //         freq[b[i]] = true;
    //     }
    // }

    for(int i = 0; i < n - k; i++){
        if(b[i] != -1){
            if(b[i] != a[i]){
                cout << "NO" << endl; return;
            }
        }
    }

    for(int i = k; i < n; i++){
        if(b[i] != -1){
            if(b[i] != a[i]){
                cout << "NO" << endl; return;
            }
        }
    }
    unordered_multiset<int> st;
    for(int i = n - k; i < k; i++){
        st.insert(a[i]);
    }

    for(int i = n - k; i < k; i++){
        if(b[i] != -1){
            if(!st.count(b[i])){
                cout << "NO" << endl; return;
            }
            st.erase(st.find(b[i]));
        }
    }

    cout << "YES" << endl;
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