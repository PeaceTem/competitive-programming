#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define MOD 1000000007
#define INF 1000000000000000000
#define MAXN 1000005
// #define int long long
#define ld long double
#define eps 1e-9
#define bit(n, b) (((n) >> (b)) & 1)
#define bitcount(n) __builtin_popcountll(n)
#define gcd(a, b) __gcd(a, b)
// #define fileIO freopen("input.txt", "r", stdin); freopen("output.txt", "w


bool isP(vector<ll>& a, ll n){
    int l=0, r= a.size() -1; bool found = false;
    while(l<=r){
        int mid = (l+r)/2;
        if(a[mid] == n){
            // cout << "found" << endl;
            return true;
        } else if(a[mid] < n){
            r = mid-1;
        } else l = mid +1;
        
    }
    // cout << "not found" << endl;
    return false;
}

ll calc_ans(vector<ll>& a, int m){
    ll ans = 0LL;
    for(int i=0;i<m;i++){
        if(i%2==0) ans += a[i];
        else ans -= a[i];
    }

    return ans;
}


void solve(){
    int n; cin>>n;
    int m = 2*n; vector<ll> a(m);
    for(int i=0; i<m;i++) cin>>a[i];
    sort(all(a), [&](const ll& a, const ll& b){
        return a > b;
    });
    vector<ll> b = a;
    ll ans = calc_ans(a, m);
    // if the ans is in list, swap the last w elements;
    if(isP(b, ans)){
        for(int i=1;i<m-1;i+=2) swap(a[i], a[i+1]);
        ans = calc_ans(a, m);
    }

    int x =0;

    while(isP(b, ans) and x <n){
        if(abs(b[x*2] - b[x*2+1])  < ans){
            a = b;
            swap(a[x*2], a[x*2+1]);
            ans = calc_ans(a, m);
        }
        x++;        
    }
    x = 1;
    while(isP(b, ans) and x < m-1){
        a = b;
        swap(a[x], a[x+1]);
        ans = calc_ans(a, m);
        x+=2;        
    }
    
    cout << ans << ' ';
    for(ll num : a) cout << num << ' ';
    cout << endl;
    
}


int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; cin>>t; while(t-->0) solve(); return 0;
}