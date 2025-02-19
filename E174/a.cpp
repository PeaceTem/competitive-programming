#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n; cin>>n;
    vector<int> a(n-2);
    for(int i=0;i<n-2;i++) cin>>a[i];

    for(int i=0; i+4<n;i++){
        if(a[i] == 1 && a[i+1]==0 && a[i+2]==1){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; cin>>t; while(t-->0) solve(); return 0;
}