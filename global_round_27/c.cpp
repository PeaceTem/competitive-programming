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
    vector<int> a;

    a.push_back(2); a.push_back(3); a.push_back(1); a.push_back(4); a.push_back(5);
    int nn = n;
    bool used_e = true;
    int k=0;
    while(nn>0) k++, nn>>=1;
    int l = 1<<(k-1);

    if(n&1 || n<=8 || n==l){
        for(int i=6; i<=n;i++) a.push_back(i);
    } else {
        for(int i=6;i<l-1;i++) a.push_back(i);
        for(int i=l;i<=n;i++) a.push_back(i);
        // for(int i=l+1;i<n;i+=2) a.push_back(i);
        a.push_back(l-1);
    }
    
    int j=0;
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