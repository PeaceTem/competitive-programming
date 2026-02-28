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

vector<int> primes;
unordered_set<int> st_primes;
void compute(){
    vector<bool> is_prime(1e6+1, true);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i * i <= 1e6; i++){
        if(is_prime[i]){
            for(int j = i * i; j <= 1e6; j += i) is_prime[j] = false;
        }
    }

    for(int i = 2; i <= 1e6; i++){
        if(is_prime[i]) primes.push_back(i);
    }
    st_primes = unordered_set<int>(all(primes));
}

vector<int> cmp(int k){
    int n = primes.size();
    int i = 0;
    unordered_set<int> st;
    while(i < n && primes[i] <= k){
        if(st_primes.count(k)){
            st.insert(k); break;
        }
        if(k % primes[i] == 0){
            k /= primes[i];
            st.insert(primes[i]);
        } else i++;
    }
    return vector<int>(all(st));
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    bool t = true;
    for(int i = 1; i < n; i++){
        if(a[i] < a[i - 1]){
            t = false; break;
        }
    }

    if(t){
        cout << "Bob\n"; return;
    }

    int prev_max = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == 1){
            if(a[i] >= prev_max) continue;
            cout << "Alice\n"; return;
        }

        vector<int> p = cmp(a[i]);
        if(p.size() == 0){
            cout << "Zero\n"; return;
        }
        if(p.size() > 1 || p[0] < prev_max){
            cout << "Alice\n"; return;
        }

        prev_max = p[0];
    }

    cout << "Bob\n";
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    int t = 1; 
    cin >> t;
    compute();
    while(t-->0){
        solve();
    }
    return 0;
}

