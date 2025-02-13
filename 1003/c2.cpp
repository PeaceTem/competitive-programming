#include <bits/stdc++.h>
using namespace std;
vector<<vector<int>(200000)> a(200000), b(200000);
int arrLen; bool found =false;
void tv(int cur, int curId){

}

void solve() {
    a.clear(); b.clear();
    int n,m; cin>>n>>m;
    for(int i=0; i<n;i++) cin>>a[0][i];
    for(int i=0; i<m;i++) cin>>b[i];

    for(int i=0;i<=n;++i){
        for(int j=0; i<m;i++) a[i][j+1] = b[j] - a[i][0];
    }
    arrLen = n;

    found = false;
    tv(numeric_limits<int>::min(), -1);

    if(found) cout << "YES" << '\n';
    else cout<<"NO"<<'\n';
}


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; std::cin >> t; while (t--) solve(); return 0;
}