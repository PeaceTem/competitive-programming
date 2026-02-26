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
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int cnt = 0;
    int less_cnt = 0;
    int g_cnt = 0;
    int signal = 0;
    int last = -1;
    for(int i = 0; i < n; i++){
        if(a[i] <= k){
            less_cnt++;
            // if(signal) signal = 0;
        } else {
            // if(signal == 0) g_cnt++;
            // else signal = 0;
            g_cnt++;
        }

        if(less_cnt != 0 && less_cnt + 1 == g_cnt && signal){
            cnt++;
            // signal = 0;
            less_cnt = 0;
            g_cnt = 0;
            last = i;
        } else if(less_cnt != 0 && less_cnt == g_cnt){
            cnt++;
            less_cnt = 0;
            g_cnt = 0;
            last = i;
        } else if(less_cnt > g_cnt){
            cnt++;
            less_cnt = 0;
            g_cnt = 0;
            if(i + 1 < n && a[i + 1] > k) signal++;
            last = i;
        }
    }

    less_cnt = 0;
    g_cnt = 0;
    signal = 0;

    int new_cnt = 0;
    int new_last = -1;
    for(int i = n - 1; i >= 0; i--){
        if(a[i] <= k){
            less_cnt++;
            // if(signal) signal = 0;
        } else {
            // if(signal == 0) g_cnt++;
            // else signal = 0;
            g_cnt++;
        }

        if(less_cnt != 0 && less_cnt + 1 == g_cnt && signal){
            new_cnt++;
            signal = 0;
            less_cnt = 0;
            g_cnt = 0;
            new_last = i;
            // cout << "signal " << a[i] << endl;
        } else if(less_cnt != 0 && less_cnt == g_cnt){
            new_cnt++;
            less_cnt = 0;
            g_cnt = 0;
            // signal = 0;
            new_last = i;
            // cout << "Equal " << a[i] << endl;
        } else if(less_cnt > g_cnt){
            new_cnt++;
            less_cnt = 0;
            g_cnt = 0;
            if(i - 1 >= 0 && a[i - 1] > k) signal++;
            new_last = i;
            // cout << "Greater " << a[i] << endl;
        }
    }
    // cout << "What is going on?\n";
    // cout << "CNT: " << cnt << " NewCNT: " << new_cnt << " Last: " << last << " NewLast: " << new_last << endl;

    if(cnt >= 2 || new_cnt >= 2){
        cout << "YES\n"; return;
    }

    if(cnt == 1 && new_cnt == 1 && last != -1 && new_last != -1 && last + 1 < new_last){

        cout << "YES\n"; return;
    }
    
    cout << "NO\n";
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

