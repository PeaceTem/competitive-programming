#include <bits/stdc++.h>
using namespace std;
// #define ll long long
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
    int n, m; cin >> n >> m;

    vector<int> a(n), b(m);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    multiset<int> alice(a.begin(), a.end()), bob(b.begin(), b.end());
    int turn = 1;
    while(alice.size() > 0 && bob.size() > 0){
        int k = *prev(alice.end());
        int j = *prev(bob.end());
        alice.erase(alice.find(k));
        bob.erase(bob.find(j));
        if(turn){
            j -= k;
            if(j > 0) bob.insert(j);

            alice.insert(k);
        } else {
            k -= j;
            if(k > 0) alice.insert(k);

            bob.insert(j);
        }

        turn = (turn + 1) % 2;
    }

    if(alice.size() > 0) cout << "Alice" << endl;
    else cout << "Bob" << endl;
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

