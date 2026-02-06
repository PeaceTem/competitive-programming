#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
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
#define vvi vector<vi>
#define eps 1e-9
#define bitcountll(n) __builtin_popcountll(n)
#define bitcount(n) __builtin_popcount(n)
#define fileIO freopen("input.txt", "r", stdin);

// ==================== FUNCTION DECLARATIONS ====================
// (Place only function names + parameter lists here)

// void fastIO();
// template<typename T> void read(T &x);
// template<typename T> void read(vector<T> &v);
// template<typename T> void print(const T &x);
// template<typename T> void print(const vector<T> &v, char sep=' ');
// long long modpow(long long a, long long b, long long m);
// long long egcd(long long a, long long b, long long &x, long long &y);
// long long modinv(long long a, long long m);
// vector<string> split(const string &s, char delim=' ');
// string join(const vector<string> &v, const string &sep=" ");

// ========================= MAIN SOLVE ===========================
// ================= Additional Useful CP Snippets =================

// -------- Disjoint Set Union (DSU) --------
struct DSU {
    vector<int> p, sz;
    DSU(int n){ p.resize(n); sz.assign(n,1); iota(p.begin(), p.end(), 0); }
    int find(int x){ return p[x] == x ? x : p[x] = find(p[x]); }
    bool unite(int a, int b){
        a = find(a); b = find(b);
        if(a == b) return false;
        if(sz[a] < sz[b]) swap(a,b);
        p[b] = a; sz[a] += sz[b]; return true;
    }
};

// -------- Fenwick Tree (Point Update, Prefix Sum) --------
struct Fenwick {
    int n; vector<long long> f;
    Fenwick(int n): n(n), f(n+1,0) {}
    void update(int i, long long v){ for(; i<=n; i+=i&-i) f[i]+=v; }
    long long sum(int i){ long long s=0; for(; i>0; i-=i&-i) s+=f[i]; return s; }
    long long range(int l, int r){ return sum(r) - sum(l-1); }
};

// -------- Segment Tree (Range Sum) --------
struct SegTree {
    int n; vector<long long> st;
    SegTree(int n): n(n), st(4*n,0) {}
    void build(vector<long long> &a, int v, int tl, int tr){
        if(tl==tr) st[v]=a[tl];
        else{
            int tm=(tl+tr)/2;
            build(a,v*2,tl,tm);
            build(a,v*2+1,tm+1,tr);
            st[v]=st[v*2]+st[v*2+1];
        }
    }
    long long query(int v, int tl, int tr, int l, int r){
        if(l>r) return 0;
        if(l<=tl && tr<=r) return st[v];
        int tm=(tl+tr)/2;
        return query(v*2,tl,tm,l,min(r,tm)) + query(v*2+1,tm+1,tr,max(l,tm+1),r);
    }
    void update(int v, int tl, int tr, int pos, long long val){
        if(tl==tr) st[v]=val;
        else{
            int tm=(tl+tr)/2;
            if(pos<=tm) update(v*2,tl,tm,pos,val);
            else update(v*2+1,tm+1,tr,pos,val);
            st[v]=st[v*2]+st[v*2+1];
        }
    }
};

// -------- Dijkstra (Adj List) --------
vector<long long> dijkstra(int n, int src, vector<vector<pair<int,int>>> &g){
    vector<long long> dist(n, INF);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    dist[src]=0; pq.push({0,src});
    while(!pq.empty()){
        auto [d,u]=pq.top(); pq.pop();
        if(d!=dist[u]) continue;
        for(auto &e:g[u]){
            auto [v,w]=e;
            if(dist[u]+w < dist[v]){
                dist[v]=dist[u]+w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

// Dijkstra's algorithm: O((n + m) log n)
//
// n = number of nodes
// m = number of edges
//
// g[u] contains pairs (v, w) meaning: edge u -> v with weight w

vector<long long> dijkstra(int n, int src, vector<vector<pair<int,int>>> &g) {

    // INF should be a large constant, e.g. 4e18
    vector<long long> dist(n, INF);   // distance array
    dist[src] = 0;

    // Min-heap of (distance, node)
    priority_queue<
        pair<long long,int>,
        vector<pair<long long,int>>,
        greater<pair<long long,int>>
    > pq;

    pq.push({0, src});   // start from the source with distance 0

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        // Skip outdated pairs
        if (d != dist[u]) continue;

        // Relax edges from node u
        for (auto &e : g[u]) {
            auto [v, w] = e;

            // If a shorter path is found
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});     // push new pair into heap
            }
        }
    }

    return dist; // shortest distances from src to all nodes
}


