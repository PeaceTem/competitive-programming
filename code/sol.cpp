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
    int n; cin >> n;
    vector<int> a(n), b(n), c(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) cin >> c[i];
    long long ans = n;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int k = i; bool t = true;
        for(int j = 0; j < n; j++, k = (k + 1) % n){
            if(b[k] >= c[j]){
                t = false;
                break;
            }
        }

        if(t) cnt++;
    }

    ans *= cnt;
    cnt = 0;

    for(int i = 0; i < n; i++){
        int k = i; bool t = true;
        for(int j = 0; j < n; j++, k = (k + 1) % n){
            if(a[k] >= b[j]){
                t = false;
                break;
            }
        }

        if(t) cnt++;
    }

    ans *= cnt;
    cout << ans << endl;
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

