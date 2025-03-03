#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n; vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    bool b=false;
    for(int i=0;i<n;i++){
        if(a[i+1]>a[i]){
            b = true; break;
        }
    }

    if(b) cout << "YES\n";
    else{
        //check if the array is already sorted
        sort(a.begin(),a.end());
        if(a.front()==a.back()) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; std::cin >> t; while (t--) solve(); return 0;
} 

The index for the first video is 000