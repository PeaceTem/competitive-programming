#include <bits/stdc++.h>
using namespace std;

void solve(){
    vector<int> a(4);
    for(int i = 0; i < 4; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int ans=0;
    for(int i=1;i<=4;i++){
        auto it = find(a.begin(), a.end(), i);
        if(it == a.end()) ans = i;
    }

    cout << ans << '\n';
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	solve(); return 0;
}