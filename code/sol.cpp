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

    if(k < n || k >= 2 * n){
        cout << "NO\n"; return;
    }

    cout << "YES\n";

    if(n == k){
        for(int i = 1; i <= n; i++) cout << i << " " << i << " ";
        cout << endl;
        return;
    }

    vector<int> ans = {1, 2};
    k = k - n - 1;

    queue<int> st;
    st.push(1);
    st.push(2);
    int nt = 3;
    while(k){
        ans.push_back(nt);
        ans.push_back(st.front());
        st.pop();
        st.push(nt);
        nt++;
        k--;
    }

    while(!st.empty()) ans.push_back(st.front()), st.pop();

    while(nt <= n){
        ans.push_back(nt);
        ans.push_back(nt);
        nt++;
    }

    for(int& x : ans) cout << x << " ";
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

