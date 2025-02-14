#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n,m,q; cin>>n>>m>>q; vector<int> nm(m), nq(q);
    for(int i=0;i<m;i++) cin>>nm[i];
    for(int i=0;i<q;i++) cin>>nq[i];
    sort(nm.begin(), nm.end());
    if(nq[0] == nm[0] || nq[0] == nm[1]) cout << 0 << '\n';
    else if(nq[0] > nm[0] && nq[0] < nm[1]) cout << (nm[1]-nm[0])/2 << '\n';
    else if(nq[0]< nm[0]) cout << nm[0] - 1 << '\n';
    else if(nq[0]>nm[1]) cout << n - nm[1]<< '\n';
    
}

int main (){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t-->0) solve(); return 0;
    return 0;
}