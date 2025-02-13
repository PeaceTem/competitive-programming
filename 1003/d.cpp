#include <bits/stdc++.h>
using namespace std;
// find the max of the sum of each array
// if there are more than 1 max, find the greatest one in descending order.
// you that to sort the array to be processed first
// then use n(a[i]);

void solve() {
    unsigned long long n,m; cin>>n>>m; vector<vector<unsigned long long>> a(n, vector<unsigned long long>(m)); vector<pair<unsigned long long, unsigned long long>> b;

    for(unsigned long long i=0;i<n;i++){
        for(unsigned long long j=0;j<m;j++) cin>>a[i][j];
    }

    for(unsigned long long i=0;i<n;i++){
        unsigned long long r = accumulate(a[i].begin(), a[i].end(), 0ULL);
        b.push_back({i, r});
    }

    //use pair<unsigned long long, unsigned long long> and custom sort
    auto cmp = [&](const pair<unsigned long long, unsigned long long>& x, const pair<unsigned long long, unsigned long long>& y) -> bool {
        if(x.second != y.second) return x.second>y.second;

        const vector<unsigned long long>& u = a[x.first];
        const vector<unsigned long long>& v = a[y.first];
        unsigned long long z = min(u.size(), v.size());
        for(unsigned long long i=0; i<n;i++){
            if(u[i] != v[i]) return u[i] > v[i];
        }

        return u.size() > v.size();
    };

    sort(b.begin(), b.end(), cmp);

    unsigned long long ans = 0; unsigned long long mul = n*m;
    for(const auto& p:b){
        const vector<unsigned long long>& k = a[p.first];
        for(unsigned long long num : k) ans += mul*num, mul--;
    }

    cout << ans << '\n';
}


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	unsigned long long t; std::cin >> t; while (t--) solve(); return 0;
}