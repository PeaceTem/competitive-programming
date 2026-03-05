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

vii sol;

void zero_func(vector<int>& a, vector<int>& ind){
    int n = a.size();
    int right = n - 1, left = n - 2;
    vector<int> h = a;

    while(right >= 0 && left >= 0){
        if(a[ind[left]] >= h[ind[right]]) break;

        h[ind[right]] -= a[ind[left]];
        sol.push_back({ind[left] + 1, ind[right] + 1});
        left--;
    }

    if(left == -1 ){
        cout << left << endl; return;
    }

    right = left;

    left = 0;

    for(; left < right; left++) sol.push_back({ind[left] + 1, ind[left + 1] + 1});

    sol.push_back({ind[right] + 1, ind[n - 1] + 1});

    cout << sol.size() << endl;
    for(auto& [u, v] : sol){
        cout << u << " " << v << endl;
    }
}

void sol_func(vector<int>& a, vector<int>& ind, int m){
    int n = a.size();
    int left = 0, right = n - 1;

    vector<int> h = a;

    for(int i = 0; i < m - 1; i++){
        sol.push_back({ind[right - i] + 1, ind[i] + 1});
    }

    for(int i = m - 1; i <= right - m; i++){
        if(i == right - m) sol.push_back({ind[i + 1] + 1, ind[i] + 1});
        else sol.push_back({ind[i] + 1, ind[i + 1] + 1});
    }

    cout << sol.size() << endl;
    for(auto& [u, v] : sol){
        cout << u << " " << v << endl;
    }
}

void solve(){
    int n, m; cin >> n >> m;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    if(m > (n / 2)) {
        cout << -1 << endl; return;
    }

    vector<int> ind(n); iota(all(ind), 0LL);

    sort(all(ind), [&](int& x, int& y){
        return a[x] < a[y];
    });

    sol.clear();
    if(m == 0) zero_func(a, ind);
    else sol_func(a, ind, m);
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

