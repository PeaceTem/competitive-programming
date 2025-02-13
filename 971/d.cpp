#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n;
    int x,y; set<int> a,b; vector<int> u(n),v(n);
    for(int i=0;i<n;i++){
        cin>>x>>y; u[i] = x; v[i] = y;
        if(y==0) a.insert(x);
        else b.insert(x);
    }
    vector<int> intersection; vector<int> diff;
    set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(intersection));
    set_symmetric_difference(a.begin(), a.end(), b.begin(), b.end(), back_inserter(diff));

    int m = intersection.size(), k = diff.size(), l = 0;
    for(int i=0;i<n-2;i++){
        if(u[i] == u[i+1] + 1 && u[i]==u[i+2]+2)
    }
    if(m >0){
        cout << 2*m*(m-1) + k*m + 1<< '\n';
    }
    else cout << 0 << '\n';
}
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; cin>>t; while(t-->0) solve(); return 0;
}
