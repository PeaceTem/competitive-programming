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



// int C[501][501] = {1};
// C[]

// void comb(int n){
//     for(int i=2;i<=n;i++){
//         C[i][1]=C[i][i]=1;
//         for(int j=2;j<i;j++){
//             C[i][j] = C[i-1][j] + C[i-1][j-1];
//         }
//     }
// }
vi b(500);
void triangular_number(){
    int sm =0; // I should have make the 0 th index 0
    for(int i=1;i<=500;i++){
        sm+=i;
        b[i-1]=sm; // and also use i instead of i-1
    }
    // for(int i=0;i<10;i++) cout << b[i] << " ";
    // cout << endl;
}
int bs(vi& bb, int n){
    auto it = lower_bound(all(bb), n);
    int r = it - bb.begin();
    if(*it == n) return r+1;
    else return r;
}


void solve(){
    int n; cin>>n;
    if(n==0){
        cout << 0 << endl;
        return;
    }
    
    vii a; int s = 1;
    while(n>0){
        int k = bs(b, n); n = n - b[k-1];
        for(int i=0;i<=k;i++){
            a.pb(mp(s,s+i));
        }
        s=s+(k+1);
    }

    cout << a.size() << endl;
    for(auto& p : a){
        cout << p.F << ' ' << p.S << endl;
    }
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
    // comb(500);
    triangular_number();
	int t; cin>>t; while(t-->0) solve(); return 0;
}