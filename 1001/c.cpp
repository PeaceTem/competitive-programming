#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin>>n;vector<int> a(n); long long sum;
    for(int i=0; i<n; i++) cin>>a[i];
    long long ans = accumulate(a.begin(), a.end(), 0);
    while(n>1){
        for(int i=0; i<n; i++){
            a[i] = a[i+1] - a[i];
        }
        a.pop_back();
        sum = accumulate(a.begin(), a.end(), 0);
        ans = max(ans, abs(sum));
        n--;
    }
    cout << ans << '\n';
}


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; std::cin >> t; while (t--) solve(); return 0;
}