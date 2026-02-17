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
#define int long long

int cnk[31][31];
void compute(){
    for(int i = 0; i < 30; ++i){
        for(int j = 0; j < 30; ++j){
            if(i < j) cnk[i][j] = 0;
            else if(j == 0) cnk[i][j] = 1;
            else cnk[i][j] = cnk[i - 1][j] + cnk[i - 1][j - 1];
        }
    }
}

void solve(){
    int n, k; cin >> n >> k;
    int d = (int) log2(n);
    int ans = 0;

    for(int i = 1; i < d; i++){
        for(int j = 1; j <= i + 1; j++){
            if(i + j <= k) continue;
            ans += cnk[i][j - 1];
        }
    }

    if(d + 1LL > k) ++ans;
    cout << ans << endl;
}

int32_t main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    compute();
    int t = 1; 
    cin >> t;
    while(t-->0){
        solve();
    }
    return 0;
}