// -------- Check if Graph is Bipartite --------
bool bipartite(int n, vector<vector<int>> &g){
    vector<int> color(n,-1);
    for(int i=0;i<n;i++) if(color[i]==-1){
        queue<int>q; q.push(i); color[i]=0;
        while(!q.empty()){
            int u=q.front(); q.pop();
            for(int v:g[u]){
                if(color[v]==-1){ color[v]=color[u]^1; q.push(v);} 
                else if(color[v]==color[u]) return false;
            }
        }
    }
    return true;
}

// -------- Longest Increasing Subsequence (n log n) --------
int LIS(vector<int> &a){
    vector<int> d;
    for(int x:a){
        auto it = lower_bound(d.begin(), d.end(), x);
        if(it==d.end()) d.push_back(x);
        else *it=x;
    }
    return d.size();
}

// -------- LCS (DP O(n*m)) --------
int LCS(const string &a, const string &b){
    int n=a.size(), m=b.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1,0));
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
        dp[i][j]=(a[i-1]==b[j-1])?dp[i-1][j-1]+1:max(dp[i-1][j], dp[i][j-1]);
    return dp[n][m];
}

// -------- Matrix Multiplication --------
typedef vector<vector<long long>> matrix;
matrix matmul(const matrix &A, const matrix &B, long long mod){
    int n=A.size();
    matrix C(n, vector<long long>(n,0));
    for(int i=0;i<n;i++)
        for(int k=0;k<n;k++) if(A[i][k])
            for(int j=0;j<n;j++)
                C[i][j]=(C[i][j] + A[i][k]*B[k][j])%mod;
    return C;
}

matrix matpow(matrix A, long long e, long long mod){
    int n=A.size();
    matrix R(n, vector<long long>(n,0));
    for(int i=0;i<n;i++) R[i][i]=1;
    while(e){
        if(e&1) R=matmul(R,A,mod);
        A=matmul(A,A,mod);
        e>>=1;
    }
    return R;
}

// -------- Tree Diameter --------
pair<int,long long> farthest(int u, int p, vector<vector<pair<int,int>>> &g){
    pair<int,long long> best = {u,0};
    for(auto &e:g[u]) if(e.first!=p){
        auto t = farthest(e.first, u, g);
        t.second += e.second;
        if(t.second > best.second) best = t;
    }
    return best;
}

long long tree_diameter(int n, vector<vector<pair<int,int>>> &g){
    auto a = farthest(0,-1,g);
    auto b = farthest(a.first,-1,g);
    return b.second;
}

long long count_divisors(long long n) {
    long long ans = 1;
    for (long long p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            int cnt = 0;
            while (n % p == 0) n /= p, cnt++;
            ans *= (cnt + 1);
        }
    }
    if (n > 1) ans *= 2; // n is prime
    return ans;
}

long long sum_divisors(long long n) {
    long long ans = 1;
    for (long long p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            long long current = 1, term = 1;
            while (n % p == 0) {
                n /= p;
                term *= p;
                current += term;
            }
            ans *= current;
        }
    }
    if (n > 1) ans *= (1 + n);
    return ans;
}

vector<pair<long long, int>> prime_fact(long long n) {
    vector<pair<long long, int>> factors;

    for (long long p = 2; p * p <= n; p++) {     // O(√n)
        if (n % p == 0) {
            int cnt = 0;
            while (n % p == 0) {                 // O(log n)
                n /= p;
                cnt++;
            }
            factors.push_back({p, cnt});
        }
    }

    if (n > 1) {                                 // leftover prime
        factors.push_back({n, 1});
    }

    return factors;
}

