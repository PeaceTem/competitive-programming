#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long

ll bin_exp(ll a, ll b){
    ll res = 1;
    while(b>0){
        if(b & 1LL) res = res * a;
        a = a*a;
        b >>= 1;
    }
    return res;
}
void mul2(vector<int>& digits){
    int carry = 0;
    for(int i=0;i<digits.size();i++){
        int p = digits[i] * 2 + carry;
        digits[i] = p % 10;
        carry = p/10;
    }
    while(carry) digits.push_back(carry%10), carry /= 10;
}
void solve(){
    int b = 1000;
    vector<int> digits; digits.push_back(1);
    for(int i=0;i<b;i++){
        mul2(digits);
    }

    int sum = accumulate(digits.begin(), digits.end(), 0);

    cout << sum << '\n';
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	solve(); return 0;
}