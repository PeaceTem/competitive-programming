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



vector<int> sieve(){
    vector<bool> primes(2e5 + 1, true);

    primes[0] = primes[1] = false;
    for(int i = 2; i * i <= 2e5; i++){
        if(primes[i]){
            for(int j = i * i; j <= 2e5; j+=i) primes[j] = false;
        }
    }

    vector<int> p;
    for(int i = 2; i <= 2e5; i++){
        if(primes[i]) p.push_back(i);
    }

    return p;
}

vector<int> p;

void solve(){
    int n; cin >> n;

    vector<int> a(n), b(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    // int cnt = 0;
    // unordered_set<int> st(a.begin(), a.end());

    // why not find the prime factor of each number.
    and use that
    priority_queue<int> pq;
    int ans = 2;
    int k = p.size();
    for(int i = 0; i < k; i++){
        // if(st.count(p[i]) == 0 && p[i] > 2 ) continue;
        for(int j = 0; j < n; j++){
            pq.push((a[j] % p[i] ? p[i] - a[j] % p[i] : 0));
            if(pq.size() > 2) pq.pop();
        }

        int cur = 0;
        while(!pq.empty()){
            cur += pq.top();
            pq.pop();
        }
        ans = min(ans, cur);

        if(ans == 0) break;
    }

    cout << ans << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    int t = 1; 
    cin >> t;
    p = sieve();
    while(t-->0){
        solve();
    }
    return 0;
}

