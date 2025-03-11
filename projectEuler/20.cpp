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

void multiply(vi& digits, int c, int multiplier){
    for(int i=0;i<digits.size(); i++){
        int product = digits[i] * multiplier + c;
        digits[i] = product%10;
        c = product/10;
    }
    while(c) digits.push_back(c%10), c/=10;
}


void solve(){
    vi digits = {1};
    for(int i=2;i<=100;i++){
        multiply(digits, 0, i);
    }

    cout << accumulate(all(digits), 0);
}


int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
    solve(); return 0;
}