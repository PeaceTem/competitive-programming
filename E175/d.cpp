#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
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
#define bit(n, b) (((n) >> (b)) & 1)
#define bitcount(n) __builtin_popcountll(n)
#define gcd(a, b) __gcd(a, b)
// #define fileIO freopen("input.txt", "r", stdin); freopen("output.txt", "w

// use assert

// struct Mint {
//     static const int MOD = 1e9+7;
//     int value;

//     Mint(long long v = 0) { 
//         value = v % MOD;
//         if (value < 0) value += MOD;
//     }

//     Mint operator+(const Mint& other) const { return Mint(value + other.value); }
//     Mint operator-(const Mint& other) const { return Mint(value - other.value); }
//     Mint operator*(const Mint& other) const { return Mint(1LL * value * other.value); }

//     Mint pow(long long exp) const {
//         Mint res = 1, base = value;
//         while (exp > 0) {
//             if (exp % 2) res = res * base;
//             base = base * base;
//             exp /= 2;
//         }
//         return res;
//     }

//     Mint inv() const { return pow(MOD - 2); }  // Fermat's little theorem
//     Mint operator/(const Mint& other) const { return *this * other.inv(); }

//     friend ostream& operator<<(ostream& os, const Mint& m) {
//         return os << m.value;
//     }
// };




ull ans = 0ULL;
map<int, int> m;


void udfs(vector<vi>& adj, vector<bool>& vis, vi& dist, int v){
    if(vis[v]) return;
    vis[v] = true;
    for(int u: adj[v]){
        if(!vis[u]){
            dist[u] = dist[v]+1;
            udfs(adj, vis, dist, u);
        }
    }
}

// use this dp to update the 
void dp(vector<vi>& adj, vi& dist, int k){
    int kk = sz(adj[k]); // this might be a potential bottleneck
    int dis = dist[k]+1;
    // dis++;
    int valid_nodes = m[dis] - kk;
    if(valid_nodes <=0) return;
    // cout << "kk: " << kk << ' ' << m[dis] << endl;


    // check if you can use memoization here
    ans = (ans + (ull) valid_nodes)%998244353;
    for(int u : adj[k]) dp(adj, dist, u);
}


void solve(){
    int n; cin>>n; n--;
    ans = 0ULL;
    // fill(all(dist), 0);
    // fill(all(adj))
    // adj.clear();
    // adj.assign(300001, vi()); // this is where the error comming from
    vector<vi> adj(n+2, vi());
    vi dist(n+2, 0); 
    vector<bool> vis(n+2, false);

    // adj.clear(); adj.resize(300001);
    // fill(all(vis), false);
    // for(int i=0;i<n;i++) cin>>a[i];
    for(int i = 0; i < n; i++){
        int x; cin>>x;
        adj[x].pb(i+2);
    }
    udfs(adj, vis, dist, 1);
    for(int i=1;i<=n+1;i++){
        if(dist[i]>0) m[dist[i]]++;
    }
    ans += (1 + sz(adj[1]));
    for(int j : adj[1]) dp(adj, dist, j);

    cout << ans << endl;
    // for(int i=1;i<n+1;i++){
    //     int y = sz(adj[i]);
    //     for(int j=0;j<y;j++) cout << adj[i][j] << ' ';
    //     cout << endl;
    // }
    // for(auto& p : m){

    // }
    m.clear();
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; cin>>t; while(t-->0) solve(); return 0;
}