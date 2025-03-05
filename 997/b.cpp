#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin>>n;
    vector<string> a(n); string x; 
    for(int i=0;i<n;i++){
        cin>>x;
        a[i]=x;
    }

    vector<int> b(n, 0);
    iota(b.begin(), b.end(),1);
    sort(b.begin(),b.end(),[&](int i,int j){
        if(i<j){
            if(a[i-1][j-1]=='1') return true;
            else return false;
        } else {
            if(a[i-1][j-1]=='1') return false;
            else return true;
        }
    });

    for(int num : b) cout << num << ' ';
    cout << '\n';
    
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; cin>>t; while(t-->0) solve(); return 0;
}
