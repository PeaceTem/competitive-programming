#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
// #define mp make_pair
#define F first
#define S second
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define lb lower_bound
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
// #define MOD 1000000007
#define INF 1000000000000000000
#define MAXN 1000005
#define ld long double
#define eps 1e-9


void solve(){
    long long n, ax, ay, bx, by; cin >> n >> ax >> ay >> bx >> by;

    vector<long long> x(n), y(n), dp[2];
    
    dp[0] = dp[1] = vector<long long>(n + 6, 0);

    for(long long i = 0; i < n; i++) cin >> x[i];
    for(long long i = 0; i < n; i++) cin >> y[i];
    map<long long, long long> mx, mn;

    mx[ax] = mn[ax] = ay;
    mn[bx] = mx[bx] = by;

    for(long long i = 0; i < n; i++){
        mx[x[i]] = max(mx[x[i]], y[i]);
        mn[x[i]] = min(mn.count(x[i]) ? mn[x[i]] : LLONG_MAX, y[i]);
    }
    long long cnt = 0, last = ax, need;

    dp[0][0] = dp[1][0] = 0;

    for(auto px : mx){
        cnt++;
        need = px.F - last + px.S - mn[px.F];

        dp[0][cnt] = min(dp[0][cnt - 1] + abs(mx[last] - mn[px.F]), dp[1][cnt - 1] + abs(mn[last] - mn[px.F])) + need;
        dp[1][cnt] = min(dp[0][cnt - 1] + abs(mx[last] - px.S), dp[1][cnt - 1] + abs(mn[last] - px.S)) + need;
        last = px.F;
    }

    cout << dp[0][cnt] << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    int t = 1; 
    cin >> t;

    while(t-->0){
        solve();
    }
    return 0;
}

