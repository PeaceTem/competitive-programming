#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n,k; cin>>n>>k;
    vector<int> a(n);
    string st; cin>>st;
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> ri,bi,rp,bp;
    for(int i=0;<n;i++){
        if(st[i] == 'R') ri.push_back(i), rp.push_back(a[i]);
        else bi.push_back(i), bp.push_back(a[i]);
    }

    int mx=0;
    if(k==0){
        mx = *max_element(bi.begin(), bi.end());
        cout << mx << '\n'; return;
    }

    for(auto& it : )
}
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; cin>>t; while(t-->0) solve(); return 0;
}