vi sieve(int n = 1000000) {
    vector<bool> isPrime(n+1, true);
    for (int i = 2; i * i <= n; i++)
        if (isPrime[i])
            for (int j = i*i; j <= n; j += i)
                isPrime[j] = false;

    vector<int> primes;
    
    for (int i = 2; i <= n; i++)
        if (isPrime[i]) primes.push_back(i);

    return primes;
}

vector<string> split(const string &s) {
    vector<string> res;
    stringstream ss(s);
    string token;
    while (ss >> token) {
        res.push_back(token);
    }
    return res;
}

ll binpow(ll a, ll b) {
    ull res = 1;
    while(b){
        if(b & 1) res = res * a;
        a *= a;
        b >>=1;
    }

    return res;
}

void solve();


// ====================== FUNCTION DEFINITIONS =====================

void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

template<typename T>
void read(T &x) {
    cin >> x;
}

template<typename T>
void read(vector<T> &v) {
    for (auto &x : v) cin >> x;
}

template<typename T>
void print(const T &x) {
    cout << x;
}

template<typename T>
void print(const vector<T> &v, char sep) {
    for (int i = 0; i < (int)v.size(); i++) {
        if (i) cout << sep;
        cout << v[i];
    }
}

long long modpow(long long a, long long b, long long m) {
    long long r = 1;
    while (b) {
        if (b & 1) r = (r * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return r;
}

long long egcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) { x = 1; y = 0; return a; }
    long long x1, y1;
    long long g = egcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

long long modinv(long long a, long long m) {
    long long x, y;
    long long g = egcd(a, m, x, y);
    if (g != 1) return -1; // inverse doesn't exist
    x %= m;
    if (x < 0) x += m;
    return x;
}

vector<string> split(const string &s, char delim) {
    vector<string> res;
    string token;
    stringstream ss(s);
    while (getline(ss, token, delim)) res.push_back(token);
    return res;
}

string join(const vector<string> &v, const string &sep) {
    string out = "";
    for (int i = 0; i < (int)v.size(); i++) {
        if (i) out += sep;
        out += v[i];
    }
    return out;
}

long long gcdll(long long a, long long b){
    return b == 0 ? a : gcdll(b, a % b);
}

long long lcmll(long long a, long long b){
    return (a / gcdll(a, b)) * b;
}

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b){
    return (a / gcd(a, b)) * b;
}

// ============================ MAIN ==============================
int main() {
    fastIO();
    int t = 1;
    cin >> t;  // uncomment if needed
    while(t--) solve();
    return 0;
}

// =============== SOLVER (EDIT FOR EACH PROBLEM) ==================
void solve() {
    
    int n; cin>>n;
    vi v(n);
    auto f = [](int x) {
        return x * x;
    };
    for(int& it : v) cin>>it;

    for(int k : v) cout << k << endl;
}

// ===============================================================
//  vector<long long> dijkstra(int n, int src, vector<vector<pair<int,int>>> &g) -> distance
// sieve(int n) -> vector of primes up to n
// long long tree_diameter(int n, vector<vector<pair<int,int>>> &g) -> diameter of tree
// long long count_divisors(long long n) -> number of divisors of n 
// long long sum_divisors(long long n) -> sum of divisors of n
// vector<pair<long long, int>> prime_fact(long long n) -> prime factorization of n
// DSU dsu(n) -> disjoint set union structure
// Fenwick fenw(n) -> fenwick tree structure
// SegTree segt(n) -> segment tree structure
// bool bipartite(int n, vector<vector<int>> &g) -> check if graph is bipartite

// int LIS(vector<int> &a) -> length of longest increasing subsequence
// int LCS(const string &a, const string &b) -> length of longest common subsequence

// matrix matpow(matrix A, long long e, long long mod) -> matrix exponentiation
// matrix matmul(const matrix &A, const matrix &B, long long mod) -> matrix multiplication

// vector<string> split(const string &s) -> splits string into words
// string join(const vector<string> &v, const string &sep) -> joins vector of strings into one string

// ll binpow(ll a, ll b) -> binary exponentiation
// ll modpow(ll a, ll b, ll m) -> binary exponentiation modulo m
// long long modinv(long long a, long long m) -> modular inverse of a mod m
// long long egcd(long long a, long long b, long long &x, long long &y) -> extended gcd

// ====================== SOLVE ===============================


18
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
