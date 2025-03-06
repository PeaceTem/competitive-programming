#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int term=0,_term=0; ll number = 0;
ll collatz(ll n){
    _term++;
    if(n==1LL) return 0;
    if(n%2LL==0LL) return collatz(n/2LL);
    return collatz(n*3LL+1LL);
}
void solve() {
    ll n = 1000000LL;
    for(ll i=n; i>0; i--){
        int temp = collatz(i);
        if(_term>term){
            number = i;
            term=_term;
        }
        _term=0;
    }
    cout << number << ' ' << term << '\n';

}


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	solve(); return 0;
}