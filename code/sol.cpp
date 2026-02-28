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

// unordered_map<int, vector<int>> mp;
vector<vector<int>> vp(2e5 + 5);
vector<pair<int, int>> pre_max(2e5 + 5);

void solve(){
    int n, m; cin >> n >> m;
    int x, y;
    
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        a[i] = {y, x};
    }

    sort(all(a));
    // process from right to left;
    // store acc;
    // int inf = 1e18;
    int cnt = n - 1;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    int acc = 0, last = 0;
    int tot = 0;
    for(int i = n; i >= 0; i--){
        while(cnt >= 0 && a[cnt].first == i){
            pq.push({a[cnt].second, i});
            acc += a[cnt].second;
            while((int) pq.size() > i + 1){
                acc -= pq.top().first;
                pq.pop();
            }
            cnt--;
        }

        while((int) pq.size() > i + 1){
            acc -= pq.top().first;
            pq.pop();
        }
        
        if((int) pq.size() == 0LL) last = 0;
        else last = pq.top().first;

        // mp[i] = {acc, last, (int) pq.size()};
        vp[i] = {acc, last, (int) pq.size()};
        tot = max(tot, acc);
    }

    // prefix max;
    int mx1 = 0, mx2 = -1;
    // mx1 means nothing to spare.
    // mx2 means something to spare
    for(int i = 0; i <= n; i++){
        if(vp[i][0] >= vp[mx1][0]){
            mx1 = i;
        }

        if(vp[i][2] <= i){
            if(mx2 == -1) mx2 = i;
            else if(vp[i][0] > vp[mx2][0]) mx2 = i;
            // else if(vp[i][1] < vp[mx2][1]) mx2 = i;
        }   

        pre_max[i] = {mx1, mx2};
    }

    for(int i = 0; i < m; i++){
        cin >> x >> y;

        if(y > n){
            cout << max(x, tot) << " ";
            continue;
        }

        int acc = vp[y][0];
        if(vp[y][2] <= y) acc += x;
        else if (vp[y][2] > y && vp[y][1] < x ){
            acc += x - vp[y][1];
        }

        int acc1 = vp[pre_max[y].first][0];
        if (vp[pre_max[y].first][1] < x ){
            acc1 += x - vp[pre_max[y].first][1];
        }
        
        int acc2 = -1;
        if(pre_max[y].second > -1){
            acc2 = vp[pre_max[y].second][0] + x;
            // cout << "Got it: " << pre_max[y].second << " " << acc2 << " " << vp[pre_max[y].second][1] << endl;
        }

        cout << max({tot, acc, acc1, acc2}) << " ";
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

