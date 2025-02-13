#include <bits/stdc++.h>
using namespace std;

// vector<long long> f(1000000000, 0);
long long result;
long long factorial(int n){
    // if(f[n] >0) return f[n];
    if(n==0) result = 1;
    else result = n*factorial(n-1);
    // f[n] = result;
    return result;
}

void solve() {
    long long n, d; cin>>n>>d; n = min(n,(long long) 7);
    long long fact = factorial(n);
    long long sumN = fact*d; long long sumN1 = sumN - d; long long rem = fact%3; long long nm = (rem == 2)? 11*d : (rem == 1)? d : 0;
    cout << "1" << ' ';
    for(long long i=3; i<10; i+=2){
        if((i==3 && sumN%3==0) || (i==5 && d%5==0) || (i==7 && nm%7==0) || (i==9 && sumN%9 == 0)) cout << i << ' ';
    }
    cout << '\n';
}


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; std::cin >> t; while (t--) solve(); return 0;
}