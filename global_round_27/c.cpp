#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
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

void solve(){
    int n; cin>>n;
    int a[n];
    for(int i=1; i<=n;i++) a[i-1] = i;

    int nn = n;
    bool used_e = true;
    while(nn>0);
    int m,l,k;
    if(n&1) m = n-2, l=n-4, k=n-5;
    else m = n-1, l=n-3, k=n-4;

    swap(a[l], a[k]);
    swap(a[l], a[m]);
    int j =0;
    for(int i=0;i<n;i++){
        if(i&1) j |= a[i];
        else j &= a[i];
    }
    cout << j << endl;
    for(int num : a) cout << num << ' ';
    cout << endl;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; cin>>t; while(t-->0) solve(); return 0;
}