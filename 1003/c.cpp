#include <bits/stdc++.h>
using namespace std;
vector<int> a(200000), b(1), c(200000);
int arrLen; bool found =false;
void tv(int cur, int curId){
    if(a[curId+1] >= cur){
        if(curId+1 == arrLen-1) found = true;
        else tv(a[curId+1], curId+1);}

    if(c[curId+1] >= cur){
        if(curId+1 == arrLen-1) found = true;
        else tv(c[curId+1], curId+1);}

}

void solve() {
    a.clear(); b.clear(); c.clear();
    int n,m; cin>>n>>m;
    for(int i=0; i<n;i++) cin>>a[i];
    for(int i=0; i<m;i++) cin>>b[i];

    for(int i=0; i<n;i++) c[i] = b[0] - a[i];
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